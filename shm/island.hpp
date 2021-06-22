#pragma once

class Island {
    
    public:

        Island(int positionX, int positionY)
        : position_(Coordinates(positionX, positionY))
        {}

        class Coordinates {
            public:
            
            Coordinates(int& positionX, int& positionY) 
            : positionX_(positionX)
            , positionY_(positionY)
            {}

            void setPositionX(int& );
            int getPositionX() const;

            void setPositionY(int& );
            int getPositionY() const;
        
            bool operator== (const Coordinates& n_pos) const;

            private:
            int positionX_;
            int positionY_;
        };

        Coordinates getPosition() const;


    private:
        Coordinates position_;

};