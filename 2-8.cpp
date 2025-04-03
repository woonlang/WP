#define _CRT_SECURE_NO_WARNINGS
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
	static SIZE size;
	static TCHAR str[10][31];
	static int count;
	static int y;
	static int max;

	switch (iMessage) {
	case WM_CREATE:
		CreateCaret(hWnd, NULL, 5, 15);
		y = 0;
		max = 1;
		ShowCaret(hWnd);
		count = 0;
		break;

	case WM_CHAR:
		hDC = GetDC(hWnd);
		if (wParam == VK_BACK) {
			if (count > 0) {
				count--;

				for (int i = count; i < 30; i++) {
					str[y][i] = str[y][i + 1];
				}
			}
			else if (count == 0) {
				y--;
				count = lstrlen(str[y]);
			}
		}
		else if (wParam == VK_RETURN) {
			y++;
			if (max < 10) {
				max++;
			}
			count = 0;
			if (y > 9) {
				y = 0;
			}
		}
		else if (wParam == VK_ESCAPE) {
			y = 0;
			max = 1;
			count = 0;
			for (int i = count; i < 30; i++) {
				str[y][i] = 0;
			}
		}
		else if (wParam == VK_TAB) {
			for (int i = 0; i < 5; i++) {
				str[y][count] = ' ';
				count++;
			}
		}
		

		else {
			str[y][count++] = wParam;
			if (lstrlen(str[y]) == count) {
				str[y][count] = '\0';
			}
			if (count > 29) {
				y++;
				if (max < 10) {
					max++;
				}
				count = 0;
				if (y > 9) {
					y = 0;
				}
			}
		}
		InvalidateRect(hWnd, NULL, TRUE);
		ReleaseDC(hWnd, hDC);
		break;
	case WM_KEYDOWN:
		hDC = GetDC(hWnd);
		if (wParam == VK_HOME) { //캐럿이 맨 앞으로, 이동 훔 문장 입력, 덮어쓰기 디폴트
			count = 0;
		}
		else if (wParam == VK_END) { //캐럿이 맨 뒤로, 새로운 문자 넣기 가능.
			count = lstrlen(str[y]);
		}
		else if (wParam == VK_INSERT) {
			

		}
		else if (wParam == VK_DELETE) {
				
		}
		InvalidateRect(hWnd, NULL, TRUE);
		ReleaseDC(hWnd, hDC);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		GetTextExtentPoint32(hDC, str[y], count, &size);

		for (int i = 0; i < max; i++) {
			TextOut(hDC, 0, i * 20, str[i], lstrlen(str[i]));
		}

		SetCaretPos(size.cx, y * 20);

		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		HideCaret(hWnd);
		DestroyCaret();
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}