/*
** EPITECH PROJECT, 2021
** Text.cpp.cc
** File description:
** Text.cpp.cc
*/

#include "component/Text.hpp"

Text::Text(std::string text, unsigned int size, std::string font) :
    m_x(0),
    m_y(0),
    m_message(text),
    m_font(sf::Font()),
    m_text(sf::Text())
{
    m_font.loadFromFile(font);
    m_text.setFont(m_font);
    m_text.setCharacterSize(size);
    m_text.setString(m_message);
}

void Text::setText(std::string text)
{
    m_message = text;
    m_text.setString(m_message);
}

std::string Text::getText()
{
    return (m_message);
}

void Text::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    m_text.setPosition((float)m_x, (float)m_y);
}

const sf::Text& Text::getComponent() const
{
    return (m_text);
}