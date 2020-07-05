#include "island.hpp"

Island::Island(int posX, int posY, Time* gameTime) : position_(Coordinates(posX, posY)), 
                                     timeTracker_(gameTime),
                                     store_(std::make_shared<Store>(timeTracker_)) {}
