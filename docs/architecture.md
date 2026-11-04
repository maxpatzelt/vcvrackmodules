# VCV Rack Modules Architecture

## Project Intent
This repository is the shared collection for the experimental VCV Rack modules.
It is a standalone Git repository, separate from the VST plugin collection.

## Structure
- Each module directory owns its Rack plugin source, panel assets, and Makefile.
- The root README describes the collection and links the module families by name.
- Root `docs/` records collection architecture, decisions, and changes.
- `Rack-SDK/` is a local-only dependency; it is not part of the GitHub repository.

## Build Boundary
Build each plugin from its module directory using its Makefile and a locally
available Rack SDK. Build output belongs in that module's `build/` directory
and is excluded from Git. Installation into a Rack user directory is a separate
operation from compilation.

## Module Status
- Most modules own their DSP implementation within their module class.
- Oscillateur Tritonique currently implements a sine oscillator and glide; its
	topology, skew, and bloom controls are not yet connected to DSP.
- Siren Concrete currently implements a sawtooth oscillator; its exposed
	controls and CV inputs are not yet connected to DSP.
- Keep documentation explicit about prototype behavior until those controls
	are implemented and tested.
