#pragma once

#include <cstddef>

#include "command.hpp"

class Map;
class Time;

class Travel : public Command {
public:
    Travel(Map* map, Time* time);

    // Overrides from Command
    ~Travel() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
    Time* time_;
    int coordinate_x;
    int coordinate_y;

    void displayPossibleOptions();
    void displayCurrentPosition();
    void enterCoordinates();
    size_t countDaysOfTravel(size_t speed);
    void incrementDays(size_t count);
    bool isChosenIslandValid();
    void changeCurrentPositionToChosenIsland();
};
