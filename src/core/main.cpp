/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main.cpp
*/

#include <iostream>
#include "../../inc/IDisplayModule.hpp"
#include "../../inc/IGame.hpp"
#include "../../inc/DLLoader.hpp"
#include "../../inc/Chrono.hpp"

int main(int ac, char **av)
{
    arc::IDisplayModule *moduleFunc = nullptr;
    arc::IGame *gameFunc = nullptr;

    if (ac != 3)
        return (84);
    try {
        arc::DLLoader module(av[1]);
        arc::DLLoader game(av[2]);
        moduleFunc = module.getInstance<arc::IDisplayModule>();
        gameFunc = game.getInstance<arc::IGame>();

        arc::Chrono clock;

        clock.start();
        gameFunc->start(moduleFunc);
        while (moduleFunc->isOk()) {
            if (clock.getElapsedTime() < 0.03)
                continue;
            gameFunc->update(moduleFunc);
            clock.tour();
        }
        clock.stop();
        delete (moduleFunc);
        delete (gameFunc);
    } catch (const arc::Error &e) {
        std::cout << "Error: " << e << std::endl;
        delete (moduleFunc);
        delete (gameFunc);
        return (84);
    }
    return (0);
}