/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
*/

#include <iostream>
#include "../inc/pacMan.hpp"

__attribute__((constructor))
void pacManConstructor()
{
    printf("[PacMan] Loading PacMan game...\n");
}

__attribute__((destructor))
void pacManDestructor()
{
    printf("[PacMan] PacMan game stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *game = new PacMan();

    return (game);
}

PacMan::PacMan()
{}

void PacMan::start(arc::IDisplayModule *module)
{
    (void)module;
    std::cout << "Ah" << std::endl;
    arc::IText *text = module->createText("Text");
    text->setString("Lol");
    std::cout << "Bai" << std::endl;
}

void PacMan::update(arc::IDisplayModule *module)
{
    while (module->pollEvent())
        module->closeWindow();
    module->clear();
    module->display();
}

bool PacMan::isOk(arc::IDisplayModule *module)
{
    return (module->isOk());
}

void PacMan::end(arc::IDisplayModule *module)
{
    (void)module;
    std::cout << "Cé" << std::endl;
    //module->deleteComponent<arc::AText>("Text");
    std::cout << "Des" << std::endl;
}