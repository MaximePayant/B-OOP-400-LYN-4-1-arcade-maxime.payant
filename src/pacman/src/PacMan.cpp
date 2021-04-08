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
    std::ifstream filestream("rsc/pacmanMap.txt");

    std::srand(std::time(NULL));
    ghost.color = arc::Color::RED;
    pacGumNb = 3;//181;
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
}

void PacMan::terminate(arc::IDisplayModule* module)
{
    (void)module;
}

void PacMan::playerTurn(arc::IDisplayModule *module)
{
    player.checkDirection(module);
    player.chooseDirection(m_map);
    player.makeDirection(m_map);
    player.checkAround(m_map, pacGumNb);
}

void PacMan::ghostTurn()
{
    static arc::Chrono startingChrono(arc::Chrono::Lauch);

    if (startingChrono.getElapsedTime() < waitGhostStart)
        return;
    startingChrono.stop();
    ghost.checkDirection();
    ghost.chooseDirection(m_map);
    ghost.makeDirection(m_map);
}

void PacMan::checkBoth()
{
    ghost.powerLess = (player.powerUp ? true : false);
    if (abs(player.x - ghost.x) < 1 && abs(player.y - ghost.y) < 1)
        player.powerUp ? ghost.grailled = true : player.grailled = true;
}

static void lose(arc::IDisplayModule *module)
{
    module->drawText("You Lose !", 50, arc::WHITE, {20, 60});
    module->drawText("Press P to access menu", 30, arc::WHITE, {21, 65});
    module->drawText("or press r to reload", 30, arc::WHITE, {21, 68});
}

static void win(arc::IDisplayModule *module)
{
    module->drawText("You Win !", 50, arc::WHITE, {20, 60});
    module->drawText("Press P to access menu", 30, arc::WHITE, {21, 65});
    module->drawText("or press r to reload", 30, arc::WHITE, {21, 68});
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->clearWindow();
    module->checkEvent();
    if (player.grailled)
        lose(module);
    else if (pacGumNb) {
        playerTurn(module);
        ghostTurn();
        checkBoth();
    } else
        win(module);
    drawing(module);
    module->displayWindow();
}