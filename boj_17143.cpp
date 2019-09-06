//	@date 2019/09/05
//	@author psunny0104
//	@brief boj_17143_낚시왕

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//상어 정보 저장을 위한 구조체 배열
struct SK {
	int spd; //속력
	int dir; //이동 방향
	int size;//크기
	int y;   //y좌표(R)
	int x;   //x좌표(C)
	bool death = true; //잡히거나 먹혔는지 유무로 살아 있는 것으로 초기화
	                   //true면 살아 있음,false면 죽음
} sk[100 * 100 + 1]; //sk[100*100]...........

int Y, X, M, ans;

//해당 칸에 상어가 있는지 중복체크를 위한 격자판 배열
int st[101][101];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> M;
	for (int i = 1; i <= M; i++) {//x, y,속력,이동방향,크기
		cin >> sk[i].y >> sk[i].x >> sk[i].spd >> sk[i].dir >> sk[i].size;
	}

	int nsw = 0; //낚시왕의 위치, 0부터 시작
	while (1)
	{
		nsw++;       //낚시왕 이동, 사냥, 상어이동, 상어중복체크 순으로 이루어짐
		if (nsw > X) //낚시왕이 문제에서 주어진 최대 X좌표를 벗어나면 모든 작업 종료
			break;

		int idx = 0; //낚시왕이 이번 x좌표에서 잡을 수 있는 상어의 인덱스 저장 변수
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death) //죽은 상어는 제외
				continue;

			if (sk[i].x == nsw) {//낚시왕과 상어의 x좌표가 같은지 확인
				if (idx == 0)    //처음으로 뽑히는 상어는 바로 상어의 인덱스 저장
					idx = i;
				else { //이미 저장된 상어가 있다면 서로 y좌표를 비교하여
					   //더 땅에 가까운 상어로 낚시왕이 잡을 상어의 인덱스를 갱신
					   //하나의 칸에 둘 이상의 상어가 있는 경우가 없다고 주어졌으므로 하나씩 비교 가능
					if (sk[i].y < sk[idx].y) //i번째 상어의 y좌표가 기존보다 더 작으면 인덱스 갱신
						idx = i; //갱신
				}
			}
		}

		//인덱스가 0이 아닌 상어들의 인덱스 범위인 1~M사이의 값으로
		//갱신이 되었다면 해당 상어를 죽이고 답에 해당 상어의 사이즈를 더함
		if (idx != 0) {
			sk[idx].death = false;
			ans += sk[idx].size;
		}

		//상어 이동
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death)
				continue;

			int step = sk[i].spd; //해당 상어의 속도를 따로 저장
			while (1) {           //반복문을 돌면서 상어의 속도만큼 움직였으면 멈춤
				if (step == 0)
					break;
				if (sk[i].dir == 1) { //방향에 따라 다름
					if (step <= sk[i].y - 1) { //남은 스텝이 이동할 수 있는 거리보다 작거나 같으면
						sk[i].y -= step;       //바로 이동
						step = 0;              //남은 스텝 0
						if (sk[i].y == 1)      //이동 후 끝 값에 도달했다면 
							sk[i].dir = 2;     //반대 방향을 바꿔 줌
					}
					else { //남은 스텝이 이동할 수 있는 거리보다 크다면
						step = step - (sk[i].y - 1); //이동 방향의 최소 혹은 최대 값까지의 차이만큼을 스텝에서 뺌
						sk[i].y = 1;                 //이동 방향으로 가는 방향의 가장 최소 혹은 최대 값으로 위치 이동
						sk[i].dir = 2;               //방향 바꿔 줌 -> 다음 while에서 새로운 방향의 조건문에서 처리
					}
				}    
				else if (sk[i].dir == 2) { //아래, 오른쪽, 왼쪽 모두 같은 방식으로 처리
					if (step <= Y - sk[i].y) {
						sk[i].y += step;
						step = 0;
						if (sk[i].y == Y)
							sk[i].dir = 1;
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
						if (sk[i].x == X)
							sk[i].dir = 4;
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
						if (sk[i].x == 1)
							sk[i].dir = 3;
					}
					else {
						step = step - (sk[i].x - 1);
						sk[i].x = 1;
						sk[i].dir = 3;
					}
				}
			}
		}

		//상어중복체크
		memset(st, 0, sizeof(st)); //중복을 체크하기 위한 격자판 배열 초기화
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death) //살아있는 상어만 체크
				continue;

			int tmp_y = sk[i].y;
			int tmp_x = sk[i].x;
			if (!st[tmp_y][tmp_x])    //해당 격자판에 아직 상어가 없다면
				st[tmp_y][tmp_x] = i; //상어의 인덱스 저장
			else if (st[tmp_y][tmp_x] != 0) {
				if (sk[st[tmp_y][tmp_x]].size < sk[i].size) {  //이미 저장된 상어가 있다면 사이즈를 비교
					sk[st[tmp_y][tmp_x]].death = false;        //새로운 상어의 사이즈가 더 크다면
					st[tmp_y][tmp_x] = i;                      //기존 상어는 죽이고, 격자판 배열의 상어 인덱스 갱신
				}
				else
					sk[i].death = false; //새로운 상어의 사이즈가 더 작다면 해당 상어 죽임
			}
		}
	}

	cout << ans << "\n";

	return 0;
}