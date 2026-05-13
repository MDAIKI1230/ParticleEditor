#pragma once

class SystemBase
{
public:
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
};