#pragma once


struct Vector2
{
	Vector2(
		const float& startX = 0.0, 
		const float& startY = 0.0)
	{
		x = startX;
		y = startY;
	}
	float x;
	float y;
};

struct Vector3
{
	Vector3(
		const float& startX = 0.0, 
		const float& startY = 0.0, 
		const float& startZ = 0.0)
	{
		x = startX;
		y = startY;
		z = startZ;
	}
	float x;
	float y;
	float z;
};


