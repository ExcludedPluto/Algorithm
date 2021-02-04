#include <iostream>
#include <algorithm>
#define MAX_WIDTH 100

using namespace std;

typedef struct Location {
	int row;
	int col;
	bool operator < (Location l) {
		if (col != l.col)
			return col < l.col;
		else
			return row > l.row;
	}
} Location;

int R, C;
bool map[MAX_WIDTH][MAX_WIDTH], visit[MAX_WIDTH][MAX_WIDTH];
Location q[MAX_WIDTH * MAX_WIDTH];

void throwStick(int height, bool isLeft);
void generateBFS(int r, int c);
void BFS(int r, int c);
void initVisit(int length);
void pushDown(int length);

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			char temp;
			cin >> temp;
			if (temp == '.')
				map[i][j] = false;
			else
				map[i][j] = true;
		}

	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		throwStick(R - temp, i % 2 == 0 ? true : false);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c = map[i][j] ? 'x' : '.';
			cout << c;
		}
		cout << endl;
	}
}

void throwStick(int height, bool isLeft) {
	if (isLeft) {
		int i = 0;
		for (; i < C; i++)
			if (map[height][i])
				break;
		if (i == C)
			return;

		map[height][i] = false;
		generateBFS(height, i);
	}
	else {
		int i = C-1;
		for (; i >=0; i--)
			if (map[height][i])
				break;
		if (i == -1)
			return;

		map[height][i] = false;
		generateBFS(height, i);
	}

	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c = map[i][j] ? 'x' : '.';
			cout << c;
		}
		cout << endl;
	}
	cout << endl;
}

void generateBFS(int r, int c) {
	if (r > 0 && map[r - 1][c])
		BFS(r - 1, c);
	if (r < R - 1 && map[r + 1][c])
		BFS(r + 1, c);
	if (c > 0 && map[r][c - 1])
		BFS(r, c - 1);
	if (c < C - 1 && map[r][c + 1])
		BFS(r, c + 1);
}

void BFS(int r, int c) {
	int length = 0, index = 0;
	visit[r][c] = true;
	q[length++] = { r,c };

	while (index < length) {
		Location temp = q[index++];
		int row = temp.row, col = temp.col;
	
		if (row == R - 1) {
			initVisit(length);
			return;
		}

		if (row > 0 && !visit[row - 1][col] && map[row - 1][col]) {
			q[length++] = { row - 1, col };
			visit[row - 1][col] = true;
		}
		if (row < R - 1 && !visit[row + 1][col] && map[row + 1][col]) {
			q[length++] = { row + 1, col };
			visit[row + 1][col] = true;
		}
		if (col > 0 && !visit[row][col - 1] && map[row][col - 1]) {
			q[length++] = { row, col - 1 };
			visit[row][col - 1] = true;
		}
		if (col < C - 1 && !visit[row][col + 1] && map[row][col + 1]) {
			q[length++] = { row, col + 1 };
			visit[row][col + 1] = true;
		}
	}
	pushDown(length);
	initVisit(length);
}

void initVisit(int length) {
	for (int i = 0; i < length; i++)
		visit[q[i].row][q[i].col] = false;
}

void pushDown(int length) {
	sort(q, q + length);
	//밑이 빈 것들만 뽑고, 그중 밑하고 떨어진 거리가 가장 짧은 것을 따로 길이만 저장
	//그 길이만큼 하강
	int minHeight = 1000000, cur = -1;
	for (int i = 0; i < length; i++) {
		if (cur != q[i].col) {
			cur = q[i].col;

			int row = q[i].row + 1;
			//미네랄을 만나거나 바닥이면 스탑
			int j = row;
			for (; j < R; j++)
				if (map[j][cur])
					break;
			minHeight = minHeight < j - row ? minHeight : j - row;
		}
	}
	cout << minHeight << endl;

	//해당 클러스트를 minHeight만큼 내리기
	//****임시 배열을 만들어서 표시
	for (int i = 0; i < length; i++) {
		map[q[i].row][q[i].col] = false;
		map[q[i].row + minHeight][q[i].col] = true;
	}
}