/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Ghost.cpp
*/

#include <math.h>
#include <iostream>

#include "PacMan.hpp"

Ghost::Ghost() :
    Entity(9 * 3, 10 * 3),
    needMoveChoice(false),
    powerLess(false)
{
    dirChoiceChrono.start();
    direction = Right;
    wantedDirection = Up;
}

void Ghost::checkDirection()
{
    if (dirChoiceChrono.getElapsedTime() > 1) {
        needMoveChoice = true;
        dirChoiceChrono.tour();
    }
    if (!needMoveChoice)
        return;

    int random = std::rand() % 4;

    if (random == 0 && direction != Down)
        wantedDirection = Up;
    else if (random == 1 && direction != Up)
        wantedDirection = Down;
    else if (random == 2 && direction != Right)
        wantedDirection = Left;
    else if (random == 3 && direction != Left)
        wantedDirection = Right;
    needMoveChoice = false;
}

void Ghost::draw(arc::IDisplayModule *module)
{
    module->drawSquare(3, color, {x + spacingX, y + spacingY});
}

void Ghost::makeDirection(const std::array<std::string, 22>& map)
{
    int posX = x / 3;
    int posY = y / 3;

    if (direction == Up
    && (fmod(y, 3) != 0 || (map[posY - 1][posX] != 'X' && map[posY - 1][posX] != 'x')))
        y -= 0.5;
    else if (direction == Down
    && (fmod(y, 3) != 0 || (map[posY + 1][posX] != 'X' && map[posY + 1][posX] != 'x')))
        y += 0.5;
    else if (direction == Left
    && (fmod(x, 3) != 0 || (map[posY][posX - 1] != 'X' && map[posY][posX - 1] != 'x')))
        x -= 0.5;
    else if (direction == Right
    && (fmod(x, 3) != 0 || (map[posY][posX + 1] != 'X' && map[posY][posX + 1] != 'x')))
        x += 0.5;
    else
        needMoveChoice = true;
}