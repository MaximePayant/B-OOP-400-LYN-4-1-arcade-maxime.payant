/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main.cpp
*/

#include <dlfcn.h>
#include <iostream>
#include "../../inc/IDisplayModule.hpp"
#include "../../inc/IGame.hpp"
#include "../../inc/DLLoader.hpp"

void *loadLibrary(const char *filename, int mode)
{
    void *lib = dlopen(filename, mode);

    if (!lib) {
        std::cerr << "Lib " << filename << " cannot be loaded: " << dlerror() << std::endl;
        return (nullptr);
    }
    return (lib);
}

int main(int ac, char **av)
{
    arc::DLLoader module(av[1]);
    arc::DLLoader game(av[2]);
    auto *moduleFunc = module.getInstance<arc::IDisplayModule>();
    auto *gameFunc = game.getInstance<arc::IGame>();

    if (ac != 3) {
        delete (moduleFunc);
        delete (gameFunc);
        return (84);
    }
    gameFunc->start(moduleFunc);
    while (moduleFunc->isOk())
        gameFunc->update(moduleFunc);

    delete (moduleFunc);
    delete (gameFunc);
    return (0);
}