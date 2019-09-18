//	@date 2019/09/18
//	@author psunny0104
//	@brief boj_1874_스택 수열

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> q;
	while (N--) {
		int input;
		cin >> input;
		q.push(input);
	}
	
	string ans;
	stack<int> s;
	int num = 0;

	while (1)
	{
		if (q.empty()) {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << '\n';
			}
			break;
		}
		if (s.empty()) {
			s.push(++num);
			ans += '+';
		}
		if (s.top() <= q.front()) {
			while (s.top() < q.front()) {
				s.push(++num);
				ans += '+';
			}
			if (s.top() == q.front()) {
				s.pop();
				q.pop();
				ans += '-';
			}
		}
		else if(s.top() > q.front()) {
			cout << "NO" << '\n';
			break;
		}
	}

	return 0;
}