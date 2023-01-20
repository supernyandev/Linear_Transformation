project(Linear_Transformation)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Linear_Transformation main.cpp Utilities/Shapes.cpp Utilities/Shapes.h Utilities/Coordinate.cpp Utilities/Coordinate.h)

target_link_libraries(Linear_Transformation sfml-graphics sfml-audio)