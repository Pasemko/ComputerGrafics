//
// Created by apasemko on 4/16/2022.
//

#include "Color.h"
#include <GL/glut.h>
#include <random>
#include <map>

namespace
{
    constexpr float alpha_distinctive_value = 0.25f;
    const std::map<ColorType, float> ct_alpha_map = {
            {ColorType::CLASSIC, 1.0f},
            {ColorType::PRIMARY, 0.5f},
            {ColorType::SECONDARY, 0.25f}
    };

    float map_type_alpha(ColorType type)
    {
        auto type_alpha = ct_alpha_map.find(type);
        if (type_alpha != ct_alpha_map.end())
        {
            return type_alpha->second;
        }

        return 0.0f;
    }

    float generate_atomic_color_value()
    {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        static std::uniform_real_distribution<float> distribution(0, 1);
        return distribution(engine);
    }
}



Color::Color(ColorType type) :
    red(generate_atomic_color_value()),
    green(generate_atomic_color_value()),
    blue(generate_atomic_color_value()),
    alpha(map_type_alpha(type)),
    highlight_value(0.0f)
{}

Color::Color(const Color &other, ColorType type) :
    alpha(map_type_alpha(type)),
    highlight_value(0.0f)
{
    red = other.red;
    green = other.green;
    blue = other.blue;
}

Color::Color(const Color &other) :
    highlight_value(0.0f)
{
    red = other.red;
    green = other.green;
    blue = other.blue;
    alpha = other.alpha;
}

void Color::gl_specify() const
{
    glColor4f(red, green, blue, alpha + highlight_value);
}

void Color::highlight()
{
    if (highlight_value == 0.0f)
    {
        highlight_value += alpha_distinctive_value;
    }
}

void Color::unhighlight()
{
    if (highlight_value == alpha_distinctive_value)
    {
        highlight_value -= alpha_distinctive_value;
    }
}

