/*
	@date 2020/06/08
	@author psunny0104
	@brief boj_7562_나이트의 이동
*/

#include <bits/stdc++.h>
using namespace std;

int chk[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
queue<int> ans;
void bfs(int& cy, int& cx, int fy, int fx, int length)
{
	queue<pair<int, int> > q;
	q.push(make_pair(cy, cx));
	chk[cy][cx] = 1;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		if (y == fy && x == fx) {
			ans.push(chk[y][x] - 1);
			break;
		}

		for (int k = 0; k < 8; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= length || nx >= length)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			q.push(make_pair(ny, nx));
			chk[ny][nx] = chk[y][x] + 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(chk, 0, sizeof(chk));
		int length;
		cin >> length;
		int cx, cy, fx, fy;
		cin >> cy >> cx >> fy >> fx;

		bfs(cy, cx, fy, fx, length);
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}

	return 0;
}