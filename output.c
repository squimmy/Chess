#include <stdio.h>
#include <stdlib.h>
#include "chess.h"



void DrawBoard(Dudes *Board[8][8])
{
				int x, y;
				system("clear");
				printf("  +----+----+----+----+----+----+----+----+\n");
				for (y = 7; y >= 0; y--)
				{
								char background;
								printf("%d ", y+1);
								for (x = 0; x < 8; x++)
								{
												printf("|");
												if (x%2 == y%2)
												{
																background = ' ';
												}
												else
												{
																background = '#';
												}
												printf("%c", background);
												switch ((Board[x][y])->Colour)
												{
																case white	: printf("W");
																							break;
																case black	: printf("B");
																							break;
																default			: printf("%c", background);
																							break;
												}
												switch ((Board[x][y])->Piece)
												{
																case pawn		: printf("P");
																							break;
																case rook		: printf("R");
																							break;
																case knight	: printf("N");
																							break;
																case bishop	: printf("B");
																							break;
																case king		: printf("K");
																							break;
																case queen	: printf("Q");
																							break;
																default			: printf("%c", background);
																							break;
												}

												printf("%c", background);
								}
								printf("|\n  +----+----+----+----+----+----+----+----+\n");
				}
				printf("    A    B    C    D    E    F    G    H\n\n");
}
