#include "MainWindow.h"
#include <iostream>
#include "unit.h"
#include "weapon.h"
#include "GraphicsView.h"


HANDLE readThread;


RECT SCREEN;


DWORD WINAPI Answers(LPVOID lp) {
	std::cout << '3';

	return 0;
}


LRESULT CALLBACK MainWindow::MainWindowProcedures(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) //Эту фигню починить добавил статик
{
	switch (msg) {
	case WM_CREATE:
		std::cout << "Created";
		//readThread = CreateThread(NULL, 0, Answers, NULL, 0, NULL);
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
		10, 640, 480, NULL, NULL, NULL, NULL);



	

	ShowWindow(hwnd, SW_SHOWNORMAL);
	GraphicsView GraphicProc(hwnd, SCREEN);


	//memDC = CreateCompatibleDC(dc); // то начем рисовать
	//memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);
	

	while (1) {


		std::cout << "1";
		
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE) > 0) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			std::cout << std::endl << &msg.wParam << std::endl;
		}

	GraphicProc.WNDraw();
	Sleep(41);


	
	}

	return 0;
}


