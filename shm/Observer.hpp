#pragma once

class Observer {
public:
    virtual void NextDay() = 0;
    virtual ~Observer();
};
