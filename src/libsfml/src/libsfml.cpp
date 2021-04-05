/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../inc/SfmlModule.hpp"

SfmlModule::SfmlModule() :
    m_window(),
    m_name("libSfml")
{
    m_window.create({1920, 1080, 32}, "arcade_sfml");
}

void SfmlModule::init()
{
    std::cout << "[" << m_name << "] initializing..." << std::endl;
}

void SfmlModule::stop()
{
    std::cout << "[" << m_name << "] stopping...\n";
}

std::string SfmlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

void SfmlModule::clearWindow()
{
    m_window.clear();
}

void SfmlModule::displayWindow()
{
    m_window.display();
}

bool SfmlModule::pollEvent()
{
    return (m_window.pollEvent(m_event));
}

void SfmlModule::closeWindow()
{
    if (m_event.type == sf::Event::Closed)
        m_window.close();
}

bool SfmlModule::isOk()
{
    return (m_window.isOpen());
}