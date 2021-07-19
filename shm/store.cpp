#include "store.hpp"
#include 

std::string Store::getResponse(const Response& response) {
    switch (response) {
    case Response::done:
        return "done";
    case Response::lack_of_cargo:
        return "Lack of cargo";
    case Response::lack_of_money:
        return "Lack of money";
    case Response::lack_of_space:
        return "Lack of space";
    }
}
