/*
	@date 2020/06/02
	@author psunny0104
	@brief boj_16946_벽 부수고 이동하기 4
*/

#include <bits/stdc++.h>
using namespace std;

int Y, X;
int maps[1001][1001];
int chk[1001][1001];
int ans[1001][1001];

vector<pair<int, int>> wall;
vector<int> blood;
int idx = 1;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	chk[y][x] = idx;
	int cnt = 1;

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			if (maps[ny][nx] == 0) {
				chk[ny][nx] = idx;
				q.push(make_pair(ny, nx));
				cnt++;
			}
		}
	}
	idx++;
	blood.push_back(cnt);
}

void destroy()
{
	for (int t = 0; t < wall.size(); t++) {
		int cy = wall[t].first;
		int cx = wall[t].second;

		set<int> s;

		for (int k = 0; k < 4; k++) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;

			if (chk[ny][nx] > 0) {
				s.insert(chk[ny][nx]);
			}
		}

		set<int>::iterator iter;

		int cnt = 1;
		for (iter = s.begin(); iter != s.end(); iter++) {
			cnt += blood[*iter];
		}
		ans[cy][cx] = cnt % 10;
	}
}
int main()
{
	scanf("%d %d", &Y, &X);
	getchar();
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%1d", &maps[i][j]);
			if (maps[i][j] == 1)
				wall.push_back(make_pair(i, j));
		}
		getchar();
	}

	blood.push_back(0);

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (chk[i][j] == 0 && maps[i][j] == 0)
				bfs(i, j);
		}
	}

	destroy();

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			printf("%1d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}