class Coordinates {
private:
    float positionX_;
    float positionY_;

public:
    Coordinates(float positionX, float positionY) {
        positionX_ = positionX;
        positionY_ = positionX;
    }
    Coordinates()
        : Coordinates(0.f, 0.f) {}

    float GetPositionX() { return positionX_; }
    float GetPositionY() { return positionY_; }

    void SetPositionX(const float& positionX) { positionX_ = positionX; }
    void SetPositionY(const float& positionY) { positionY_ = positionY; }

    friend bool operator==(Coordinates& c1, Coordinates& c2);
};

bool operator==(Coordinates& c1, Coordinates& c2) {
    return c1.GetPositionX() == c2.GetPositionX() && c1.GetPositionY() == c2.GetPositionY();
}
