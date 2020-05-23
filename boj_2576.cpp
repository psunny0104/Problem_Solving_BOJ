//	@date 2020/05/24
//	@author psunny0104
//	@brief boj_2576_홀수

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		int tmp = 0;
		cin >> tmp;
		if (tmp % 2 != 0) {
			sum += tmp;
			v.push_back(tmp);
		}
	}
	if (v.empty()) {
		cout << -1;
	}
	else {
		sort(v.begin(), v.end());
		cout << sum << "\n" << v[0];
	}

	return 0;
}