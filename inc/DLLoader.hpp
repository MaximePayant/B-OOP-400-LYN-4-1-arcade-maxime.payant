/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** DLLoader.hpp
*/

#ifndef DLLOADER
#define DLLOADER

#include <string>
#include <memory>

namespace arc
{
    class DLLoader
    {
        void *m_library;
        void *(*m_entry)();
    public:
        explicit DLLoader(const std::string &path);
        ~DLLoader();
        template <typename T>
        std::shared_ptr<T> getInstance();
    }; // class DLLoader
} // namespace arc

#include "DLLoader.inl"

#endif //DLLOADER
