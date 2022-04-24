cmake_minimum_required(VERSION 3.21)
project(ComputerGraphics)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ComputerGraphics
        main.cpp
        utils/WindowManager.h
        lab_1/PrimitivesWM.cpp
        lab_1/PrimitivesWM.h
        utils/WMHolder.cpp
        utils/WMHolder.h
        lab_1/PrimitivesWMHolder.cpp
        lab_1/PrimitivesWMHolder.h
        utils/utils.cpp
        utils/utils.h
        utils/Color.cpp
        utils/Color.h
        utils/Point.cpp
        utils/Point.h
        lab_1/TriangleStrip.cpp
        lab_1/TriangleStrip.h
        lab_1/TriangleStripManager.cpp
        lab_1/TriangleStripManager.h
        utils/VerticesDelimiter.h
        lab_2/PrimitivesRasteringWM.cpp
        lab_2/PrimitivesRasteringWM.h
        lab_2/PrimitivesRasteringWMHolder.cpp
        lab_2/PrimitivesRasteringWMHolder.h
        lab_2/PolygonManager.cpp
        lab_2/PolygonManager.h
        lab_2/Polygon.cpp
        lab_2/Polygon.h)

target_link_libraries(ComputerGraphics ${OPENGL_LIBRARIES})
target_link_libraries(ComputerGraphics ${GLUT_LIBRARIES})
target_link_libraries(ComputerGraphics -lopengl32 -g -lfreeglut)
