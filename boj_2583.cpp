/*
	@date 2020/05/26
	@author psunny0104
	@brief boj_2583_영역 구하기
*/

#include <bits/stdc++.h>
using namespace std;

int X, Y, K;
int maps[101][101];
int chk[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int cnt;
vector<int> v;

void bfs(int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	chk[y][x] = 1;
	int inner_ans = 1;
	cnt++;
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx < 0 || ny < 0 || nx >= Y || ny >= X)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			if (maps[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = chk[cy][cx] + 1;
				inner_ans++;
			}
		}
	}
	v.push_back(inner_ans);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> K;
	
	int lx, ly, rx, ry;
	for (int k = 0; k < K; k++) {
		cin >> lx >> ly >> rx >> ry;
		for (int i = lx; i < rx; i++) {
			for (int j = ly; j < ry; j++) {
				maps[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (maps[i][j] == 1)
				continue;
			if (chk[i][j] == 0)
				bfs(i, j);
		}
	}
	
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int z = 0; z < v.size(); z++) {
		cout << v[z] << ' ';

	}
	return 0;
}