#pragma once


#include <iostream>
#include <string>


#include "MainWindow.h"
#include "weapon.h"


struct TPoint { int x, y; };

TPoint point(float x, float y);




class unit {
public:
	unit(const char* name = "Unnamed", bool pl = false, float xPos = -100, float yPos = -100, float width = 50, float height = 50);

	void SetParams(int str = 0, int agi = 0, int intelect = 0, int vit = 0);
	void ChooseParams();

	void hit(unit& target);
	void takeitem(weapon& w, bool hand = 1);

	void status();
	void death(unit* killer);


	void DrawUnit(HDC dc);
	void MoveUnit();

	void Up();
	void Right();
	void Down();
	void Left();

	const char* GetName();
private:
	void Recalculate(bool flag = 1);

	int ID;
	int LEVEL = 1;
	int STR, AGI, INT, VIT;
	float SPD;
	int SGr = 1; int AGr = 1; int IGr = 1; int VGr = 2;
	float EXP = 0;
	weapon Lhand, Rhand;
	int ATTACK, DEFENCE, ATTACKSPEED, HEALTH;

	TPoint pos;
	TPoint move;
	TPoint size;
	COLORREF brush;
	
	
	bool IsPlayer = true;
	bool DEAD = false;
	size_t& UnitCount() { static size_t c = 1; return c; };

	const char* NAME;
};

