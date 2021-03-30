/*
** EPITECH PROJECT, 2021
** Text.cpp.cc
** File description:
** Text.cpp.cc
*/

#include "../inc/Text.hpp"

Text::Text(std::string text, unsigned int size, std::string font) :
m_x(0), m_y(0), m_message(text), m_font(TTF_open(font, size))
{
    m_textSurface = TTF_RenderText_Solid(m_font, m_message, {255, 255, 255, 0});
    m_textTexture = SDL_CreateTextureFromSurface(renderer, m_textSurface);
}

void Text::setText(std::string text)
{
    m_message = text;
}

std::string Text::getText()
{
    return (m_message);
}

void Text::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}