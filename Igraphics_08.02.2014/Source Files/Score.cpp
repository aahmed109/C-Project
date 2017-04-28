#include "Header.h"
#include "glut.h"
#include <stdio.h>
#include <string.h>

void iText(GLdouble x, GLdouble y, char *str, void* font);
FILE *highsc;

struct scorekeep hscore[15];
int low_score, low_pos;

void show_score(int n, int pos_x, int pos_y)
{
	int digit;
	int i, locator = 100;

	for (i = 0; i < 3; i++)
	{
		digit = (n / locator) % 10;
			text(digit, pos_x + i * 10, pos_y);
			locator = locator / 10;
	}
}

void text(int n, int pos_x, int pos_y)
{
	if (n == 0) iText(pos_x, pos_y, "0", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 1) iText(pos_x, pos_y, "1", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 2) iText(pos_x, pos_y, "2", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 3) iText(pos_x, pos_y, "3", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 4) iText(pos_x, pos_y, "4", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 5) iText(pos_x, pos_y, "5", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 6) iText(pos_x, pos_y, "6", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 7) iText(pos_x, pos_y, "7", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 8) iText(pos_x, pos_y, "8", GLUT_BITMAP_TIMES_ROMAN_24);
	if (n == 9) iText(pos_x, pos_y, "9", GLUT_BITMAP_TIMES_ROMAN_24);
}

void add_to_leaderboard(char name[], int score)
{
	if (score>low_score)
	{
		strcpy(hscore[low_pos].name, name);
		hscore[low_pos].score = score;
		sort_hscore();
		save_hscore();
	}
}

void sort_hscore()
{
	int i, j;
	struct scorekeep temp;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (hscore[i].score < hscore[j].score)
			{
				temp = hscore[i];
				hscore[i] = hscore[j];
				hscore[j] = temp;
			}
		}
	}
	for (i = 0; i< 15; i++)
	{
		if (hscore[i].score == low_score)
		{
			low_pos = i;
			break;
		}
	}
}

void save_hscore()
{
	int i;
	highsc = fopen("allsave/highscore.txt", "w");
	for (i = 0; i<5; i++) fprintf(highsc, "%s %d\n", hscore[i].name, hscore[i].score);
	fclose(highsc);
}

void show_leaderboard()
{
	int i;
	highsc = fopen("allsave/highscore.txt", "r");
	for (i = 0; i<5; i++) fscanf(highsc, "%s %d\n", &hscore[i].name, &hscore[i].score);
	fclose(highsc);
}

