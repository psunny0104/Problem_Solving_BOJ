//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_2004_조합 0의 개수

#include <iostream>
using namespace std;

long long find_two(long long num)
{
	long long cnt_two = 0;
	for (long long i = 2; i <= num; i *= 2) {
		cnt_two += num / i;
	}
	return cnt_two;
}

long long find_five(long long num)
{
	long long cnt_five = 0;
	for (long long i = 5; i <= num; i *= 5) {
		cnt_five += num / i;
	}
	return cnt_five;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long N, M;
	cin >> N >> M;
	//N! / (N-M)!*M!

	long long two, five;
	two = find_two(N) - (find_two(N-M) + find_two(M));
	five = find_five(N) - (find_five(N - M) + find_five(M));
	
	if (two > five)
		cout << five << '\n';
	else
		cout << two << '\n';

	return 0;
}
