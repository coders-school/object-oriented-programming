#include <Ship.hpp>

Ship::Ship()
    : m_id(-1) { }

Ship::Ship (int id, const std:string & name, size_t speed, size_t maxCrew, size_t capacity)
    : m_id(id), m_name(name), m_speed(speed), m_maxCrew(maxCrew), m_capacity(capacity)
    { }

Ship::Ship(int id, size_t speed, size_t maxCcrew)
    : Ship(id, "", speed, maxCrew, 0) {}

Ship::Ship& operator+=(const size_t crew){
    // std::clamp(m_crew + crew, 0, m_maxCrew);

    if (m_crew + crew > maxCrew) {
        std::cerr << "To many papays!\n";
        return *this;
    }

    m_crew += crew;
    return *this;
}

Ship::​Ship operator-=(const size_t crew){
    if (m_crew < crew) {
        std::cerr << "Number of papays is lower then zero!\n";
        return *this;
    }

    m_crew -= crew;
    return *this;
}
