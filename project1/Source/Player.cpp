#include "Player.h"
#include "Field.h"

Player::Player()
{
	hImage = LoadGraph("data/image/chara.png");
	x = 200;
	y = 500;
}

Player::Player(int sx, int sy)
{
	hImage = LoadGraph("data/image/chara.png");
	x = sx;
	y = sy;
}

Player::~Player()
{

}

void Player::Update()
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
	if (CheckHitKey(KEY_INPUT_W)) {
		y -= 10;
		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckDown(x + 50, y + 5);
		int push2 = field->HitCheckDown(x + 50, y + 63);
		x -= max(push1, push2);
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		y += 10;

		Field* field = FindGameObject<Field>();
		int push1 = field->HitCheckDown(x + 14, y + 5);
		int push2 = field->HitCheckDown(x + 50, y + 64);
		x += max(push1, push2);
	}

	
	//Ç±Ç±Ç…ÉXÉNÉçÅ[ÉãÇèëÇ≠
	Field* field = FindGameObject<Field>();
	int sc = field->GetScrollX();
	if (x - sc >= 600) {
		field->SetScrollX(x - 600);
	}
	if(x + sc >= 600) {
		field->SetScrollX(x - 600);
	}
	
}

void Player::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScrollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}
