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
int cur_r, cur_c; //현재 행과 열의 개수를 저장하기 위한 변수
int map[101][101]; //숫자를 저장하기 위한 이차원 배열
int cnt[101]; //연산할 때 숫자들의 개수를 카운트하기 위한 배열

//새로 저장할 때 순서를 결정하기 위한 우선순위 큐
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void opr()
{
	//연산에서의 for문의 범위를 cur 변수로 하게되면 중간에 갱신이 될 경우
	//그 이후의 열이나 행에서 필요 없는 연산이 추가됨
	//따라서 처음 행과 열의 개수을 저장하기 위한 변수를 따로 사용
	int pv_c = cur_c; //열, x
	int pv_r = cur_r; //행, y

	if (cur_r >= cur_c) { //R 연산
		for (int i = 1; i <= pv_r; i++) {
			memset(cnt, 0, sizeof(cnt)); //카운트 배열 초기화
			for (int j = 1; j <= pv_c; j++) { //행의 존재하는 숫자 카운트
				int val = map[i][j];
				cnt[val]++;
			}

			//카운트한 숫자와 횟수를 우선순위 큐에 저장
			//등장횟수가 pair에서 first에 저장되어 있으므로
			//등장횟수, 숫자 순으로 오름차순 정렬됨
			for (int j = 1; j <= 100; j++) { 
				if (!cnt[j])
					continue;
				//pq의 size를 50까지 저장하여 길이가 100을 넘지 않도록 함
				if (pq.size() <= 50)
					pq.push(make_pair(cnt[j], j)); //등장횟수, 숫자
				else
					break;
			}

			//행의 길이가 길어졌는지 확인
			//길어졌으면 cur변수 갱신
			int size_pq = pq.size();
			if (size_pq * 2 > cur_c)
				cur_c = size_pq * 2;

			//저장 전에 cur의 범위만큼 0으로 초기화
			for (int j = 1; j <= cur_c; j++)
				map[i][j] = 0;

			//길이를 100까지 허용하여 숫자와 등장횟수순으로 값 저장
			for (int j = 1; j <= size_pq*2 - 1; j+=2) {
				//if (j > 50) //pair이므로 반인 50이 넘으면 남은 값은 버림
				//	break;
				map[i][j] = pq.top().second;
				map[i][j + 1] = pq.top().first;
				pq.pop();
			}
		}
	}
	//C 연산은 R연산에서 c와 r에 관련된 변수와 map배열의 인덱스를 서로 바꿔줌
	else { 
		for (int i = 1; i <= pv_c; i++) {
			memset(cnt, 0, sizeof(cnt));

			for (int j = 1; j <= pv_r; j++) {
				int val = map[j][i];
				cnt[val]++;
			}
			for (int j = 1; j <= 100; j++) {
				if (!cnt[j])
					continue;
				if (pq.size() <= 50)
					pq.push(make_pair(cnt[j], j)); //등장횟수, 숫자
				else
					break;
			}
			int size_pq = pq.size();
			if (size_pq * 2 > cur_r)
				cur_r = size_pq * 2;
			for (int j = 1; j <= cur_r; j++)
				map[j][i] = 0;
			for (int j = 1; j <= size_pq * 2 - 1; j += 2) {
				//if (j > 50)
				//	break;
				map[j][i] = pq.top().second;
				map[j+1][i] = pq.top().first;
				pq.pop();
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >>C >> K;
	
	//초기값인 3x3의 배열값 저장
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	
	cur_r = 3, cur_c = 3; //열,행 개수 3으로 초기화

	int ans = 0;

	//행의 개수가 2차원배열에서는 첫번째 인덱스
	//열의 개수가 2차원배열에서는 두번째 인덱스임을 유의!
	//문제의 조건이 만족할 때까지 while문을 실행
	//while안에서 연산 실행 및 시간을 1씩 더해줌
	while (map[R][C] != K) {

		//시간이 100을 넘어가면 -1 로 저장
		//ans갱신 후에 while이 다시 실행된 것은 101번째에 돌입한 것임
		//따라서 ans > 100이 아닌 ans == 100으로 판단해 줌
		//ans >100으로 할 경우 while문이 한 번 더 돌게됨(답과는 무관)
		if (ans == 100) { 
			ans = -1;
			break;
		}
		opr(); //연산 실행
		ans++; //시간 갱신
	}

	cout << ans << "\n";

	return 0;
}