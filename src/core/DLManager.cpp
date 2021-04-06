/*
** EPITECH PROJECT, 2021
** DLManager.cpp.cc
** File description:
** DLManager.cpp.cc
*/

#include "../../inc/DLManager.hpp"

arc::DLLoader arc::DLManager::m_module();
arc::DLLoader arc::DLManager::m_game();

void arc::DLManager::init(const std::string& path)
{
    m_module = DLLoader(path);
    m_game = DLLoader("./lib/interface.so");
}

void arc::DLManager::ChangeGraphicModule(const std::string module)
{
    m_module = DLLoader(module);
}

void arc::DLManager::ChangeGameModule(const std::string module)
{
    m_game = DLLoader(module);
}

arc::DLLoader& arc::DLManager::getGraphicsModule()
{
    return (m_module);
}

arc::DLLoader& arc::DLManager::getGameModule()
{
    return (m_game);
}