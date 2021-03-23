#pragma once
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

class Component;

enum class Tag {
	Ball,
	Rectangle
};

class GameObject
{
	private : 
		sf::Shape* shape;
		sf::Vector2f direction;
		float speed;


		std::vector<Component*> components;

	public :

		Tag tag;
		std::string name;

		GameObject();
		GameObject(const std::string& name, Tag _tag, sf::Shape* _shape, sf::Color color);

		

		void AddComponent(Component* c);


		template<class T>
		T* GetComponent() {

			for (Component* c : components)
			{
				if (typeid(*c).name() == typeid(T).name())
					return dynamic_cast<T*>(c);
			}

			return nullptr;
		}


		void SetDirection(const sf::Vector2f direction);
		void SetSpeed(const float speed);
		void SetPosition(const sf::Vector2f pos);

		sf::Vector2f GetPosition();
		sf::Shape* GetShape();

		void Move();
		void CheckCollisions(GameObject* go);

		void Draw();

};

