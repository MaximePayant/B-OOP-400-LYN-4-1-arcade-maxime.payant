/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "../inc/SfmlModule.hpp"

__attribute__((constructor))
void libSfml_constructor()
{
    printf("[Sfml Module] Starting SFML module...\n");
}

__attribute__((destructor))
void libSfml_destructor()
{
    printf("[Sfml Module] SFML module stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *module = new sfml::SfmlModule();

    std::cout << module->getName() << " Entry point created!" << std::endl;
    return (module);
}

sfml::SfmlModule::SfmlModule() : IDisplayModule(),
                                 m_window(),
                                 m_name("libSfml")
SfmlModule::SfmlModule() :
    m_window(),
    m_name("libSfml")
{
    std::cout << this->getName() << " initializing..." << std::endl;
    m_window.create({1920, 1080, 32}, "arcade_sfml");
}

sfml::SfmlModule::~SfmlModule()
{
    std::cout << this->getName() << " stopping...\n";
}

void sfml::SfmlModule::init()
{
    std::cout << getName() << " initializing..." << std::endl;
}

void sfml::SfmlModule::stop()
{
    std::cout << getName() << " stopping...\n";
}

std::string sfml::SfmlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool sfml::SfmlModule::isOk()
{
    sf::Event event;

    while (m_window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            m_window.close();
    return (m_window.isOpen());
}

void sfml::SfmlModule::clearWindow()
{
    m_window.clear();
}

void sfml::SfmlModule::displayWindow()
{
    m_window.display();
}

bool sfml::SfmlModule::pollEvent()
{
    return (m_window.pollEvent(m_event));
}

void sfml::SfmlModule::closeWindow()
{
    if (m_event.type == sf::Event::Closed)
        m_window.close();
}

bool sfml::SfmlModule::isOk()
{
    return (m_window.isOpen());
}

IText *sfml::SfmlModule::createText(const std::string& name, const std::string& text, unsigned int size,
                                 const std::string& font)
{
    m_TextMap.emplace(name, new Text(text, size, font));
    return (getText(name));
}

IText *sfml::SfmlModule::getText(const std::string& name)
{
    auto result = m_TextMap.find(name);

    if (result != m_TextMap.end())
        return (result->second);
    throw std::runtime_error("Text not found");
}

void sfml::SfmlModule::deleteText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    m_TextMap.erase(it);
}

void sfml::SfmlModule::drawText(const std::string& name)
{
    m_window.draw(dynamic_cast<Text*>(m_TextMap[name])->getComponent());
}