/*
** EPITECH PROJECT, 2021
** IText.hpp.h
** File description:
** IText.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ITEXT
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ITEXT

class IText
{
public:
    virtual ~IText() = default;
    //void pause_text(IText *text, arcade::pause pause);
    //void load_text(IText *text, arcade::load load);
    //void delete_text(IText *text);
    virtual void setText(std::string content) = 0;
    virtual std::string getText() = 0;
    virtual void setPosition(int x, int y) = 0;
    //void set_text_position(IText *text, std::pair<float, float> pos);
//void set_text_rotation(IText *text, float angle);
//void set_text_scale(IText *text, std::pair<float, float> scale);
    //void set_text_color(IText *text, arcade::color color);
//void set_text_font(IText *text, std::string font_path);
    //std::pair <float, float> get_text_position(IText *text);
//float get_text_rotation(arcade::Text *text);
//std::pair <float, float> get_text_scale(arcade::Text *text);
    //arcade::color get_text_color(IText *text);
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ITEXT
