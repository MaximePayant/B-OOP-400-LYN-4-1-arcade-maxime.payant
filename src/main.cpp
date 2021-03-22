/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include <dlfcn.h>
#include <iostream>
#include "libsfml/inc/SfmlModule.hpp"
#include "libsdl/inc/SdlModule.hpp"
#include "../inc/IDisplayModule.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    void *handle_oui = dlopen(av[1], RTLD_LAZY);
    void *(*oui_entry)();

    if (!handle_oui) {
        std::cerr << "Lib cannot be loaded: " << dlerror() << std::endl;
        return (84);
    }
    *(void **)(&oui_entry) = dlsym(handle_oui, "entryPoint");

    const char *error = dlerror();
    if (error) {
        std::cerr << "Function cannot be found: " << error << std::endl;
        return (84);
    }
    auto *test = static_cast<IDisplayModule *>(oui_entry());

    while (test->isOk());

    delete (test);
    dlclose(handle_oui);
    return (0);
}