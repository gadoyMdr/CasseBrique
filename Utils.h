#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>

class Utils {
public :
	static sf::Vector2f Normalize(const sf::Vector2f toNormalize) {

		float fMagnitude = std::sqrt((toNormalize.x * toNormalize.x) + (toNormalize.y * toNormalize.y));

		sf::Vector2f returned = toNormalize / fMagnitude;

		return returned;
	}

	static sf::Vector2f Clamp(const sf::Vector2f toClamp, const sf::Vector2f minClampingVector, const sf::Vector2f maxClampingVector) {
		sf::Vector2f returned = toClamp;

		returned.x = Clamp(toClamp.x, minClampingVector.x, maxClampingVector.x);
		returned.y = Clamp(toClamp.y, minClampingVector.y, maxClampingVector.y);

		return returned;
	}

	static sf::Vector2f Dunno(const sf::Vector2f toChange, float theFloat) {
		sf::Vector2f d = toChange;
		return d * (float)(1.0 / fmax((double)toChange.x, (double)toChange.y));
	}

	static float Dot(const sf::Vector2f first, const sf::Vector2f second) {
		return (first.x * second.x) + (first.y * second.y);
	}

	static float Clamp(float number, float low, float high) {
		if (number > high) number = high;
		if (number < low) number = low;

		return number;
	}

	static int RandomRange(int min, int max) {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
		int i = dist6(rng) - 1;
		if (i < 0) i = 0;
		return i;
	}

	static sf::Color* LerpColor(sf::Color colorOne, sf::Color colorTwo, float value) {
		sf::Color* color = new sf::Color();
		color->r = Lerp(colorOne.r, colorTwo.r, value);
		color->g = Lerp(colorOne.g, colorTwo.g, value);
		color->b = Lerp(colorOne.b, colorTwo.b, value);
		color->a = Lerp(colorOne.a, colorTwo.a, value);
		return color;
	}

	static float Lerp(float one, float two, float value) {
		return (one + two) / 2;
	}

	static bool CheckCollision(Entity& a, Entity& b) {


		if (a.tag == GameObject::Tag::Ball && b.tag == GameObject::Tag::Ball) {
			sf::CircleShape* circleA = (sf::CircleShape*)a.GetShape();
			sf::CircleShape* circleB = (sf::CircleShape*)b.GetShape();
			sf::Vector2f posA = a.GetPosition();
			sf::Vector2f posB = b.GetPosition();
			sf::Vector2f line = posB - posA;

			sf::Vector2f crossProduct = Utils::Normalize(sf::Vector2f(line.y, -line.x));
			sf::Vector2f finall = (float)2 * (Utils::Dot(crossProduct, a.GetDirection()) * crossProduct) - a.GetDirection();

			float distance = std::sqrt((line.x * line.x) + (line.y * line.y));
			float penetrationDistance = (circleA->getRadius() + circleB->getRadius()) - distance;

			if (penetrationDistance > 0) {

				a.OnHit(b);
				b.OnHit(a);

				if (b.GetCollisionType() == CollisionType::Sticky) {
					a.MakeChildOf(&b);

					return true;
				}

				a.SetDirection(finall);
			}

			return false;
		}


		if (a.tag == GameObject::Tag::Ball && b.tag == GameObject::Tag::Rectangle) {

			sf::CircleShape* circle = (sf::CircleShape*)a.GetShape();

			sf::Vector2f distanceFromMiddles = a.GetPosition() - b.GetPosition();
			sf::Vector2f localGoExtends = sf::Vector2f(b.GetShape()->getLocalBounds().width / 2.0, b.GetShape()->getLocalBounds().height / 2.0);
			sf::Vector2f closestPointOnGO = b.GetPosition() + Utils::Clamp(distanceFromMiddles, -localGoExtends, localGoExtends);
			sf::Vector2f lineToClosestPoint = closestPointOnGO - a.GetPosition();
			float length = sqrt((lineToClosestPoint.x * lineToClosestPoint.x) + (lineToClosestPoint.y * lineToClosestPoint.y));



			float penetrationDistance = circle->getRadius() - length;
			sf::Vector2f offsetNeeded = Utils::Dunno(lineToClosestPoint, circle->getRadius()) * penetrationDistance;

			float bigger = circle->getRadius() - fmax(abs(lineToClosestPoint.x), abs(lineToClosestPoint.y));

			if (lineToClosestPoint.x < 0 || lineToClosestPoint.y < 0)
				bigger *= -1;

			if (abs(lineToClosestPoint.x) > 0) offsetNeeded = sf::Vector2f(bigger, 0);
			else offsetNeeded = sf::Vector2f(0, bigger);



			sf::Vector2f compass[] = {
			sf::Vector2f(0.0f, 1.0f),	// down
			sf::Vector2f(1.0f, 0.0f),	// right
			sf::Vector2f(0.0f, -1.0f),	// up
			sf::Vector2f(-1.0f, 0.0f)	// left
			};
			float max = 0.0f;
			int best_match = -1;


			if (length < circle->getRadius()) {

				sf::Vector2f from;

				for (int i = 0; i < 4; i++)
				{
					float dot_product = Utils::Dot(Utils::Normalize(Utils::Normalize(lineToClosestPoint)), compass[i]);
					if (dot_product > max)
					{
						max = dot_product;
						best_match = i;
						from = compass[i];
					}
				}

				a.OnHit(b);
				b.OnHit(a);

				if (b.GetCollisionType() == CollisionType::Sticky) {
					a.MakeChildOf(&b);

					return true;
				}


				a.ReactToCollision(from, offsetNeeded);

				return true;
			}
		}

		return false;
	}

	static sf::Vector2f RandomWithinCircle() {
		return sf::Vector2f(((float)rand() / (RAND_MAX)) + 1, ((float)rand() / (RAND_MAX)) + 1);
	}
};
