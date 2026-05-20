#pragma once

#include "ComponentStorageBase.h"

#include "TransformComponent.h"

class TransformComponentStorage :public ComponentStorageBase<TransformComponent>
{
public:
	TransformComponentStorage()
	{

		sparseSet.Reserve(50);
	}
};