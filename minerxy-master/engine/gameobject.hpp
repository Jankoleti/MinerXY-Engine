#pragma once


#include <vector>
#include <memory>
#include "utilities.hpp"
#include "render.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "r_texture.hpp"
#include "r_files.hpp"


struct Component;

class GameObject
{
public:	
	Transform				transform;
	template<class T>
		requires std::derived_from<T, Component>
	T* AddComponent()
	{
		auto component = std::make_unique<T>();
		T* rawPtr = component.get();
		component->parentGameObject = this;
		componentList.emplace_back(std::move(component));
		return rawPtr;
	}
	std::vector<std::unique_ptr<Component>>		componentList = {};
	static std::unique_ptr<GameObject> CreateGameObject()
	{
		std::unique_ptr<GameObject>	object = std::make_unique<GameObject>();
		return object;
	}
	
};

struct Component
{
public:
	virtual void OnUpdate() = 0;
	GameObject*				parentGameObject;
};



struct PlaneRender : Component
{
public:
	void OnUpdate() override;
	float			planeWidth = 64.0;
	float			planeHeight = 64.0;
private:
	SDL_FRect			rect;
};

struct QuadRender : Component
{
public:
	void OnUpdate() override;
	QuadRender();

	SDL_Vertex		vert[4];
	float			planeWidth = 64.0;
	float			planeHeight = 64.0;
	int				indices[6];

	void QuadColor(const Vector3& color);

};

struct RQuad : Renderable
{
public:
	RQuad(QuadRender* parent);
	void Render() override;
private:
	QuadRender* parentComponent;
};

struct BackgroundRender : Component
{
public:
	BackgroundRender();
	void OnUpdate() override;
	std::string m_texture = "terrain";
};

struct BackRender : Renderable
{
public:
	BackRender(BackgroundRender* parent);
	void Render() override;
private:
	BackgroundRender* parentComponent;
};