//
// Created by apasemko on 4/16/2022.
//

#include "Point.h"
#include <GL/glut.h>
#include <cmath>


/// COORDINATES

Coordinates::Coordinates(float x, float y) :
    x(x),
    y(y)
{}

float Coordinates::get_x() const
{
    return x;
}

float Coordinates::get_y() const
{
    return y;
}

void Coordinates::gl_specify() const
{
    glVertex2f(x, y);
}

float Coordinates::distance_to(const Coordinates &other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}


/// POINT

Point::Point(const Coordinates &coords, const Color &color) :
    coordinates(coords),
    color(color)
{}

Point::Point() :
        coordinates({0.0, 0.0})
{}

void Point::gl_specify() const
{
    color.gl_specify();
    coordinates.gl_specify();
}

void Point::highlight()
{
    color.highlight();
}

void Point::unhighlight()
{
    color.unhighlight();
}

const Coordinates &Point::get_coordinates() const
{
    return coordinates;
}

void Point::set_coordinates(const Coordinates &coords)
{
    coordinates = coords;
}
