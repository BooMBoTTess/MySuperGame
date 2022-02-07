#include "MainWindow.h"
#include <iostream>
#include "unit.h"
#include "weapon.h"


RECT SCREEN;

HDC dc;
HDC memDC;
HBITMAP memBM;




const int UNITS_LENGHT = 3;
unit player("Vasyan", true, 50, 50, 50, 50);
unit A("Petya", false, 100, 100, 50, 50);
unit B("kotik", false, 150, 150, 50, 50);

unit* UNITS[UNITS_LENGHT] = {&player, &A, &B };




LRESULT CALLBACK MainWindow::MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) //Эту фигню починить добавил статик
{
	switch (msg) {
	case WM_CREATE:
		break;
	case WM_DESTROY:
		DeleteDC(memDC);
		DeleteObject(memBM);
		PostQuitMessage(0);
		break;
	case WM_SIZE:
	{
		GetClientRect(hWnd, &SCREEN);
		break;
		
		//HDC memDC = CreateCompatibleDC(dc); // то начем рисовать
		//HBITMAP memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);
		//SelectObject(memDC, memBM);
	}

	case WM_MOUSEMOVE:
		
		break;

	default:
		std::cout << '4';
		return DefWindowProcA(hWnd, msg, wp, lp);
	}
}

int MainWindow::StartMainWindow()
{
	
	WNDCLASSA wcl;
	memset(&wcl, 0, sizeof(WNDCLASSA));
	wcl.lpszClassName = ClassName2;
	wcl.lpfnWndProc = MainWindowProcedures;
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassA(&wcl);

	


	hwnd = CreateWindow(ClassName, L"OKNO OHUENNOE", WS_OVERLAPPEDWINDOW, 10,
		10, 640, 480, NULL, NULL, NULL, NULL);

	dc = GetDC(hwnd);



	ShowWindow(hwnd, SW_SHOWNORMAL);

	//memDC = CreateCompatibleDC(dc); // то начем рисовать
	//memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);


	MSG msg;
	while (1) {
		std::cout << "1";
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
			std::cout << '3';
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			std::cout << std::endl << &msg.wParam << std::endl;
		}
		else {

			

			
		}
	ObjectsMove();
	WNDraw(dc);
	Sleep(1);
	}

	return 0;
}


void MainWindow::ObjectsDraw(HDC dc)
{
	// Для всех объектов блаблабал сделать функцию рисования. но покачто пох
	for (int i = 0; i < UNITS_LENGHT; ++i) {
		UNITS[i]->DrawUnit(dc);

	}
}

void MainWindow::BGDraw(HDC dc)
{
	SelectObject(memDC, GetStockObject(DC_BRUSH));
	SetDCBrushColor(memDC, RGB(255, 0, 255));
	Rectangle(memDC, SCREEN.left, SCREEN.top, SCREEN.right, SCREEN.bottom);
	//Скрин. Обернуть до сюда 
}
void MainWindow::WNDraw(HDC dc)
{
	
	memDC = CreateCompatibleDC(dc); // то начем рисовать
	memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);

	std::cout << "2";
	
	SelectObject(memDC, memBM);
	
	
	BGDraw(memDC);
	
	
	ObjectsDraw(memDC);

	DrawLine(memDC, 50, 50, 100, 100);

	BitBlt(dc, 0, 0, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top, memDC, 0, 0, SRCCOPY); // То начем рисовали кидается на экран
	
	DeleteObject(memBM);
	DeleteDC(memDC);
	
}

void MainWindow::ObjectsMove()
{
	for (int i = 0; i < UNITS_LENGHT; ++i) {
		UNITS[i]->MoveUnit();

	}
	
	
}

BOOL MainWindow::DrawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2);
}

