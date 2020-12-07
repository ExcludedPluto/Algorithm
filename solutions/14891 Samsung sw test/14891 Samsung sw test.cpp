#include <iostream>
#include <cstdio>
#define MAX_ROTATE 100
#define LEFT 6
#define RIGHT 2

using namespace std;

int command[MAX_ROTATE][2];
int gear[4][8];
int numOfRotate;

int implementCommand();
void implementSingleCommand(int gearN, int way);
void rotateSingleGear(int gearN, int way);

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf_s("%1d", &gear[i][j]);
	cin >> numOfRotate;
	for (int i = 0; i < numOfRotate; i++) {
		cin >> command[i][0] >> command[i][1];
		command[i][0] -= 1;
	}
	
	cout << implementCommand();
}

int implementCommand() {
	for (int i = 0; i < numOfRotate; i++)
		implementSingleCommand(command[i][0], command[i][1]);

	int score = 0;
	score += gear[0][0] == 0 ? 0 : 1;
	score += gear[1][0] == 0 ? 0 : 2;
	score += gear[2][0] == 0 ? 0 : 4;
	score += gear[3][0] == 0 ? 0 : 8;
	return score;
}

void implementSingleCommand(int gearN, int way) {
	//1 : 시계방향, -1 : 반시계방향

	rotateSingleGear(gearN, way);

	//왼쪽
	int exWay = way;
	for (int current = gearN - 1; current >= 0; current--) {
		if (exWay == 1) {
			if (gear[current + 1][LEFT + 1] != gear[current][RIGHT]) {
				rotateSingleGear(current, -1);
				exWay = -1;
			}
			else
				exWay = 0;
		}
		else if (exWay == -1) {
			if (gear[current + 1][LEFT - 1] != gear[current][RIGHT]) {
				rotateSingleGear(current, 1);
				exWay = 1;
			}
			else
				exWay = 0;
		}
		else
			break;
	}

	//오른쪽
	exWay = way;
	for (int current = gearN + 1; current <= 3; current++) {
		if (exWay == 1) {
			if (gear[current - 1][RIGHT + 1] != gear[current][LEFT]) {
				rotateSingleGear(current, -1);
				exWay = -1;
			}
			else
				exWay = 0;
		}
		else if (exWay == -1) {
			if (gear[current - 1][RIGHT - 1] != gear[current][LEFT]) {
				rotateSingleGear(current, 1);
				exWay = 1;
			}
			else
				exWay = 0;
		}
		else
			break;
	}

}

void rotateSingleGear(int gearN, int way) {
	if (way == 1) {
		int temp = gear[gearN][0];
		for (int i = 1; i < 8; i++) {
			int temp2 = gear[gearN][i];
			gear[gearN][i] = temp;
			temp = temp2;
		}
		gear[gearN][0] = temp;
	}
	else if (way == -1) {
		int temp = gear[gearN][7];
		for (int i = 6; i >= 0; i--) {
			int temp2 = gear[gearN][i];
			gear[gearN][i] = temp;
			temp = temp2;
		}
		gear[gearN][7] = temp;
	}
}