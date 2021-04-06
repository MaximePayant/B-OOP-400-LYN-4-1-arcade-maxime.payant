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
    std::cout << "[PacMan] Loading PacMan game..." << std::endl;
}

__attribute__((destructor))
void pacManDestructor()
{
    std::cout << "[PacMan] PacMan game stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new PacMan();

    std::cout << "[PacMan] Entrypoint created." << std::endl;
    return (game);
}

PacMan::PacMan()
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
    module->drawSquare(30, arc::WHITE, {10, 10});
    module->drawText("Title", 50, arc::CYAN, {10, 10});
    module->displayWindow();
}