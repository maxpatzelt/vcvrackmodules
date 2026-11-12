#pragma once
#include "rack.hpp"

struct SirenConcreteModule : rack::Module {
	enum ParamIds {
		GRAIN_MORPH_PARAM,
		SPECTRAL_SHIFT_PARAM,
		PHASE_DRIFT_PARAM,
		ECHO_BLOOM_PARAM,
		GRAIN_MORPH_ATTEN_PARAM,
		SPECTRAL_SHIFT_ATTEN_PARAM,
		PHASE_DRIFT_ATTEN_PARAM,
		ECHO_BLOOM_ATTEN_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		PITCH_INPUT,
		GRAIN_MORPH_CV_INPUT,
		SPECTRAL_SHIFT_CV_INPUT,
		PHASE_DRIFT_CV_INPUT,
		ECHO_BLOOM_CV_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		AUDIO_OUTPUT,
		NUM_OUTPUTS
	};

	// Simple oscillator state
	float phase = 0.f;
	float currentFreq = 220.f;

	SirenConcreteModule();
	void process(const ProcessArgs& args) override;
};
