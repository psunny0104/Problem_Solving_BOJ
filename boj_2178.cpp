//	@date 2020/05/23
//	@author psunny0104
//	@brief boj_2178_미로 탐색

#include <bits/stdc++.h>
using namespace std;

int X, Y;
int maps[101][101];
int chk[101][101];
int dx[] = { 0, 0 ,1 , -1 };
int dy[] = { 1, -1, 0, 0, };
int ans;

void bfs(int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	chk[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			if (maps[ny][nx] == 1) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = chk[cy][cx] + 1;
				if (ny == Y-1 && nx == X-1) {
					ans = chk[ny][nx];
					return;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d", &Y, &X);

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%1d", &maps[i][j]);
		}
		getchar();
	}

	bfs(0, 0);

	cout << ans;

	return 0;
}