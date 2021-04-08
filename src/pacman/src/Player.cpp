/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Player.cpp
*/

#include <math.h>

#include "PacMan.hpp"

Player::Player() :
    Entity(11 * gamingScale, 15 * gamingScale),
    powerUpChrono(),
    powerUp(false),
    grailled(false),
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

void Player::makeDirection(const std::array<std::string, heightMap>& map)
{
    int posX = x / gamingScale;
    int posY = y / gamingScale;

    if (direction == Up
    && (fmod(y, gamingScale) != 0 || (map[posY - 1][posX] != 'X' && map[posY - 1][posX] != '-')))
        y -= 0.5;
    else if (direction == Down
    && (fmod(y, gamingScale) != 0 || (map[posY + 1][posX] != 'X' && map[posY + 1][posX] != '-')))
        y += 0.5;
    else if (direction == Left
    && (fmod(x, gamingScale) != 0 || (map[posY][posX - 1] != 'X' && map[posY][posX - 1] != '-')))
        x -= 0.5;
    else if (direction == Right
    && (fmod(x, gamingScale) != 0 || (map[posY][posX + 1] != 'X' && map[posY][posX + 1] != '-')))
        x += 0.5;
}

void Player::checkAround(std::array<std::string, heightMap>& map, int& pacGumNb)
{
    int posX = x / gamingScale;
    int posY = y / gamingScale;

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
    if (posY == 12 && posX == 23)
        x = 0 * gamingScale;
    else if (posY == 12 && posX == -1)
        x = 22 * gamingScale;
    if (powerUp && powerUpChrono.getElapsedTime() > powerUpTime) {
        powerUp = false;
        powerUpChrono.stop();
    }
}

void Player::draw(arc::IDisplayModule *module)
{
    module->drawSquare(gamingScale, arc::Color::YELLOW, {x + spacingX, y + spacingY});
}