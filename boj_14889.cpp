//	@date 2019/10/20
//	@author psunny0104
//	@brief boj_14889_스타트와 링크

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, tg_cnt, tmp_cnt, ans;
int rt[21][21];
bool sltd[21];

void dfs(int idx, int cnt)
{
	if (cnt == M) {
		int scr_st = 0;
		int scr_link = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (sltd[i] && sltd[j])
					scr_st += rt[i][j];
				if (!sltd[i] && !sltd[j])
					scr_link += rt[i][j];
			}
		}

		ans = min(ans, abs(scr_st - scr_link));
		return;
	}

	for (int i = idx; i < N; i++) {
		if (sltd[i])
			continue;
		sltd[i] = true;
		dfs(i, cnt + 1);
		sltd[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> rt[i][j];
		}
	}

	M = N / 2;

	ans = 987654321;
	dfs(1, 0);
	cout << ans << '\n';

	return 0;
}