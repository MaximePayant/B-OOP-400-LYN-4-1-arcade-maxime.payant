/*
** EPITECH PROJECT, 2021
** InterfaceLoad.cpp.c
** File description:
** InterfaceLoad.cpp.c
*/

#include <iostream>
#include "../inc/Interface.hpp"

__attribute__((constructor))
void interfaceConstructor()
{
    std::cout << "[Interface] Loading Interface game..." << std::endl;
}

__attribute__((destructor))
void interfaceDestructor()
{
    std::cout << "[Interface] Interface game stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new Interface();

    std::cout << "[Interface] Entrypoint created." << std::endl;
    return (game);
}