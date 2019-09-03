//	@date 2019/09/03
//	@author psunny0104
//	@brief boj_17142_������ 3

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321 //�ּڰ��� ã�� ���� ans ���� �ʱ�ȭ�ϱ� ���� INF
using namespace std;

int N, M, ans, cnt;
int map[51][51];//�� ĭ=0, ��=1, ���̷���=2
int chk[51][51];//bfs �湮���� �� �Ÿ� ���

vector<pair<int, int>> vrs_list_all; //�־��� �Է��� ��� ���̷��� ����Ʈ
vector<pair<int, int>> vrs_act_all;  //������ ���� ������ Ȱ��ȭ�� ���̷��� ����Ʈ
bool selected[10]; //���� ����� ���� �迭

int dx[] = { 0, 0, 1, -1 }; //4���� �̵��� ���� �迭
int dy[] = { 1, -1, 0 ,0 };//4���� �̵��� ���� �迭

int bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < vrs_act_all.size(); i++) { //ť�� ������ Ȱ��ȭ ���̷����� ��� �ְ� bfs ����
		int act_y = vrs_act_all[i].first;
		int act_x = vrs_act_all[i].second;
		q.push(make_pair(act_y, act_x));
		chk[act_y][act_x] = 1; //�ʱⰪ�� 1�� �����ϹǷ�, �信�� 1�� ���߿� ����� ��
	}
	int tmp_cnt = 0; //�̹� �������� ���̷����� �� �� ĭ�� ������ ���� ���� �� ĭ�� ������ ��
	int max_val = 0; //�̹� �������� �� ĭ�� ���̷����� �Ǵµ� ���� ���� �ɸ� �ð��� ����

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

			if (map[ny][nx] == 0 || map[ny][nx] == 2) {//�� ĭ�̰ų� ��Ȱ��ȭ ���̷����̸� �Ÿ��� ����
				chk[ny][nx] = chk[y][x] + 1;
				if (map[ny][nx] == 0) { //�� ĭ�ΰ�� ī��Ʈ�ϰ�, �ش� �ð��� ������ ����� �ð����� ũ�� max_val ����
					tmp_cnt++;
					if (chk[ny][nx] > max_val) {
						max_val = chk[ny][nx];
					}
				}
				q.push(make_pair(ny, nx));
			}
		}
	}

	if (cnt != tmp_cnt) //�� ĭ�� ��� ���̷����� ���� �ʾ����� -1 ����
		return -1;
	
	return max_val - 1; //���̷����� �Ǵµ� ���� ���� �ɸ� �ð��� ����, ó�� ���� �ð��� 1�� �����Ƿ� -1 ����
}

void cmb(int idx, int cnt) //idx = ������, cnt = �� ����
{
	if (cnt == M) { //�� ������ ������ ������ ���� ������ ������ ������ ������ bfs�� ���� ���̷��� ��Ʈ��
		vrs_act_all.clear(); //Ȱ��ȭ ���̷��� ����Ʈ ���� �ʱ�ȭ
		memset(chk, 0, sizeof(chk)); //�Ÿ� ��� �迭 �ʱ�ȭ

		for (int i = 0; i < vrs_list_all.size(); i++) { //Ȱ��ȭ ���̷��� ����Ʈ�� �� ���̷����� �־���
			if (selected[i] == true) {
				int act_y = vrs_list_all[i].first;
				int act_x = vrs_list_all[i].second;
				vrs_act_all.push_back(make_pair(act_y, act_x));
			}
		}
		int tmp_ans = bfs(); //bfs�� ���� ���̷��� ��Ʈ���� ����

		if (tmp_ans != -1 && tmp_ans < ans) //�� ĭ�� ��� ä����, ������ ������ ������ ans ����
			ans = tmp_ans;
	
		return;
	}
	for (int i = idx; i < vrs_list_all.size(); i++) { //ù ���� �������� dfs�� ���� ������ ������
		if (selected[i] == true)
			continue;
		selected[i] = true;

		cmb(i, cnt + 1); //dfs�� ���� ���
		selected[i] = false; //���������� �� �� ����� ���� �ٽ� ���� ����
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
			if (map[i][j] == 2) { //���̷����� ��� ���� �迭�� ����
				vrs_list_all.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 0)
				cnt++; // �� ĭ�� ������ ��
		}
	}

	if (cnt == 0) {
		cout << 0 << "\n"; //���ʿ� �� ĭ ������ ������ 0 ���
		return 0;
	}
	else {
		ans = INF;
		//dfs�� ���� ������ �����Ͽ� Ȱ��ȭ��ų ���̷����� ���� �� �ȿ��� bfs�� ����
		cmb(0, 0);

		if (ans == INF) //bfs���� �� ĭ�� �� ä���� ���� ��� ans�� ���� �ٲ��� �����Ƿ�, �״�� INF�̸� -1�� ���
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}
	
	return 0;
}