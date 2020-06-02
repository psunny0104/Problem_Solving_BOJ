/*
	@date 2020/06/02
	@author psunny0104
	@brief boj_14226_이모티콘
*/

#include <bits/stdc++.h>
using namespace std;

int N;

int chk[2002][2002]; //화면, 클립보드
int ans;

void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(1, 0));
	chk[1][0] = 1;

	while (!q.empty()) {
		int dis = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (dis == N) {
			ans = chk[dis][clip]-1;
			return;
		}
		int dx[] = { dis,dis + clip,dis - 1 };
		int dy[] = { dis, clip, clip };

		for (int k = 0; k < 3; k++) {
			if (dx[k] < 0)
				continue;
			if (dx[k] > 2000 || dy[k] > 2000)
				continue;

			if (chk[dx[k]][dy[k]] != 0)
				continue;

			q.push(make_pair(dx[k], dy[k]));
			chk[dx[k]][dy[k]] = chk[dis][clip] + 1;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	bfs();

	cout << ans << "\n";

	return 0;
}