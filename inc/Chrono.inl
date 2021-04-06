/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.inl
*/

void arc::Chrono::start()
{
    m_start = std::chrono::system_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRuning = true;
}

void arc::Chrono::stop() {
    m_end = std::chrono::system_clock::now();
    m_isRuning = false;
}

void arc::Chrono::tour() {
    m_tour = m_end;
}

double arc::Chrono::getElapsedTime()
{
    if (m_isRuning)
        m_end = std::chrono::system_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

double arc::Chrono::getTotalTime()
{
    if (m_isRuning)
        m_end = std::chrono::system_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}