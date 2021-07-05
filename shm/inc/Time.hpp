#include <vector>

class Subscriber;

class Time {
public:
    void addSubscriber(Subscriber* subscriber);
    void removeSubscriber(Subscriber* subscriber);
    void notifySubscribers();

private:
    std::vector<Subscriber*> subscribers_;
};
