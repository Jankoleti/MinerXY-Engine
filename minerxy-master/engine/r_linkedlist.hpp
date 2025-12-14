#pragma once


struct RenderLayer;

struct RNode
{
	RNode* nextNode;
	RenderLayer* renderLayer;
	RNode(RenderLayer* rl = NULL) : nextNode{nullptr}, renderLayer{rl} {}
};


struct RLinkedList
{
	RNode* head;

	RLinkedList() : head {new RNode} {}
	void AddNewNodeBack(RNode* newNode)
	{
		if (!head){
			head = newNode;
			return;
		}
		RNode* currentNode = head;
		while (currentNode->nextNode != nullptr)
		{
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = newNode;
	}

	void DeleteLinkedList()
	{
		while (head != nullptr)
		{
			RNode* next = nullptr;
			next = head->nextNode;
			delete head->renderLayer;
			delete head;
			head = next;
		}
	}
};