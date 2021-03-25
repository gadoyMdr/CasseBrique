#pragma once

#include <vector>

class MonoBehavior
{

private :
	static std::vector<MonoBehavior*> all;

public :
	virtual void Update() = 0;

	MonoBehavior();
	~MonoBehavior();

	static std::vector<MonoBehavior*> GetAllMonobehaviors();
};

