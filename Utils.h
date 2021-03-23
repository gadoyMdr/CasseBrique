#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Utils {
public :
	static sf::Vector2f Normalize(sf::Vector2f toNormalize) {

		sf::Vector2f returned = toNormalize;

		if (toNormalize.x <= 1 && toNormalize.y <= 1)
			return returned;

		float temp = (float)(1.0 / fmax((double)toNormalize.x, (double)toNormalize.y));

		if (toNormalize.x > toNormalize.y) {
			returned.x = 1;
			returned.y = toNormalize.y * temp;
		}
		else {
			returned.y = 1;
			returned.x = toNormalize.x * temp;
		}

		return returned;
	}
};
