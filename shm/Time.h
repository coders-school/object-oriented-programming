#include <vector>

#include "Observer.h";
#include "Subject.h";

class Time : public Subject {
public:
    Time() = default;
    ~Time() override;
    void subscribe(Observer* observer) override;
    void unsubscribe(Observer* observer) override;
    void notify() override;

protected:
    std::vector<Observer*> observers_;
};