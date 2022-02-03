#pragma once


#include <iostream>
#include <string>

#include "weapon.h"

class unit {
public:
	unit(std::string name = "Unnamed");

	void SetParams(int str = 0, int agi = 0, int intelect = 0, int vit = 0);
	void ChooseParams();

	void hit(unit& target);
	void takeitem(weapon& w, bool hand = 1);

	void status();

	void death(unit* killer);

private:
	void Recalculate(bool flag = 1);

	int ID;
	int LEVEL = 1;
	int STR, AGI, INT, VIT;
	int SGr = 1; int AGr = 1; int IGr = 1; int VGr = 2;

	float EXP = 0;

	weapon Lhand, Rhand;


	int ATTACK, DEFENCE, ATTACKSPEED, HEALTH;


	bool DEAD = false;
	size_t& UnitCount() { static size_t c = 1; return c; };

	std::string NAME;
};
