/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libsfml.cpp
*/

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../inc/SfmlModule.hpp"
#include "../inc/SfmlColor.hpp"
#include "../inc/SfmlKeyboard.hpp"

sfml::SfmlModule::SfmlModule() :
    m_window(),
    m_name("libSfml"),
    m_font()
{
    std::cout << "[" << m_name << "] initializing..." << std::endl;
    m_font.loadFromFile("8bit.ttf");
    m_window.create({1920, 1080, 32}, "arcade_sfml");
}

sfml::SfmlModule::~SfmlModule()
{
    std::cout << "[" << m_name << "] stopping...\n";
}

std::string sfml::SfmlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

void sfml::SfmlModule::clearWindow()
{
    m_window.clear();
}

void sfml::SfmlModule::displayWindow()
{
    m_window.display();
}

void sfml::SfmlModule::checkEvent()
{
    while (m_window.pollEvent(m_event))
        if (m_event.type == sf::Event::Closed)
            m_window.close();
}

bool sfml::SfmlModule::isOk()
{
    return (m_window.isOpen());
}

void sfml::SfmlModule::drawText(const std::string& message, int size, arc::Color color, std::pair<int, int> position)
{
    sf::Text text(message, m_font, size);

    text.setFillColor(sfml::sfmlColorMap.find(color)->second);
    text.setPosition(position.first * 10, position.second * 10);
    m_window.draw(text);
}

void sfml::SfmlModule::drawSquare(int size, arc::Color color, std::pair<int, int> position)
{
    sf::RectangleShape shape({(float)size, (float)size});

    shape.setFillColor(sfmlColorMap.find(color)->second);
    shape.setPosition(position.first * 10, position.second * 10);
    m_window.draw(shape);
}

bool sfml::SfmlModule::getKeyDown(arc::Keyboard key)
{
    if (sf::Keyboard::isKeyPressed(sfml::keyboardMap.find(key)->second))
        return (true);
    return (false);
}