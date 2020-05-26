/*
	@date 2020/05/26
	@author psunny0104
	@brief boj_13913_숨바꼭질4
*/

#include <bits/stdc++.h>
using namespace std;

int N, T;
int chk[100001];
int step[100001];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	chk[x] = 1;

	while (!q.empty()) {
		int cx = q.front();
		q.pop();

		for (int k = 0; k < 3; k++) {
			int nx;
			if (k == 0)
				nx = cx + 1;
			else if (k == 1)
				nx = cx - 1;
			else
				nx = 2 * cx;

			if (nx < 0 || nx>100000)
				continue;

			if (chk[nx] != 0)
				continue;

			if (chk[nx] == 0) {
				q.push(nx);
				chk[nx] = chk[cx] + 1;
				step[nx] = cx;
				if (nx == T) {
					cout << chk[nx] - 1 << '\n';
					return;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> T;
	//같은 경우에 대한 예외처리로 해결
	//알고리즘을 다시 생각해서 풀어볼 필요 있음
	if (N == T) {
		cout << 0 << '\n';
		cout << N << '\n';
		return 0;
	}

	bfs(N);

	int idx = T;
	stack<int> s;
	s.push(T);
	while (true) {
		if (step[idx] == N) {
			s.push(N);
			break;
		}
		s.push(step[idx]);
		idx = step[idx];
	}
	
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}