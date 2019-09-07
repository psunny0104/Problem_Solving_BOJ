//	@date 2019/09/07
//	@author psunny0104
//	@brief boj_11720_숫자의 합

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	char input[101]; //문자열로 input받음
	cin >>N>>input;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += input[i] - '0';//한 글짜씩 숫자로 변환 후 sum에 더함
	}
	cout << sum << "\n";

	return 0;
}