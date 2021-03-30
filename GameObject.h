#pragma once
#include <string>
#include "MonoBehavior.h"
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject : public MonoBehavior
{
private:

	std::vector<GameObject*> children;

public :
		
	enum class Tag {
		Ball,
		Rectangle,
		None
	};

	Tag tag;
	std::string name;

	GameObject();
	GameObject(const std::string& name);
	GameObject(const std::string& name, Tag _tag);

	void Update();

	void MoveChildren(sf::Vector2f dir);
	void MakeChildOf(GameObject* go);
	void Free(GameObject* go);

	virtual void OnTriggerChildrenUpdate();
};

