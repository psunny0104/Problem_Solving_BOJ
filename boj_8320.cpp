/*
	@date 2020/05/26
	@author psunny0104
	@brief boj_8320_직사각형을 만드는 방법
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ans = 0;
	int N;
	cin >> N;
	
	ans += N;

	for (int i = 2; i <= N; i++) {
		if (i * i <= N) {
			for (int j = i * i; j <= N; j = j+i) { //4 <= 8
				if (j <= N)
					ans++;
			}
		}
	}
	
	cout << ans;

	return 0;
}