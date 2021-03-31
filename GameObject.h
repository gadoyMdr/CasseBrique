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

	GameObject* parent;	//will be null if isnt a child
	Tag tag;
	std::string name;

	GameObject();
	GameObject(const std::string& name);
	GameObject(const std::string& name, Tag _tag);

	virtual void Update() override;

	void MakeChildOf(GameObject* go);
	void Free();

	virtual void OnMadeChildOf(GameObject* go);
	virtual void OnTriggerChildrenUpdate();

	void Destroy() override;
};

