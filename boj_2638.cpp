/*
	@date 2020/05/26
	@author psunny0104
	@brief boj_2638_치즈
*/

#include <bits/stdc++.h>
using namespace std;

int Y, X;
int maps[101][101];
int chk[101][101];
int dx[] = { 0, 0, 1, -1 }; //북, 남, 동, 서
int dy[] = { 1, -1, 0, 0, };

void bfs(int y, int x)
{
	queue<pair<int, int> >q;
	q.push(make_pair(y, x));
	chk[y][x] = 1;

	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			if (maps[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = 1;
			}
			else if (maps[ny][nx] >= 1) {
				maps[ny][nx]++;
			}
		}
	}
}

bool chk_dir()
{
	int ch_cnt = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (maps[i][j] == 1)
				ch_cnt++;
			else if (maps[i][j] == 2) {
				ch_cnt++;
				maps[i][j] = 1;
			}
			else if (maps[i][j] >= 3) {
				maps[i][j] = 0;
			}
		}
	}

	if (ch_cnt == 0)
		return true;
	else
		return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> maps[i][j];
		}
	}
	
	int ans = 0;
	while (true) {
		bfs(0, 0);
		ans++;
		if (chk_dir()) {
			cout << ans << "\n";
			break;
		}
		memset(chk, 0, sizeof(chk));
	}

	return 0;
}