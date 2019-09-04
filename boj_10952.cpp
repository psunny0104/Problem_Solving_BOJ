//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_10952_A+B - 5

#include<iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A = 0, B = 0;
	//cin의 경우 입력받으면 True, 입력 받지 않으면 False를 return함을 이용
	while (cin >> A >> B) {
		if (A == 0 && B == 0)
			break;
		cout << A + B << "\n";
	}

	return 0;
}