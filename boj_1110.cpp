//	@date 2019/09/30
//	@author psunny0104
//	@brief boj_1110_더하기 사이클

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, OG, cnt = 0;
	cin >>OG;
	N = OG;
	while (true) {
		int first = (N % 10)* 10;
		int second = (N / 10 + N % 10) % 10;
		N = first + second;
		cnt++;
		if (N == OG)
			break;
	}
	cout << cnt << '\n';

	return 0;
}