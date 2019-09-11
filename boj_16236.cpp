//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_16236_아기 상어

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[21][21];
int dist[21][21];
int time;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1, 0, 0 };

struct SHARK{
	int x;
	int y;
	int size = 2;
	int cnt = 0;
	int cnt_level = 2;
} sk;

void bfs(int y, int x)
{
	memset(dist, 0, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 1;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;
			if (dist[ny][nx] > 0)
				continue;
			if (map[ny][nx] > sk.size)
				continue;
			
			if (map[ny][nx] >= 0) {
				dist[ny][nx] += dist[y][x]+1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

bool select_feed()
{
	int min_x = 0, min_y = 0, min_val = 401;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] > 0 && sk.size>map[i][j]) {
				if (dist[i][j] > 1 && dist[i][j] < min_val) {
					min_x = j;
					min_y = i;
					min_val = dist[i][j];
				}
			}
		}
	}
	if (min_val == 401)
		return 0;

	sk.x = min_x;
	sk.y = min_y;
	sk.cnt++;
	map[sk.y][sk.x] = 0;
	time += dist[min_y][min_x] - 1;
	
	if (sk.cnt == sk.cnt_level) {
		sk.cnt_level++;
		sk.cnt = 0;
		sk.size = sk.cnt_level;
	}
	return 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sk.x = j;
				sk.y = i;
			}
		}
	}

	bool flag = false;
	map[sk.y][sk.x] = 0;

	while (1) {
		bfs(sk.y, sk.x);
		flag = select_feed();
		if (!flag)
			break;
	}
	
	cout << time << "\n";

	return 0;
}