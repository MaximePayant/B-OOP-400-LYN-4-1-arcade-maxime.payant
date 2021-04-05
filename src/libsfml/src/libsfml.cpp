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
    auto *module = new SfmlModule();
    std::cout << module->getName() << ": Loaded!" << std::endl;
    return (module);
}

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

IText *SfmlModule::createText(const std::string& name, const std::string& text, unsigned int size,
                                 const std::string& font)
{
    m_TextMap.emplace(name, new Text(text, size, font));
    return (getText(name));
}

IText *SfmlModule::getText(const std::string& name)
{
    auto result = m_TextMap.find(name);

    if (result != m_TextMap.end())
        return (result->second);
    throw std::runtime_error("Text not found");
}

void SfmlModule::deleteText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    m_TextMap.erase(it);
}

void SfmlModule::drawText(const std::string& name)
{
    m_window.draw(dynamic_cast<Text*>(m_TextMap[name])->getComponent());
}