#include "Player.h"
#include "Field.h"

Player::Player()
{
	hImage = LoadGraph("data/image/chara.png");
}

Player::Player(int sx, int sy)
{
	hImage = LoadGraph("data/image/chara.png");
	x = sx;
	y = sy;
}

Player::~Player()
{
	if (CheckHitKey(KEY_INPUT_D)) {
		x += 10;
		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckDown(x + 50, y + 5);
		int push2 = field->HitCheckDown(x + 50, y + 63);
		x -= max(push1, push2);
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		x -= 10;

		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckDown(x + 14, y + 5);
		int push2 = field->HitCheckDown(x + 50, y + 64);
		x += max(push1, push2);
	}
}

void Player::Update()
{
}

void Player::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScrollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}
