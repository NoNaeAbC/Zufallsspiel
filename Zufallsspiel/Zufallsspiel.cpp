// Zufallsspiel.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <random>
#include <time.h>

size_t it = 0;
int Galton() {
	int l = 0;
	for (size_t i = 0; i < 7; i++)
	{
		if (rand() % 2) {
			l++;
		}
	}
	return l;
}

double g1() {
	int i1 = (rand()%6)+1;
	int i2 = (rand() % 6) + 1;
	switch (i1+i2)
	{
	case 2:
		return 0.5;
		break;
	case 3:
		return 0.5;
		break;
	case 4:
		return 0.5;
		break;
	case 5:
		return 0.5;
		break;
	case 6:
		return 0.5;
		break;
	case 7:
		return 0.5;
		break;
	case 8:
		return 1.0;
		break;
	case 9:
		return 2.0;
		break;
	case 10:
		return 2.0;
		break;
	case 11:
		return 3.0;
		break;
	case 12:
		return 3.0;
		break;
	default:
		break;
	}
}


double g2() {
	int j = 0;
	for (size_t i = 0; i < 6; i++)
	{
		j += rand() % 2;
	}
	if (j < 2) {
		return 0.5;
	}
	return j - 1;

}
double g3() {
	int a[3] = { 0,0,0 };
	for (size_t i = 0; i < 3; i++)
	{
		a[i] = (rand() % 6) + 1;
	}

	if (a[0] == a[1] && a[1] == a[2]) {
		if (a[0] < 4) {
			return 8;
		}
		return 9;
	}
	if (a[1] == a[2]) {
		return a[1] + 1;
	}
	if (a[0] == a[2]) {
		return a[0] + 1;
	}
	if (a[1] == a[0]) {
		return a[1] + 1;
	}
	return 0.5;
}
double g4() {
	int i1[10] = {0,0,0,0,0,0,0,0,0};

	for (size_t i = 0; i < 10; i++)
	{
		int r = 0;
		do
		{
			r = (rand()%52)+1;
			//printf("%d-%d\n", r , it);
		} while (!(r != i1[0] && r != i1[1] && r != i1[2] && r != i1[3] && r != i1[4] && r != i1[5] && r != i1[6] && r != i1[7] && r != i1[8] && r != i1[9]));
		i1[i] = r;
	}
	int ass = 0;
	for (size_t i = 0; i < 10; i++)
	{
		if (i1[i] < 5) {
			ass++;
		}
	}
	if (ass != 0) {
		return ass * 3;
	}
	return 1;


}


int main()
{
	double money = 0;
	srand(clock());
	double maxmoney = 0;
	double minmoney = 200;
	for (it = 0; it < 10; it++)
	{
		double p = 1;
		for (size_t j = 0; j < 2; j++)
		{
			switch (Galton()) {
			case 0:
				p*=g4();
				break;
			case 1:
				p *= g2();
				break;
			case 2:
				break;
			case 3:
				p *= g1();
				break;
			case 4:
				p*=g1();
				break;
			case 5:
				break;
			case 6:
				p *= g2();
				break;
			case 7:
				p *= g4();
				break;
				
			};
		}
		p /= 1.42;
		p *= 100;

		p = -100 + p;
		money += p;
		if (p > maxmoney) {
			maxmoney = p;
		}
		if (p < minmoney) {
			minmoney = p;
		}
		printf("%d\n", it);
	}
	printf("%f-%f-%f\n", (money / 10),maxmoney,minmoney);
    return 0;
}

