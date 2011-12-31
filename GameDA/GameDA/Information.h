#pragma once
#define GAME_WIDTH 800
#define GAME_HEIGHT 640
#define KEYDOWN(name,key) (name[key] & 0x80 ? 1 : 0)
#define KEYUP(name,key) (name[key] & 0x80 ? 0 : 1)
//////////////////////////////////////////////////////////////////////////
/// define states in game
enum GameState
{
	GamePlay = 0,
	GameMenu = 1,
	GameContinue = 2,
	GameExit = 3,
	MenuInGame = 4,
	GameOver = 5
};
//////////////////////////////////////////////////////////////////////////
/// define units in game, 
/// such as enemies, trees,etc
/// ie, #define UnitTree '0'
//////////////////////////////////////////////////////////////////////////