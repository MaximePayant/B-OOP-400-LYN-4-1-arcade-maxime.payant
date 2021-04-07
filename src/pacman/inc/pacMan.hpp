/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include <memory>
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

        void start(std::shared_ptr<arc::IDisplayModule>) override;
        void update(std::shared_ptr<arc::IDisplayModule>) override;
};

extern "C" void *entryPoint();

#endif // __PACMAN_HPP__
