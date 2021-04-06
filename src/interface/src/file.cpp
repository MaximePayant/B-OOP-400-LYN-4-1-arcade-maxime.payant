/*
** EPITECH PROJECT, 2021
** file.cpp.c
** File description:
** file.cpp.c
*/

#include <filesystem>
#include <iostream>
#include "../inc/Interface.hpp"

static bool IsLibValid(const std::string &name)
{
    std::array<std::string, 13> libList = {"sfml", "sdl2", "ncurses", "ndk++", "aalib", "libcaca", "allegro5", "xlib", "gtk+", "irrlicht", "opengl", "vulkan", "qt5"};

    for (auto & it : libList)
        if (name.find("arcade_" + it + ".so") != std::string::npos)
            return (true);
    return (false);
}

static bool IsGameValid(const std::string &name)
{
    std::array<std::string, 5> gameList = {"pacman", "nibbler", "qix", "centipede", "solarfox"};

    for (auto& it : gameList)
        if (name.find("arcade_" + it + ".so") != std::string::npos)
            return (true);
    return (false);
}

static std::string FormatName(const std::string &path)
{
    auto index = path.find_last_of('_');
    auto lastIndex = path.length() - 4;
    std::string result = path.substr(index + 1, lastIndex - index);

    return (result);
}

void Interface::getList()
{
    std::string path = "./lib";

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (IsLibValid(entry.path()))
            m_lib.push_back(FormatName(entry.path()));
        if (IsGameValid(entry.path()))
            m_game.push_back(FormatName(entry.path()));
    }
}