#pragma once


struct Vector2
{
	Vector2(
		const float& startX = 0.0, 
		const float& startY = 0.0) : x(startX), y(startY) {}
	float x;
	float y;
};

struct Vector3
{
	Vector3(
		const float& startX = 0.0, 
		const float& startY = 0.0, 
		const float& startZ = 0.0) : x(startX), y(startY), z(startZ) {}
	float x;
	float y;
	float z;
};

struct Mat2
{
	Vector2 cols[2];


	Mat2()
	{
		cols[0] = Vector2(1, 0);
		cols[1] = Vector2(0, 1);
	}

	Vector2 operator*(const Vector2& v) const
	{
		return Vector2(
			cols[0].x * v.x + cols[1].x * v.y,
			cols[0].y * v.x + cols[1].y * v.y
			);
	}
};


struct Mat3
{
	Vector3 cols[3];

	Mat3()
	{
		cols[0] = Vector3(1, 0, 0);
		cols[1] = Vector3(0, 1, 0);
		cols[2] = Vector3(0, 0, 1);
	}

	Vector3 operator*(const Vector3& v) const
	{
		return Vector3(
			cols[0].x * v.x + cols[1].x * v.y + cols[2].x * v.z,
			cols[0].y * v.x + cols[1].y * v.y + cols[2].y * v.z,
			cols[0].z * v.x + cols[1].z * v.y + cols[2].z * v.z
		);
	}
};

struct Transform
{
public:
	Vector2				position;
	Vector2				scale;
	float				rotation;

	Transform() : position{0,0}, rotation(0), scale{1,1} {}

	inline Vector2 operator+(const Vector2& other) const
	{
		Vector2 newVector(
			position.x + other.x,
			position.y + other.y);
		return newVector;
	}
	inline Vector2 operator-(const Vector2& other) const
	{
		Vector2 newVector(
			position.x - other.x,
			position.y - other.y);
		return newVector;
	}

};