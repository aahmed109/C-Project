#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS

//final
extern int Start;
extern int sec;

//mewMenu
extern int levelflag;
void menuDraw();
void iMenuPassiveMouseMove(int mx, int my);
void iMenuMouse(int mx, int my);
void iScoreDraw();
void iScoreMouse(int mx, int my);
void iScorePassiveMouseMove(int mx, int my);
void levelSelectdraw();
void returnLevel(int level);
extern int level;
void draw_score();
void iScorePassiveMouseMove(int mx, int my);
void iScoreMouse(int mx, int my);
void iNameScreenDraw();
extern int score;
extern int buttonflag[];

//iGraphics
void iLine(double x1, double y1, double x2, double y2);
void iSetColor(double r, double g, double b);
void iPoint(double x, double y, int size);
void iFilledRectangle(double left, double bottom, double dx, double dy);
void iFilledEllipse(double x, double y, double a, double b, int slices);
void iFilledCircle(double x, double y, double r, int slices);
int iSetTimer(int msec, void(*f)(void));
void iShowBMP(int x, int y, char filename[]);
void iRectangle(double left, double bottom, double dx, double dy);
void iPassiveMouseMove(int mx, int my);
void iPauseTimer(int Index);

//levels

extern int mgrid[30][30];
extern int mineornot[30][30];
extern int buttonpressed[30][30];
extern int buttonsize;
extern int hgt;
extern int wdt;
extern int mul;
extern int mine;

//score
void show_score(int , int , int);
void text(int, int, int);
void add_to_leaderboard(char[],int score);
struct scorekeep{
	char name[50];
	int score;
};
extern struct scorekeep hscore[15];
void sort_hscore();
void save_hscore(); 
void show_leaderboard();

//save
extern int state;
void gamesave();
void gameload();


#endif
