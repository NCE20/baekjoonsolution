#include <iostream>

using namespace std;
int a[3000][3000];
int cnt[3];

bool same(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[x][y] != a[x + i][y + j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (same(x, y, n)) {
		cnt[a[x][y] + 1] += 1;
		return;
	}

	int m = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + m * i, y + m * j, m);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	solve(0, 0, n);

	cout << cnt[0] << endl << cnt[1] << endl << cnt[2] << endl;
}
