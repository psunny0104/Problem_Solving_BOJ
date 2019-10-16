//	@date 2019/10/17
//	@author psunny0104
//	@brief boj_14002_가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

//sq[n] = n번째 수열의 값
//dp[n][2] = [n][0] -> 1 ~ n까지의 원소로 만들 수 있는 가장 긴 증가하는 부분 수열의 길이
//			 [n][1] -> 이전 수열의 인덱스
//dp[n][0] = max(dp[x][0]+1, (1<=x<=n-1)) (sq[n]의 값이 sq[x]의 값보다 클때만 포함시킴)

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int sq[1001] = { 0, };
	int dp[1001][2] = { 0, };
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sq[i];
	}

	int ans = 1;
	//정답의 마지막 수열의 인덱스를 저장
	int idx_last = 1;
	for (int i = 1; i <= N; i++) {
		int tmp_len = 1;
		int tmp_idx = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (sq[i] > sq[j]) {
				if (tmp_len < dp[j][0] + 1) {
					tmp_len = dp[j][0] + 1;
					tmp_idx = j;
				}
			}
		}
		//[0]에 길이, [1]에 이전 수열의 인덱스 저장
		dp[i][0] = tmp_len;
		dp[i][1] = tmp_idx;
		if (tmp_len > ans) {
			ans = tmp_len;
			idx_last = i;
		}		
	}

	//스택을 이용해 수열의 뒤에서 부터 저장해감
	stack<int> s;
	
	//마지막 인덱스를 저장한 후에, 저장한 이전 인덱스 값을 갱신해가며 값 저장
	for(int i = 0; i<ans; i++){
		s.push(sq[idx_last]);
		idx_last = dp[idx_last][1];
	}

	cout << ans << '\n';
	while (!s.empty()) {
		cout << s.top()<<' ';
		s.pop();
	}

	return 0;
}