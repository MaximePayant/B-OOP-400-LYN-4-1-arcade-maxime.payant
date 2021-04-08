/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.cpp
*/

#include <iostream>
#include <fstream>

#include "PacMan.hpp"

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

void PacMan::start(arc::IDisplayModule* module)
{
    (void)module;
    std::ifstream filestream("pacmanMap.txt");

    std::srand(std::time(NULL));
    ghost.color = arc::Color::RED;
    pacGumNb = 3;//181;
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->clearWindow();
    module->checkEvent();
    if (pacGumNb == 0) {
        module->drawText("You Win !", 50, arc::WHITE, {20, 60});
        module->drawText("Press P to access menu", 30, arc::WHITE, {20, 65});
    }
    else {
        player.checkDirection(module);
        player.chooseDirection(m_map);
        player.makeDirection(m_map);
        player.checkAround(m_map, pacGumNb);
        ghost.checkDirection();
        ghost.chooseDirection(m_map);
        ghost.makeDirection(m_map);
    }
    drawing(module);
    module->displayWindow();
}