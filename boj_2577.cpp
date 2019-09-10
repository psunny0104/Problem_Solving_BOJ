//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_2577_숫자의 개수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, C, result;
	int cnt[10] = { 0, };
	
	cin >> A >> B >> C;
	result = A * B * C;

	while(result>0) {
		cnt[result % 10]++;
		result /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << "\n";
	}

	return 0;
}