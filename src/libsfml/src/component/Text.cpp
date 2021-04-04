/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Text.cpp
*/

#include "../../inc/Module.hpp"

sfml::Text::Text() :
m_text()
{}

arc::IText *sfml::Module::createText(const std::string& cptName)
{
    auto it = m_textMap.find(cptName);

    if (it == m_textMap.end())
        it = m_textMap.try_emplace(cptName, std::make_unique<sfml::Text>()).first;
    return (it->second.get());
}

arc::IText *sfml::Module::getText(const std::string& cptName)
{
    auto it = m_textMap.find(cptName);

    if (it == m_textMap.end())
        throw std::exception(); // Component <cptName> not found
    return (it->second.get());
}

void sfml::Module::deleteText(const std::string& cptName)
{
    auto it = m_textMap.find(cptName);

    if (it == m_textMap.end())
        throw std::exception(); // Component <cptName> not found
    m_textMap.erase(it);
}