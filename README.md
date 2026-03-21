# zBot

zBot is a free cross-platform replay bot for Geometry Dash, built as a [Geode](https://geode-sdk.org/) mod. See [about.md](about.md) for full feature details.

## Building

### Prerequisites

- [CMake](https://cmake.org/) 3.21 or newer
- [Geode SDK](https://docs.geode-sdk.org/getting-started/cpp-primer) (set up via the Geode CLI)
- A C++23-capable compiler:
  - **Windows**: MSVC (Visual Studio 2022) or Clang
  - **macOS**: Xcode / Apple Clang
  - **Android**: Android NDK r26+ (installed and configured automatically by the Geode CLI via `geode build`)

### Building locally

1. Install the Geode CLI and set up the SDK by following the [Geode getting-started guide](https://docs.geode-sdk.org/getting-started/).

2. Clone the repository (with submodules):
   ```sh
   git clone --recursive https://github.com/Zanci19/zbot.git
   cd zbot
   ```

3. Configure with CMake:
   ```sh
   cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
   ```

4. Build:
   ```sh
   cmake --build build --config RelWithDebInfo
   ```

The compiled `.geode` file will be placed in the build output directory.

### Building via GitHub Actions (CI)

The repository ships with a workflow (`.github/workflows/build.yml`) that automatically builds the mod for **Windows**, **macOS**, **Android32**, and **Android64** on every push and pull request.

The workflow uses the official [`geode-sdk/build-geode-mod`](https://github.com/geode-sdk/build-geode-mod) action and then combines the per-platform artifacts into a single `.geode` file that is uploaded as a build artifact.

To trigger a build manually, push to any branch or open a pull request.
