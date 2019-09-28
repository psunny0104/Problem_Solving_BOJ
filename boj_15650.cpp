//	@date 2019/09/28
//	@author psunny0104
//	@brief boj_15650_N과 M (2)

#include <iostream>
#include <cstring>
using namespace std;

int M, N;

int num[9];
bool selected[9];

void dfs(int idx, int cnt)
{
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if (selected[i] == true)
				cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (selected[i] == true)
			continue;

		selected[i] = true;
		dfs(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		num[i] = i;
	}

	dfs(1, 0);

}