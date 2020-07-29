#include "Map.hpp"

#include <algorithm>
#include <cstddef>
#include <random>
#include <iostream>

Map::Map() {
    islandsLocations_.reserve(amountOfIslands);
    generateIslands(amountOfIslands);
}

void Map::generateIslands(int numOfIslandsToGenerate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);

    size_t positionX{};
    size_t positionY{};
    size_t iterations = 0;
    std::cout<<"wygenerowane wyspy\n";
    while (numOfIslandsToGenerate){
        positionX = distrib(gen);
        positionY = distrib(gen);
        if (std::none_of(islandsLocations_.begin(), islandsLocations_.end(),
                        [positionX, positionY](const auto& island) {
                            return island.getPosition() == Coordinates(positionX, positionY);
                        })) {
            addIsland({positionX, positionY});
            --numOfIslandsToGenerate;

            std::cout<<"iter:\t"<<iterations <<"\tisland {X;Y} = { "<<positionX<<" ; "<<positionY<<" }\n";
        }

        ++iterations;
    }
}

void Map::setCurrentPosition(Island* const currentPosition) {
    currentPosition_ = currentPosition;
}

void Map::addIsland(const Island& newIsland) {
    islandsLocations_.push_back(newIsland);
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto island = std::find_if(islandsLocations_.begin(), islandsLocations_.end(),
                               [&coordinate](const auto& isld) {
                                   return isld.Island::getPosition() == coordinate;
                               });

    return (island != islandsLocations_.end()) ? &(*island) : nullptr;
}

size_t Map::getDistanceToIsland(Island* destination) {
    return Coordinates::distance(currentPosition_->getPosition(), destination->getPosition());
}

//Start of helper functions for operator<<

void placeMarkersOnMapScreen(std::ostream& out, const std::vector<Island>& islandLocations, const Coordinates& cord, size_t& columnIndex, const Coordinates& currentPosition) {
    const std::string islandMarker = "O";
    const std::string currentLocationMarker = "X";
    const std::string waterMarker = " ";

    auto foundLocation = std::find_if(islandLocations.begin(), islandLocations.end(), [&cord](const auto& el) { return el.getPosition() == cord; });

    if (foundLocation != islandLocations.end()) {
        // columnIndex++;
        //out << ((foundLocation->getPosition() == currentPosition) ? currentLocationMarker : islandMarker) << "\t";
        std::cout<<"found loc {X;Y} = { "<<(*foundLocation).getPosition().getX()<<" ; "<<(*foundLocation).getPosition().getY()<<" }\n";
    }

    //out << waterMarker << '\t';
}

void populateMapScreen(std::ostream& out, const Map& map) {
    auto playerPosition = map.currentPosition_->getPosition();
    size_t cnt=0;
    std::cout<<"\n\nwyspy znalezione find_if'em\n";
    for (size_t row = minPositionXY; row <= maxPositionXY; row++) {
        //out << row << '\t';
        for (size_t column = minPositionXY; column <= maxPositionXY; column++) {
            Coordinates cord(column, row);
            placeMarkersOnMapScreen(out, map.islandsLocations_, cord, column, playerPosition);
            cnt++;
        }
        //out << "\n";
    }
    std::cout<<"cnt: "<<cnt<<"\n";
}

void fillXCoordinatesRow(std::ostream& out) {
    for (size_t i = minPositionXY; i <= maxPositionXY; i++) {
        //out << '\t' << i;
    }
    //out << '\n';
}

//End of helper functions for operator<<

std::ostream& operator<<(std::ostream& out, const Map& map) {
    fillXCoordinatesRow(out);
    populateMapScreen(out, map);

    return out;
}
