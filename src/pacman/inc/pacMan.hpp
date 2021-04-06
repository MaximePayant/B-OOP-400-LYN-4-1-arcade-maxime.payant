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

class PacMan :
    public arc::IGame
{

    private:
        int x;
        int y;

    public:
        PacMan();
        ~PacMan();

        void start(arc::IDisplayModule *) override;
        void update(arc::IDisplayModule *) override;
};

extern "C" void *entryPoint();

#endif // __PACMAN_HPP__
