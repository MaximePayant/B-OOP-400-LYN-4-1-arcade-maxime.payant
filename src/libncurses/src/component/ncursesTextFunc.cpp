/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ncursesTextFunc.cpp
*/

#include "NcursesModule.hpp"

IText *NcursesModule::createText(const std::string& name,
                              const std::string& text,
                              unsigned int size,
                              const std::string& font)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        it = m_TextMap.emplace(name, new Text(text, size, font)).first;
    return (it->second);
}

IText *NcursesModule::getText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    return (it->second);
}

void NcursesModule::deleteText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    m_TextMap.erase(it);
}

void NcursesModule::drawText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    printw(it->second->getText().c_str());
}