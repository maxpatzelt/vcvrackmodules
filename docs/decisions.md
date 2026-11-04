# VCV Rack Modules Decisions

## Repository Boundary
- Keep `vcv-rack-modules` as one Git repository containing the current module collection.
- Keep the VST plugin collection in its separate repository.
- Preserve the previous `VCVRackModules.git` URL as a local `legacy` remote while using the lowercase repository URL as `origin`.

## Dependencies and Outputs
- Keep `Rack-SDK/` local and ignored; obtain the SDK separately for each development machine.
- Keep generated module `build/` directories out of Git.
- Keep project source, panel assets, build configuration, and documentation in Git.

## Licensing
- Preserve licenses at their existing module scope.
- OBF has an MIT license in `OBF/LICENSE`; do not imply that it licenses the entire collection.

## Validation
- Do not describe a module as implemented until its controls and inputs affect the DSP and the module has been built and checked in Rack.
- Record build and runtime verification when it is performed; no new VCV build has been verified in this setup.
