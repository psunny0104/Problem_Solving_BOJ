//	@date 2019/09/10
//	@author psunny0104
//	@brief boj_17144_미세먼지 안녕!

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int X, Y, T;
int map_og[51][51];
int map_cp[51][51];
vector<pair<int, int>> dust_list;
vector<pair<int, int>> cleaner_lc;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 ,0 };

void map_rn()
{
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			map_og[i][j] = map_cp[i][j];
		}
	}
}

void check_dust()
{
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			if (map_og[i][j] > 0)
				dust_list.push_back(make_pair(i, j));
		}
	}
}

void spread_dust()
{
	memset(map_cp, 0, sizeof(map_cp));
	for (int i = 0; i < cleaner_lc.size(); i++)
		map_cp[cleaner_lc[i].first][cleaner_lc[i].second] = -1;

	dust_list.clear();
	check_dust();
	int dust_cnt = dust_list.size();
	for (int i = 0; i < dust_cnt; i++) {
		int x = dust_list[i].second;
		int y = dust_list[i].first;
		int spread_cnt = 0;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 1 || ny<1 || nx>X || ny>Y)
				continue;
			if (map_og[ny][nx] == -1)
				continue;

			map_cp[ny][nx] += map_og[y][x] / 5;
			spread_cnt += 1;
		}
		map_cp[y][x] += map_og[y][x] - ((map_og[y][x] / 5) * spread_cnt);
	}

	map_rn();
}

void operate_cleaner()
{
	int one_x = cleaner_lc[0].second;
	int one_y = cleaner_lc[0].first;

	int two_x = cleaner_lc[1].second;
	int two_y = cleaner_lc[1].first;

	//위 청정기
	for (int j = 3; j <= X; j++) { // 동쪽
		map_cp[one_y][j] = map_og[one_y][j - 1];
	}
	for (int i = one_y - 1; i >= 1; i--) {// 북쪽
		map_cp[i][X] = map_og[i + 1][X];
	}
	for (int j = X - 1; j >= 1; j--) { //서쪽
		map_cp[1][j] = map_og[1][j + 1];
	}
	for (int i = 2; i <= one_y - 1; i++) {// 남쪽
		map_cp[i][one_x] = map_og[i - 1][one_x];
	}
	map_cp[one_y][2] = 0;

	//아래 청정기
	for (int j = 3; j <= X; j++) { // 동쪽
		map_cp[two_y][j] = map_og[two_y][j - 1];
	}
	for (int i = two_y + 1; i <= Y; i++) {// 남쪽
		map_cp[i][X] = map_og[i - 1][X];
	}
	for (int j = X - 1; j >= 1; j--) { //서쪽
		map_cp[Y][j] = map_og[Y][j + 1];
	}
	for (int i = Y - 1; i >= two_y + 1; i--) {// 북쪽
		map_cp[i][two_x] = map_og[i + 1][two_x];
	}
	map_cp[two_y][2] = 0;

	map_rn();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> T;

	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cin >> map_og[i][j];
			if (map_og[i][j] > 0)
				dust_list.push_back(make_pair(i, j));
			else if (map_og[i][j] == -1)
				cleaner_lc.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < T; i++) {
		spread_dust();
		operate_cleaner();
	}

	int ans = 0;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			ans += map_og[i][j];
		}
	}

	cout << ans + 2 << "\n";

	return 0;
}