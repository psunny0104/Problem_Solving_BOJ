//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_1913_달팽이

#include <iostream>
#include <vector>
using namespace std;

int map[1000][1000];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	//n=7 49, 25, 9, 1 
	//시작 위치 49부터 채우자
	
	int N, X; //(y,x)로 나타내기
	cin >> N >> X;

	//그룹 만들기
	vector<vector<int>> groups;
	for (int i = N; i >= 1; i -= 2) {
		int st = i * i;
		int ed = (i - 2) * (i - 2);
		vector<int> group;
		for (int k = st; k > ed; k--) {
			group.push_back(k);
		}
		//1은 별도로 그룹 만들어서 넣어줌
		if (st == 1 && ed == 1)
			group.push_back(1);
		groups.push_back(group);
	}

	//배열에 넣기
	int size = groups.size();
	for (int k = 1; k <= size; k++) {
		int st_x = k;
		int ed_x = N - k + 1;
		int st_y = k;
		int ed_y = N - k + 1;

		int grp_len = groups[k - 1].size();
		int cnt = 0;
		//왼쪽 변 cnt = (cnt + 1) % grp_len-> 1일 때 더 안 커지게 해줌
		for (int i = st_y; i <= ed_y; i++, cnt = (cnt + 1) % grp_len) {
			map[i][st_x] = groups[k - 1][cnt];
		}
		//아래쪽 변
		for (int j = st_x + 1; j <= ed_x - 1; j++, cnt = (cnt + 1) % grp_len) {
			map[ed_y][j] = groups[k - 1][cnt];
		}
		//오른쪽 변
		for (int i = ed_y; i >= st_y; i--, cnt = (cnt + 1) % grp_len) {
			map[i][ed_x] = groups[k - 1][cnt];
		}
		//위쪽 변
		for (int j = ed_x - 1; j >= st_x + 1; j--, cnt = (cnt + 1) % grp_len) {
			map[st_y][j] = groups[k - 1][cnt];
		}
	}
	//배열 출력
	int x = 0, y = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
			if (map[i][j] == X) {
				x = j;
				y = i;
			}
		}
		cout << '\n';
	}
	cout << y << ' ' << x << '\n';

	return 0;
}
