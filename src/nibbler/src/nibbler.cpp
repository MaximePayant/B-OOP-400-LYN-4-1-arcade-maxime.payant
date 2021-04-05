/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
*/

#include <iostream>
#include "../../pacman/inc/pacMan.hpp"

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
    auto *game = new PacMan();

    std::cout << "[Nibbler] Entrypoint created." << std::endl;
    return (game);
}

PacMan::PacMan() : IGame()
{}

PacMan::~PacMan()
= default;

void PacMan::start(arc::IDisplayModule *module)
{
    (void) module;
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->checkEvent();
    module->clearWindow();
    module->drawText("UN JEU", 30, arc::WHITE, {10, 10});
    module->displayWindow();
}