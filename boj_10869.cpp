//	@date 2019/11/07
//	@author psunny0104
//	@brief boj_10869_사칙연산

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;
	
	int arr[5];
	arr[0] = A + B;
	arr[1] = A - B;
	arr[2] = A * B;
	arr[3] = A / B;
	arr[4] = A % B;

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}