##
## CMakeLists: Primitives / Moebius
##


add_library(
  raytracer_moebius SHARED
  src/Moebius.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_moebius PRIVATE ./include)
target_compile_options(raytracer_moebius PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_moebius PRIVATE raytracer-interface)
set_property(TARGET raytracer_moebius PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_moebius PROPERTY CXX_STANDARD_REQUIRED ON)
