/*
	@date 2020/06/12
	@author psunny0104
	@brief boj_1012_유기농 배추
*/

#include <bits/stdc++.h>
using namespace std;

int T;
int Y, X, K;
int ans;
int maps[51][51];
int chk[51][51];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1, -1, 0,0 };

vector<pair<int, int>> v;

void bfs()
{
	queue<pair<int, int>> q;
	for (int t = 0; t < v.size(); t++) {
		if (chk[v[t].first][v[t].second] != 0)
			continue;

		q.push(make_pair(v[t].first, v[t].second));
		chk[q.front().first][q.front().second] = 1;
		ans++;

		while (!q.empty()) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (ny < 0 || nx < 0 || ny >= Y || nx >= X)
					continue;

				if (chk[ny][nx] != 0)
					continue;

				if (maps[ny][nx] == 1) {
					q.push(make_pair(ny, nx));
					chk[ny][nx] = 1;
				}
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		memset(chk, 0, sizeof(chk));
		memset(maps, 0, sizeof(maps));
		ans = 0;
		v.clear();

		cin >> X >> Y >> K;
		int t_x, t_y;

		for (int k = 0; k < K; k++) {
			cin >> t_x >> t_y;
			maps[t_y][t_x] = 1;
			v.push_back(make_pair(t_y, t_x));
		}

		bfs();
		cout << ans << "\n";
	}


	return 0;
}