//	@date 2019/10/17
//	@author psunny0104
//	@brief boj_15652_N과 M (4)
//	@중복조합

#include <iostream>
using namespace std;

int N, M;
int selected[9];

void dfs(int idx, int cnt)
{
	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt == 0 || selected[cnt] <= i) {
			selected[idx] = i;
			dfs(idx + 1, cnt + 1);
			selected[idx] = 0;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	dfs(1, 0);

	return 0;
}