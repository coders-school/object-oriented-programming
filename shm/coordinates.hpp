#pragma once

class Coordinates {
public:    
    Coordinates(int positionX, int positionY) 
    : positionX_(positionX)
    , positionY_(positionY)
    {}

    void setPositionX(int );
    int getPositionX() const;

    void setPositionY(int );
    int getPositionY() const;

    bool operator== (const Coordinates ) const;

private:
    int positionX_;
    int positionY_;
};

