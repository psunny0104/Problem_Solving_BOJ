/*
	@date 2020/06/08
	@author psunny0104
	@brief boj_1260_DFS와 BFS
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, V;
bool chk[1001];
bool dhk[1001];
vector<pair<int, int> > v;

void dfs(int x) {
	if (dhk[x] == true)
		return;
	else {
		dhk[x] = true;
		cout << x << " ";
		for (int k = 0; k < v.size(); k++) {
			if (v[k].first != x)
				continue;

			int nx = v[k].second;

			if (nx<1 || nx>N)
				continue;

			if (dhk[nx] == true)
				continue;

			dfs(nx);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> V;
	
	int one, two;
	for (int i = 0; i < M; i++) {
		cin >> one >> two;
		v.push_back(make_pair(one, two));
		v.push_back(make_pair(two, one));
	}

	//dfs_재귀 이용
	sort(v.begin(), v.end());
	dfs(V);

	//dfS_스택 이용
	/* 
	reverse(v.begin(), v.end());
	stack<int> s;
	s.push(V);

	while (!s.empty()) {
		int x = s.top();
		s.pop();
		if (dhk[x] == true)
			continue;

		dhk[x] = true;

		cout << x << " ";
		for (int k = 0; k < v.size(); k++) {
			if (v[k].first != x)
				continue;

			int nx = v[k].second;

			if (nx<1 || nx>N)
				continue;

			if (dhk[nx] == true)
				continue;

			s.push(nx);

			//break;
		}
	}
	*/
	cout << "\n";

	//bfs
	sort(v.begin(), v.end());
	queue<int> q;
	q.push(V);
	chk[V] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		cout << x << " ";
		for (int k = 0; k < v.size(); k++) {
			if (v[k].first != x)
				continue;

			int nx = v[k].second;

			if (nx<1 || nx>N)
				continue;

			if (chk[nx] == true)
				continue;

			chk[nx] = true;
			q.push(nx);
		}
	}

	return 0;
}