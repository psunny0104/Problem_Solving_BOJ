//	@date 2019/10/16
//	@author psunny0104
//	@brief boj_11053_가장 긴 증가하는 부분 수열

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//sq[n] = n번째 수열의 값
//dp[n]: 1 ~ n까지의 원소로 만들 수 있는 가장 긴 증가하는 부분 수열의 길이
//dp[n] = max(dp[x]+1, (1<=x<=n-1)) (sq[n]의 값이 sq[x]의 값보다 클때만 포함시킴)

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sq[1001] = { 0, };
	int dp[1001];
	int N;
	cin >> N;
	//sq에 입력 저장
	for (int i = 1; i <= N; i++) {
		cin >> sq[i];
	}

	int ans = 0;
	//1~N까지의 가장 긴 증가하는 부분 수열 구함
	for (int i = 1; i <= N; i++) {
		//1개면 1이므로 값 1로 초기화
		int tmp = 1;
		//1 ~ n-1까지의 원소 중 n보다 작으면,
		//+1 하여 기존의 가장 긴 길이보다 길면 갱신
		for (int j = 1; j <= i - 1; j++) {
			if (sq[i] > sq[j]) {
				if(dp[j]+1>tmp)
					tmp = dp[j] + 1;
			}
		}
		dp[i] = tmp;
		//답을 위해 ans 갱신
		if (dp[i] > ans)
			ans = dp[i];
	}

	cout << ans << '\n';

	return 0;
}