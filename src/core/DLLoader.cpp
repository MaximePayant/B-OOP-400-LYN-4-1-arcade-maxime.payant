/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** DLLoader.cpp
*/

#include <dlfcn.h>
#include <exception>
#include <iostream>
#include "../../inc/DLLoader.hpp"

arc::DLLoader::DLLoader(const std::string &path) : m_library(nullptr), m_entry(nullptr)
{
    void *library = dlopen(path.c_str(), RTLD_LAZY);

    if (!library)
        throw (std::exception()); //TODO
    m_library = library;
    *(void **)(&m_entry) = dlsym(m_library, "entryPoint");
    if (!m_entry) {
        std::cerr << "Function cannot be found: " << dlerror() << std::endl;
        throw (std::exception()); //TODO
    }
}

arc::DLLoader::~DLLoader()
{
    dlclose(m_library);
}