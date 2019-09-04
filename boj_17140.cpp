//	@date 2019/09/05
//	@author psunny0104
//	@brief boj_17140_이차원 배열과 연산

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int R, C, K;
int cur_r, cur_c;
int map[101][101];
int cnt[101];

priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void print()
{
	cout << "\n";
	for (int i = 1; i <= cur_r; i++) {
		for (int j = 1; j <= cur_c; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void opr()
{
	int tmp_c = cur_c; //열, x
	int tmp_r = cur_r; //행, y
	//cout << tmp_c << "\n" << tmp_r << "\n";
	if (cur_r >= cur_c) {
		for (int i = 1; i <= tmp_r; i++) {
			memset(cnt, 0, sizeof(cnt));
			for (int j = 1; j <= tmp_c; j++) {
				int val = map[i][j];
				cnt[val]++;
			}
			for (int j = 1; j <= 100; j++) {
				if (!cnt[j])
					continue;
				pq.push(make_pair(cnt[j], j)); //등장횟수, 숫자
			}

			int size_pq = pq.size();
			if (size_pq * 2 > cur_c)
				cur_c = size_pq * 2;
			for (int j = 1; j <= cur_c; j++)
				map[i][j] = -1;
			for (int j = 1; j <= size_pq*2 - 1; j+=2) {
				if (j > 50)
					break;
				map[i][j] = pq.top().second;
				map[i][j + 1] = pq.top().first;
				pq.pop();
			}
		}
		for (int i = 1; i <= cur_r; i++) {
			for (int j = 1; j <= cur_c; j++) {
				if (map[i][j] == -1)
					map[i][j] = 0;
			}
		}
		//print();
	}
	else {
		for (int i = 1; i <= tmp_c; i++) {
			memset(cnt, 0, sizeof(cnt));
			for (int j = 1; j <= tmp_r; j++) {
				int val = map[j][i];
				cnt[val]++;
			}
			for (int j = 1; j <= 100; j++) {
				if (!cnt[j])
					continue;
				pq.push(make_pair(cnt[j], j)); //등장횟수, 숫자
			}

			int size_pq = pq.size();
			if (size_pq * 2 > cur_r)
				cur_r = size_pq * 2;
			for (int j = 1; j <= cur_r; j++)
				map[j][i] = -1;
			for (int j = 1; j <= size_pq * 2 - 1; j += 2) {
				if (j > 50)
					break;
				map[j][i] = pq.top().second;
				map[j+1][i] = pq.top().first;
				pq.pop();
			}
		}
		for (int i = 1; i <= cur_r; i++) {
			for (int j = 1; j <= cur_c; j++) {
				if (map[i][j] == -1)
					map[i][j] = 0;
			}
		}
		//print();
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >>C >> K;
	memset(map, -1, sizeof(map));
	
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	
	cur_r = 3, cur_c = 3;
	int ans = 0;
	while (map[R][C] != K) {//체크
		if (ans == 100) {
			ans = -1;
			break;
		}
		ans++;
		//연산
		opr();
		//다시 넣기
	}

	cout << ans << "\n";
	return 0;
}