/*
** EPITECH PROJECT, 2021
** Text.cpp.cc
** File description:
** Text.cpp.cc
*/

#include <curses.h>
#include "component/Text.hpp"

Text::Text(std::string text, unsigned int size, std::string font) :
m_x(0), m_y(0), m_message(text)
{
    (void) size;
    (void) font;
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
    m_x = x / 1920 * 100;
    m_y = y / 1080 * 100;
}