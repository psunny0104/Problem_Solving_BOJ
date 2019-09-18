//	@date 2019/09/18
//	@author psunny0104
//	@brief boj_9012_°ıÈ£

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	bool ans;

	while (T--) {
		ans = true;
		char input[51] = { '\0', };
		stack<char> s;
		cin >> input;
		for (int i = 0; i < 50; i++) {
			if (input[i] == '\0')
				break;
			if (input[i] == ')') {
				if (s.empty() || s.top() == ')') {
					ans = false;
					break;
				}
				else
					s.pop();
			}
			else
				s.push(input[i]);
		}
		if (!s.empty())
			ans = false;

		if (ans == true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}