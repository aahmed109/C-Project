#include "Header.h"
#include "glut.h"
#include <stdio.h>
void iText(GLdouble x, GLdouble y, char *str, void* font);
int score;
int buttonflag[8], lev_sel[3];

void menuDraw()
{
	iShowBMP(40,535,"title.bmp");
	iShowBMP(40,350,"minesweep1.bmp");
	iSetColor(0, 100, 200);
	iFilledRectangle(290, 280, 300, 50);
	iFilledRectangle(290, 210, 300, 50);
	iFilledRectangle(290, 140, 300, 50);
	iFilledRectangle(290, 70, 300, 50);
	

	if (buttonflag[0] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(291, 281, 298, 48);
	}
	else if (buttonflag[1] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(291, 211, 298, 48);
	}
	else if (buttonflag[2] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(291, 141, 298, 48);
	}
	else if (buttonflag[3] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(291, 71, 298, 48);
	}
	iSetColor(0, 0, 0);
	iText(385, 295, "New Game", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(380, 225, "Load Game", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(378, 160, "High Scores", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(410, 90, "Quit", GLUT_BITMAP_TIMES_ROMAN_24);

}
void levelSelectdraw()
{
	iShowBMP(40, 507, "difficulty.bmp");
	iShowBMP(420,110,"minesweep2.bmp");
	iSetColor(0, 0, 255);
	iFilledRectangle(90, 340, 300, 80);
	iFilledRectangle(90, 240, 300, 80);
	iFilledRectangle(90, 140, 300, 80);
	iFilledRectangle(45, 5, 70, 30);

	if (lev_sel[0] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(91, 341, 298, 78);
	}
	else if (lev_sel[1] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(91, 241, 298, 78);
	}
	else if (lev_sel[2] == 1)
	{
		iSetColor(0, 200, 80);
		iFilledRectangle(91, 141, 298, 78);
	}
	else if (buttonflag[5] == 1){
		iSetColor(0, 200, 80);
		iFilledRectangle(46, 6, 68, 28);
	}

	iSetColor(0, 0, 0);
	iText(195, 375, "Beginner", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(180, 275, "Intermediate", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(205, 175, "Expert", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(50, 10, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
}

void iMenuPassiveMouseMove(int mx, int my){
	
	if (Start == 2){
		if (mx > 290 && mx < 590 && my > 280 && my < 330) buttonflag[0] = 1;
		else if (mx > 290 && mx < 590 && my < 260 && my> 210) buttonflag[1] = 1;
		else if (mx > 290 && mx < 590 && my < 190 && my> 140) buttonflag[2] = 1;
		else if (mx > 290 && mx < 590 && my < 120 && my> 70) buttonflag[3] = 1;
		else
		{
			buttonflag[0] = 0;
			buttonflag[1] = 0;
			buttonflag[2] = 0;
			buttonflag[3] = 0;
		}
	}
	if (Start == 0){
		if (mx>90 && mx<390 && my<420 && my>340) lev_sel[0] = 1;
		else if (mx>90 && mx<390 && my<320 && my>240) lev_sel[1] = 1;
		else if (mx>90 && mx<390 && my<220 && my>140) lev_sel[2] = 1;
		else if (mx>45 && mx < 115 && my > 5 && my < 35)	buttonflag[5] = 1;
		else
		{
			lev_sel[0] = 0;
			lev_sel[1] = 0;
			lev_sel[2] = 0;
			buttonflag[5] = 0;
		}
	}
}

void iScorePassiveMouseMove(int mx, int my){
	if (mx > 720 && mx < 770 && my >10 && my < 40)	buttonflag[4] = 1;
}

void iMenuMouse(int mx, int my)
{
	if (Start == 2){
		if (buttonflag[0] == 1)
		{
			Start = 0;
			buttonflag[0] = 0;
			buttonflag[1] = 0;
			buttonflag[2] = 0;
			buttonflag[3] = 0;
		}
		else if (buttonflag[1] == 1)
		{
			Start = 1;
			gameload();
			buttonflag[0] = 0;
			buttonflag[1] = 0;
			buttonflag[2] = 0;
			buttonflag[3] = 0;
		}
		else if (buttonflag[2] == 1)
		{
			Start = 3;
			buttonflag[0] = 0;
			buttonflag[1] = 0;
			buttonflag[2] = 0;
			buttonflag[3] = 0;
		}
		else if (buttonflag[3] == 1)
		{
			exit(0);
		}
	}
	else if (Start == 0){
		if (lev_sel[0] == 1){
			level = 1;
			lev_sel[0] = 0;
			lev_sel[1] = 0;
			lev_sel[2] = 0;
			buttonflag[5] = 0;
			returnLevel(1);
		}
		else if (lev_sel[1] == 1){
			level = 2;
			lev_sel[0] = 0;
			lev_sel[1] = 0;
			lev_sel[2] = 0;
			buttonflag[5] = 0;
			returnLevel(2);
		}
		else if (lev_sel[2] == 1){
			level = 3;
			lev_sel[0] = 0;
			lev_sel[1] = 0;
			lev_sel[2] = 0;
			buttonflag[5] = 0;
			returnLevel(3);
		}
		else if (buttonflag[5] == 1){
			Start = 2;
			lev_sel[0] = 0;
			lev_sel[1] = 0;
			lev_sel[2] = 0;
			buttonflag[5] = 0;
		}
	}
}
void iNameScreenDraw()
{
	if (Start == -1){
		iShowBMP(52, 52, "losecry.bmp");
	}
	else if (Start == -2){
		iSetColor(0, 0, 0);
		iShowBMP(102, 102, "winlaugh.bmp");
		iText(225, 400, "YOUR SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
		show_score(score, 275, 370);

		iText(225, 310, "ENTER NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(100, 275, 400, 30);

		//iText(102, 283, NameString, GLUT_BITMAP_TIMES_ROMAN_24);

		iRectangle(250, 225, 100, 30);
		if (buttonflag[5] == 1)
		{
			iSetColor(0, 100, 50);
			iFilledRectangle(250, 225, 100, 30);
		}
		iSetColor(40, 70, 150);
		iText(265, 233, "DONE", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}


void show_place(int n, int pos_x, int pos_y)
{
	int digit;
	int i, locator = 10;

	for (i = 0; i<2; i++)
	{
		digit = (n / locator) % 10;
		text(digit, pos_x + i * 10, pos_y);
		locator = locator / 10;
	}
}
void draw_score()
{
	int i;

	if (buttonflag[4] == 1)
	{
		iSetColor(0, 200, 100);
		iFilledRectangle(720, 10, 50, 30);
	}
	iSetColor(0, 100, 200);
	show_leaderboard();
	iRectangle(720, 10, 50, 30);
	iText(724, 20, "Back", GLUT_BITMAP_HELVETICA_18);
	for (i = 0; i<16; i++) iRectangle(115, 60 + i * 30, 635, 30);
	iLine(240, 60, 240, 540);
	iLine(600, 60, 600, 540);

	iText(160, 517, "Pos", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350, 517, "Player Name", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640, 517, "Time", GLUT_BITMAP_TIMES_ROMAN_24);

	for (i = 1; i <= 9; i++) text(i, 163, 515 - i * 30);
	for (i = 10; i <= 15; i++) show_place(i, 163, 515 - i * 30);

	for (i = 1; i <= 15; i++) iText(3, 515 - i * 30, hscore[i - 1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	for (i = 1; i <= 15; i++) show_score(hscore[i - 1].score, 650, 57015 - i * 30);

}

void iScoreMouse(int mx, int my)
{
	if (buttonflag[4] == 1)
	{
		Start = 2;
		buttonflag[4] = 0;
	}
}