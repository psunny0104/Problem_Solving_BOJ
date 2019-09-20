//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_1676_팩토리얼 0의 개수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 5; j <= N; j *= 5) {
			if (i % j == 0)
				ans++;
		}
	}

	/*
	for(int i = 5; i<=N; i *= 5){
		ans += n/i;
	}
	*/

	cout << ans << '\n';

	return 0;
}
