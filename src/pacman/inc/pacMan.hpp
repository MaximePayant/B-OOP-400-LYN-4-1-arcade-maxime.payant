/*
** EPITECH PROJECT, 2021
** pacMan.hpp.h
** File description:
** pacMan.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_PACMAN
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_PACMAN

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"

class PacMan :
    public arc::IGame
{
    public:
        PacMan() = default;
        ~PacMan() = default;

        void start(arc::IDisplayModule *) override;
        void update(arc::IDisplayModule *) override;
};

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_PACMAN
