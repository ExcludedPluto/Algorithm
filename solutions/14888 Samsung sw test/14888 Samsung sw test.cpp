#include <iostream>
#define MAX_NUM 11

using namespace std;

int num[MAX_NUM];
int numOfNum;
int operators[4];	// + - * /
int operatorPerm[MAX_NUM - 1];	// 1 : +, 2 : -, 3 : *, 4 : /
int min = 1000000001;
int max = -1000000001;
void getMinAndMax(int operatorPerm[MAX_NUM-1], int len);
void swap_arr(int *arr, int i, int j);

int main() {
	cin >> numOfNum;
	for (int i = 0; i < numOfNum; i++)
		cin >> num[i];
	cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

	int index = 0;
	for (int j = 0; j < operators[0]; j++)
		operatorPerm[index++] = 0;
	for (int j = 0; j < operators[1]; j++)
		operatorPerm[index++] = 1;
	for (int j = 0; j < operators[2]; j++)
		operatorPerm[index++] = 2;
	for (int j = 0; j < operators[3]; j++)
		operatorPerm[index++] = 3;

	getMinAndMax(operatorPerm, 0);
	cout << max << endl << min << endl;
}

//각 연산자 수에 맞게 0~numOfNum-1에서 수를 뽑아 각 연산자에 배치
void getMinAndMax(int operatorPerm[MAX_NUM - 1], int len) {
	if (len == numOfNum - 1) {
		int temp = num[0];
		for (int i = 1; i < numOfNum; i++) {
			if (operatorPerm[i - 1] == 0)
				temp += num[i];
			else if (operatorPerm[i - 1] == 1)
				temp -= num[i];
			else if (operatorPerm[i - 1] == 2)
				temp *= num[i];
			else
				temp /= num[i];
		}

		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		return;
	}

	getMinAndMax(operatorPerm, len+1);
	for (int i = len+1; i < numOfNum - 1; i++) {
		if (operatorPerm[len] == operatorPerm[i])
			continue;
		swap_arr(operatorPerm, i, len);
		getMinAndMax(operatorPerm, len + 1);
		swap_arr(operatorPerm, i, len);
	}
}

void swap_arr(int *arr, int i, int j) {
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

