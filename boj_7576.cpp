/*
	@date 2020/05/24
	@author psunny0104
	@brief boj_7576_토마토
*/

#include <bits/stdc++.h>
using namespace std;

int X, Y;
int maps[1001][1001];
int chk[1001][1001];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans;
vector<pair<int, int> > v;

void bfs()
{
	queue<pair<int, int> > q;
	for (int i = 0; i < v.size(); i++) {
		q.push(make_pair(v[i].first, v[i].second));
		chk[v[i].first][v[i].second] = 1;
	}

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;
			if (chk[ny][nx] != 0)
				continue;

			if (maps[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = chk[cy][cx] + 1;
				maps[ny][nx] = 1;
				if (chk[ny][nx] >= ans)
					ans = chk[ny][nx]-1;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> X >> Y;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 1)
				v.push_back(make_pair(i, j));
		}
	}

	bfs();

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (maps[i][j] == 0) {
				ans = -1;
				break;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}