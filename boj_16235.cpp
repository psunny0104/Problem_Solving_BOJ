//	@date 2019/09/17
//	@author psunny0104
//	@brief boj_16235_나무 재테크

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int feed_cur[11][11];
int feed[11][11];
vector<int> map[11][11];
vector<int> list_tree;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].empty())
				continue;

			sort(map[i][j].begin(), map[i][j].end());
			int num_tree = map[i][j].size();
			int summer = 0;
			list_tree.clear();

			for (int k = 0; k < num_tree; k++) {
				if (feed_cur[i][j] >= map[i][j][k]) {
					list_tree.push_back(map[i][j][k] + 1);
					feed_cur[i][j] -= map[i][j][k];

				}
				else {
					summer += map[i][j][k]/2;
				}
			}

			map[i][j].clear();
			for (int k = 0; k < list_tree.size(); k++) {
				map[i][j].push_back(list_tree[k]);
			}
			feed_cur[i][j] += summer;
		}
	}
}



void fall()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].empty())
				continue;
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] % 5 != 0)
					continue;

				int x = j;
				int y = i;

				for (int z = 0; z < 8; z++) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx > N || ny > N || nx < 1 || ny < 1)
						continue;
					
					map[ny][nx].push_back(1);
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			feed_cur[i][j] += feed[i][j];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			cin >> feed[i][j];
		}
	}

	int x, y, age;
	for (int i = 1; i <= M; i++) {
		cin >> y >> x >> age;
		map[y][x].push_back(age);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			feed_cur[i][j] = 5;
		}
	}

	for (int i = 0; i < K; i++) {
		spring();;
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += map[i][j].size();
		}
	}

	cout<<ans<<"\n";

	return 0;
}