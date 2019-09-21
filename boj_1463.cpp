//	@date 2019/09/21
//	@author psunny0104
//	@brief boj_1463_1로 만들기

#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	d[1] = 0;
	
	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
			d[i] = d[i / 3] + 1;
	}

	cout << d[N] << '\n';

	return 0;
}