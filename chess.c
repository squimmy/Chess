#include <stdlib.h>
#include <string.h>
#include "chess.h"

GameData Gamestate;

main()
{
	Dudes *Board[8][8];
	CreateBoard(Board);
	SetupBoard(Board);
	while (1)
	{
		TakeTurn(Board);
	}
}

void TakeTurn(Dudes *Board[8][8])
{
	GetMove(Board);
	NextTurn();
}

void NextTurn()
{

		if (Gamestate.Turn == white)
		{
			Gamestate.Turn = black;
		}
		else
		{
			Gamestate.Turn = white;
		}
}


void CreateBoard(Dudes *Board[8][8])
{
	Gamestate.White.CastleLeft	=
	Gamestate.White.CastleRight	=
	Gamestate.Black.CastleLeft	=
	Gamestate.Black.CastleRight	= false;
	Gamestate.Turn = white;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			Board[i][j] = malloc(sizeof(Dudes));
		}
	}
}


void SetupBoard(Dudes *Board[8][8])
{
	int x, y;

	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			switch (y)
			{
				case 1	: Board[x][y]->Piece = pawn;
				case 0	: Board[x][y]->Colour = white;
					  break;
				case 6	: Board[x][y]->Piece = pawn;
				case 7	: Board[x][y]->Colour = black;
					  break;
			}

			if (y == 0 || y == 7)
			{
				switch (x)
				{
					case 0	:
					case 7	: Board[x][y]->Piece = rook;
						  break;
					case 1	:
					case 6	: Board[x][y]->Piece = knight;
						  break;
					case 2	:
					case 5	: Board[x][y]->Piece = bishop;
						  break;
					case 3	: Board[x][y]->Piece = queen;
						  break;
					case 4	: Board[x][y]->Piece = king;
						  break;
				}
			}
		}
	}
}
