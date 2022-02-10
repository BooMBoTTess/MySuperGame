#include "unit.h"



unit::unit(const char* name, bool pl, float xPos, float yPos, float width, float height)
{
	ID = UnitCount();
	++UnitCount();

	SetParams();
	NAME = name;
	IsPlayer = pl;

	pos = point(xPos, yPos);
	size = point(width, height);
	brush = RGB(0, 255, 0);
}

void unit::SetParams(int str, int agi, int intelect, int vit)
{
	STR = 5 + LEVEL * SGr + str;
	AGI = 5 + LEVEL * AGr + agi;
	INT = 5 + LEVEL * IGr + intelect;
	VIT = 5 + LEVEL * VGr + vit;
	
	Recalculate();
}

void unit::ChooseParams()
{
}

void unit::hit(unit& target)
{
	if (DEAD) {
		std::cout << "You are Dead " << ID;
	}
	else if (target.DEAD) {
		std::cout << "Unit - " << ID << " IS DEAD";
	}
	else {
		float damage = ATTACK - target.DEFENCE;
		target.HEALTH -= damage;
		if (target.HEALTH <= 0) {
			target.death(this);
		}
	}
}

void unit::takeitem(weapon& w, bool hand)
{
	if (w.CHECKTAKE()) {
		std::cout << w.GETNAME() << " Was taken" << std::endl;
	}
	else {
		w.take();
		if (hand) {
			Rhand.put();
			Rhand = w;
		}
		else {
			Rhand.put();
			Lhand = w;
		}
		Recalculate(0);
	}
}

void unit::status()
{
	std::cout << "ID " << ID << " Name " << NAME << " ATTACK " << ATTACK << " DEFENCE "
		<< DEFENCE << " Health " << HEALTH << " Level " << LEVEL << " EXP " << EXP;
	if (Lhand.GETLEVEL() != 0)
		std::cout << " Left Hand " << Lhand.GETNAME();
	if (Rhand.GETLEVEL() != 0)
		std::cout << " Right Hand " << Rhand.GETNAME();

	std::cout << std::endl;
}

void unit::death(unit* killer)
{
	killer->EXP += 10 * LEVEL;
	DEAD = true;
}


void unit::DrawUnit(HDC dc)
{
	// std::cout << NAME << ' ' << pos.x << ' ' << pos.y << std::endl;

	SelectObject(dc, GetStockObject(DC_PEN));
	SetDCBrushColor(dc, RGB(0, 0, 0));
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCBrushColor(dc, RGB(0, 255, 0));
	Ellipse(dc, pos.x, pos.y, pos.x + size.x, pos.y + size.y);
}

void unit::MoveUnit()
{
	
	move.x = 0;
	move.y = 0;
	
	if (GetKeyState('W') < 0) move.y = -SPD;
	if (GetKeyState('S') < 0) move.y = SPD;
	if (GetKeyState('A') < 0) move.x = -SPD;
	if (GetKeyState('D') < 0) move.x = SPD;
	if ((move.x != 0) && (move.y != 0)) {
		move.x *= 0.7;
		move.y *= 0.7;
	}
	

	pos.x += move.x;
	pos.y += move.y;
}

// ÔÓÍÊÖÈÈ ÄËß ÁÓÄÓÙÅÉ ÀÍÈÌÀÖÈÈ 
void unit::Up()
{
	pos.y -= SPD;
	size.y -= SPD;
}
void unit::Right()
{
	pos.x += SPD;
	size.x += SPD;
}
void unit::Down()
{
	pos.y += SPD;
	size.y += SPD;
}
void unit::Left()
{
	pos.x -= SPD;
	size.x -= SPD;
}

// Êîíåö ôóíêöèé äëÿ áóäóùåé àíèìàöèè

const char* unit::GetName()
{
	return NAME;
}

void unit::Recalculate(bool flag)
{
	ATTACK = 10 + STR / 3 + Rhand.GETDAMAGE() + Lhand.GETDAMAGE();
	ATTACKSPEED = 5 - AGI / 2 + STR / 2;

	DEFENCE = 5 + AGI / 4 + STR / 4 + Rhand.GETDEFENCE() + Lhand.GETDEFENCE();
	SPD = 5 + AGI / 5 + STR / 5;

	if (flag)
		HEALTH = 100 + VIT / 2;
}

TPoint point(float x, float y)
{
	TPoint tp;
	tp.x = x;
	tp.y = y;
	return tp;
}

