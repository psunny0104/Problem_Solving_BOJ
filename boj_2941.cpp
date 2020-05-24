/*
	@date 2020/05/25
	@author psunny0104
	@brief boj_2941_크로아티아 알파벳
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	int ans = 0;

	cin >> input;
	int end = input.size();
	for (int i = 0; i<end; i++) {
		ans++;
		if (input[i] == 'c') {
			if (i + 1 >= end)
				continue;
			if (input[i + 1] == '=' || input[i + 1] == '-')
				ans -= 1;
		}
		else if (input[i] == 'd') {
			if (i + 1 >= end)
				continue;
			if (input[i + 1] == '-')
				ans -= 1;
			if (i + 2 >= end)
				continue;
			if (input[i + 1] == 'z' && input[i + 2] == '=')
				ans -= 2;
		}
		else if (input[i] == 'l' || input[i] == 'n') {
			if (i + 1 >= end)
				continue;
			if (input[i + 1] == 'j')
				ans -= 1;
		}
		else if (input[i] == 's' || input[i] == 'z') {
			if (i + 1 >= end)
				continue;
			if (input[i + 1] == '=') {
				ans -= 1;
				if (i - 1 >= 0 && input[i - 1] == 'd')
					ans += 1;
			}
		}
	}
	cout << ans << '\n';


	return 0;
}