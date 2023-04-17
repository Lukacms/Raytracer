##
## CMakeLists: Plugins/Primitives/Sphere
##

add_library(
  raytracer_plane SHARED
  src/Plane.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_plane PRIVATE ./include)
target_compile_options(raytracer_plane PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_plane PRIVATE raytracer-interface)
set_property(TARGET raytracer_plane PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_plane PROPERTY CXX_STANDARD_REQUIRED ON)