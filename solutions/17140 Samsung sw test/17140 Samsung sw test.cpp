#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX_NUM 101

using namespace std;

typedef struct Cell {
	int value;
	int count;

	bool operator < (Cell c) {
		if (count < c.count)
			return true;
		else if (c.count < count)
			return false;
		else {
			if (value < c.value)
				return true;
			else
				return false;
		}
	}
} Cell;

int map[MAX_NUM][MAX_NUM];
int width, height;
int r, c, k;

int getTimeToReachRCK();
void print() {
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < MAX_NUM; i++)
		memset(map[i], 0, sizeof(int) * MAX_NUM);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	width = height = 3;
	cout << getTimeToReachRCK();
}

int getTimeToReachRCK() {
	int time = 0;

	for (time; time <= 100; time++) {
		if (map[r-1][c-1] == k)
			break;
		
		int temp[MAX_NUM];
		memset(temp, 0, sizeof(int) * (MAX_NUM));

		if (height >= width) {
			int maxWidth = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					temp[map[i][j]]++;
				}

				vector<Cell> temp2;
				for (int j = 1; j < MAX_NUM; j++)
					if (temp[j] != 0)
						temp2.push_back({ j, temp[j] });

				sort(temp2.begin(), temp2.end());
				int index = 0;
				for (int j = 0; j < temp2.size(); j++) {
					if (index >= 100)
						break;
					map[i][index++] = temp2[j].value;
					map[i][index++] = temp2[j].count;
				}
				if (index < width)
					for (int j = index; j < width; j++)
						map[i][j] = 0;

				maxWidth = index > maxWidth ? index : maxWidth;
				memset(temp, 0, sizeof(int) * (MAX_NUM));
			}
			width = maxWidth;
		}
		else {
			int maxHeight = 0; 
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					temp[map[j][i]]++;
				}

				vector<Cell> temp2;
				for (int j = 1; j < MAX_NUM; j++)
					if (temp[j] != 0)
						temp2.push_back({ j, temp[j] });
				
				sort(temp2.begin(), temp2.end());
				int index = 0;
				for (int j = 0; j < temp2.size(); j++) {
					if (index >= 100)
						break;
					map[index++][i] = temp2[j].value;
					map[index++][i] = temp2[j].count;
				}
				if (index < height)
					for (int j = index; j < height; j++)
						map[j][i] = 0;

				maxHeight = index > maxHeight ? index : maxHeight;
				memset(temp, 0, sizeof(int) * MAX_NUM);
			}
			height = maxHeight;
		}
	}

	
	return (time == 101 ? -1 : time);
}
