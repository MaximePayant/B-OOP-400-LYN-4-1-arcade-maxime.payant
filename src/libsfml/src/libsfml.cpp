/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
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
    return (new SfmlModule());
}

SfmlModule::SfmlModule() : IDisplayModule(),
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

bool SfmlModule::isOk()
{
    return (m_window.isOpen());
}