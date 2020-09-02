#include <iostream>

using namespace std;

class Chocolate
{
public:
    Chocolate() {
    	cout << "Chocolate ctor" << endl;
    }
    ~Chocolate() {
        cout << "Chocolate dtor" << endl;
    }
};

class ChocolateCake
{
public:
    ChocolateCake() {
        cout << "ChocolateCake ctor" << endl;
    }
    ~ChocolateCake() {
        cout << "ChocolateCake dtor" << endl;
    }
private:
    Chocolate chocolate;
};

class Candles
{
public:
    Candles() {
        cout << "Candles ctor" << endl;
    }
    ~Candles() {
        cout << "Candles dtor" << endl;
    }
};

class BirthdayCake : public ChocolateCake
{
public:
    BirthdayCake() {
        cout << "BirthdayCake ctor" << endl;
    }
    ~BirthdayCake() {
        cout << "BirthdayCake dtor" << endl;
    }
private:
    Candles candles;
};

int main(int argc, char *argv[]) {
    BirthdayCake birthdayCake;
    return 0;
}
