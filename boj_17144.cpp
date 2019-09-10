//	@date 2019/09/10
//	@author psunny0104
//	@brief boj_17144_미세먼지 안녕!

#include <iostream>
#include <vector>
using namespace std;

int X, Y, T;
int map_og[51][51]; //저장과 계산을 위한 지도
vector<pair<int, int>> cleaner_lc; //청정기 위치 저장

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 ,0 };

void spread_dust() //미세먼지 확산
{
	int map_cp[51][51] = { 0, }; //동시확산을 위해 따로 계산을 위한 배열 만듬, 0으로 초기화
	for (int i = 0; i < cleaner_lc.size(); i++) //청정기 표시
		map_cp[cleaner_lc[i].first][cleaner_lc[i].second] = -1;

	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			if (map_og[i][j] > 0) { //지도를 돌면서 미세먼지값이 존재하면
				int x = j;
				int y = i;
				int spread_cnt = 0; //확산 횟수 계산 변수

				for (int k = 0; k < 4; k++) { //4방향으로 확산시킴
					int nx = x + dx[k]; 
					int ny = y + dy[k];

					if (nx < 1 || ny<1 || nx>X || ny>Y) //범위 벗어나면 확산 X
						continue;
					if (map_og[ny][nx] == -1) //청정기이면 확산 X
						continue;

					map_cp[ny][nx] += map_og[y][x] / 5; //미세먼지 확산
					spread_cnt += 1; //확산 횟수 계산
				}
				//동시 확산을 위해 0으로 초기화 해준 후 계산해서 나오는 값들을 계속 더함
				map_cp[y][x] += map_og[y][x] - ((map_og[y][x] / 5) * spread_cnt); //
			}
		}
	}
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			map_og[i][j] = map_cp[i][j]; //원본 지도 배열로 복사
		}
	}
}

void operate_cleaner() //청정기 실행
{
	int one_x = cleaner_lc[0].second; //첫번째 청정기 x좌표
	int one_y = cleaner_lc[0].first;  //첫번째 청정기 y좌표

	int two_x = cleaner_lc[1].second; //두번째 청정기 x좌표
	int two_y = cleaner_lc[1].first;  //두번째 청정기 y좌표

	//첫번째 청정기 실행
	for (int i = one_y - 1; i >= 2; i--) {// 북->남
		map_og[i][one_x] = map_og[i - 1][one_x];
	}
	for (int j = 1; j <= X - 1; j++) { //동->서
		map_og[1][j] = map_og[1][j + 1];
	}
	for (int i = 1; i <= one_y - 1; i++) {//남->북
		map_og[i][X] = map_og[i + 1][X];
	}
	for (int j = X; j >= 3; j--) { //서->동
		map_og[one_y][j] = map_og[one_y][j - 1];
	}
	map_og[one_y][2] = 0; //이동 첫번째 칸 무조건 0

	//두번째 청정기 실행
	for (int i = two_y + 1; i <= Y - 1; i++) {// 북쪽
		map_og[i][one_x] = map_og[i + 1][one_x];
	}
	for (int j = 1; j <= X - 1; j++) { //서쪽
		map_og[Y][j] = map_og[Y][j + 1];
	}
	for (int i = Y; i >= two_y + 1; i--) {// 남쪽
		map_og[i][X] = map_og[i - 1][X];
	}
	for (int j = X; j >= 3; j--) { // 동쪽
		map_og[two_y][j] = map_og[two_y][j - 1];
	}
	map_og[two_y][2] = 0;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> T;

	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			cin >> map_og[i][j];
			if (map_og[i][j] == -1) //청정기 위치 따로 저장
				cleaner_lc.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < T; i++) { //입력받은 T시간 동안
		spread_dust();            //미세먼지 확산
		operate_cleaner();        //청정기 실행 반복
	}

	int ans = 0;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			if (map_og[i][j] != -1) //청정기가 아니면 답에 미세먼지 값 더함
				ans += map_og[i][j];
		}
	}

	cout << ans << "\n";

	return 0;
}