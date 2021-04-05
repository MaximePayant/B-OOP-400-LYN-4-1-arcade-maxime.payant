/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** sfmlTextFunc.cpp
*/

#include "SfmlModule.hpp"

IText *SfmlModule::createText(const std::string& name,
                              const std::string& text,
                              unsigned int size,
                              const std::string& font)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        it = m_TextMap.emplace(name, new Text(text, size, font)).first;
    return (it->second);
}

IText *SfmlModule::getText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    return (it->second);
}

void SfmlModule::deleteText(const std::string& name)
{
    auto it = m_TextMap.find(name);

    if (it == m_TextMap.end())
        throw std::runtime_error("Text not found");
    m_TextMap.erase(it);
}

void SfmlModule::drawText(const std::string& name)
{
    m_window.draw(dynamic_cast<Text*>(m_TextMap[name])->getComponent());
}