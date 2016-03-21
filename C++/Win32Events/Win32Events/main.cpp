// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <windows.h>
#include <tchar.h>
#include <map>
#include <ctime>
using namespace std;

//�������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������"); /* ��� ������ ���� */

typedef LRESULT CALLBACK EventProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);


map<UINT, EventProc*> eventMap;

LRESULT CALLBACK OnTimer(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	RECT r;
	GetWindowRect(hWnd, &r);
	POINT t1;
	GetCursorPos(&t1);
	int width = r.right - r.left;
	int height = r.bottom - r.top;
	if (t1.x > r.left)
	{
		r.left += rand()%50;
	}
	if (t1.x < r.right)
	{
		r.left -= rand() % 50;
	}
	if (t1.y > r.top)
	{
		r.top += rand() % 50;
	}
	if (t1.y < r.bottom)
	{
		r.top -= rand() % 50;
	}
		MoveWindow(hWnd, r.left, r.top, width, height, TRUE);
	return 0;
}





LRESULT CALLBACK OnExit(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	PostQuitMessage(0);	// ������� ��������� WM_QUIT
	return 0;
}





INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;

	/* 1. ����������� ������ ����  */

	wcl.cbSize = sizeof (wcl);	// ������ ��������� WNDCLASSEX 
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// ���� ������ �������� ��������� � ������� ������ (DBLCLK)
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		// �������� ������������ �������
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���������� ���� ����� ������			
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����


	/*  2. ����������� ������ ����  */

	if (!RegisterClassEx(&wcl))
		return 0;	// ��� ��������� ����������� - �����

	/*  3. �������� ����  */

	// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,		// ����������� ����� ����
		szClassWindow,	// ��� ������ ����
		TEXT("������  Windows ����������"),	// ��������� ����
		/* ���������, �����, ����������� ������ �������, ��������� ����,
		������ ������������ � ���������� ����  */
		WS_OVERLAPPEDWINDOW,	// ����� ����
		CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// ������ ����
		CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ����
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������


	/* 4. ����������� ���� */

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);	// ����������� ����

	SetTimer(hWnd, 1, 10, NULL);


	/* 4.5 ������������ ������� */

	eventMap[WM_DESTROY] = OnExit;
	eventMap[WM_MOUSEMOVE] = OnTimer;
	
	/* 5. ������ ����� ��������� ���������  */

	// ��������� ���������� ��������� �� ������� ���������
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);	// ���������� ���������
		DispatchMessage(&Msg);	// ��������������� ���������
	}
	return Msg.wParam;
}


// ������� ��������� ���������� ������������ �������� � �������� � �������� 
// ���������� ��������� �� ������� ��������� ������� ����������	




LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	if (eventMap.find(uMessage) != eventMap.end())
		return (eventMap[uMessage])  (hWnd, uMessage, wParam, lParam);
	else 
		return DefWindowProc(hWnd, uMessage, wParam, lParam);


	/*
	switch (uMessage)
	{


	case WM_LBUTTONDOWN:
		MessageBox(
			0,
			TEXT("������ ����� ������ ����"),
			TEXT("WM_LBUTTONDOWN"),
			MB_OK | MB_ICONINFORMATION);
		break;
	case WM_LBUTTONUP:
		MessageBox(
			0,
			TEXT("�������� ����� ������ ����"),
			TEXT("WM_LBUTTONUP"),
			MB_OK | MB_ICONINFORMATION);
		break;
	case WM_RBUTTONDOWN:
		MessageBox(
			0,
			TEXT("������ ������ ������ ����"),
			TEXT("WM_RBUTTONDOWN"),
			MB_OK | MB_ICONINFORMATION);
		break;
	case WM_MOUSEMOVE:{
						  TCHAR str[50];
						  wsprintf(str, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // ������� ���������� ������� ����
						  SetWindowText(hWnd, str);	// ������ ��������� � ��������� ����
	}break;
	case WM_CHAR:{
					 TCHAR str[50];

					 wsprintf(str, TEXT("������ ������� %c"), (TCHAR)wParam);	// ASCII-��� ������� �������
					 MessageBox(0, str, TEXT("WM_CHAR"), MB_OK | MB_ICONINFORMATION);
					 break;
	}
	}
	*/

	return 0;
	
}
