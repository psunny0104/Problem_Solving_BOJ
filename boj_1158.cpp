//	@date 2019/10/23
//	@author psunny0104
//	@brief boj_1158_조세퍼스 문제

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	queue<int> q;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int cnt = 1;
	cout << '<';
	while (!q.empty()) {
		if (cnt != K) {
			q.push(q.front());
			q.pop();
			cnt++;
			continue;
		}
		else {
			cout << q.front();
			if (q.size() != 1) {
				cout << ", ";
			}
			q.pop();
			cnt = 1;
		}
	}

	cout << '>';
	return 0;
}