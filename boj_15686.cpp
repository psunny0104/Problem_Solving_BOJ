//	@date 2019/10/18
//	@author psunny0104
//	@brief boj_15686_치킨 배달

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int>> list_ck;
vector<pair<int, int>> list_hm;
vector<int> list_dist;
vector<int> list_select;
int ans;

void dfs(int idx, int cnt, int size, int num)
{
	if (cnt == num) {
		for (int i = 0; i < list_dist.size(); i++) {
			list_dist[i] = 987654321;
		}
		for (int i = 0; i < list_select.size(); i++) {
			 //치킨 집 선택
			int k = list_select[i];
			for (int j = 0; j < list_hm.size(); j++) { //각 집과의 거리->각 집마다 최단거리 갱신
				int dist = abs(list_hm[j].first - list_ck[k].first) + abs(list_hm[j].second - list_ck[k].second);
				if (list_dist[j] > dist)
					list_dist[j] = dist;
			}
		
		}
		int sum_dist = 0;
		for (int i = 0; i < list_dist.size(); i++) {
			sum_dist += list_dist[i];
		}
		if (ans > sum_dist)
			ans = sum_dist;

		return;
	}

	for (int i = idx; i < size; i++) {
		list_select.push_back(i);
		dfs(i+1, cnt + 1, size, num);
		list_select.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int vl;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> vl;
			if (vl == 1)
				list_hm.push_back(make_pair(i, j));
			else if (vl == 2)
				list_ck.push_back(make_pair(i, j));
		}
	}

	int size_ck = list_ck.size();
	list_dist.resize(list_hm.size());
	ans = 987654321;

	for (int i = 1; i <= M; i++) {
		dfs(0, 0, size_ck, i);
	}

	cout << ans << '\n';

	return 0;
}