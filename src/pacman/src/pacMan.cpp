/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
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

PacMan::PacMan() : IGame()
{}

PacMan::~PacMan()
= default;

void PacMan::start(arc::IDisplayModule *module)
{
    module->createText("Title", "Choose your game!", 10, "rsc/verdana.ttf")->setPosition(100, 100);
}

void PacMan::update(arc::IDisplayModule *module)
{
    while (module->pollEvent())
        module->closeWindow();
    module->clearWindow();
    module->drawText("Title");
    module->displayWindow();
}