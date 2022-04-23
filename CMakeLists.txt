cmake_minimum_required(VERSION 3.21)
project(ComputerGraphics)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ComputerGraphics
        main.cpp
        util/WindowManager.h
        lab_1/PrimitivesWM.cpp
        lab_1/PrimitivesWM.h
        util/WMHolder.cpp
        util/WMHolder.h
        lab_1/PrimitivesWMHolder.cpp
        lab_1/PrimitivesWMHolder.h
        util/utils.cpp
        util/utils.h
        lab_1/Color.cpp
        lab_1/Color.h
        lab_1/Point.cpp
        lab_1/Point.h
        lab_1/TriangleStrip.cpp
        lab_1/TriangleStrip.h
        lab_1/TriangleStripManager.cpp
        lab_1/TriangleStripManager.h
        util/VerticesDelimiter.h
)

target_link_libraries(ComputerGraphics ${OPENGL_LIBRARIES})
target_link_libraries(ComputerGraphics ${GLUT_LIBRARIES})
target_link_libraries(ComputerGraphics -lopengl32 -g -lfreeglut)
