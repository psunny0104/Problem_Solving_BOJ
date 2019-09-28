//	@date 2019/09/28
//	@author psunny0104
//	@brief boj_15649_N과 M (1)

#include <iostream>
#include <cstring>
using namespace std;

int M, N;

int num[9];
bool selected[9];

void dfs(int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (selected[i] == false) {
			selected[i] = true;
			num[cnt] = i;
			dfs(cnt + 1);
			selected[i] = false;
			//num[cnt] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	dfs(0);

}