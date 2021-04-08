/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Entity.cpp
*/

#include <math.h>

#include "PacMan.hpp"

Entity::Entity(float xVal, float yVal) :
    direction(None),
    wantedDirection(None),
    x(xVal),
    y(yVal)
{}

void Entity::chooseDirection(const std::array<std::string, heightMap>& map)
{
    int posX = x / 3;
    int posY = y / 3;

    if (((direction == Up || direction == Down) && fmod(y, 3) != 0)
    || ((direction == Left || direction == Right) && fmod(x, 3) != 0))
        return;
    if (wantedDirection == Up && map[posY - 1][posX] != 'X')
        direction = Up;
    else if (wantedDirection == Down && map[posY + 1][posX] != 'X')
        direction = Down;
    else if (wantedDirection == Left && map[posY][posX - 1] != 'X')
        direction = Left;
    else if (wantedDirection == Right && map[posY][posX + 1] != 'X')
        direction = Right;
}