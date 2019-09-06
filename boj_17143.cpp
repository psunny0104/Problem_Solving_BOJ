//	@date 2019/09/05
//	@author psunny0104
//	@brief boj_17143_낚시왕

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct SK {
	int spd;
	int dir;
	int size;
	int y;
	int x;
	bool death = true; //false면 죽음
} sk[100 * 100 + 1]; //sk[100*100]...........

int Y, X, M, ans;

int dx[] = { 0, 0, 0, +1, -1 }; //제자리, 위, 아래, 오, 왼
int dy[] = { 0, -1, +1, 0, 0 };

int st[101][101];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> M;
	for (int i = 1; i <= M; i++) {//x, y,속력,이동방향,크기
		cin >> sk[i].y >> sk[i].x >> sk[i].spd >> sk[i].dir >> sk[i].size;
	}

	int nsw = 0;
	while (1)
	{
		nsw++;
		if (nsw > X)
			break;
		int idx = 0;
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death)
				continue;

			if (sk[i].x == nsw) {
				if (idx == 0)
					idx = i;
				else {
					if (sk[i].y < sk[idx].y) //같은 칸에 있는 경우 없음
						idx = i;
				}
			}
		}

		if (idx != 0) {
			sk[idx].death = false;
			ans += sk[idx].size;
		}

		for (int i = 1; i <= M; i++) {
			if (!sk[i].death)
				continue;
			int step = sk[i].spd;
			while (1) {
				if (step == 0)
					break;
				if (sk[i].dir == 1) {
					if (step <= sk[i].y - 1) {
						sk[i].y -= step;
						step = 0;
					}
					else {
						step = step - (sk[i].y - 1);
						sk[i].y = 1;
						sk[i].dir = 2;
					}
				}
				else if (sk[i].dir == 2) {
					if (step <= Y - sk[i].y) {
						sk[i].y += step;
						step = 0;
					}
					else {
						step = step - (Y - sk[i].y);
						sk[i].y = Y;
						sk[i].dir = 1;
					}
				}
				else if (sk[i].dir == 3) {
					if (step <= X - sk[i].x) {
						sk[i].x += step;
						step = 0;
					}
					else {
						step = step - (X - sk[i].x);
						sk[i].x = X;
						sk[i].dir = 4;
					}
				}
				else if (sk[i].dir == 4) {
					if (step <= sk[i].x - 1) {
						sk[i].x -= step;
						step = 0;
					}
					else {
						step = step - (sk[i].x - 1);
						sk[i].x = 1;
						sk[i].dir = 3;
					}
				}
			}
		}

		memset(st, 0, sizeof(st));
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death)
				continue;

			int tmp_y = sk[i].y;
			int tmp_x = sk[i].x;
			if (!st[tmp_y][tmp_x])
				st[tmp_y][tmp_x] = i;
			else if (st[tmp_y][tmp_x] != 0) {
				if (sk[st[tmp_y][tmp_x]].size < sk[i].size) {
					sk[st[tmp_y][tmp_x]].death = false;
					st[tmp_y][tmp_x] = i;
				}
				else
					sk[i].death = false;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}