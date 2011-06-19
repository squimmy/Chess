#include "chess.h"

KnightMove(Move *move)
{
	return ((abs(move->From.X - move->To.X) == 1) && (abs(move->From.Y - move->To.Y) == 2)) || ((abs(move->From.X - move->To.X) == 2) && (abs(move->From.Y - move->To.Y) == 1));
}
