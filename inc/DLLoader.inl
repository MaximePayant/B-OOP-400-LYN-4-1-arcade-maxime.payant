/*
** EPITECH PROJECT, 2021
** DLLoader.inl
** File description:
** DLLoader.inl
*/

#include "Error.hpp"

template <typename T>
std::shared_ptr<T> arc::DLLoader::getInstance()
{
    auto module = std::shared_ptr<T>(static_cast<void *>(m_entry()));

    if (!module)
        throw (arc::Error("Cannot create an instance of the module!", "LIB003"));
    return (module);
}