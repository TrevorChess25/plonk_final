#pragma once
#include "entity.h"
class paddle_player :public Entity {
public:
	//prototypes for paddle funcs
	paddle_player(int player_num);
	void Update();
private:
	int player_num;
	bool p1_upKey, p1_downKey, p2_upKey, p2_downKey;
};