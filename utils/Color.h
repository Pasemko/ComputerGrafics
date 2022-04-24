//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_COLOR_H
#define COMPUTERGRAPHICS_COLOR_H


enum ColorType
{
    CLASSIC,
    PRIMARY,
    SECONDARY,
};

class Color
{
public:
    Color() = default;
    explicit Color(ColorType type);
    Color(const Color &other, ColorType type);
    Color(const Color &other);
    void gl_specify() const;
    void highlight();
    void unhighlight();

private:
    float red{};
    float green{};
    float blue{};
    float alpha{};
    float highlight_value{};
};


#endif //COMPUTERGRAPHICS_COLOR_H
