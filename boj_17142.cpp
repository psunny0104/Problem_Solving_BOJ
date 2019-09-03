//	@date 2019/09/03
//	@author pstar12
//	@brief boj_17142_연구소 3

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321 //최솟값을 찾기 위해 ans 값을 초기화하기 위한 INF
using namespace std;

int N, M, ans, cnt;
int map[51][51];//빈 칸=0, 벽=1, 바이러스=2
int chk[51][51];//bfs 방문여부 및 거리 계산

vector<pair<int, int>> vrs_list_all; //주어진 입력의 모든 바이러스 리스트
vector<pair<int, int>> vrs_act_all;  //조합을 통해 구해진 활성화된 바이러스 리스트
bool selected[10]; //조합 계산을 위한 배열

int dx[] = { 0, 0, 1, -1 }; //4방향 이동을 위한 배열
int dy[] = { 1, -1, 0 ,0 };//4방향 이동을 위한 배열

int bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < vrs_act_all.size(); i++) { //큐에 선택한 활성화 바이러스를 모두 넣고 bfs 시작
		int act_y = vrs_act_all[i].first;
		int act_x = vrs_act_all[i].second;
		q.push(make_pair(act_y, act_x));
		chk[act_y][act_x] = 1; //초기값을 1로 시작하므로, 답에서 1을 나중에 빼줘야 함
	}
	int tmp_cnt = 0; //이번 지도에서 바이러스가 된 빈 칸의 개수를 세고 원래 빈 칸의 개수와 비교
	int max_val = 0; //이번 지도에서 빈 칸이 바이러스가 되는데 가장 오래 걸린 시간을 저장

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (chk[ny][nx] != 0)
				continue;

			if (map[ny][nx] == 0 || map[ny][nx] == 2) {//빈 칸이거나 비활성화 바이러스이면 거리를 갱신
				chk[ny][nx] = chk[y][x] + 1;
				if (map[ny][nx] == 0) { //빈 칸인경우 카운트하고, 해당 시간이 이전에 저장된 시간보다 크면 max_val 갱신
					tmp_cnt++;
					if (chk[ny][nx] > max_val) {
						max_val = chk[ny][nx];
					}
				}
				q.push(make_pair(ny, nx));
			}
		}
	}

	if (cnt != tmp_cnt) //빈 칸이 모두 바이러스가 되지 않았으면 -1 리턴
		return -1;
	
	return max_val - 1; //바이러스가 되는데 가장 오래 걸린 시간을 리턴, 처음 시작 시간을 1로 했으므로 -1 해줌
}

void cmb(int idx, int cnt) //idx = 시작점, cnt = 고른 개수
{
	if (cnt == M) { //고른 원소의 개수가 조합을 통해 고르려는 원소의 개수와 같으면 bfs를 통해 바이러스 퍼트림
		vrs_act_all.clear(); //활성화 바이러스 리스트 벡터 초기화
		memset(chk, 0, sizeof(chk)); //거리 계산 배열 초기화

		for (int i = 0; i < vrs_list_all.size(); i++) { //활성화 바이러스 리스트에 고른 바이러스를 넣어줌
			if (selected[i] == true) {
				int act_y = vrs_list_all[i].first;
				int act_x = vrs_list_all[i].second;
				vrs_act_all.push_back(make_pair(act_y, act_x));
			}
		}
		int tmp_ans = bfs(); //bfs를 통한 바이러스 퍼트리기 시작

		if (tmp_ans != -1 && tmp_ans < ans) //빈 칸을 모두 채웠고, 기존의 값보다 작으면 ans 갱신
			ans = tmp_ans;
	
		return;
	}
	for (int i = idx; i < vrs_list_all.size(); i++) { //첫 점을 시작으로 dfs를 통해 조합을 구현함
		if (selected[i] == true)
			continue;
		selected[i] = true;

		cmb(i, cnt + 1); //dfs를 위한 재귀
		selected[i] = false; //시작점으로 한 번 골랐던 것은 다시 고르지 않음
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) { //바이러스인 경우 따로 배열에 저장
				vrs_list_all.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 0)
				cnt++; // 빈 칸의 개수를 셈
		}
	}

	if (cnt == 0) {
		cout << 0 << "\n"; //최초에 빈 칸 없으면 답으로 0 출력
		return 0;
	}
	else {
		ans = INF;
		//dfs를 통해 조합을 구현하여 활성화시킬 바이러스를 고르고 그 안에서 bfs를 실행
		cmb(0, 0);

		if (ans == INF) //bfs에서 빈 칸을 다 채우지 못할 경우 ans의 값을 바꾸지 않으므로, 그대로 INF이면 -1을 출력
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}
	

	return 0;
}