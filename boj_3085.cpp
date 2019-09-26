//	@date 2019/09/26
//	@author psunny0104
//	@brief boj_3085_사탕 게임

#include <iostream>
#include <algorithm>
using namespace std;

char map[50][50];
int ans;

void check(int n)
{
	//가로 체크
	for (int i = 0; i < n; i++) {
		int cnt_r = 0;
		int cnt_tmp = 0;

		for (int j = 0; j < n-1; j++) {
			if (map[i][j] == map[i][j + 1])
				cnt_tmp++;
			else {
				if (cnt_tmp > cnt_r)
					cnt_r = cnt_tmp;
				cnt_tmp = 0;
			}
		}

		if (cnt_r == 0)
			cnt_r = cnt_tmp;
		
		if (cnt_r > ans)
			ans = cnt_r;
	}

	for (int j = 0; j < n; j++) {
		int cnt_c = 0;
		int cnt_tmp = 0;

		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j])
				cnt_tmp++;
			else {
				if (cnt_tmp > cnt_c)
					cnt_c = cnt_tmp;
				cnt_tmp = 0;
			}
		}
		if (cnt_c == 0)
			cnt_c = cnt_tmp;

		if (cnt_c > ans)
			ans = cnt_c;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
			cin >> map[i];
	}

	//아무 것도 안 바꾼 상태에서 ans 갱신
	check(N);

	//가로 바꾸기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j+1])
				continue;

			swap(map[i][j], map[i][j + 1]);
		
			check(N);
			
			swap(map[i][j], map[i][j + 1]);
		}
	}
	
	//세로 바꾸기
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (map[i][j] == map[i + 1][j])
				continue;

			swap(map[i][j], map[i + 1][j]);

			check(N);
				
			swap(map[i][j], map[i + 1][j]);
		}
	}

	if (ans != 0)
		ans++;

	cout << ans << '\n';

	return 0;
}