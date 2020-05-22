//	@date 2020/05/22
//	@author psunny0104
//	@brief boj_1926_±×¸²

#include <bits/stdc++.h>
using namespace std;

int area;
int cnt;
int Y, X;

int in[501][501];
int chk[501][501];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void bfs(int i, int j)
{
	queue<pair<int, int> > q;
	q.push(make_pair(i,j));
	int innerCnt = 1;
	chk[i][j] = innerCnt;
	cnt++;
	if (area == 0)
		area = 1;

	while(!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y)
				continue;

			if (chk[ny][nx] > 0)
				continue;

			if (in[ny][nx] == 1 && chk[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = ++innerCnt;
				if (innerCnt >= area)
					area = innerCnt;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> in[i][j];
		}
	}

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (chk[i][j] != 0)
				continue;
			if (in[i][j] == 0)
				continue;
			bfs(i, j);
		}
	}

	cout << cnt << "\n" << area;

	return 0;
}