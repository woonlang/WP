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
//	srand(time(NULL));
//	TCHAR lpOut[100];
//	int n = (rand() % 9) + 2;
//	int m = (rand() % 9) + 2;
//	int k = (rand() % 25) + 2;
//	RECT rect;
//
//	rect.left = 0;
//	rect.top = 0;
//	rect.right = (800 / n);
//	rect.bottom = (600 / m);
//	for (int i = 0; i < k; i++) {
//		lpOut[i] = 'a' + i;
//	}
//	
//
//	switch (iMessage) {
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps);
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				int r1 = rand() % 256;
//				int g1 = rand() % 256;
//				int b1 = rand() % 256;
//				// 배경색
//				SetBkColor(hDC, RGB(r1, g1, b1));
//
//				int r2 = rand() % 256;
//				int g2 = rand() % 256;
//				int b2 = rand() % 256;
//				// 문자색
//				SetTextColor(hDC, RGB(r2, g2, b2));
//
//				DrawText(hDC, lpOut, k, &rect, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
//				rect.left += (800 / n);
//				rect.right += (800 / n);
//			}
//			rect.top += (600 / m);
//			rect.bottom += (600 / m);
//			rect.left -= (800 / n)*m;
//			rect.right -= (800 / n)*m;
//		}
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}