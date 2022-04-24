//
// Created by apasemko on 4/17/2022.
//

#ifndef COMPUTERGRAPHICS_VERTICESDELIMITER_H
#define COMPUTERGRAPHICS_VERTICESDELIMITER_H

#include <GL/glut.h>

class VerticesDelimiter
{
public:
    explicit VerticesDelimiter(GLenum mode)
    {
        glBegin(mode);
    }

    ~VerticesDelimiter()
    {
        glEnd();
    }
};


#endif //COMPUTERGRAPHICS_VERTICESDELIMITER_H
