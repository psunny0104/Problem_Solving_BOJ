//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_10953_A+B - 6

#include<cstdio>
using namespace std;

int main()
{
	int N = 0;
	int A = 0, B = 0;
	scanf("%d", &N);
	//cin�� ��� �Է¹����� True, �Է� ���� ������ False�� return���� �̿�
	while (N--) {
		scanf("%d,%d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}