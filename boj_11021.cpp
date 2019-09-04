//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_11021_A+B - 7

#include <cstdio>
using namespace std;

int main()
{
	int N = 0;
	int A = 0, B = 0;
	scanf("%d", &N);

	for(int i = 1; i<=N; i++){
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", i, A + B);
	}

	return 0;
}