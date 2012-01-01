#include <Windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine,int nCmdShow)
{
	CGame* game = new CGame(hInstance);
	if(game->GameInit(hInstance) == 1)
	{
		game->GameRun();
	}
	return 0;
};