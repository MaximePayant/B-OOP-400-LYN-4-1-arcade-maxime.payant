/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include <dlfcn.h>
#include <iostream>
#include "../inc/IDisplayModule.hpp"
#include "../inc/IGame.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    void *module = dlopen(av[1], RTLD_LAZY);
    void *game = dlopen(av[2], RTLD_LAZY);
    void *(*moduleEntry)();
    void *(*gameEntry)();

    if (!module || !game) {
        std::cerr << "Lib cannot be loaded: " << dlerror() << std::endl;
        return (84);
    }
    *(void **)(&moduleEntry) = dlsym(module, "entryPoint");
    *(void **)(&gameEntry) = dlsym(game, "entryPoint");

    const char *error = dlerror();
    if (error) {
        std::cerr << "Function cannot be found: " << error << std::endl;
        return (84);
    }
    auto *moduleFunc = static_cast<IDisplayModule *>(moduleEntry());
    auto *gameFunc = static_cast<IGame *>(gameEntry());

    gameFunc->start(moduleFunc);
    while (moduleFunc->isOk()) {
        moduleFunc->clearWindow();
        gameFunc->update(moduleFunc);
        moduleFunc->draw();
    }

    delete (moduleFunc);
    dlclose(module);
    return (0);
}