#include "OscillateurTritoniqueModule.hpp"
#include <cmath>

OscillateurTritoniqueModule::OscillateurTritoniqueModule() {
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

    configParam(TOPOLOGY_PARAM, 0.f, 1.f, 0.5f, "Topology");
    configParam(TOPOLOGY_ATTEN_PARAM, -1.f, 1.f, 0.f, "Topology CV");

    configParam(SKEW_PARAM, 0.f, 1.f, 0.5f, "Skew");
    configParam(SKEW_ATTEN_PARAM, -1.f, 1.f, 0.f, "Skew CV");

    configParam(BLOOM_PARAM, 0.f, 1.f, 0.5f, "Bloom");
    configParam(BLOOM_ATTEN_PARAM, -1.f, 1.f, 0.f, "Bloom CV");

    configParam(GLIDE_PARAM, 0.f, 1.f, 0.f, "Glide");
    configParam(GLIDE_ATTEN_PARAM, -1.f, 1.f, 0.f, "Glide CV");

    configInput(VOCT_INPUT, "V/Oct");
    configInput(TOPOLOGY_CV_INPUT, "Topology CV");
    configInput(SKEW_CV_INPUT, "Skew CV");
    configInput(BLOOM_CV_INPUT, "Bloom CV");
    configInput(GLIDE_CV_INPUT, "Glide CV");

    configOutput(AUDIO_OUTPUT, "Audio");

    onReset();
}

void OscillateurTritoniqueModule::onReset() {
    phase = 0.f;
    currentFreq = 261.626f;
}

void OscillateurTritoniqueModule::process(const ProcessArgs& args) {
    // Get V/Oct input
    float voct = inputs[VOCT_INPUT].getVoltage();
    float targetFreq = 261.626f * std::pow(2.f, voct);

    // Simple glide
    float glide = params[GLIDE_PARAM].getValue();
    if (inputs[GLIDE_CV_INPUT].isConnected()) {
        glide += inputs[GLIDE_CV_INPUT].getVoltage() * params[GLIDE_ATTEN_PARAM].getValue() * 0.1f;
    }
    glide = clamp(glide, 0.f, 1.f);

    float portamentoTime = glide * 0.1f; // 0 to 100ms
    if (portamentoTime > 0.001f) {
        float lambda = args.sampleTime / portamentoTime;
        currentFreq += (targetFreq - currentFreq) * clamp(lambda, 0.f, 1.f);
    } else {
        currentFreq = targetFreq;
    }

    // Advance phase
    phase += currentFreq * args.sampleTime;
    if (phase >= 1.f) {
        phase -= 1.f;
    }

    // Simple sine wave output
    float output = std::sin(2.f * M_PI * phase);

    // Output at standard 5V amplitude
    outputs[AUDIO_OUTPUT].setVoltage(output * 5.f);
}
