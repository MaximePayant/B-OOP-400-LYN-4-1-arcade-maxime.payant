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

void *loadLibrary(const char *filename, int mode)
{
    void *lib = dlopen(filename, mode);

    if (!lib) {
        std::cerr << "Lib " << filename << " cannot be loaded: " << dlerror() << std::endl;
        return (NULL);
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

    gameFunc->start(moduleFunc);
    while (moduleFunc->isOk())
        gameFunc->update(moduleFunc);

    delete (moduleFunc);
    delete (gameFunc);
    dlclose(module);
    return (0);
}