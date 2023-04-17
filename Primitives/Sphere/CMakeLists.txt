##
## CMakeLists: Plugins/Primitives/Sphere
##

add_library(
  sphere_plugin SHARED
  src/Sphere.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(sphere_plugin PRIVATE ./include)
target_compile_options(sphere_plugin PRIVATE ${WARNING_FLAGS})
target_link_libraries(sphere_plugin PRIVATE raytracer-interface)
set_property(TARGET sphere_plugin PROPERTY CXX_STANDARD 20)
set_property(TARGET sphere_plugin PROPERTY CXX_STANDARD_REQUIRED ON)