#include "weapon.h"

weapon::weapon()
{
	NAME = "Без Оружия";
	DAMAGE = 0;
	DEFENCE = 0;
	LEVEL = 0;
	ID = 0;
}

weapon::weapon(int damage, int defence, int level, std::string name)
{
	ID = WeaponCount();
	++WeaponCount();


	DAMAGE = damage;
	DEFENCE = defence;
	LEVEL = level;
	NAME = name;
}

bool weapon::CHECKTAKE()
{
	return TOOKED;
}

int weapon::GETDAMAGE()
{
	return DAMAGE;
}

int weapon::GETDEFENCE()
{ return DEFENCE; }

int weapon::GETLEVEL()
{
	return LEVEL;
}

const std::string weapon::GETNAME()
{
	return NAME;
}