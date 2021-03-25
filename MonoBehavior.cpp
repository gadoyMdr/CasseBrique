#include "MonoBehavior.h"

std::vector<MonoBehavior*> MonoBehavior::all = std::vector<MonoBehavior*> (0);

MonoBehavior::MonoBehavior() {
	all.push_back(this);
}

MonoBehavior::~MonoBehavior() {
}

std::vector<MonoBehavior*> MonoBehavior::GetAllMonobehaviors() {
	return all;
}