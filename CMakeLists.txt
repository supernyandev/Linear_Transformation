project(Linear_Transformation)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Linear_Transformation main.cpp Simulation/Utilities/Shapes.cpp Simulation/Utilities/Shapes.h Simulation/Utilities/Coordinate.cpp Simulation/Utilities/Coordinate.h Simulation/transformation.cpp Simulation/transformation.h Simulation/Utilities/includes.h)

target_link_libraries(Linear_Transformation sfml-graphics sfml-audio)