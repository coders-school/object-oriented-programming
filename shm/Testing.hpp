#include "Alcohol.hpp"
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Store.hpp"

void sampleTest1() {
    Alcohol alcohol{"bushmills", 8, 240, 68};
    Fruit fruit{"truskawka", 15, 7, 2, 5};

    const Cargo& lhs = alcohol;
    const Cargo& rhs = fruit;

    if (lhs == rhs) {
        std::cout << "the same\n";
    } else {
        std::cout << "different\n";
    }

    // const Cargo* pRHS = new Alcohol("wodka", 4, 35, 42);
    const Cargo* pRHS = new Alcohol("bushmills", 8, 240, 68);

    if (lhs == *pRHS) {
        std::cout << "the same\n";
    } else {
        std::cout << "different\n";
    }

    delete pRHS;
}

void sellBuyTest1() {
    std::cout << "\nTest Cargo:\n";
    // name amount baseprice power
    Alcohol alc1("whiskey", 10, 20, 55);
    Alcohol alc2("whiskey", 5, 20, 55);
    Alcohol alc3("kognac", 15, 40, 80);
    // name amount baseprice expirydate timetospoil
    Fruit frt1("orange", 20, 5, 7, 7);
    Fruit frt2("orange", 10, 5, 7, 7);
    Fruit frt3("apple", 50, 8, 20, 20);
    // name amount baseprice price rarity
    Item itm1("sword", 5, 80, Item::Rarity::legendary);
    Item itm2("sword", 10, 80, Item::Rarity::legendary);
    Item itm3("knife", 15, 30, Item::Rarity::common);
    std::cout << "alc1 name: " << alc1.getName() << ", amount: " << alc1.getAmount() << ", base price: " << alc1.getBasePrice() << ", price: " << alc1.getPrice() << ", power: " << alc1.getPower() << "\n";
    std::cout << "alc2 name: " << alc2.getName() << ", amount: " << alc2.getAmount() << ", base price: " << alc2.getBasePrice() << ", price: " << alc2.getPrice() << ", power: " << alc2.getPower() << "\n";
    std::cout << "alc3 name: " << alc3.getName() << ", amount: " << alc3.getAmount() << ", base price: " << alc3.getBasePrice() << ", price: " << alc3.getPrice() << ", power: " << alc3.getPower() << "\n";
    std::cout << "frt1 name: " << frt1.getName() << ", amount: " << frt1.getAmount() << ", base price: " << frt1.getBasePrice() << ", price: " << frt1.getPrice() << ", expiry date: " << frt1.getExpiryDate() << ", time to spoil: " << frt1.getTimeToSpoil() << "\n";
    std::cout << "frt2 name: " << frt2.getName() << ", amount: " << frt2.getAmount() << ", base price: " << frt2.getBasePrice() << ", price: " << frt2.getPrice() << ", expiry date: " << frt2.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "frt3 name: " << frt3.getName() << ", amount: " << frt3.getAmount() << ", base price: " << frt3.getBasePrice() << ", price: " << frt3.getPrice() << ", expiry date: " << frt3.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "itm1 name: " << itm1.getName() << ", amount: " << itm1.getAmount() << ", base price: " << itm1.getBasePrice() << ", price: " << itm1.getPrice() << ", rarity: " << itm1.getRarityStr() << "\n";
    std::cout << "itm2 name: " << itm2.getName() << ", amount: " << itm2.getAmount() << ", base price: " << itm2.getBasePrice() << ", price: " << itm2.getPrice() << ", rarity: " << itm2.getRarityStr() << "\n";
    std::cout << "itm3 name: " << itm3.getName() << ", amount: " << itm3.getAmount() << ", base price: " << itm3.getBasePrice() << ", price: " << itm3.getPrice() << ", rarity: " << itm3.getRarityStr() << "\n";

    Ship testShip(1, "TestShip", 540, 26, 1000);
    Player testPlayer(testShip, 2000);

    Store testStore;
    std::cout << "\nBefore Sell:\n\n";
    std::cout << testStore;
    std::cout << "\n";

    testStore.Sell(&alc1, 10, &testPlayer);
    testStore.Sell(&alc2, 5, &testPlayer);
    testStore.Sell(&alc3, 10, &testPlayer);
    testStore.Sell(&alc3, 10, &testPlayer);
    testStore.Sell(&frt1, 20, &testPlayer);
    testStore.Sell(&frt2, 10, &testPlayer);
    testStore.Sell(&frt3, 30, &testPlayer);
    testStore.Sell(&frt3, 30, &testPlayer);
    testStore.Sell(&itm1, 5, &testPlayer);
    testStore.Sell(&itm2, 10, &testPlayer);
    testStore.Sell(&itm3, 10, &testPlayer);

    std::cout << "\nAfter Sell:\n";
    std::cout << testStore;

    std::cout << "Test Cargo status:\n";
    std::cout << "alc1 name: " << alc1.getName() << ", amount: " << alc1.getAmount() << ", base price: " << alc1.getBasePrice() << ", price: " << alc1.getPrice() << ", power: " << alc1.getPower() << "\n";
    std::cout << "alc2 name: " << alc2.getName() << ", amount: " << alc2.getAmount() << ", base price: " << alc2.getBasePrice() << ", price: " << alc2.getPrice() << ", power: " << alc2.getPower() << "\n";
    std::cout << "alc3 name: " << alc3.getName() << ", amount: " << alc3.getAmount() << ", base price: " << alc3.getBasePrice() << ", price: " << alc3.getPrice() << ", power: " << alc3.getPower() << "\n";
    std::cout << "frt1 name: " << frt1.getName() << ", amount: " << frt1.getAmount() << ", base price: " << frt1.getBasePrice() << ", price: " << frt1.getPrice() << ", expiry date: " << frt1.getExpiryDate() << ", time to spoil: " << frt1.getTimeToSpoil() << "\n";
    std::cout << "frt2 name: " << frt2.getName() << ", amount: " << frt2.getAmount() << ", base price: " << frt2.getBasePrice() << ", price: " << frt2.getPrice() << ", expiry date: " << frt2.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "frt3 name: " << frt3.getName() << ", amount: " << frt3.getAmount() << ", base price: " << frt3.getBasePrice() << ", price: " << frt3.getPrice() << ", expiry date: " << frt3.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "itm1 name: " << itm1.getName() << ", amount: " << itm1.getAmount() << ", base price: " << itm1.getBasePrice() << ", price: " << itm1.getPrice() << ", rarity: " << itm1.getRarityStr() << "\n";
    std::cout << "itm2 name: " << itm2.getName() << ", amount: " << itm2.getAmount() << ", base price: " << itm2.getBasePrice() << ", price: " << itm2.getPrice() << ", rarity: " << itm2.getRarityStr() << "\n";
    std::cout << "itm3 name: " << itm3.getName() << ", amount: " << itm3.getAmount() << ", base price: " << itm3.getBasePrice() << ", price: " << itm3.getPrice() << ", rarity: " << itm3.getRarityStr() << "\n";

    std::cout << "\n";

    std::cout << "Before Buy:\n";
    std::cout << testStore;
    std::cout << "\n";

    testStore.Buy(&alc1, 15, &testPlayer);
    testStore.Buy(&alc2, 15, &testPlayer);
    testStore.Buy(&alc3, 5, &testPlayer);
    testStore.Buy(&frt1, 30, &testPlayer);
    testStore.Buy(&frt2, 30, &testPlayer);
    testStore.Buy(&frt3, 10, &testPlayer);
    testStore.Buy(&itm1, 15, &testPlayer);
    testStore.Buy(&itm2, 15, &testPlayer);
    testStore.Buy(&itm3, 5, &testPlayer);

    std::cout << "\nAfter Buy:\n";
    std::cout << testStore;

    std::cout << "Test Cargo status:\n";
    std::cout << "alc1 name: " << alc1.getName() << ", amount: " << alc1.getAmount() << ", base price: " << alc1.getBasePrice() << ", price: " << alc1.getPrice() << ", power: " << alc1.getPower() << "\n";
    std::cout << "alc2 name: " << alc2.getName() << ", amount: " << alc2.getAmount() << ", base price: " << alc2.getBasePrice() << ", price: " << alc2.getPrice() << ", power: " << alc2.getPower() << "\n";
    std::cout << "alc3 name: " << alc3.getName() << ", amount: " << alc3.getAmount() << ", base price: " << alc3.getBasePrice() << ", price: " << alc3.getPrice() << ", power: " << alc3.getPower() << "\n";
    std::cout << "frt1 name: " << frt1.getName() << ", amount: " << frt1.getAmount() << ", base price: " << frt1.getBasePrice() << ", price: " << frt1.getPrice() << ", expiry date: " << frt1.getExpiryDate() << ", time to spoil: " << frt1.getTimeToSpoil() << "\n";
    std::cout << "frt2 name: " << frt2.getName() << ", amount: " << frt2.getAmount() << ", base price: " << frt2.getBasePrice() << ", price: " << frt2.getPrice() << ", expiry date: " << frt2.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "frt3 name: " << frt3.getName() << ", amount: " << frt3.getAmount() << ", base price: " << frt3.getBasePrice() << ", price: " << frt3.getPrice() << ", expiry date: " << frt3.getExpiryDate() << ", time to spoil: " << frt2.getTimeToSpoil() << "\n";
    std::cout << "itm1 name: " << itm1.getName() << ", amount: " << itm1.getAmount() << ", base price: " << itm1.getBasePrice() << ", price: " << itm1.getPrice() << ", rarity: " << itm1.getRarityStr() << "\n";
    std::cout << "itm2 name: " << itm2.getName() << ", amount: " << itm2.getAmount() << ", base price: " << itm2.getBasePrice() << ", price: " << itm2.getPrice() << ", rarity: " << itm2.getRarityStr() << "\n";
    std::cout << "itm3 name: " << itm3.getName() << ", amount: " << itm3.getAmount() << ", base price: " << itm3.getBasePrice() << ", price: " << itm3.getPrice() << ", rarity: " << itm3.getRarityStr() << "\n";

    std::cout << "\n";
}

void RunSelfTests(bool cond) {
    if (cond) {
        sampleTest1();
        sellBuyTest1();
    }
}

