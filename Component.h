#pragma once
#include "GameObject.h"

class Component
{
	protected :
		GameObject* parentGO;

	public :
		Component();
		virtual ~Component();

		void SetParentGO(GameObject* parentGO);
		GameObject* GetAttachedGameObject();
};

