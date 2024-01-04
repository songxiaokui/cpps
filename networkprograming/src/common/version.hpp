#pragma once

/// For CMake
#define PROJECT_VER_MAJOR 12
#define PROJECT_VER_MINOR 8
#define PROJECT_VER_PATCH 0

#define PROJECT_VERSION (PROJECT_VER_MAJOR * 10000 + PROJECT_VER_MINOR * 100 + PROJECT_VER_PATCH)

/// For 3-rd Party
#define PROJECT_DEPS_VER_MAJOR 1
#define PROJECT_DEPS_VER_MINOR 6

/// For Source Code
#define _PROJECT_STR(s) #s
#define PROJECT_VERSION_STR(major, minor, patch) _PROJECT_STR(major.minor.patch)
