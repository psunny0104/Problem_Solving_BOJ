//	@date 2019/09/22
//	@author psunny0104
//	@brief boj_1463_1로 만들기

#include <iostream>
using namespace std;
int d[1000001];

//d[i] = i를 1로 만드는데 필요한 최소 연산 횟수
//d[i] = min(d[i/3]+1,d[i/2]+1,d[i-1]+1);
int dp(int n)
{
	if (n == 1)
		return 0;
	if (d[n] > 0)
		return d[n];

	d[n] = dp(n - 1)+ 1;

	if (n % 2 == 0) {
		int tmp = dp(n/2) + 1;
		if (d[n] > tmp)
			d[n] = tmp;
	}

	if (n % 3 == 0) {
		int tmp = dp(n/3) + 1;
		if (d[n]>tmp)
			d[n] = tmp;
	}

	return d[n];
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << dp(N) << '\n';

	return 0;
}