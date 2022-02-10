#include "GraphicsView.h"

const int UNITS_LENGHT = 3;
unit player("Vasyan", true, 50, 50, 50, 50);
unit A("Petya", false, 100, 100, 50, 50);
unit B("kotik", false, 150, 150, 50, 50);

unit* UNITS[UNITS_LENGHT] = { &player, &A, &B };


GraphicsView::GraphicsView(HWND hwnd, RECT& SCREEN) :  SCREEN(SCREEN)
{
	dc = GetDC(hwnd);
}

void GraphicsView::ObjectsDraw()
{
	for (int i = 0; i < UNITS_LENGHT; ++i) {
		UNITS[i]->MoveUnit();
		UNITS[i]->DrawUnit(memDC);
	}
}



void GraphicsView::BGDraw()
{
	SelectObject(memDC, GetStockObject(DC_BRUSH));
	SetDCBrushColor(memDC, RGB(255, 0, 255));
	Rectangle(memDC, SCREEN.left, SCREEN.top, SCREEN.right, SCREEN.bottom);

}
void GraphicsView::WNDraw()
{

	memDC = CreateCompatibleDC(dc); // то начем рисовать
	memBM = CreateCompatibleBitmap(dc, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top);

	std::cout << "2";

	SelectObject(memDC, memBM);


	BGDraw();


	ObjectsDraw();


	BitBlt(dc, 0, 0, SCREEN.right - SCREEN.left, SCREEN.bottom - SCREEN.top, memDC, 0, 0, SRCCOPY); // То начем рисовали кидается на экран

	DeleteObject(memBM);
	DeleteDC(memDC);

}