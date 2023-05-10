##
## CMakeLists: Plugins/Primitives/Limited_Cylinder
##

add_library(
  raytracer_limited_cylinder SHARED
  src/Limited_Cylinder.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_limited_cylinder PRIVATE ./include)
target_compile_options(raytracer_limited_cylinder PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_limited_cylinder PRIVATE raytracer-interface)
set_property(TARGET raytracer_limited_cylinder PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_limited_cylinder PROPERTY CXX_STANDARD_REQUIRED ON)
