/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
*/

#include <iostream>
#include "../inc/nibbler.hpp"

__attribute__((constructor))
void pacManConstructor()
{
    std::cout << "[Nibbler] Loading Nibbler game..." << std::endl;
}

__attribute__((destructor))
void pacManDestructor()
{
    std::cout << "[Nibbler] Loading Nibbler stopped" << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new Nibbler();

    std::cout << "[Nibbler] Entrypoint created." << std::endl;
    return (game);
}

Nibbler::Nibbler() : IGame()
{}

Nibbler::~Nibbler()
= default;

void Nibbler::start(arc::IDisplayModule* module)
{
    (void) module;
}

void Nibbler::update(arc::IDisplayModule* module)
{
    module->checkEvent();
    module->clearWindow();
    module->drawText("UN JEU", 30, arc::WHITE, {10, 10});
    module->displayWindow();
}