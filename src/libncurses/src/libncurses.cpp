/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <curses.h>
#include "../inc/NcursesModule.hpp"

__attribute__((constructor))
void libNcurses_constructor()
{
    printf("[Ncurses Module] Starting Ncurses module...\n");
}

__attribute__((destructor))
void libNcurses_destructor()
{
    printf("[Ncurses Module] Ncurses module stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *module = new NcursesModule();

    std::cout << module->getName() << " Entry point created!" << std::endl;
    return (module);
}

NcursesModule::NcursesModule() : IDisplayModule(),
m_name("Ncurses")
{
    std::cout << this->getName() << " initializing..." << std::endl;
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    curs_set(true);
}

NcursesModule::~NcursesModule()
{
    std::cout << this->getName() << " stopping...\n";
    curs_set(true);
    endwin();
    for (auto& [_, obj] : m_TextMap)
        delete (obj);
}

void NcursesModule::init()
{
    std::cout << this->getName() << " initializing..." << std::endl;
}

void NcursesModule::stop()
{
    std::cout << this->getName() << " stopping...\n";
}

std::string NcursesModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool NcursesModule::isOk()
{
    return (getch() != 'l');
}

void NcursesModule::clearWindow()
{
    clear();
}

void NcursesModule::draw()
{
    refresh();
}

IText *NcursesModule::createText(std::string name, std::string text, unsigned int size,
                                 std::string font)
{
    m_TextMap.emplace(name, new Text(text, size, font));
    return (getText(name));
}

IText *NcursesModule::getText(std::string name)
{
    auto result = m_TextMap.find(name);

    if (result != m_TextMap.end())
        return (result->second);
    throw std::runtime_error("Text not found");
}

void NcursesModule::displayText(IText *text)
{
    printw(text->getText().c_str());
}