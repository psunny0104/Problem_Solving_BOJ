/*
	@date 2020/05/28
	@author psunny0104
	@brief boj_4179_불!
*/

#include <bits/stdc++.h>
using namespace std;

int X, Y;
char maps[1001][1001];
int chk_fire[1001][1001];
int chk_jh[1001][1001];
pair<int, int> jh;
queue<pair<int, int> > q_fire;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void fire_bfs()
{
	queue<pair<int, int> > q_jh;
	q_jh.push(jh);
	chk_jh[jh.first][jh.second] = 1;
	
	chk_fire[q_fire.front().first][q_fire.front().second] = 1;

	while (!q_jh.empty()) {
		int cx = q_jh.front().second;
		int cy = q_jh.front().first;
		q_jh.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

		}
	}

}
int main()
{
	scanf("%d%d", &Y, &X);
	getchar();
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%1c", &maps[i][j]);
			if (maps[i][j] == 'J') {
				jh.first = i;
				jh.second = j;
			}
			else if (maps[i][j] == 'F')
				q_fire.push(make_pair(i, j));
		}
		getchar();
	}

	fire_bfs();

	return 0;
}