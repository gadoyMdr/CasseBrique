#pragma once

#include <vector>
#include <list>

class MonoBehavior
{

public :
	static std::list<MonoBehavior*> all;

public :
	bool toDestroy;
	virtual void Update() = 0;

	MonoBehavior();
	~MonoBehavior();

	virtual void Destroy();

	static std::list<MonoBehavior*> GetAllMonobehaviors();
};

