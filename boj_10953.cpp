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
	//cin의 경우 입력받으면 True, 입력 받지 않으면 False를 return함을 이용
	while (N--) {
		scanf("%d,%d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}