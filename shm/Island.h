#pragma once
#include "Coordinates.h"

public class Island {
public:
	Island();
	Coordinates GetPosition() const;
private:
	Coordinates position_;
};