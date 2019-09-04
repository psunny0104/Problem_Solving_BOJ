//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_10951_A+B - 4

#include <stdio.h>

int main()
{
	int A = 0, B = 0;
	//printf의 경우 입력받은 변수의 개수를 리턴함
	while (scanf("%d %d",&A, &B) == 2) {
		printf("%d\n", A + B);
	}

	return 0;
}