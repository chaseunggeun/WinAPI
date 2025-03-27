#include "Collider.h"
#include "CommonFunction.h"
void Collider::Init(GameObject* owner, int size, FPOINT pos, CollisionType type)
{
	this->owner = owner;
	this->size = size;
	this->pos = pos;
	this->type = type;
}

void Collider::Release()
{
	owner = nullptr;
}

void Collider::Update()
{

}

void Collider::Render(HDC hdc)
{
	// RenderRectAtCenter(hdc, pos.x, pos.y, size, size);
}
