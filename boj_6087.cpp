/*
	@date 2020/06/01
	@author psunny0104
	@brief boj_6087_레이저 통신
*/

#include <bits/stdc++.h>
using namespace std;

int Y, X;
char maps[101][101];
int chk[101][101];

vector<pair<int, int> > crds;
vector<int> ans;
int dx[] = { 0, 0, 0, 1, -1 }; //남, 북, 동, 서
int dy[] = { 0, 1, -1 ,0, 0 };

typedef struct {
	int y;
	int x;
	int dir;
	int mr;
}ITEM;

void bfs()
{
	queue<ITEM> q;
	q.push({crds[0].first, crds[0].second, 0, 0});
	chk[crds[0].first][crds[0].second] = 1;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int c_dir = q.front().dir;
		int c_mr = q.front().mr;
		q.pop();

		for (int k = 1; k <= 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			
			while (0 <=nx && nx < X && 0 <= ny && ny < Y && maps[ny][nx] != '*') {
				if (chk[ny][nx] == 0) {
					if (maps[ny][nx] == '.') {
						chk[ny][nx] = chk[ny][nx] + 1;
						if (c_dir == 0 || c_dir == k)
							q.push({ ny,nx,k, c_mr });
						else
							q.push({ ny,nx,k,c_mr + 1 });
					}
					else if (maps[ny][nx] == 'C') {
						if (c_dir == 0 || c_dir == k)
							ans.push_back(c_mr);
						else
							ans.push_back(c_mr+1);
					}
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
}

int main()
{
	scanf("%d %d", &X, &Y);
	getchar();
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			scanf("%1c", &maps[i][j]);
			if (maps[i][j] == 'C')
				crds.push_back(make_pair(i, j));
		}
		getchar();
	}

	bfs();

	sort(ans.begin(), ans.end());

	printf("%d\n", ans[0]);

	return 0;
}