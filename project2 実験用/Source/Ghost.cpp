#include "Ghost.h"
#include "Field.h"

Ghost::Ghost()
{
	hImage = LoadGraph("data/image/ghost.png");
	x = 200;
	y = 400;
}

Ghost::Ghost(int sx, int sy)
{
	hImage = LoadGraph("data/image/ghost.png");
	x = sx;
	y = sy;
}

Ghost::~Ghost()
{
}

void Ghost::Update()
{

}

void Ghost::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScrollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}

bool Ghost::IsHit(float tx, float ty)
{
	float dx = tx - x;
	float dy = ty - y;
	float d = sqrt(dx * dx + dy * dy);
	if (d < 30 + 5)
	{
		DestroyMe();
		return true;//“–‚½‚Á‚½¨true‚ð•Ô‚·  Stone.cpp‚Ìif•¶‚É“ü‚é
	}

	if (tx == x && ty == y)
	{
		DestroyMe();
	}
	return false;
}
