#include "gameobject.hpp"



void PlaneRender::OnUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	rect.w = planeWidth;
	rect.h = planeHeight;
	rect.x = parentGameObject->transform.x - mainCamera.transform.x;
	rect.y = parentGameObject->transform.y - mainCamera.transform.y;
	SDL_RenderFillRect(renderer, &rect);
}

BackgroundRender::BackgroundRender()
{
	AddRenderObject(new BackRender(this), 0);
}

void BackgroundRender::OnUpdate(){}

BackRender::BackRender(BackgroundRender* parent) : parentComponent {parent}
{
}

void BackRender::Render()
{
	if (parentComponent->m_texture == "") return;
	TEXTURES[parentComponent->m_texture]->rect.x = 0;
	TEXTURES[parentComponent->m_texture]->rect.y = 0;
	TEXTURES[parentComponent->m_texture]->rect.w = TEXTURES[parentComponent->m_texture]->textureWidth;
	TEXTURES[parentComponent->m_texture]->rect.h = TEXTURES[parentComponent->m_texture]->textureHeight;
	SDL_RenderTexture(renderer, 
		TEXTURES[parentComponent->m_texture]->sdlTexture, 
		NULL, 
		&TEXTURES[parentComponent->m_texture]->rect);
}

QuadRender::QuadRender()
{
	QuadColor(Vector3(0.0f, 0.0f, 1.0f));
	int indicesTemp[6] = {
		0, 2, 3,
		0, 1, 2
	};
	for (int i = 0; i < 6; i++){
		indices[i] = indicesTemp[i];
	}
	AddRenderObject(new RQuad(this), 1);
}

void QuadRender::OnUpdate(){}

void QuadRender::QuadColor(const Vector3& color)
{
	for (int i = 0; i < 4; i++){
		vert[i].color = { color.x, color.y, color.z, 1.0f };
	}
}

RQuad::RQuad(QuadRender* parent) : parentComponent{ parent }
{
}


void RQuad::Render()
{
	QuadRender* p = parentComponent;
	float x = p->parentGameObject->transform.x - mainCamera.transform.x;
	float y = p->parentGameObject->transform.y - mainCamera.transform.y;


	p->vert[0].position = { x,y };
	p->vert[1].position = { x + p->planeWidth ,y };
	p->vert[2].position = { x + p->planeWidth, y + p->planeHeight };
	p->vert[3].position = { x, y + p->planeHeight };

	if (!SDL_RenderGeometry(renderer, NULL, p->vert, 4, p->indices, 6))
	{
		SDL_Log("Couldnt render geometry: %s", SDL_GetError());
	}
}