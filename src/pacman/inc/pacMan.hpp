/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"
#include "../../../inc/Chrono.hpp"

#include <string>
#include <array>

class PacMan :
    public arc::IGame
{

    private:
        enum direction_e { None = -1, Up, Down, Left, Right };
        direction_e direction;
        direction_e wantedDirection;

        arc::Chrono chrono;
        bool powerUp;

        int x;
        int y;
        std::array<std::string, 22> m_map;
        int score;

    public:
        PacMan();
        ~PacMan();

        void start(arc::IDisplayModule *) override;
        void update(arc::IDisplayModule *) override;

        void drawing(arc::IDisplayModule *module);
        void checkDirection(arc::IDisplayModule *module);
        void chooseDirection();
        void makeDirection();
        void checkAround();

};

extern "C" void *entryPoint();

#endif // __PACMAN_HPP__
