#include "commands.hpp"

Buy::Buy(Map* map) : map_(map) {}
Sell::Sell(Map* map) : map_(map) {}
Travel::Travel(Map* map, Time* time) : map_(map), time_(time) {}
