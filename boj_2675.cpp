//	@date 2020/05/24
//	@author psunny0104
//	@brief boj_2675_문자열 반복

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int r;
		string str;
		cin >> r >> str;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < r; j++) {
				cout << str[i];
			}
		}
		cout << "\n";
	}

	return 0;
}