##
## CMakeLists: Plugins/Primitives/Cylinder
##

add_library(
  raytracer_cylinder SHARED
  src/Cylinder.cpp
  src/EntryPoint.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_cylinder PRIVATE ./include)
target_compile_options(raytracer_cylinder PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_cylinder PRIVATE raytracer-interface)
set_property(TARGET raytracer_cylinder PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_cylinder PROPERTY CXX_STANDARD_REQUIRED ON)
