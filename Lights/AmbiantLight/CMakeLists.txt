##
## CMakeLists: Plugins/Primitives/Sphere
##

add_library(
  raytracer_ambiant_light SHARED
  src/AmbiantLight.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_ambiant_light PRIVATE ./include)
target_compile_options(raytracer_ambiant_light PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_ambiant_light PRIVATE raytracer-interface)
set_property(TARGET raytracer_ambiant_light PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_ambiant_light PROPERTY CXX_STANDARD_REQUIRED ON)