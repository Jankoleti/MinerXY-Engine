#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "r_linkedlist.hpp"


struct GameObject;
struct RenderLayer;

void InitRenderPipeline();
void RenderAll();

extern RLinkedList layerLinkedList;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern GameObject mainCamera;

const int windowWidth = 640;
const int windowHeight = 480;




struct Renderable
{
public:
	virtual void Render() = 0;
	int renderLayer = 0;
};

struct RenderLayer
{
public:
	RenderLayer(const unsigned int& renderLayerInit = 0);
	std::vector<std::unique_ptr<Renderable>> renderObjects = {};
	unsigned int renderLayerIndx;
};



template<class T>
	requires std::derived_from<T, Renderable>
void AddRenderObject(T* parentObject, const unsigned int &layer)
{
	RNode* curr = layerLinkedList.head;
	RNode* prevReal = nullptr;
	while (curr)
	{
		if (curr->renderLayer->renderLayerIndx == layer)
		{
			curr->renderLayer->renderObjects.emplace_back(std::unique_ptr<T>(parentObject));
			return;
		}
		if (curr->renderLayer)
		{
			prevReal = curr;
		}
		curr = curr->nextNode;
	}
	prevReal->renderLayer->renderObjects.emplace_back(std::unique_ptr<T>(parentObject));
}

