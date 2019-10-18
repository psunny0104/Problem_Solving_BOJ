//	@date 2019/10/18
//	@author psunny0104
//	@brief boj_16234_인구 이동

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N,L,R,ans;
int tmp_ans;
//다르고, 차이가 L<<x<<R
int map[101][101];
int map_og[101][101];
int chk[101][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void show()
{
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void cp()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = map_og[i][j];
		}
	}
}

void bfs(int i, int j)
{
	int y = i;
	int x = j;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	chk[y][x] = ans;

	int sum = map[y][x];
	int cnt = 1;

	while (!q.empty()) {
		int qx = q.front().second;
		int qy = q.front().first;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = qx + dx[k];
			int ny = qy + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (chk[ny][nx] == -1 || chk[ny][nx] >0)
				continue;

			int diff = abs(map[ny][nx] - map[qy][qx]);
			if (L <= diff && diff <= R) {
				q.push(make_pair(ny, nx));
				chk[ny][nx] = ans;
				sum += map[ny][nx];
				cnt++;
			}
		}
	}
	if (cnt <= 1) {
		chk[y][x] = -1;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chk[i][j] == ans) {
				map_og[i][j] = sum / cnt;
			}
		}
	}
	//cout << "계산 후";
	//show();
	ans++;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map_og[i][j] = map[i][j];
		}
	}
	
	ans = 1;
	tmp_ans = 0;
	int real_ans = 0;
	while (ans != tmp_ans) {
		tmp_ans = ans;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(chk[i][j] == 0)
					bfs(i, j);
			}
		}
		cp();
		memset(chk, 0, sizeof(chk));
		if (tmp_ans != ans)
			real_ans++;
	}
	
	cout << real_ans << '\n';
	return 0;
}
