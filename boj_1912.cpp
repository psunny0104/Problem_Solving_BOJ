//	@date 2019/10/17
//	@author psunny0104
//	@brief boj_1912_연속합

#include <iostream>
#include <algorithm>
using namespace std;

//dp[n] : 1 ~ n까지의 수 중 연속된 수를 선택해서 구할 수 있는 최대의 합
//sq[n] : 수열의 n번째 값
//dp[n] = max(dp[i-1]+sq[n],sq[n])

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int dp[100001] = { 0, };
	int sq[100001] = { 0, };
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sq[i];
	}
	//초기화
	int ans = dp[1] = sq[1];

	//이전까지의 최대값에 이번 수열의 값을 더했을 떄와
	//이번 수열의 값을 비교하여 더 큰값을 dp 배열에 저장
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 1] + sq[i], sq[i]);
		ans = max(ans,dp[i]);
	}

	cout << ans << '\n';

	return 0;
}