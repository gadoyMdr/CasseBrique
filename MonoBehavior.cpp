#include "MonoBehavior.h"

std::list<MonoBehavior*> MonoBehavior::all = std::list<MonoBehavior*> (0);

MonoBehavior::MonoBehavior() {
	all.push_back(this);
}

MonoBehavior::~MonoBehavior() {
}

std::list<MonoBehavior*> MonoBehavior::GetAllMonobehaviors() {
	return all;
}

void MonoBehavior::Destroy() {
	all.erase(std::remove(all.begin(), all.end(), this), all.end());
	delete this;
	
}