//	@date 2019/10/25
//	@author psunny0104
//	@brief boj_9663_N-Queen

#include <iostream>
#include <algorithm>
using namespace std;

bool col[16];
bool inc[31];
bool des[31];
int N, ans;

//이미 놓은 열은 놓으면 안 됨
//왼대각, 오른대각 체크

void dfs(int row_cnt)
{
	if (row_cnt > N) {
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (col[i] || inc[row_cnt + i] || des[N + row_cnt - i])
			continue;
		col[i] = inc[row_cnt + i] = des[N + row_cnt - i] = 1;
		dfs(row_cnt + 1);
		col[i] = inc[row_cnt + i] = des[N + row_cnt - i] = 0;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	dfs(1);
	
	cout << ans << '\n';

	return 0;
}