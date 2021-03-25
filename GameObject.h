#pragma once
#include <string>
#include "MonoBehavior.h"

enum class Tag {
	Ball,
	Rectangle,
	None
};

class GameObject : public MonoBehavior
{
	public :

		Tag tag;
		std::string name;

		GameObject();
		GameObject(const std::string& name);
		GameObject(const std::string& name, Tag _tag);

		void Update();
};

