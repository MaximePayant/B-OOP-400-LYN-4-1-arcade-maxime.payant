/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>

#include "../inc/Module.hpp"

__attribute__((constructor))
void libSfml_constructor()
{
    printf("[Sfml Module]: Starting SFML module...\n");
}

__attribute__((destructor))
void libSfml_destructor()
{
    printf("[Sfml Module]: SFML module stopped.\n");
}

std::string sfml::Module::getName()
{
    return ("[" + m_name + " Module]");
}

extern "C" void *entryPoint()
{
    auto *module = new sfml::Module();

    std::cout << module->getName() << ": Loaded!" << std::endl;
    return (module);
}

sfml::Module::Module() :
    m_name("Sfml"),
    m_window(),
    m_event()
{
    m_window.create({1920, 1080, 32}, "arcade_sfml");
}

void sfml::Module::init()
{
    std::cout << getName() << ": initializing..." << std::endl;
}

void sfml::Module::stop()
{
    std::cout << getName() << ": stopping...\n";
}

bool sfml::Module::isOk()
{
    return (m_window.isOpen());
}

bool sfml::Module::pollEvent()
{
    return (m_window.pollEvent(m_event));
}

void sfml::Module::closeWindow()
{
    if (m_event.type == sf::Event::Closed)
        m_window.close();
}

void sfml::Module::clear()
{
    m_window.clear(sf::Color(28, 28, 28));
}

template <typename... Args>
void sfml::Module::draw(Args... values)
{
    m_window.draw(values...);
}

void sfml::Module::display()
{
    m_window.display();
}