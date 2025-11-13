#pragma once
#include "../Library/GameObject.h"

class Ghost : public GameObject
{
public:
	Ghost();
	Ghost(int sx, int sy);
	~Ghost();
	void Update() override;
	void Draw() override;
	bool IsHit(float tx, float ty);
private:
	int hImage;//Stone.cpp‚ÉÀ•W‚ğã‚°‚é‚½‚ß‚ÌŠÖ”
	float x, y;

};
