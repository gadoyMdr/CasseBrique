#include "Component.h"

Component::Component() : parentGO(nullptr){}

Component::~Component(){}

void Component::SetParentGO(GameObject* _parentGO) {
	parentGO = _parentGO;
}

GameObject* Component::GetAttachedGameObject() {
	return parentGO;
}
