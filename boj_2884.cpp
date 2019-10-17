//	@date 2019/10/17
//	@author psunny0104
//	@brief boj_2884_알람 시계

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int H, M;
	cin >> H >> M;

	if (M >= 45) {
		cout << H << ' ' << M - 45 << '\n';
	}
	else {
		if (H == 0)
			cout << 23 << ' ' << 60 + M - 45 << '\n';
		else
			cout << H - 1 << ' ' << 60 + M - 45 << '\n';
	}

	return 0;
}