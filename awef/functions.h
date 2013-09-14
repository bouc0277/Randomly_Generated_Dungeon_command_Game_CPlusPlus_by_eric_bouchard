


#define H_WALL char(186)
#define V_WALL char(205)
#define TR_CORNER char(187)
#define TL_CORNER char(201)
#define BR_CORNER char(200)
#define BL_CORNER char(188)
#define NOTIN char(0)

void GotoXY_1(int x,int y);

void CreateLevel();

void DrawLevel();

char Getgrid(short x,short y,short dir);

int randomizeFunc(int randomize);

void delThing(short x,short y);


