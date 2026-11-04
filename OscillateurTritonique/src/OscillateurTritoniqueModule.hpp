#pragma once
#include <rack.hpp>

using namespace rack;

struct OscillateurTritoniqueModule : Module {
    enum ParamIds {
        TOPOLOGY_PARAM,
        TOPOLOGY_ATTEN_PARAM,
        SKEW_PARAM,
        SKEW_ATTEN_PARAM,
        BLOOM_PARAM,
        BLOOM_ATTEN_PARAM,
        GLIDE_PARAM,
        GLIDE_ATTEN_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        VOCT_INPUT,
        TOPOLOGY_CV_INPUT,
        SKEW_CV_INPUT,
        BLOOM_CV_INPUT,
        GLIDE_CV_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        AUDIO_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS
    };

    // Simple oscillator state
    float phase = 0.f;
    float currentFreq = 261.626f; // C4

    OscillateurTritoniqueModule();
    void process(const ProcessArgs& args) override;
    void onReset() override;
};
