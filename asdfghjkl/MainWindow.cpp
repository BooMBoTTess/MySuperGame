#include "MainWindow.h"
#include <iostream>
#include "unit.h"




RECT SCREEN;



LRESULT CALLBACK MainWindow::MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) //Эту фигню починить добавил статик
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_KEYDOWN:
		std::cout << wp;
		player.MoveUnit(wp);
	case WM_SIZE:
		GetClientRect(hWnd, &SCREEN);
	default:
		return DefWindowProcA(hWnd, msg, wp, lp);
	}
}

int MainWindow::StartMainWindow()
{
	LPCWSTR ClassName = L"MainWindowClass";
	LPCSTR ClassName2 = "MainWindowClass";
	WNDCLASSA wcl;
	memset(&wcl, 0, sizeof(WNDCLASSA));
	wcl.lpszClassName = ClassName2;
	wcl.lpfnWndProc = MainWindowProcedures;
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassA(&wcl);

	HWND hwnd;
	hwnd = CreateWindow(ClassName, L"OKNO OHUENNOE", WS_OVERLAPPEDWINDOW, 10, 10, 640, 480, NULL, NULL, NULL, NULL);

	
	HDC dc = GetDC(hwnd); 

	player.UnitInit(100,100,50,50);


	ShowWindow(hwnd, SW_SHOWNORMAL);
	MSG msg;
	while (1) {

		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
			
			if (msg.message == WM_QUIT) break;
		
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			
		}
		else {
			WinDraw(dc);
			Sleep(5);
		}
		
	}

	return 0;
}


void MainWindow::WinDraw(HDC dc)
{
	HDC memDC = CreateCompatibleDC(dc); // то начем рисовать
	HBITMAP memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);
	SelectObject(memDC, memBM);

	SelectObject(memDC, GetStockObject(DC_BRUSH));	
	SetDCBrushColor(memDC, RGB(255, 255, 255));
	Rectangle(memDC, 0, 0, 640, 480); //Скрин

	
	
	BitBlt(dc, 0, 0, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top, memDC, 0, 0, SRCCOPY); // То начем рисовали кидается на экран
	DeleteDC(memDC);
	DeleteObject(memBM);
}

