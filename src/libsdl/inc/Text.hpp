/*
** EPITECH PROJECT, 2021
** Text.hpp.h
** File description:
** Text.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_TEXT
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_TEXT


#include <string>
#include "../../../inc/IText.hpp"
#include "SdlModule.hpp"


class Text : public IText
{
    int m_x;
    int m_y;
    std::string m_message;
    TTF_Font *m_font;
    SDL_Surface *m_textSurface;
    SDL_Texture *m_textTexture;
public:
    Text(std::string text, unsigned int size, std::string font);
    void setText(std::string text) override;
    std::string getText() override;
    void setPosition(int x, int y) override;
};


#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_TEXT
