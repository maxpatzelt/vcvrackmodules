# VCV Rack Modules Project Context

Updated: 2026-11-03.

## Purpose
- Develop and maintain the experimental VCV Rack module collection.
- Keep each module's source, panel assets, and build files in its module directory.

## Repository
- NAS working path: `VSCODE PROGRAMS/Audio Programming/vcv-rack-modules/`.
- GitHub: `https://github.com/maxpatzelt/vcv-rack-modules`.
- Primary branch: `main`.
- The previous `https://github.com/maxpatzelt/VCVRackModules.git` URL is retained as the local `legacy` remote.

## Structure
- Modules: `Diffusaire/`, `DubBoite/`, `OBF/`, `OscillateurTritonique/`, `SirenConcrete/`, `Sonogenese/`, and `Temporaliste/`.
- Shared collection documentation and `VCVModulePicture.PNG` are at the repository root.
- `Rack-SDK/` is a local development dependency and is ignored by Git.
- Module `build/` directories are generated output and are ignored by Git.

## Development Requirements
- VCV Rack SDK 2.x.
- A C++11-compatible compiler and Make.
- Build each module using its own Makefile; review that module's README and Makefile before installing it into Rack.

## Current Status
- The collection is connected to its GitHub repository; the old remote remains available as `legacy`.
- Build and runtime validation have not been performed as part of this repository setup.
- Oscillateur Tritonique currently outputs a sine wave with V/Oct and glide; topology, skew, and bloom controls are not yet applied.
- Siren Concrete currently outputs a sawtooth wave; its controls and CV inputs are not yet applied.
- The OBF directory contains its own MIT license. No collection-wide license is declared.

## Working Rules
- Keep source, documentation, and project configuration in Git.
- Do not commit generated builds or the local Rack SDK.
- Preserve module naming and per-module licensing.
- Use normal commits and pushes; do not rewrite shared history.
