## CMakeLists: Plugins/Primitives/Sphere
##
##

add_library(
  raytracer_sphere SHARED
  src/Sphere.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_sphere PRIVATE ./include)
target_compile_options(raytracer_sphere PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_sphere PRIVATE raytracer-interface)
set_property(TARGET raytracer_sphere PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_sphere PROPERTY CXX_STANDARD_REQUIRED ON)