#include "RectangleEntity.h"

RectangleEntity::RectangleEntity(sf::Color color, sf::Vector2f size, sf::Vector2f pos) : Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(size), color, pos ){}

RectangleEntity::RectangleEntity(){}

RectangleEntity::~RectangleEntity(){}

void RectangleEntity::ReactToCollision(sf::Vector2f from, sf::Vector2f offset) {

}
