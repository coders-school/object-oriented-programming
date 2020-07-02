#include "cargo.hpp"
#include <map>

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 3,
                        epic = 6,
                        legendary = 10 };
                        
    const char* enumToString (Rarity r) const {
        const std::map<Rarity,const char*> enumStrings {
            { Rarity::common, "common" },
            { Rarity::rare, "rare" },
            { Rarity::epic, "epic" },
            { Rarity::legendary, "legendary" }
        };
        auto   it  = enumStrings.find(r);
        return it == enumStrings.end() ? "Out of range" : it->second;
    }

    Item(const std::string& name, size_t amount, double basePrice);
    Item(const std::string& name, size_t amount, double basePrice, Rarity rarity);
    ~Item() override {}

    double getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    Rarity getRarity() const { return rarity_; }
    std::string getInfo() const override;

    void nextDay() override {}

    Cargo& operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& item) const override;

private:
    Rarity rarity_;
};
