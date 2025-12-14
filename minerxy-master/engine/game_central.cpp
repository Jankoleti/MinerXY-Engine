#include "game_central.hpp"
#include <vector>
#include "t_time.hpp"

std::vector<std::unique_ptr<GameObject>>	gameObjectList = {};
GameObject									mainCamera;






void Init()
{
	InitRenderPipeline();
	CreateTextureFromBMP("terrain", "terrain.bmp");
	mainCamera.transform.x -= windowWidth / 2;
	mainCamera.transform.y -= windowHeight / 2;

	auto background = GameObject::CreateGameObject();
	background->AddComponent<QuadRender>();
	gameObjectList.emplace_back(std::move(background));
	
}

void MainLoop()
{
	ProcessDeltaTime();
	ProcessComponents();
	RenderAll();
}




void ProcessComponents()
{
for (int x = 0; x < gameObjectList.size(); x++)
{
for (int i = 0; i < gameObjectList[x]->componentList.size(); i++)
{
gameObjectList[x]->componentList[i]->OnUpdate();
}
}
}