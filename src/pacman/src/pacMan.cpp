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
    (void)module;
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->checkEvent();
    module->clearWindow();
    module->drawText("Title", 30, arc::BLACK);
    module->displayWindow();
}