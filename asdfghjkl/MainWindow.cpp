#include "MainWindow.h"
#include <iostream>
#include "unit.h"
#include "weapon.h"
#include "GraphicsView.h"

HWND hwnd;
MSG msg;

RECT SCREEN;


DWORD MainWindow::Graph(LPVOID lp) {
	GraphicsView GraphicProc(hwnd, SCREEN);

	std::cout << "FLOOOOOOOW";
	while (1) {
		GraphicProc.WNDraw();
		Sleep(40);
	}
	ExitThread(0);
}

LRESULT CALLBACK MainWindow::MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) //Эту фигню починить добавил статик
{
	switch (msg) {
	case WM_CREATE:
		std::cout << "Created";
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	//case WM_KEYDOWN:
	//	std::cout << '5';
	//	ObjectsMove();
	//	break;
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
	memset(&wcl, 0, sizeof(WNDCLASSA));
	wcl.lpszClassName = ClassName2;
	wcl.lpfnWndProc = MainWindowProcedures;
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassA(&wcl);
	hwnd = CreateWindow(ClassName, L"OKNO OHUENNOE", WS_OVERLAPPEDWINDOW, 10,
		10, 480, 640, NULL, NULL, NULL, NULL);
	
	
	
	GRAPHThread = CreateThread(NULL, 0, Graph, NULL, 0, NULL);

	
	ShowWindow(hwnd, SW_SHOWNORMAL);
	while (1) {
		std::cout << '1';
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
			std::cout << '3';
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			std::cout << std::endl << &msg.wParam << std::endl;

		}
		Sleep(120);
	}
	return 0;
}
	



