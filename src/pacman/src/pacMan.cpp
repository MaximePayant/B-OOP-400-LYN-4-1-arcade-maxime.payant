/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.cpp
*/

#include <iostream>
#include <fstream>
#include <math.h>
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
    std::ifstream filestream("pacmanMap.txt");

    powerUp = false;
    direction = None;
    wantedDirection = None;
    x = 3;
    y = 3;
    score = 0;
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
}

void PacMan::checkDirection(arc::IDisplayModule *module)
{
    if (module->getKeyDown(arc::Keyboard::Up))
        wantedDirection = Up;
    if (module->getKeyDown(arc::Keyboard::Down))
        wantedDirection = Down;
    if (module->getKeyDown(arc::Keyboard::Left))
        wantedDirection = Left;
    if (module->getKeyDown(arc::Keyboard::Right))
        wantedDirection = Right;
}

void PacMan::chooseDirection()
{
    int posX = x / 3;
    int posY = y / 3;

    if ((direction == Up || direction == Down) && fmod(y, 3) != 0)
        return;
    if ((direction == Left || direction == Right) && fmod(x, 3) != 0)
        return;
    if (wantedDirection == Up && m_map[posY - 1][posX] != 'X')
        direction = Up;
    else if (wantedDirection == Down && m_map[posY + 1][posX] != 'X')
        direction = Down;
    else if (wantedDirection == Left && m_map[posY][posX - 1] != 'X')
        direction = Left;
    else if (wantedDirection == Right && m_map[posY][posX + 1] != 'X')
        direction = Right;
}

void PacMan::makeDirection()
{
    int posX = x / 3;
    int posY = y / 3;

    if (direction == Up
    && (fmod(y, 3) != 0 || m_map[posY - 1][posX] != 'X'))
        y -= 0.5;
    else if (direction == Down
    && (fmod(y, 3) != 0 || m_map[posY + 1][posX] != 'X'))
        y += 0.5;
    else if (direction == Left
    && (fmod(x, 3) != 0 || m_map[posY][posX - 1] != 'X'))
        x -= 0.5;
    else if (direction == Right
    && (fmod(x, 3) != 0 || m_map[posY][posX + 1] != 'X'))
        x += 0.5;
}

void PacMan::drawing(arc::IDisplayModule *module)
{
    int spacingX = 60;
    int spacingY = 20;

    for (std::size_t line = 0; line < m_map.size(); line += 1)
        for (std::size_t col = 0; col < m_map[line].size(); col += 1)
            switch (m_map[line][col]) {
                case 'X':
                    module->drawSquare(3, arc::Color::BLUE, {col * 3 + spacingX, line * 3 + spacingY});
                    break;
                case 'P':
                    module->drawSquare(2, arc::Color::MAGENTA, {col * 3 + 0.5 + spacingX, line * 3 + 0.5 + spacingY});
                    break;
                case 'o':
                    module->drawSquare(1, arc::Color::YELLOW, {col * 3 + 1 + spacingX, line * 3 + 1 + spacingY});
                    break;
            }
    module->drawSquare(3, (powerUp ? arc::Color::MAGENTA : arc::Color::YELLOW), {x + spacingX, y + spacingY});
    module->drawText("Score : " + std::to_string(score), 30, arc::WHITE, {20, 50});
}

void PacMan::checkAround()
{
    int posX = x / 3;
    int posY = y / 3;

    if (m_map[posY][posX] == 'o') {
        score += 100;
        m_map[posY][posX] = ' ';
    }
    if (m_map[posY][posX] == 'P') {
        powerUp = true;
        chrono.start();
        m_map[posY][posX] = ' ';
    }
    if (posY == 10 && posX == 24)
        x = 1 * 3;
    else if (posY == 10 && posX == 0)
        x = 23 * 3;
    if (powerUp && chrono.getElapsedTime() > 6) {
        powerUp = false;
        chrono.stop();
    }
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->checkEvent();
    module->clearWindow();
    checkDirection(module);
    chooseDirection();
    makeDirection();
    checkAround();
    drawing(module);
    module->displayWindow();
}