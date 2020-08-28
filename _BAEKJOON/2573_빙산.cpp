#include <iostream>
#define MAX 301

using namespace std;

int N, M;
int sea[MAX][MAX] = { 0, };
int sea_copy[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int flag = 0;

void melting() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (sea_copy[i][j] > 0) {
				int nx, ny;
				for (int k = 0; k < 4; k++) {
					nx = j + dx[k];
					ny = i + dy[k];
					if (0 <= nx && nx < M && 0 <= ny && ny < N) {
						if (sea_copy[ny][nx] <= 0) sea[i][j]--;
					}
				}
			}
		}
	}
}

void reset_setting() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sea_copy[i][j] = sea[i][j];
			visited[i][j] = 0;
		}
	}
}

void dfs(int i, int j) {
	if (visited[i][j] != 0) return;
	visited[i][j] = 1;

	int nx, ny;
	for (int k = 0; k < 4; k++) {
		nx = j + dx[k];
		ny = i + dy[k];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (sea[ny][nx] > 0) {
				dfs(ny, nx);
				flag = 1;
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> sea[i][j];
			sea_copy[i][j] = sea[i][j];
		}
	}

	int year = 0, ice_num = 0;
	while (1) {
		ice_num = 0;
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (sea[i][j] > 0 && visited[i][j] == 0) {
					dfs(i, j);
					ice_num++;
					flag = 1; //flag=1이면 아직 빙산이 남아있다는 얘기
				}
			}
		}
		
		if (ice_num < 2) {
			year++;
			melting();
			reset_setting();
		}
		if (flag == 0) {
			cout << "0";
			break;
		}
		if (ice_num >= 2) {
			cout << year;
			break;
		}
	}
	
	return 0;
}