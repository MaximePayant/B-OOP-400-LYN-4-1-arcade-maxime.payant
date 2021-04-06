/*
** EPITECH PROJECT, 2021
** DLLoader.inl
** File description:
** DLLoader.inl
*/

template <typename T>
T* arc::DLLoader::getInstance()
{
    T* module = static_cast<T *>(m_entry());

    if (!module)
        throw (std::exception()); //TODO
    return (module);
}