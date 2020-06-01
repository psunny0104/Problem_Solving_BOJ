/*
	@date 2020/06/01
	@author psunny0104
	@brief boj_14502_연구소	
*/

#include <bits/stdc++.h>
using namespace std;

int Y, X;
int maps[9][9];
int maps_cp[9][9];
int chk[9][9];
bool selected[82];
vector<pair<int, int>> site;
vector<pair<int, int>> virus;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans;

void check()
{
	int cnt = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (maps_cp[i][j] == 0)
				cnt++;
		}
	}
	if (cnt >= ans)
		ans = cnt;
}

void copy()
{
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			maps_cp[i][j] = maps[i][j];
		}
	}
}

void cmb(int idx, int cnt)
{
	if (cnt == 3) {
		memset(maps_cp, 0, sizeof(maps_cp));
		memset(chk, 0, sizeof(chk));
		copy();
		for (int k = 0; k < site.size(); k++) {
			if (selected[k] == false)
				continue;
			maps_cp[site[k].first][site[k].second] = 1;
		}
		
		queue<pair<int, int>> q;
		for (int k = 0; k < virus.size(); k++) {
			q.push(make_pair(virus[k].first, virus[k].second));
			chk[virus[k].first][virus[k].second] = 1;
		}

		while (!q.empty()) {
			int cx = q.front().second;
			int cy = q.front().first;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (nx < 0 || ny<0 || nx >= X || ny >= Y)
					continue;

				if (chk[ny][nx] != 0)
					continue;

				if (maps_cp[ny][nx] == 0) {
					chk[ny][nx] = 1;
					maps_cp[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
		check();

		return;
	}

	for (int k = idx; k < site.size(); k++) {
		if (selected[k] == true)
			continue;

		selected[k] = true;
		cmb(k, cnt + 1);
		selected[k] = false;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> Y >> X;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 0)
				site.push_back(make_pair(i, j));
			else if (maps[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	cmb(0, 0);

	cout << ans << "\n";

	return 0;
}