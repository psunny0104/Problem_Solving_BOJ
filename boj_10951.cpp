//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_10951_A+B - 4

#include<iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A = 0, B = 0;
	//cin�� ��� �Է¹����� True, �Է� ���� ������ False�� return���� �̿�
	while (cin >> A >> B) { 
		cout << A + B << "\n";
	}

	return 0;
}