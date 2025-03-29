#include <Windows.h>
#include <tchar.h>
#include <time.h>

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Window Programming Lab";

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC;
	srand(time(NULL));
	static TCHAR lpOut[80];
	static int x = rand() % 601;
	static int y = rand() % 401;
	static int n = rand() % 201;
	static int count = (rand() % 16) + 5;
	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;
	

	switch (iMessage) {
	case WM_CHAR:
		hDC = GetDC(hWnd);
		if (wParam == 'q') {
			PostQuitMessage(0);
			return 0;
		}
		else if (wParam == VK_RETURN) {
			x = rand() % 601;
			y = rand() % 401;
			n = rand() % 201;
			count = (rand() % 16) + 5;
			InvalidateRgn(hWnd, NULL, TRUE);
		}
		ReleaseDC(hWnd, hDC);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		
		SetTextColor(hDC, RGB(r, g, b));

		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		SetBkColor(hDC, RGB(r, g, b));
		
		wsprintf(lpOut, L"%d", n);

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (n >= 0 && n < 10) {
					TextOut(hDC, x + j * 8, y + i * 15, lpOut, lstrlen(lpOut));
				}
				else if (n >= 10 && n < 100) {
					TextOut(hDC, x + j * 15, y + i * 15, lpOut, lstrlen(lpOut));
				}
				else if (n >= 100) {
					TextOut(hDC, x + j * 24, y + i * 15, lpOut, lstrlen(lpOut));
				}
			}
		}
		
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}