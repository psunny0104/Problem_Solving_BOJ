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

int cmb(int n, int k)
{
	if (k == n) 
		return 1;
	else if (k == 1) 
		return n;
	else 
		return cmb(n - 1, k - 1) + cmb(n - 1, k);
}

void dfs(int idx, int cnt)
{
	if (cnt == M) {
		tmp_cnt++;
		vector<int> st;
		vector<int> link;
		for (int i = 1; i <= N; i++) {
			if (sltd[i])
				st.push_back(i);
			else
				link.push_back(i);
		}

		int scr_st = 0;
		int scr_link = 0;

		for (int i = 0; i < st.size(); i++) {
			for (int j = 0; j < st.size(); j++) {
				if (i == j)
					continue;
				scr_st += rt[st[i]][st[j]];
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				if (i == j)
					continue;
				scr_link += rt[link[i]][link[j]];
			}
		}

		ans = min(ans, abs(scr_st-scr_link));
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (sltd[i])
			continue;
		if (tmp_cnt == tg_cnt/2)
			break;
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
	tg_cnt = cmb(N, M);
	dfs(1, 0);
	cout << ans << '\n';

	return 0;
}