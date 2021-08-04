#include "ExitCommand.hpp"
#include "GeneralPrint.hpp"

void Exit::operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) {
    endGame_ = true;
}

std::string Exit::getName() const { 
    return "End game"; 
}
