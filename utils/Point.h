//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_POINT_H
#define COMPUTERGRAPHICS_POINT_H

#include "Color.h"

class Coordinates
{
public:
    Coordinates(float x, float y);
    float get_x() const;
    float get_y() const;
    void gl_specify() const;
    float distance_to(const Coordinates &other) const;

private:
    float x;
    float y;
};

class Point
{
public:
    Point(const Coordinates &coords, const Color &color);

    Point();

    void gl_specify() const;
    void highlight();
    void unhighlight();
    const Coordinates &get_coordinates() const;

    void set_coordinates(const Coordinates &coordinates);

private:
    Coordinates coordinates;
    Color color;
};


#endif //COMPUTERGRAPHICS_POINT_H
