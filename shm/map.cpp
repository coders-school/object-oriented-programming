#include "map.hpp"
#include "island.hpp"

Map::Map(Island* currentPosition)
    : currentPostion_(currentPosition)
    {}
void Map::initializeMap (Island& island) { //I think there might be some problems that i am using not const reference
    islands_.push_back(island);
}
Island* const Map::getPosition() {
   return currentPostion_;
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    //Ok, if i understand it correctly, std::find should work, because we have definiiton of ==. Source: https://stackoverflow.com/questions/42933943/how-to-use-lambda-for-stdfind-if
    return std::find(islands_.begin(), islands_.end(), coordinate);
    //std::find_if(islands_.begin(), islands_.end(), [&coordinate](const Island& island) {
    //    return island::Coordinates == coordinate;
    //})
}