#include "Alcohol.hpp"
#include <assert.h>
//#include <string_view>

size_t Alcohol::alcoholBasePriceFor96percent_ = alcoholBasePriceFor96percent;

void addAlcoholNaming(std::string& name) {
    constexpr std::string_view suffix = " (Alcohol)";
    if(name.empty()){
        name = suffix;
        return;
    }
    std::string_view sv(name);
    auto suffixPos = sv.find(suffix, sv.npos - suffix.npos);//should sheck only suffix
    if (suffixPos != sv.npos) {
        return;
    }
    name += suffix;
}

/*const std::string_view getWithoutAlcoholNaming(const std::string& name){
    constexpr std::string_view suffix = "(alcohol)";
    std::string_view sv(name);
    auto trim_pos = sv.find(suffix, sv.npos - suffix.npos);
    if (trim_pos != sv.npos) {
        sv.remove_suffix(sv.size() - trim_pos);
        return sv;
    }
    return sv;
}*/

Alcohol::Alcohol(std::string name, size_t amount, unsigned char percentage)
    : Cargo(name, amount, alcoholBasePriceFor96percent), percentage_{percentage} {
    if (percentage_ > maxPercentage) {
        percentage_ = maxPercentage;
    }
    addAlcoholNaming(name_);
}

bool Alcohol::operator==(const Cargo& other) const {
    if (auto otherAlcohol = dynamic_cast<const Alcohol*>(&other)) {
        return name_ == otherAlcohol->getName() and percentage_ == otherAlcohol->percentage_;
    }
    return false;
}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(basePrice_ * percentage_ / static_cast<double>(maxPercentage));
}

std::unique_ptr<Cargo> Alcohol::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<Alcohol>(name_, amount, percentage_);
    assert(*result == *this);
    return result;
}
