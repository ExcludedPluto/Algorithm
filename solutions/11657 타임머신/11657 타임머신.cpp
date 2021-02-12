#include <bits/stdc++.h>

using namespace std;

struct Road {
	int to;
	int time;
};
struct City {
	vector<Road> next;
	long long minTime;
	int before;
};

City city[501];
list<Road> q;
int N, M;
bool generateMinTime();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		city[a].next.push_back({ b, c });
	}
	for (int i = 2; i <= N; i++)
		city[i].minTime = 2000000000000;

	if (generateMinTime()) {
		for (int i = 2; i <= N; i++) {
			if (city[i].minTime != 2000000000000)
				cout << city[i].minTime << "\n";
			else
				cout << -1 << "\n";
		}
	}
	else
		cout << -1 << "\n";
}

bool generateMinTime() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j <= N; j++) {
			if (city[j].minTime != 2000000000000) {
				for (int k = 0; k < city[j].next.size(); k++) {
					Road t = city[j].next[k];
					long long nt = city[j].minTime + t.time;

					if (nt < city[t.to].minTime)
						city[t.to].minTime = nt;
				}
			}
		}
	}

	for (int j = 1; j <= N; j++) {
		if (city[j].minTime != 2000000000000) {
			for (int k = 0; k < city[j].next.size(); k++) {
				Road t = city[j].next[k];
				long long  nt = city[j].minTime + t.time;

				if (nt < city[t.to].minTime)
					return false;
			}
		}
	}
	return true;
}