##
## CMakeLists: Plugins/Primitives/Cone
##

add_library(
  raytracer_cone SHARED
  src/Cone.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_cone PRIVATE ./include)
target_compile_options(raytracer_cone PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_cone PRIVATE raytracer-interface)
set_property(TARGET raytracer_cone PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_cone PROPERTY CXX_STANDARD_REQUIRED ON)
