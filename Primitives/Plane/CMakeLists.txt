##
## CMakeLists: Plugins/Primitives/Sphere
##

add_library(
  plane_plugin SHARED
  src/Plane.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(plane_plugin PRIVATE ./include)
target_compile_options(plane_plugin PRIVATE ${WARNING_FLAGS})
target_link_libraries(plane_plugin PRIVATE raytracer-interface)
set_property(TARGET plane_plugin PROPERTY CXX_STANDARD 20)
set_property(TARGET plane_plugin PROPERTY CXX_STANDARD_REQUIRED ON)