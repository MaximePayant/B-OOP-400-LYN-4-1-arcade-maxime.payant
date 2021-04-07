/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main.cpp
*/

#include <dlfcn.h>
#include <iostream>
#include "IDisplayModule.hpp"
#include "IGame.hpp"
#include "Chrono.hpp"

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
    if (ac != 3)
        return (84);
    void *module = loadLibrary(av[1], RTLD_LAZY);
    void *game = loadLibrary(av[2], RTLD_LAZY);
    void *(*moduleEntry)();
    void *(*gameEntry)();

    if (!module || !game)
        return (84);

    *(void **)(&moduleEntry) = dlsym(module, "entryPoint");
    *(void **)(&gameEntry) = dlsym(game, "entryPoint");

    const char *error = dlerror();
    if (error) {
        std::cerr << "Function cannot be found: " << error << std::endl;
        return (84);
    }
    auto *moduleFunc = static_cast<arc::IDisplayModule *>(moduleEntry());
    auto *gameFunc = static_cast<arc::IGame *>(gameEntry());

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
    dlclose(module);
    return (0);
}