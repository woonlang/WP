//#define _CRT_SECURE_NO_WARNINGS
//#include <Windows.h>
//#include <tchar.h>
//#include <time.h>
//
//HINSTANCE g_hInst;
//LPCTSTR lpszClass = L"Window Class Name";
//LPCTSTR lpszWindowName = L"Window Programming Lab";
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASSEX WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbSize = sizeof(WndClass);
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = (WNDPROC)WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hInstance = hInstance;
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	WndClass.lpszMenuName = NULL;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	RegisterClassEx(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	while (GetMessage(&Message, 0, 0, 0)) {
//		TranslateMessage(&Message);
//		DispatchMessage(&Message);
//	}
//	return Message.wParam;
//
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hDC;
//	HPEN hPen, oldPen;
//	HBRUSH hBrush, oldBrush;
//	static int x;
//	static int y;
//	static int type;
//	POINT point3[] = { {x - 15,y + 15},{x ,y - 15},{x + 15,y + 15} };
//	static int x1;
//	static int x2;
//	static int y1;
//	static int y2;
//
//
//	switch (iMessage) {
//	case WM_CHAR:
//		hDC = GetDC(hWnd);
//		
//		if (wParam == 'l') {
//			x = 250;
//			y = 150;
//			type = 2;
//		}
//		else if (wParam == 't') {
//			x = 265;
//			y = 150;
//			type = 3;
//		}
//		else if (wParam == 'r') {
//			type = 4;
//		}
//		else if (wParam == 'q') {
//			PostQuitMessage(0);
//			return 0;
//		}
//		InvalidateRect(hWnd, NULL, TRUE);
//		ReleaseDC(hWnd, hDC);
//		break;
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps);
//		Rectangle(hDC, 250, 150, 550, 450);
//		if (type == 2) {
//			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
//			oldPen = (HPEN)SelectObject(hDC, hPen);
//
//			for (int i = 0; i < 10; i++) {
//				MoveToEx(hDC, x, y, NULL);
//				LineTo(hDC, x + 25, y);
//				x += 30;
//			}
//			for (int i = 0; i < 10; i++) {
//				MoveToEx(hDC, x, y, NULL);
//				LineTo(hDC, x, y+25);
//				y += 30;
//			}
//			for (int i = 0; i < 10; i++) {
//				MoveToEx(hDC, x, y, NULL);
//				LineTo(hDC, x-25, y);
//				x -= 30;
//			}
//			for (int i = 0; i < 10; i++) {
//				MoveToEx(hDC, x, y, NULL);
//				LineTo(hDC, x, y-25);
//				y -= 30;
//			}
//
//			SelectObject(hDC, oldPen);
//			DeleteObject(hPen);
//		}
//
//		else if (type == 3) {
//			hBrush = CreateSolidBrush(RGB(255, 0, 0));
//			oldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//			for (int i = 0; i < 10; i++) {
//				Polygon(hDC, point3, 3);
//				point3[0].x += 30;
//				point3[1].x += 30;
//				point3[2].x += 30;
//			}
//			point3[0].x = 535;
//			point3[1].x = 550;
//			point3[2].x = 565;
//			point3[0].y = 180;
//			point3[1].y = 150;
//			point3[2].y = 180;
//			for (int i = 0; i < 10; i++) {
//				Polygon(hDC, point3, 3);
//				point3[0].y += 30;
//				point3[1].y += 30;
//				point3[2].y += 30;
//			}
//			point3[0].x = 520;
//			point3[1].x = 535;
//			point3[2].x = 550;
//			point3[0].y = 465;
//			point3[1].y = 435;
//			point3[2].y = 465;
//			for (int i = 0; i < 10; i++) {
//				Polygon(hDC, point3, 3);
//				point3[0].x -= 30;
//				point3[1].x -= 30;
//				point3[2].x -= 30;
//			}
//			point3[0].x = 235;
//			point3[1].x = 250;
//			point3[2].x = 265;
//			point3[0].y = 450;
//			point3[1].y = 420;
//			point3[2].y = 450;
//			for (int i = 0; i < 10; i++) {
//				Polygon(hDC, point3, 3);
//				point3[0].y -= 30;
//				point3[1].y -= 30;
//				point3[2].y -= 30;
//			}
//			SelectObject(hDC, oldBrush);
//			DeleteObject(hBrush);
//		}
//		else if (type == 4) {
//			hBrush = CreateSolidBrush(RGB(0, 255, 0));
//			oldBrush = (HBRUSH)SelectObject(hDC, hBrush);
//			
//			x1 = 250;
//			x2 = 275;
//			y1 = 135;
//			y2 = 160;
//			for (int i = 0; i < 10; i++) {
//				Rectangle(hDC, x1, y1, x2, y2);
//				x1 += 30;
//				x2 += 30;
//			}
//			x1 = 535;
//			x2 = 560;
//			y1 = 155;
//			y2 = 180;
//			for (int i = 0; i < 10; i++) {
//				Rectangle(hDC, x1, y1, x2, y2);
//				y1 += 30;
//				y2 += 30;
//			}
//			x1 = 525;
//			x2 = 550;
//			y1 = 435;
//			y2 = 460;
//			for (int i = 0; i < 10; i++) {
//				Rectangle(hDC, x1, y1, x2, y2);
//				x1 -= 30;
//				x2 -= 30;
//			}
//			x1 = 235;
//			x2 = 260;
//			y1 = 430;
//			y2 = 455;
//			for (int i = 0; i < 10; i++) {
//				Rectangle(hDC, x1, y1, x2, y2);
//				y1 -= 30;
//				y2 -= 30;
//			}
//			SelectObject(hDC, oldBrush);
//			DeleteObject(hBrush);
//		}
//		EndPaint(hWnd, &ps);
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}