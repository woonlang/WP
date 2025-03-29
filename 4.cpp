//#include <Windows.h>
//#include <tchar.h>
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
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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
//	RECT rect2 = { 0,0,200,300 };
//	RECT rect3 = { 200,0,400,300 };
//	RECT rect4 = { 400,0,600,300 };
//	RECT rect5 = { 600,0,800,300 };
//	RECT rect6 = { 0,300,200,600 };
//	RECT rect7 = { 200,300,400,600 };
//	RECT rect8 = { 400,300,600,600 };
//	RECT rect9 = { 600,300,800,600 };
//	TCHAR lpOut[100];
//	int x = 2;
//	switch (iMessage) {
//	case WM_PAINT:
//		hDC = BeginPaint(hWnd, &ps); 
//		
//		for (int i = 2; i < 10; i++) {
//			for (int j = 1; j < 10; j++) {
//				if (i == 2) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect2, DT_CENTER | DT_VCENTER);
//					rect2.top += 20;
//				}
//				else if (i == 3) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect3, DT_CENTER | DT_VCENTER);
//					rect3.top += 20;
//				}
//				else if (i == 4) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect4, DT_CENTER | DT_VCENTER);
//					rect4.top += 20;
//				}
//				else if (i == 5) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect5, DT_CENTER | DT_VCENTER);
//					rect5.top += 20;
//				}
//				else if (i == 6) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect6, DT_CENTER | DT_VCENTER);
//					rect6.top += 20;
//				}
//				else if (i == 7) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect7, DT_CENTER | DT_VCENTER);
//					rect7.top += 20;
//				}
//				else if (i == 8) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect8, DT_CENTER | DT_VCENTER);
//					rect8.top += 20;
//				}
//				else if (i == 9) {
//					wsprintf(lpOut, L"%d x %d = %d", i, j, i * j);
//					DrawText(hDC, lpOut, lstrlen(lpOut), &rect9, DT_CENTER | DT_VCENTER);
//					rect9.top += 20;
//				}
//				
//			}
//		}	
//		
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_TIMER:
//		hDC = GetDC(hWnd);
//		ReleaseDC(hWnd, hDC);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
//}