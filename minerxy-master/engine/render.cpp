#include "render.hpp"


RLinkedList layerLinkedList;

RenderLayer::RenderLayer(const unsigned int& renderLayerInit) :
	renderLayerIndx{ renderLayerInit }{
}

void InitRenderPipeline() 
{
	//Give head node a render layer object (index 0)
	layerLinkedList.head->renderLayer = new RenderLayer(0);

	//Create 6 additional render layers (indexes from 1 to 6)
	for (int i = 1; i <= 6; i++)
	{
		layerLinkedList.AddNewNodeBack(new RNode(new RenderLayer(i)));
	}
}

void RenderAll()
{
	RNode* curr = layerLinkedList.head;
	while (curr)
	{
		for (int i = 0; i < curr->renderLayer->renderObjects.size(); i++)
		{
			curr->renderLayer->renderObjects.at(i)->Render();
		}
		curr = curr->nextNode;
	}
}

