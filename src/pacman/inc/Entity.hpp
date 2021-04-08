/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Entity.hpp
*/

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>
#include <array>

#include "dependencies.hpp"
#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/Chrono.hpp"

class Entity
{
    public:
        enum direction_e { None = -1, Up, Down, Left, Right };
        direction_e direction;
        direction_e wantedDirection;
        float x;
        float y;

        Entity(float xVal, float yVal);
        ~Entity() = default;

        virtual void chooseDirection(const std::array<std::string, heightMap>& map);
        virtual void draw(arc::IDisplayModule *module) { (void)module; };
};

class Player :
    public Entity
{
    public:
        arc::Chrono powerUpChrono;
        bool powerUp;
        bool grailled;
        int score;

        Player();
        ~Player() = default;

        void draw(arc::IDisplayModule *module) override;
        void checkDirection(arc::IDisplayModule *module);
        void checkAround(std::array<std::string, heightMap>& map, int& pacGumNb);
        void makeDirection(const std::array<std::string, heightMap>& map);
};

class Ghost :
    public Entity
{
    public:
        arc::Chrono dirChoiceChrono;
        arc::Color color;
        bool needMoveChoice;
        bool powerLess;
        bool grailled;

        Ghost();
        ~Ghost() = default;

        void draw(arc::IDisplayModule *module) override;
        void makeDirection(const std::array<std::string, heightMap>& map);
        void checkDirection();
};

#endif // __ENTITY_H__