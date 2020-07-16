

#include <iostream>

#include "locators.hpp"
#include "map.hpp"
#include "player.hpp"
#include "travel.hpp"

Travel::Travel(Map* map, Time* time)
    : map_(map), time_(time), coordinate_x(-1), coordinate_y(-1) {}

void Travel::execute(Player* player) {
    displayCurrentPosition();
    displayPossibleOptions();
    enterCoordinates();
    while (!isChosenIslandValid()) {
        std::cout << "Chosen island is not valid!\n";
        enterCoordinates();
    }
    auto daysOfTravel = countDaysOfTravel(player->getSpeed());
    incrementDays(daysOfTravel);
    changeCurrentPositionToChosenIsland();
    std::cout << "Time of travel: " << daysOfTravel << "\n";
}

void Travel::displayPossibleOptions() {
    for (auto elem : map_->getAllIslands()) {
        if (elem.getCoordinates() == map_->getCurrentPosition()->getCoordinates()) {
            continue;
        }
        std::cout << elem << "\n";
    }
}

void Travel::enterCoordinates() {
    std::cout << "Enter the coordinates of the chosen island: ";
    std::cin >> coordinate_x >> coordinate_y;
}

void Travel::displayCurrentPosition() {
    std::cout << "Your current position: " << map_->getCurrentPosition()->getCoordinates() << "\n";
}

void Travel::incrementDays(size_t count) {
    for (size_t i = 0; i < count; ++i) {
        TimeServiceLocator::getTime()->operator++();
    }
}

size_t Travel::countDaysOfTravel(size_t speed) {
    return map_->getDistanceToIsland(map_->getIsland(Coordinates(coordinate_x, coordinate_y))) / speed;
}

bool Travel::isChosenIslandValid() {
    if (!map_->getIsland(Coordinates(coordinate_x, coordinate_y))) {
        return false;
    }
    return true;
}

void Travel::changeCurrentPositionToChosenIsland() {
    map_->travel(map_->getIsland(Coordinates(coordinate_x, coordinate_y)));
}
