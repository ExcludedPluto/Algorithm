#include <iostream>
#define MAX_WIDTH 501

using namespace std;

int width, height;
int map[MAX_WIDTH][MAX_WIDTH];

void getProperties();
int putTetromino();

int main() {
	while (true) {
		getProperties();
		cout << putTetromino();
	}
}

void getProperties() {
	cin >> height >> width;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];
}


int putTetromino() {
	int max = 0;

	//일자 확인
	for (int row = 0; row < height; row++) {
		int temp = map[row][0] + map[row][1] + map[row][2];
		for (int i = 3; i < width; i++) {
			temp += map[row][i];
			if (temp > max)
				max = temp;
			temp -= map[row][i - 3];
		}
	}

	//세로 일자 확인
	for (int col = 0; col < width; col++) {
		int temp = map[0][col] + map[1][col] + map[2][col];
		for (int i = 3; i < height; i++) {
			temp += map[i][col];
			if (temp > max)
				max = temp;
			temp -= map[i - 3][col];
		}
	}

	//네모 확인
	int lastHeight = height - 1;
	int lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col+1] + map[row+1][col] + map[row+1][col+1];
			max = temp > max ? temp : max;
		}
	}

	//L1 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row + 1][col] + map[row + 2][col] + map[row + 2][col + 1];
			max = temp > max ? temp : max;
		}
	}

	//L2 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row + 1][col] + map[row][col + 1] + map[row][col + 2];
			max = temp > max ? temp : max;
		}
	}

	//L3 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col + 1] + map[row + 1][col + 1] + map[row + 2][col + 1];
			max = temp > max ? temp : max;
		}
	}

	//L4 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row + 1][col] + map[row + 1][col + 1] + map[row + 1][col + 2] + map[row][col + 2];
			max = temp > max ? temp : max;
		}
	}

	//L5 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row + 2][col] + map[row + 2][col + 1] + map[row + 1][col + 1] + map[row][col + 1];
			max = temp > max ? temp : max;
		}
	}

	//L6 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row+1][col] + map[row + 1][col + 1] + map[row+1][col + 2];
			max = temp > max ? temp : max;
		}
	}

	//L7 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col + 1] + map[row + 1][col] + map[row+2][col];
			max = temp > max ? temp : max;
		}
	}

	//L8 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col + 1] + map[row][col + 2] + map[row + 1][col + 2];
			max = temp > max ? temp : max;
		}
	}

	//Z1 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col+1] + map[row+1][col + 1] + map[row+1][col] + map[row + 2][col];
			max = temp > max ? temp : max;
		}
	}
	//Z2 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col + 1] + map[row+1][col + 1] + map[row + 1][col + 2];
			max = temp > max ? temp : max;
		}
	}
	//Z3 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row+1][col] + map[row+1][col + 1] + map[row + 2][col + 1];
			max = temp > max ? temp : max;
		}
	}
	//Z4 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col+1] + map[row][col + 2] + map[row+1][col] + map[row + 1][col + 1];
			max = temp > max ? temp : max;
		}
	}

	//T1 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row+1][col] + map[row][col + 1] + map[row + 1][col+2] + map[row + 1][col + 1];
			max = temp > max ? temp : max;
		}
	}
	//T2 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row+1][col] + map[row + 2][col] + map[row + 1][col + 1];
			max = temp > max ? temp : max;
		}
	}
	//T3 확인
	lastHeight = height - 1;
	lastWidth = width - 2;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col] + map[row][col + 1] + map[row][col+2] + map[row + 1][col + 1];
			max = temp > max ? temp : max;
		}
	}
	//T4 확인
	lastHeight = height - 2;
	lastWidth = width - 1;
	for (int row = 0; row < lastHeight; row++) {
		for (int col = 0; col < lastWidth; col++) {
			int temp = map[row][col + 1] + map[row+1][col] + map[row + 1][col+1] + map[row + 2][col + 1];
			max = temp > max ? temp : max;
		}
	}


	return max;
}