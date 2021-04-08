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
    Entity(9 * gamingScale, 10 * gamingScale),
    needMoveChoice(false),
    powerLess(false),
    grailled(false)
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

    int random = (std::rand() % 4) - 2;

    if (random == -2 && direction != Down)
        wantedDirection = Up;
    else if (random == -1 && direction != Up)
        wantedDirection = Down;
    else if (random == 0 && direction != Right)
        wantedDirection = Left;
    else if (random == 1 && direction != Left)
        wantedDirection = Right;
    needMoveChoice = false;
}

void Ghost::draw(arc::IDisplayModule *module)
{
    if (!grailled)
        module->drawSquare(gamingScale, (powerLess ? arc::Color::CYAN : color), {x + spacingX, y + spacingY});
    module->drawSquare(1, arc::Color::WHITE, {x + spacingX, y + spacingY + 1});
    module->drawSquare(1, arc::Color::WHITE, {x + spacingX + 2, y + spacingY + 1});
}

void Ghost::makeDirection(const std::array<std::string, heightMap>& map)
{
    int posX = x / gamingScale;
    int posY = y / gamingScale;

    if (direction == Up
    && (fmod(y, gamingScale) != 0 || (map[posY - 1][posX] != 'X' && map[posY - 1][posX] != 'x')))
        y -= (powerLess ? 0.25 : 0.5);
    else if (direction == Down
    && (fmod(y, gamingScale) != 0 || (map[posY + 1][posX] != 'X' && map[posY + 1][posX] != 'x')))
        y += (powerLess ? 0.25 : 0.5);
    else if (direction == Left
    && (fmod(x, gamingScale) != 0 || (map[posY][posX - 1] != 'X' && map[posY][posX - 1] != 'x')))
        x -= (powerLess ? 0.25 : 0.5);
    else if (direction == Right
    && (fmod(x, gamingScale) != 0 || (map[posY][posX + 1] != 'X' && map[posY][posX + 1] != 'x')))
        x += (powerLess ? 0.25 : 0.5);
    else
        needMoveChoice = true;
}