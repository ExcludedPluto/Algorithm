#include <iostream>
#define MAX_WIDTH 50

using namespace std;

int direction;
int location[2];
int map[MAX_WIDTH][MAX_WIDTH];
int height, width;

int robot();
bool changeDirection();

int main() {
	cin >> height >> width;
	cin >> location[0] >> location[1] >> direction;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];

	cout << robot();
}

int robot() {
	bool doesStop = false;

	while (!doesStop) {
		map[location[0]][location[1]] = 2;
		
		while (!changeDirection()) {
			if (direction == 0)
				location[0] += 1;
			else if (direction == 1)
				location[1] -= 1;
			else if (direction == 2)
				location[0] -= 1;
			else if (direction == 3)
				location[1] += 1;

			if (map[location[0]][location[1]] == 1) {
				doesStop = true;
				break;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (map[i][j] == 2)
				count++;
	return count;
}

bool changeDirection() {
	for (int i = 0; i < 4; i++) {
		if (direction == 0) {
			direction = 3;
			if (map[location[0]][location[1] - 1] == 0) {
				location[1] -= 1;
				return true;
			}
		}
		else if (direction == 1) {
			direction = 0;
			if (map[location[0] - 1][location[1]] == 0) {
				location[0] -= 1;
				return true;
			}
		}
		else if (direction == 2) {
			direction = 1;
			if (map[location[0]][location[1] + 1] == 0) {
				location[1] += 1;
				return true;
			}
		}
		else if (direction == 3) {
			direction = 2;
			if (map[location[0] + 1][location[1]] == 0) {
				location[0] += 1;
				return true;
			}
		}
	}

	return false;
}