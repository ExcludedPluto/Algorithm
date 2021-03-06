#include <iostream>
#include <cstring>
#define MAX_ROTATE	1000
#define MAX_TESTCASE 100
#define WHITE 100
#define YELLOW 200
#define RED 300
#define ORANGE 400
#define GREEN 500
#define BLUE 600

using namespace std;

typedef struct Command {
	int location;	//큐브 면
	int way;		//0이 반시계, 1은 시계
} Command;

int cube[6][9];	//0이 위, 1이 뒤, 2가 오, 3은 앞, 4는 왼쪽, 5는 아래
int numOfTestcase;
Command testcase[MAX_TESTCASE][MAX_ROTATE];
int numOfCommand[MAX_TESTCASE];

void implementTestcases();
void implementSingleTC(Command command[MAX_ROTATE], int numCommand);
void implementSingleCommand(int index[4], int cubeIndex[4][3], int way, int location);
void printCube();
void initCube();

int main() {
	cin >> numOfTestcase;
	for (int i = 0; i < numOfTestcase; i++) {
		cin >> numOfCommand[i];
		for (int j = 0; j < numOfCommand[i]; j++) {
			char temp;
			cin >> temp;

			if (temp == 'U') testcase[i][j].location = 0;
			else if (temp == 'D') testcase[i][j].location = 5;
			else if (temp == 'F') testcase[i][j].location = 3;
			else if (temp == 'B') testcase[i][j].location = 1;
			else if (temp == 'L') testcase[i][j].location = 4;
			else if (temp == 'R') testcase[i][j].location = 2;

			cin >> temp;
			if (temp == '+') testcase[i][j].way = 1;
			else if (temp == '-') testcase[i][j].way = 0;
		}
	}
	implementTestcases();
}

void initCube() {
	int colors[6] = { WHITE, ORANGE, BLUE, RED, GREEN, YELLOW };
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 9; j++)
			cube[i][j] = colors[i];
}

void implementTestcases() {
	for (int i = 0; i < numOfTestcase; i++) {
		initCube();
		implementSingleTC(testcase[i], numOfCommand[i]);
		printCube();
	}
}

void implementSingleTC(Command command[MAX_ROTATE], int numCommand) {
	for (int i = 0; i < numCommand; i++) {
		if (command[i].location == 0) {	//윗 
			int index[4] = { 1,2,3,4 };
			int cubeIndex[4][3] = { {0,1,2},{0,1,2},{0,1,2},{0,1,2} };
			implementSingleCommand(index, cubeIndex,command[i].way, 0);
		}
		else if (command[i].location == 1) {	//뒤
			int index[4] = { 0,4,5,2 };
			int cubeIndex[4][3] = { {2,1,0}, {0,3,6}, {2,1,0}, {8,5,2} };
			implementSingleCommand(index, cubeIndex, command[i].way, 1);
		}
		else if (command[i].location == 2) {	//오
			int index[4] = { 0,1,5,3 };
			int cubeIndex[4][3] = { {8,5,2}, {0,3,6}, {0,3,6}, {8,5,2} };
			implementSingleCommand(index, cubeIndex, command[i].way, 2);
		}
		else if (command[i].location == 3) {	//앞 
			int index[4] = { 0,2,5,4 };
			int cubeIndex[4][3] = { {6,7,8}, {0,3,6}, {6,7,8}, {8,5,2} };
			implementSingleCommand(index, cubeIndex, command[i].way, 3);
		}
		else if (command[i].location == 4) {	//왼 
			int index[4] = { 0,3,5,1 };
			int cubeIndex[4][3] = { {0,3,6}, {0,3,6}, {8,5,2}, {8,5,2} };
			implementSingleCommand(index, cubeIndex, command[i].way, 4);
		}
		else if (command[i].location == 5) {	//아
			int index[4] = { 1,4,3,2 };
			int cubeIndex[4][3] = { {6,7,8}, {6,7,8},{6,7,8},{6,7,8} };
			implementSingleCommand(index, cubeIndex, command[i].way, 5);
		}
	}
}

void implementSingleCommand(int index[4], int cubeIndex[4][3], int way, int location) {
	if (way == 1) {
		int first = index[0];
		int temp[3] = { cube[first][cubeIndex[0][0]], cube[first][cubeIndex[0][1]], cube[first][cubeIndex[0][2]] };
		for (int r = 1; r < 4; r++) {
			int temp2[3] = { cube[index[r]][cubeIndex[r][0]], cube[index[r]][cubeIndex[r][1]], cube[index[r]][cubeIndex[r][2]] };
			cube[index[r]][cubeIndex[r][0]] = temp[0];
			cube[index[r]][cubeIndex[r][1]] = temp[1];
			cube[index[r]][cubeIndex[r][2]] = temp[2];
			memcpy(temp, temp2, sizeof(int) * 3);
		}
		cube[first][cubeIndex[0][0]] = temp[0];
		cube[first][cubeIndex[0][1]] = temp[1];
		cube[first][cubeIndex[0][2]] = temp[2];
	}
	else {
		int last = index[3];
		int temp[3] = { cube[last][cubeIndex[3][0]], cube[last][cubeIndex[3][1]], cube[last][cubeIndex[3][2]] };
		for (int r = 2; r >= 0; r--) {
			int temp2[3] = { cube[index[r]][cubeIndex[r][0]], cube[index[r]][cubeIndex[r][1]], cube[index[r]][cubeIndex[r][2]] };
			cube[index[r]][cubeIndex[r][0]] = temp[0];
			cube[index[r]][cubeIndex[r][1]] = temp[1];
			cube[index[r]][cubeIndex[r][2]] = temp[2];
			memcpy(temp, temp2, sizeof(int) * 3);
		}
		cube[last][cubeIndex[3][0]] = temp[0];
		cube[last][cubeIndex[3][1]] = temp[1];
		cube[last][cubeIndex[3][2]] = temp[2];
	}


	int tempIndex[4][3] = { {0,1,2}, {2,5,8}, {8,7,6}, {6, 3, 0} };
	int tempValue[4][3] = { {cube[location][0], cube[location][1], cube[location][2]}, {cube[location][2], cube[location][5], cube[location][8]},
		{cube[location][8], cube[location][7], cube[location][6] }, {cube[location][6], cube[location][3], cube[location][0]} };
	if (way == 1) {
		for (int i = 1; i < 4; i++) {
			cube[location][tempIndex[i][0]] = tempValue[i - 1][0];
			cube[location][tempIndex[i][1]] = tempValue[i - 1][1];
			cube[location][tempIndex[i][2]] = tempValue[i - 1][2];
		}
		cube[location][0] = tempValue[3][0];
		cube[location][1] = tempValue[3][1];
		cube[location][2] = tempValue[3][2];
	}
	else {
		for (int i = 2; i >= 0; i--) {
			cube[location][tempIndex[i][0]] = tempValue[i + 1][0];
			cube[location][tempIndex[i][1]] = tempValue[i + 1][1];
			cube[location][tempIndex[i][2]] = tempValue[i + 1][2];
		}
		cube[location][6] = tempValue[0][0];
		cube[location][3] = tempValue[0][1]; 
		cube[location][0] = tempValue[0][2];
	}
}

void printCube() {
	for (int i = 0; i < 9; i++) {
		char temp;
		if (cube[0][i] == WHITE)
			temp = 'w';
		else if (cube[0][i] == ORANGE)
			temp = 'o';
		else if (cube[0][i] == RED)
			temp = 'r';
		else if (cube[0][i] == GREEN)
			temp = 'g';
		else if (cube[0][i] == BLUE)
			temp = 'b';
		else if (cube[0][i] == YELLOW)
			temp = 'y';
		cout << temp;
		if (i % 3 == 2)
			cout << endl;
	}
}