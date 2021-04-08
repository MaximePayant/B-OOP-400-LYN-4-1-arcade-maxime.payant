/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#define spacingX 60
#define spacingY 20

#include <string>
#include <array>

#include "../../../inc/IGame.hpp"
#include "Entity.hpp"

class PacMan :
    public arc::IGame
{

    private:
        Player player;
        Ghost ghost;

        std::array<std::string, 22> m_map;
        int pacGumNb;

    public:
        PacMan() = default;
        ~PacMan() = default;

        void start(arc::IDisplayModule *) override;
        void update(arc::IDisplayModule *) override;

        void drawing(arc::IDisplayModule *module);

};

extern "C" void *entryPoint();

#endif // __PACMAN_HPP__
