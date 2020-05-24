/*
	@date 2020/05/25
	@author psunny0104
	@brief boj_10807_개수 세기
*/

#include <bits/stdc++.h>
using namespace std;

int arr[101];
int N, V, ans;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> V;

	for (int i = 0; i < N; i++) {
		if (arr[i] == V)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}