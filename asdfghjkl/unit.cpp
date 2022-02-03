#include "unit.h"



unit::unit(std::string name)
{
	ID = UnitCount();
	++UnitCount();

	SetParams();
	NAME = name;
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

void unit::Recalculate(bool flag)
{
	ATTACK = 10 + STR / 3 + Rhand.GETDAMAGE() + Lhand.GETDAMAGE();
	ATTACKSPEED = 5 - AGI / 2 + STR / 2;

	DEFENCE = 5 + AGI / 4 + STR / 4 + Rhand.GETDEFENCE() + Lhand.GETDEFENCE();

	if (flag)
		HEALTH = 100 + VIT / 2;
}