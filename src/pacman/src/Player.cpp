/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Player.cpp
*/

#include <math.h>

#include "PacMan.hpp"

Player::Player() :
    Entity(3, 3),
    powerUpChrono(),
    powerUp(false),
    score(0)
{}

void Player::checkDirection(arc::IDisplayModule *module)
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

void Player::makeDirection(const std::array<std::string, 22>& map)
{
    int posX = x / 3;
    int posY = y / 3;

    if (direction == Up
    && (fmod(y, 3) != 0 || (map[posY - 1][posX] != 'X' && map[posY - 1][posX] != '-')))
        y -= 0.5;
    else if (direction == Down
    && (fmod(y, 3) != 0 || (map[posY + 1][posX] != 'X' && map[posY + 1][posX] != '-')))
        y += 0.5;
    else if (direction == Left
    && (fmod(x, 3) != 0 || (map[posY][posX - 1] != 'X' && map[posY][posX - 1] != '-')))
        x -= 0.5;
    else if (direction == Right
    && (fmod(x, 3) != 0 || (map[posY][posX + 1] != 'X' && map[posY][posX + 1] != '-')))
        x += 0.5;
}

void Player::checkAround(std::array<std::string, 22>& map, int& pacGumNb)
{
    int posX = x / 3;
    int posY = y / 3;

    if (map[posY][posX] == 'o') {
        score += 100;
        map[posY][posX] = ' ';
        pacGumNb -= 1;
    }
    if (map[posY][posX] == 'P') {
        powerUp = true;
        powerUpChrono.start();
        map[posY][posX] = ' ';
    }
    if (posY == 10 && posX == 23)
        x = 0 * 3;
    else if (posY == 10 && posX == -1)
        x = 22 * 3;
    if (powerUp && powerUpChrono.getElapsedTime() > 6) {
        powerUp = false;
        powerUpChrono.stop();
    }
}

void Player::draw(arc::IDisplayModule *module)
{
    module->drawSquare(3, (powerUp ? arc::Color::MAGENTA : arc::Color::YELLOW), {x + spacingX, y + spacingY});
}