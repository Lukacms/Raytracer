##
## CMakeLists: Raytracer / Raytracer
##

cmake_minimum_required(VERSION 3.16)

# standard version cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
project(raytracer)

# change library prefix to none
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# for library compilation => shared libraries of primitives, lights etc
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins)

# include directories
include_directories(Core/include/)

# Warning flags
set(GCC_WARNING_FLAGS
    -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches
    -Wlogical-op -Wnull-dereference -Wuseless-cast -fno-gnu-unique -Wno-pragmas)

set(CLANG_WARNING_FLAGS
    -Weverything
    -Wno-c++20-compat
    -Wno-c++98-c++11-compat-binary-literal
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-c99-extensions
    -Wno-disabled-macro-expansion
    -Wno-documentation-unknown-command
    -Wno-exit-time-destructors
    -Wno-missing-prototypes
    -Wno-global-constructors
    -Wno-implicit-int-float-conversion
    -Wno-return-std-move
    -Wno-return-type-c-linkage
    -Wno-signed-enum-bitfield
    -Wno-weak-vtables)

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 13.0.0)
    set(CLANG_WARNING_FLAGS ${CLANG_WARNING_FLAGS} -Wno-return-std-move-in-c++11)
endif()

set(WARNING_FLAGS
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Wno-covered-switch-default
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wformat=2
    -Weffc++
    -Wno-padded
    -Wno-ctad-maybe-unsupported)

# set colors for the messages because why not ?
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()

# set different flags
set(CMAKE_BUILD_TYPE
    ${CMAKE_BUILD_TYPE}
    CACHE
      STRING
      "Choose the type of build, options are: None Debug"
      FORCE)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
endif()

# Clang-tidy
if(USE_CLANG_TIDY)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable")
  if(CLANG_TIDY_EXE)
    if(DEFINED raytracer_CLANG_TIDY_FLAGS)
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
                               "${raytracer_CLANG_TIDY_FLAGS}")
    else()
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
    message("-- Found clang-tidy: ${CLANG_TIDY_EXE}")
  else()
    message("-- Failed to find clang-tidy")
  endif()
endif()

# set warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${CLANG_WARNING_FLAGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${GCC_WARNING_FLAGS})
else()
  error("${CMAKE_CXX_COMPILER_ID}: Unsupported compiler.")
endif()

message("Warning flags: ${Cyan} ${WARNING_FLAGS}${ColourReset}")

add_library(raytracer-interface INTERFACE)

message("${Green}Loading shared libraries")
add_subdirectory(Primitives)
add_subdirectory(Lights)
message("${Green}Finished loading shared libraries${ColourReset}")

# make sure nlohmann_json is installed
message("${BoldRed}Loading nlohmann_json${ColourReset}")

set(JSON_BuildTests OFF CACHE INTERNAL "") # don't test the library

include(FetchContent)

FetchContent_Declare(json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP true)
FetchContent_MakeAvailable(json)

message("${BoldRed}Finished loading library${ColourReset}")

# link shared libraries and compile them
set_property(TARGET raytracer-interface PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer-interface PROPERTY CXX_STANDARD_REQUIRED ON)

message("Loading raytracer-core")

add_library(
    raytracer-core
    SHARED
    Core/src/factory/AFactory.cpp
    Core/src/factory/PrimitiveFactory.cpp
    Core/src/factory/LightFactory.cpp
    Core/src/ALight.cpp
    Core/src/math/Vector3D.cpp
    Core/src/math/Point3D.cpp
    Core/src/math/APrimitive.cpp
    Core/src/Camera.cpp
    Core/src/Raytracer.cpp
    Core/src/Core.cpp
    Core/src/Canva.cpp
    Core/src/PpmCreator.cpp
    Core/src/config/ConfigException.cpp
    Core/src/config/ConfigFile.cpp
    Core/src/Ray.cpp
    )
target_compile_options(raytracer-core PRIVATE ${WARNING_FLAGS})
target_include_directories(raytracer-core PUBLIC include)
set_property(TARGET raytracer-core PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer-core PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(
    raytracer-core PRIVATE
    sfml-graphics
    sfml-window
    PRIVATE nlohmann_json::nlohmann_json  # library for nlohmann_json => parse configuration files
    )

message("${BoldWhite}Finished loading raytracer-core${ColourReset}")

# adding executables
add_executable(
    raytracer
    Core/src/main.cpp
    )

# rules for raytracer project
target_link_libraries(
    raytracer PRIVATE
    raytracer-interface
    raytracer-core
    PRIVATE nlohmann_json::nlohmann_json  # library for nlohmann_json => parse configuration files
    )
target_link_options(raytracer PRIVATE -rdynamic)
target_compile_options(raytracer PRIVATE ${WARNING_FLAGS})
set_property(TARGET raytracer PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer PROPERTY CXX_STANDARD_REQUIRED ON)
