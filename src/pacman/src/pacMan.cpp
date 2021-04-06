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
    x = 0;
    y = 0;
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->checkEvent();
    module->clearWindow();
    module->drawSquare(30, arc::WHITE, {x, y});
    module->drawText("Title", 50, arc::CYAN, {x, y});
    if (module->getKeyDown(arc::Keyboard::Up))
        y -= 1;
    if (module->getKeyDown(arc::Keyboard::Down))
        y += 1;
    if (module->getKeyDown(arc::Keyboard::Left))
        x -= 1;
    if (module->getKeyDown(arc::Keyboard::Right))
        x += 1;
    module->displayWindow();
}