/*
	@date 2020/06/01
	@author psunny0104
	@brief boj_1726_로봇
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int y;
	int x;
	int dir;
	int chk;
}ROBOT;

int X, Y;
int maps[101][101]; //값, 방향
int chk[101][101][5]; //x, 동, 서, 남, 북

ROBOT st;
ROBOT dst;

int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0 ,0,  1, -1 }; //x, 동, 서, 남, 북
int ans;

void bfs()
{
	queue<ROBOT> q;
	q.push({st.y,st.x,st.dir,st.chk});
	chk[st.y][st.x][st.dir] = 1;
	
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int c_dir = q.front().dir;
		int c_chk = q.front().chk;
		q.pop();
		
		if (cy == dst.y && cx == dst.x && c_dir == dst.dir) {
			ans = c_chk;
			return;
		}
		//같은 방향
		for (int k = 1; k <= 3; k++) {
			int nx = cx + (dx[c_dir] * k);
			int ny = cy + (dy[c_dir] * k);


			if (nx < 1 || ny < 1 || nx>X || ny>Y)
				continue;

			if (chk[ny][nx][c_dir] != 0)
				continue;

			if (maps[ny][nx] == 1)
				break;

			if (maps[ny][nx] == 0) {
				chk[ny][nx][c_dir] = 1;
				q.push({ ny,nx,c_dir,c_chk + 1 });
			}
		}

		//다른 방향
		//동, 서, 남, 북 1, 2, 3, 4
		for (int k = 1; k <= 4; k++) {
			if (k == c_dir)
				continue;

			if(chk[cy][cx][k] == false){
				if ((k + c_dir + 1) % 4 == 0) {
					chk[cy][cx][k] = 1;
					q.push({ cy,cx,k,c_chk + 2 });
				}
				else {
					chk[cy][cx][k] = 1;
					q.push({ cy,cx,k,c_chk + 1 });
				}
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cin >> maps[i][j];
		}
	}

	cin >> st.y >> st.x >> st.dir;
	cin >> dst.y >> dst.x >> dst.dir;

	bfs();

	cout << ans << "\n";

	return 0;
}