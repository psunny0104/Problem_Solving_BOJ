//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_16926_배열 돌리기 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//y,x 중 작은 것을 2로 나눈 나머지는 0
int Y, X, R;
int map[301][301];

void show()
{
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cout << map[i][j];
			//if (j != X)
			cout << ' ';
		}
		cout << '\n';
	}
}

//복사를 매 번 말고 한 번만 하게->그룹으로!
void rotate()
{
	int num_box = min(Y, X) / 2;
	for (int k = 1; k <= num_box; k++) {
		//그룹 만들기
		int dist_max = (Y - 2 * k + 1) * 2 + (X - 2 * k + 1) * 2;
		int dist_rest = R % dist_max;

		int y_st = k;
		int y_ed = Y - k + 1;//2~4
		int x_st = k;
		int x_ed = X - k + 1;
		vector<int> grp;

		//위쪽 변
		for (int j = x_st; j <= x_ed; j++) {
			grp.push_back(map[y_st][j]);
		}
		//오른쪽 변
		for (int i = y_st+1; i <= y_ed - 1; i++) {
			grp.push_back(map[i][x_ed]);
		}
		//아래쪽 변
		for (int j = x_ed; j >= x_st; j--) {
			grp.push_back(map[y_ed][j]);
		}
		//왼쪽 변
		for (int i = y_ed-1; i >= y_st+1; i--) {
			grp.push_back(map[i][x_st]);
		}

		//돌려서 넣기
		//위쪽 변
		for (int j = x_st; j <= x_ed; j++, dist_rest = (dist_rest + 1) % dist_max) {
			map[y_st][j] = grp[dist_rest];
		}
		//오른쪽 변
		for (int i = y_st + 1; i <= y_ed - 1; i++, dist_rest = (dist_rest + 1) % dist_max) {
			map[i][x_ed] = grp[dist_rest];
		}
		//아래쪽 변
		for (int j = x_ed; j >= x_st; j--, dist_rest = (dist_rest + 1) % dist_max) {
			map[y_ed][j] = grp[dist_rest];
		}
		//왼쪽 변
		for (int i = y_ed - 1; i >= y_st + 1; i--, dist_rest = (dist_rest + 1) % dist_max) {
			map[i][x_st] = grp[dist_rest];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> R;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cin >> map[i][j];
		}
	}

	rotate();

	//cout << '\n';
	show();
	return 0;
}