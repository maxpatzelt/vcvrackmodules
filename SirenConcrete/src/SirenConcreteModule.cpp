#include "SirenConcreteModule.hpp"
#include <cmath>

using namespace rack;

SirenConcreteModule::SirenConcreteModule() {
	config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS);

	// Main knobs
	configParam(GRAIN_MORPH_PARAM, 0.0f, 1.0f, 0.5f, "Sweep");
	configParam(SPECTRAL_SHIFT_PARAM, 0.0f, 1.0f, 0.5f, "Grain");
	configParam(PHASE_DRIFT_PARAM, 0.0f, 1.0f, 0.5f, "Decay");
	configParam(ECHO_BLOOM_PARAM, 0.0f, 1.0f, 0.5f, "Texture");

	// Attenuverters
	configParam(GRAIN_MORPH_ATTEN_PARAM, -1.0f, 1.0f, 0.0f, "Sweep CV");
	configParam(SPECTRAL_SHIFT_ATTEN_PARAM, -1.0f, 1.0f, 0.0f, "Grain CV");
	configParam(PHASE_DRIFT_ATTEN_PARAM, -1.0f, 1.0f, 0.0f, "Decay CV");
	configParam(ECHO_BLOOM_ATTEN_PARAM, -1.0f, 1.0f, 0.0f, "Texture CV");

	// Inputs
	configInput(PITCH_INPUT, "Trig");
	configInput(GRAIN_MORPH_CV_INPUT, "Sweep CV");
	configInput(SPECTRAL_SHIFT_CV_INPUT, "Grain CV");
	configInput(PHASE_DRIFT_CV_INPUT, "Decay CV");
	configInput(ECHO_BLOOM_CV_INPUT, "Texture CV");

	// Output
	configOutput(AUDIO_OUTPUT, "Audio");
}

void SirenConcreteModule::process(const ProcessArgs& args) {
	// Get pitch from input (treating as V/Oct for now)
	float pitch = 0.f;
	if (inputs[PITCH_INPUT].isConnected()) {
		pitch = inputs[PITCH_INPUT].getVoltage();
	}
	currentFreq = 220.f * std::pow(2.f, pitch);

	// Advance phase
	phase += currentFreq * args.sampleTime;
	if (phase >= 1.f) {
		phase -= 1.f;
	}

	// Simple sawtooth wave output
	float output = 2.f * phase - 1.f;

	// Output at standard 5V amplitude
	outputs[AUDIO_OUTPUT].setVoltage(output * 5.f);
}
