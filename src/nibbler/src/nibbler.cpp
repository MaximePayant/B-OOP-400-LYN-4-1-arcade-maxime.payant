/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include "../inc/nibbler.hpp"

__attribute__((constructor))
void nibblerConstructor()
{
    std::cout << "[Nibbler] Loading Nibbler game..." << std::endl;
}

__attribute__((destructor))
void nibblerDestructor()
{
    std::cout << "[Nibbler] Loading Nibbler stopped" << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new Nibbler();

    std::cout << "[Nibbler] Entrypoint created." << std::endl;
    return (game);
}

Nibbler::Nibbler() : IGame()
{}

Nibbler::~Nibbler()
= default;

void Nibbler::drawing(arc::IDisplayModule *module)
{
    int spacingX = 60;
    int spacingY = 20;

    for (std::size_t line = 0; line < m_map.size(); line += 1)
        for (std::size_t col = 0; col < m_map[line].size(); col += 1)
            switch (m_map[line][col]) {
            case 'X':
                module->drawSquare(3, arc::Color::BLUE, {col * 3 + spacingX, line * 3 + spacingY});
                break;
            case ' ':
                module->drawSquare(3, arc::Color::YELLOW, {col * 3 + spacingX, line * 3 + spacingY});
                break;
            case 'o':
                module->drawSquare(3, arc::Color::RED, {col * 3 + spacingX, line * 3 + spacingY});
            }
    for (size_t j = 0; j < snake.size(); j++)
        if (j == 0)
            module->drawSquare(3, arc::Color::MAGENTA, {snake.at(j).first * 3 + spacingX, snake.at(j).second * 3 + spacingY});
        else
            module->drawSquare(3, arc::Color::GREEN, {snake.at(j).first * 3 + spacingX, snake.at(j).second * 3 + spacingY});
    module->drawText("Score : " + std::to_string(score), 30, arc::WHITE, {20, 50});
    module->drawText("Body size : " + std::to_string(snake.size()), 30, arc::WHITE, {20, 70});
}

void Nibbler::start(arc::IDisplayModule* module)
{
    (void)module;
    std::ifstream filestream("nibblerMap.txt");
    std::pair<int, int> pos(12, 11);

    for (int i = 0; i < 4; i++) {
        snake.push_back(pos);
        pos.first--;
    }
    direction = None;
    wantedDirection = None;
    score = 0;
    over = false;
    spawned = false;
    speed_mult = 1;
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
    spawnObstacle();
}

void Nibbler::spawnObstacle()
{
    int randX;
    int randY;
    bool find;
    int amount = rand() % 6 + 1;

    for (; amount; amount--) {
        find = false;
        while (find == false) {
            find = true;
            randX = std::rand() % m_map.size();
            randY = std::rand() % m_map.at(randX).length();
            std::pair<int, int> obstacle(randX, randY);
            if (m_map[randX][randY] != ' ' && (std::find(snake.begin(), snake.end(), obstacle) == snake.end()))
                find = false;
        }
        m_map[randX][randY] = 'X';
    }
}

void Nibbler::checkDirection(arc::IDisplayModule *module)
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

void Nibbler::gameOver(arc::IDisplayModule *module)
{
    if (!over)
        over = true;
    module->checkEvent();
    module->clearWindow();
    module->drawText("GAME OVER, PRESS P TO ACCESS MENU", 30, arc::WHITE, {50, 50});
    module->displayWindow();
}

int Nibbler::hitBody(int first, int second)
{
    for (size_t j = 1; j < snake.size(); ++j) {
        if (first == snake.at(j).first && second == snake.at(j).second)
            return (1);
    }
    return (0);
}

int Nibbler::chooseDirection(arc::IDisplayModule *module)
{
    int posX = snake.at(0).first;
    int posY = snake.at(0).second;

    if ((direction == Up || direction == Down) && posY == 0)
        return (0);
    if ((direction == Left || direction == Right) && posX == 0)
        return (0);
    if (wantedDirection == Up && m_map[posY - (1)][posX] != 'X' && !hitBody(posX, posY))
        return (direction = Up);
    else if (wantedDirection == Down && m_map[posY + (1)][posX] != 'X' && !hitBody(posX, posY))
        return (direction = Down);
    else if (wantedDirection == Left && m_map[posY][posX - (1)] != 'X' && !hitBody(posX, posY))
        return (direction = Left);
    else if (wantedDirection == Right && m_map[posY][posX + (1)] != 'X' && !hitBody(posX, posY))
        return (direction = Right);
    else if (wantedDirection != None)
        gameOver(module);
    return (0);
}

void Nibbler::makeDirection()
{
    int posX = snake.at(0).first;
    int posY = snake.at(0).second;

    if (direction != None) {
        for (size_t j = snake.size() - 1; j > 0 ; j--) {
            snake.at(j).first = snake.at(j - 1).first;
            snake.at(j).second = snake.at(j - 1).second;
        }
    }
    if (direction == Up
        && (fmod(y, 3) != 0 || m_map[posY - (1)][posX] != 'X'))
        snake.at(0).second -= 1 * speed_mult;
    else if (direction == Down
             && (fmod(y, 3) != 0 || m_map[posY + (1)][posX] != 'X'))
        snake.at(0).second += 1 * speed_mult;
    else if (direction == Left
             && (fmod(x, 3) != 0 || m_map[posY][posX - (1)] != 'X'))
        snake.at(0).first -= 1 * speed_mult;
    else if (direction == Right
             && (fmod(x, 3) != 0 || m_map[posY][posX + (1)] != 'X'))
        snake.at(0).first += 1 * speed_mult;
}

void Nibbler::checkAround()
{
    int posX = snake.at(0).first;
    int posY = snake.at(0).second;

    if (m_map[posY][posX] == 'o') {
        score += 100;
        m_map[posY][posX] = ' ';
        spawned = false;
        for (int randomGrowth = rand() % 2 + 1; randomGrowth; randomGrowth--) {
            std::pair<int, int> newNode(snake.at(snake.size() - 1).first, snake.at(snake.size() - 1).second);
            snake.push_back(newNode);
        }
    }
}


void Nibbler::spawnFruit()
{
    int randX;
    int randY;
    bool find = false;

    if (!spawned) {
        while (find == false) {
            find = true;
            randX = std::rand() % m_map.size();
            randY = std::rand() % m_map.at(randX).length();
            std::pair<int, int> fruit(randX, randY);
            if (m_map[randX][randY] != ' ' && std::find(snake.begin(), snake.end(), fruit) == snake.end())
                find = false;
        }
        m_map[randX][randY] = 'o';
        spawned = true;
    }
}

void Nibbler::update(arc::IDisplayModule* module)
{
    if (!over) {
        module->clearWindow();
        module->checkEvent();
        spawnFruit();
        checkDirection(module);
        chooseDirection(module);
        makeDirection();
        checkAround();
        drawing(module);
        module->displayWindow();
    } else
        gameOver(module);
}
