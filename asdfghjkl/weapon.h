#pragma once

#include <iostream>
#include <string>

class weapon {
public:
	weapon();

	weapon(int damage, int defence, int level = 1, std::string name = "Unknown");

	void take() { TOOKED = true; }
	void put() { TOOKED = false; }

	bool CHECKTAKE();
	int GETDAMAGE();
	int GETDEFENCE();
	int GETLEVEL();
	const std::string GETNAME();

private:
	float DAMAGE, DEFENCE;
	int LEVEL, ID;
	std::string NAME;

	bool TOOKED = false;
	size_t& WeaponCount() { static size_t c = 1; return c; };
};

unit* UNITS;
