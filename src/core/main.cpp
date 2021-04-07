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
#include "../../inc/Interface.hpp"

int main(int ac, char **av)
{
    arc::Interface interface;

    if (ac != 2)
        return (84);
    try {
        arc::DLManager manager(av[1]);

        interface.start(manager.getGraphicsInstance());
        manager.getGameInstance()->start(manager.getGraphicsInstance());
        while (manager.getGraphicsInstance()->isOk()) {
            if (manager.state == arc::DLManager::MENU) {
                interface.update(manager.getGraphicsInstance(), manager);
            } else if (manager.state == arc::DLManager::GAME) {
                manager.getGameInstance()->update(manager.getGraphicsInstance());
            }
            manager.updateGraphics();
            manager.updateGame();
        }
    } catch (const arc::Error &e) {
        std::cout << "Error: " << e << std::endl;
        return (84);
    }
    return (0);
}