typedef enum
{
	empty,
	white,
	black
}
colour;

typedef enum
{
				false,
				true
}
bool;

typedef enum 
{
	none,
	pawn,
	rook,
	knight,
	bishop,
	king,
	queen
}
piece;

typedef struct
{
	colour Colour;
	piece Piece;
}
Dudes;

typedef struct
{
	int X;
	int Y;
}
Coordinates;

typedef struct
{
	Coordinates From;
	Coordinates To;
}
Move;

typedef struct
{
	bool CastleLeft;
	bool CastleRight;
}
CastlingOK;

typedef struct
{
	CastlingOK White;
	CastlingOK Black;
	Coordinates LastMove;
	colour Turn;
}
GameData;


extern GameData Gamestate;
void DrawBoard(Dudes*[8][8]);
Move GetMove(Dudes*[8][8]);
Coordinates GetInput();
Coordinates GetToCoords(Dudes*[8][8]);
Coordinates GetFromCoords(Dudes*[8][8]);
int ConvertLetterToNumber(char);
int ValidateCoords(char, int);
void SetupBoard(Dudes*[8][8]);
void CreateBoard(Dudes*[8][8]);
void MovePiece(Move*, Dudes*[8][8]);
void TakeTurn(Dudes*[8][8]);
void NextTurn();
int KnightMove(Move*);
