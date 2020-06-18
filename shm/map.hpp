#pragma once

class Map {

public:

    Map();

private:

    std::vector<Island> allIslands;
    Island* currentPosition_;
};
