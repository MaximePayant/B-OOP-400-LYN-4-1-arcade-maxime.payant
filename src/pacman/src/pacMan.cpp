/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.cpp
*/

#include <iostream>
#include "../inc/pacMan.hpp"

__attribute__((constructor))
void pacManConstructor()
{
    printf("[PacMan] Loading PacMan game...\n");
}

__attribute__((destructor))
void pacManDestructor()
{
    printf("[PacMan] PacMan game stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *game = new PacMan();

    return (game);
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->checkEvent();
    module->clearWindow();
    module->drawText("Title", 30, arc::WHITE, {10, 10});
    module->displayWindow();
}