#include "Header.h"
#include <stdio.h>


FILE *savefile;
void reset(int state)
{
	int i, j;
	if (state == 1) for (i = 0; i < wdt; i++)	for (j = 0; j < hgt;j++)	buttonpressed[i][j] = 0;
}

void gamesave()
{
	int i, j;
	savefile = fopen("allsave/listofsave.txt", "w");

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fprintf(savefile, "%d ", buttonpressed[i][j]);
	fprintf(savefile, "\n");

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fprintf(savefile, "%d ", mineornot[i][j]);
	fprintf(savefile, "\n");

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fprintf(savefile, "%d ", mgrid[i][j]);
	fprintf(savefile, "\n");

	fprintf(savefile, "%d ", sec);
	fprintf(savefile, "\n");

	fprintf(savefile, "%d ", mul);
	fprintf(savefile, "\n");

	fprintf(savefile, "%d ", hgt);
	fprintf(savefile, "\n");

	fprintf(savefile, "%d ", wdt);
	fprintf(savefile, "\n");

	fprintf(savefile, "%d ", level);
	fprintf(savefile, "\n");

	/*fprintf(savedata, "%d ", ball_x[i]);
	fprintf(savedata, "\n");

	for (i = 0; i<16; i++) fprintf(savedata, "%d ", ball_y[i]);
	fprintf(savedata, "\n");

	for (i = 0; i<16; i++) fprintf(savedata, "%d ", dx[i]);
	fprintf(savedata, "\n");

	for (i = 0; i<16; i++) fprintf(savedata, "%d ", dy[i]);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", t);
	fprintf(savedata, "\n");

	for (i = 0; i<16; i++) fprintf(savedata, "%d ", n[i]);
	fprintf(savedata, "\n");

	for (i = 0; i<16; i++) fprintf(savedata, "%d ", m[i]);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", paddle);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", PaddleLength);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", Blockcount);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", Breakcount);
	fprintf(savedata, "\n");

	fprintf(savedata, "%d", Score);
	fprintf(savedata, "\n");
	*/
	fclose(savefile);

}

void gameload()
{
	Start = 1;
	int i, j;
	savefile = fopen("allsave/listofsave.txt", "r");

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fscanf(savefile, "%d", &buttonpressed[i][j]);

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fscanf(savefile, "%d", &mineornot[i][j]);

	for (i = 0; i < wdt; i++)	for (j = 0; j < hgt; j++)	fscanf(savefile, "%d", &mgrid[i][j]);

	fscanf(savefile, "%d", &sec);

	fscanf(savefile, "%d", &mul);

	fscanf(savefile, "%d", &hgt);

	fscanf(savefile, "%d", &wdt);

	//fscanf(savefile, "%d", &level);
	/*
	for (i = 0; i<360; i++) fscanf(savefile, "%d ", &OriginState[i]);

	for (i = 0; i<360; i++) fscanf(savedata, "%d", &HitState[i]);

	fscanf(savedata, "%d", &Lives);

	fscanf(savedata, "%d", &BallCount);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &BallFlag[i]);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &ball_x[i]);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &ball_y[i]);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &dx[i]);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &dy[i]);

	fscanf(savedata, "%d", &t);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &n[i]);

	for (i = 0; i<16; i++) fscanf(savedata, "%d", &m[i]);

	fscanf(savedata, "%d", &paddle);

	fscanf(savedata, "%d", &PaddleLength);

	fscanf(savedata, "%d", &Blockcount);

	fscanf(savedata, "%d", &Breakcount);

	fscanf(savedata, "%d", &Score);
	*/
	fclose(savefile);

	//iPauseTimer(0);
}



