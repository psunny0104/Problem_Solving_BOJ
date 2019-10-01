//	@date 2019/10/01
//	@author psunny0104
//	@brief boj_3047_ABC

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int one, two, three;
	int A = 0, B = 0, C = 0;
	cin >> one >> two >> three;
	//A<<B<<C
	if (one > two) {
		if (two > three) {
			C = one;
			B = two;
			A = three;
		}
		else {
			if (three > one) {
				C = three;
				B = one;
			}
			else {
				C = one;
				B = three;
			}
			A = two;
		}
	}
	else if(two > one) {
		if (one > three) {
			C = two;
			B = one;
			A = three;
		}
		else {
			if (three > two) {
				C = three;
				B = two;
			}
			else {
				C = two;
				B = three;
			}
			A = one;
		}
	}

	char arr[4];
	cin >> arr;
	for (int i = 0; i < 3; i++) {
		if (arr[i] == 'A')
			cout << A << ' ';
		else if (arr[i] == 'B')
			cout << B << ' ';
		else if(arr[i] == 'C')
			cout << C << ' ';
	}

	return 0;
}