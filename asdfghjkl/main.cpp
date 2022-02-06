#include <iostream>
#include <string>


#include "unit.h"
#include "weapon.h"
#include "MainWindow.h"

void Items(weapon* m) {
	std::cout << "Magazin" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << "Slot " << i << " - damage " << m[i].GETDAMAGE() << " defence " << m[i].GETDEFENCE()
			<< " level " << m[i].GETLEVEL() << " title " << m[i].GETNAME() << std::endl;
	}
	std::cout << "The end" << std::endl;
}

void bumaguga() {
	weapon magazin[4] = { {15, 2, 1, "Sword beauty"}, {13, 2, 1, "Sword not so beauty"},
						  {1, 11, 1, "shit very not beauty"}, {2, 10, 1, "shit super shit"} };
	unit A = unit("Vasyan");
	unit B = unit("IGOR");

	int flag = 1;

	while (flag != 0) {
		std::cin >> flag;
		if (flag == 1) {
			A.hit(B);

		}
		else if (flag == 2) {
			B.hit(A);

		}
		else if (flag == 3) {
			Items(magazin);
			int t = -1;
			bool h;
			std::cin >> t >> h;

			A.takeitem(magazin[t], h);

		}
		else if (flag == 4) {
			Items(magazin);
			int t = -1;
			bool h;
			std::cin >> t >> h;

			B.takeitem(magazin[t], h);
		}
		A.status();
		B.status();
	}
}






int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MainWindow w;
	w.StartMainWindow();
	
}


int main()
{
	MainWindow w;
	w.StartMainWindow();

}