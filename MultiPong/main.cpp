#include <Windows.h>
#include <memory>

#include "PongRenderer.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT paintStruct;
	HDC hDC;

	switch(message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd,&paintStruct);
		EndPaint(hwnd,&paintStruct);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}

	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow) {
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	WNDCLASSEX wndClass = {0};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = "MultiPongClass";

	if(!RegisterClassEx(&wndClass))
		return -1;

	RECT rc = {0,0,640,480};
	AdjustWindowRect(&rc,WS_OVERLAPPEDWINDOW,FALSE);

	HWND hwnd = CreateWindowA("MultiPongClass","MultiPong",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,rc.right-rc.left,rc.bottom-rc.top,NULL,NULL,hInstance,NULL);

	if(!hwnd)
		return -1;

	ShowWindow(hwnd,cmdShow);

	//Objet à initialiser;
	PongRenderer renderer;

	//Objet Initialize
	bool result = renderer.Initialize(hInstance,hwnd);

	//Error reporting
	if(result==false)
		return -1;

	MSG msg = {0};

	//Boucle principale de l'application

	//Créer une variable globale qui décrit l'état du jeu
	//MENU + sous variable qui décrit l'écran de menu
	//JEU + sv qui donne l'état (PAUSE, IN GAME, LOADING)
	//CONNECT pour la connection réseau

	while(msg.message != WM_QUIT) {
		if(PeekMessage(&msg,0,0,0,PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			//Update
			renderer.Update(0.0f);
			//Draw
			renderer.Render();
		}
	}

	//Shutdown
	renderer.Shutdown();

	return static_cast<int>(msg.wParam);
}