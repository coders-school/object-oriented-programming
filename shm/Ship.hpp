#pragma once

class Ship {
public:
    Ship();
    Ship(int, const std:string &, size_t, size_t, size_t);
    Ship(int, size_t, size_t);

    int getId() const { return m_id; }
    std::string getName() const { return m_name; }
    size_t getSpeed() const { return m_speed; }
    size_t getMaxCrew() const { return m_maxCrew; }
    size_t getCapacity() const { return m_capacity; }
    size_t getCrew() const { return m_crew; }

    void setName(const std::string& name) { m_name = name; }

    Ship& operator+=(const int);
    Ship& operator-=(const int);

private:
    const int m_id;
    std::string m_name;
    size_t m_speed;
    size_t m_maxCrew;
    size_t m_capacity;
    size_t m_crew;
};
