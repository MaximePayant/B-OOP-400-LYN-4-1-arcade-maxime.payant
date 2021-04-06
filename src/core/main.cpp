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
#include "../../inc/DLManager.hpp"

int main(int ac, char **av)
{
    arc::IDisplayModule *moduleFunc = nullptr;
    arc::IGame *gameFunc = nullptr;

    if (ac != 2)
        return (84);
    try {
        arc::DLManager manager(av[1]);
        moduleFunc = arc::DLManager::getGraphicsModule().getInstance<arc::IDisplayModule>();
        gameFunc = arc::DLManager::getGameModule().getInstance<arc::IGame>();

        gameFunc->start(moduleFunc);
        while (moduleFunc->isOk())
            gameFunc->update(moduleFunc);
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