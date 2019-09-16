//	@date 2019/09/16
//	@author psunny0104
//	@brief boj_3052_³ª¸ÓÁö

#include <iostream>
#define FT 42
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt[42] = { 0, };
	int input = 0;
	int ans = 0;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		if (cnt[input % FT] == 0) {
			cnt[input % FT]++;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}