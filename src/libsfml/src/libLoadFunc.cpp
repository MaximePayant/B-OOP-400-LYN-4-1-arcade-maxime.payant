/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libLoadFunc.cpp
*/

#include <iostream>

#include "SfmlModule.hpp"

__attribute__((constructor))
void libSfml_constructor()
{
    printf("[Sfml Module] Starting SFML module...\n");
}

__attribute__((destructor))
void libSfml_destructor()
{
    printf("[Sfml Module] SFML module stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *module = new SfmlModule();
    std::cout << module->getName() << ": Loaded!" << std::endl;
    return (module);
}