/*
	@date 2020/05/26
	@author psunny0104
	@brief boj_1697_숨바꼭질
*/

#include <bits/stdc++.h>
using namespace std;

int N, T;
int chk[100001];
int ans;

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	chk[x] = 1;

	while (!q.empty()) {
		int cx = q.front();
		q.pop();

		for (int k = 0; k < 3; k++) {
			int nx;
			if (k == 0)
				nx = cx + 1;
			else if (k == 1)
				nx = cx - 1;
			else
				nx = 2 * cx;

			if (nx < 0 || nx>100000)
				continue;

			if (chk[nx] != 0)
				continue;

			if (chk[nx] == 0) {
				q.push(nx);
				chk[nx] = chk[cx] + 1;
				if (nx == T) {
					ans = chk[nx]-1;
					return;
				}
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> T;

	bfs(N);

	cout << ans << '\n';

	return 0;
}