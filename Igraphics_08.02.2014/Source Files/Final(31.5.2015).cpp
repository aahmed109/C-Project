#include "Header.h"
# include "iGraphics.h"

int backbutton;
int sec,timerstart;
int mgrid[30][30];
int mineornot[30][30];
int buttonpressed[30][30];
int level;
int gameover, presscount;
int ct1, ct2;
int x, y, xx, yy;
int i, j, c, d, cc, dd, k, p, Start = 2;

int u, v, w, f, r, m;

void time()
{
	if (sec<999)	sec++;
}

void search(int k, int p)
{
	if (buttonpressed[k][p] == 1)
	{
		return;
	}
	else
	{
		buttonpressed[k][p] = 1;
		presscount++;
		if (mgrid[k][p] == -1) {
			gameover = 1;
			return;
		}
		else if (mgrid[k][p] == 0){
			if (k + 1 < hgt) search(k + 1, p);
			if (p + 1 < wdt) search(k, p + 1);
			if (k - 1 >= 0) search(k - 1, p);
			if (p - 1 >= 0) search(k, p - 1);
			if (k + 1 < hgt && p + 1 < wdt) search(k + 1, p + 1);
			if (k + 1 < hgt && p - 1 >= 0) search(k + 1, p - 1);
			if (k - 1 >= 0 && p + 1 < wdt) search(k - 1, p + 1);
			if (k - 1 >= 0 && p - 1 >= 0) search(k - 1, p - 1);
			return;
		}
		else return;
	}
}
void showres(int res)
{
	/*if (res == 1)
	{
		Start = -1;
		iText(380,100,"YOU LOSE!!! BETTER LUCK NEXT TIME",GLUT_BITMAP_TIMES_ROMAN_24);
	}*/
	if (res == 2)
	{
		Start = -2;
		iShowBMP(52, 52, "winlaugh.bmp");
	}
	else if (res == 1){
		Start = -1;
		iShowBMP(52, 52, "losecry.bmp");
	}
}
void iDraw()
{
	iClear();
	iSetColor(255, 255, 255);
	iFilledRectangle(40, 0, 800, 690);
	if (Start == 2)	menuDraw();
	else if (Start == 0){
		levelSelectdraw();
	}
	else if (Start == 3){
		draw_score();
	}
	else if (Start == -2 || Start == -1)
	{
		iNameScreenDraw();
	}
	else if (Start == 1){
		showres(gameover);
		iSetColor(0, 0, 255);
		iFilledRectangle(45, 5, 65, 30);
		iSetColor(0,0,0);
		
		if (buttonflag[6] == 1){
			iSetColor(0, 200, 80);
			iFilledRectangle(46, 6, 63, 28);
		}
		if (backbutton == 1)
		{
			iSetColor(0, 200, 100);
			iFilledRectangle(45, 5, 65, 30);
		}
		iSetColor(0, 0, 0);
		iText(50, 10, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(200, 150, 120);
		iFilledRectangle(783, 600, 45, 35);
		iSetColor(0, 0, 0);
		show_score(sec,790,610);
		iSetColor(100, 100, 100);
		iFilledRectangle(110, 15, 660, 660);
		for (i = 0; i < wdt; i++){
			for (j = 0; j < hgt; j++){
				iSetColor(0, 0, 0);
				if (mgrid[i][j] == 1){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "1", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "1", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 2){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19) + ((buttonsize - 24) / 2), "2", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "2", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 3){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "3", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "3", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 4){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "4", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "4", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 5){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "5", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "5", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 6){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "6", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "6", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 7){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "7", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "7", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == 8){
					if (level == 1 || level == 2){
						iText(i * mul + 114 + ((buttonsize - 24) / 2), (j * mul + 19 + ((buttonsize - 24) / 2)), "8", GLUT_BITMAP_TIMES_ROMAN_24);
					}
					else if (level == 3){
						iText(i * mul + 120 + ((buttonsize - 24) / 2), (j * mul + 25 + ((buttonsize - 24) / 2)), "8", GLUT_BITMAP_TIMES_ROMAN_10);
					}
				}
				if (mgrid[i][j] == -1)
				{
					if (mul == 66){
						iShowBMP((i * mul) + 112, (j * mul) + 17, "mine_b.bmp");
					}
					else if (mul == 33){
						iShowBMP((i * mul) + 112, (j * mul) + 17, "mine_m.bmp");
					}
					else if (mul == 22){
						iShowBMP((i * mul) + 112, (j * mul) + 17, "mine_s.bmp");
					}
				}
			}
		}
		for (i = 0; i < wdt; i++){
			for (j = 0; j < hgt; j++){
				int qq, ww;
				if (buttonpressed[i][j] == 0)
				{
					iSetColor(0, 100, 150);
					iFilledRectangle(i*mul + 112, (j*mul + 17), buttonsize, buttonsize);
				}
				else if(buttonpressed[i][j] == 1){
					if (mgrid[i][j] == -1){
						int ii, jj;
						for (ii = 0; ii < wdt; ii++){
							for (jj = 0; jj < hgt; jj++){
								if (mgrid[ii][jj] == -1) {
										{
											if (mul == 40){
												iShowBMP(i * (mul + 40) + (mul + 40), j * (mul + 40) + (mul + 40), "mine_b.bmp");
											}
											else if (mul == 30){
												iShowBMP(i * (mul + 40) + (mul + 40), j * (mul + 40) + (mul + 40), "mine_m.bmp");
											}
											else if (mul == 40){
												iShowBMP(i * (mul + 40) + (mul + 40), j * (mul + 40) + (mul + 40), "mine_s.bmp");
											}
										}
									buttonpressed[ii][jj] = 1;
								}
							}
						}
					}
				}
				else if (buttonpressed[i][j] == -1){
					if (level == 1)	iShowBMP((i * mul) + 112, (j * mul) + 17,"flag_b.bmp");
					else if (level == 2)	iShowBMP((i * mul) + 112, (j * mul) + 17, "flag_m.bmp");
					else if (level == 3)	iShowBMP((i * mul) + 112, (j * mul) + 17, "flag_s.bmp");
				}
				else if (buttonpressed[i][j] == -2){
					if (level == 1)	iShowBMP((i * mul) + 112, (j * mul) + 17, "ques_b.bmp");
					else if (level == 2)	iShowBMP((i * mul) + 112, (j * mul) + 17, "ques_m.bmp");
					else if (level == 3)	iShowBMP((i * mul) + 112, (j * mul) + 17, "ques_s.bmp");

				}
			}
		}
	}
}


void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if (Start == 2 || Start == 0) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			iMenuMouse(mx, my);
		}
	}
	else if (Start == 3)	iScoreMouse(mx, my);
	else if (Start == 1){
		if (gameover == 0){
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >= 110 && mx <= 770) && (my >= 15 && my <= 675))
			{
				x = mx;
				y = my;
				c = (x - 110) / mul;
				d = (y - 15) / mul;
				if (buttonpressed[c][d] == 0){
					if ((buttonpressed[c][d]) != -1 && buttonpressed[c][d] != -2){
						search(c, d);
					}
					if (timerstart == 0)
					{
						iSetTimer(1000, time);
						timerstart = 1;
					}
					if (buttonpressed[c][d] == -2){
						buttonpressed[c][d] = 1;
					}
					if (presscount == wdt*hgt - mine)
					{
						printf("DONE!!!!!!!!!!!!!!!\n");
						iPauseTimer(0);
						gameover = 2;
					}
				}
			}
			if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && (mx >= 110 && mx <= 770) && (my >= 15 && my <= 675))
			{
				xx = mx;
				yy = my;
				cc = (xx - 110) / mul;
				dd = (yy - 15) / mul;
				if (buttonpressed[cc][dd] == 0){
					buttonpressed[cc][dd] = -1;
				}
				else if (buttonpressed[cc][dd] == -1){
					buttonpressed[cc][dd] = -2;
				}
				else if (buttonpressed[cc][dd] == -2){
					buttonpressed[cc][dd] = 0;
				}
			}
			else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (mx >= 50 && mx <= 110) && (my >= 10 && my <= 30))
			{
				gamesave();
				Start = 0;
			}
		}
		else if (gameover == 1){
			iPauseTimer(0);
		}
	}
}

void iPassiveMouseMove(int mx, int my)
{
	if (Start == 2 || Start == 0) iMenuPassiveMouseMove(mx, my);
	else if (Start == 3) iScorePassiveMouseMove(mx, my);
	else if (Start == 1){
		if (mx > 50 && mx < 110 && my > 10 && my < 30) backbutton = 1;
		else backbutton = 0;
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q'){
		exit(0);
	}
	if (key == 'p'){
		iPauseTimer(0);
	}
	if (key == 'r'){
		iResumeTimer(0);
	}

}

void iSpecialKeyboard(unsigned char key)
{

}


int main()
{
	iInitialize(880, 690, "Minesweeper");
	return 0;
}
