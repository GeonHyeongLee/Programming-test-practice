//#include <iostream>
//#include <string>
//#include <queue>
//#include <algorithm>
//#define MAX 25
//
//using namespace std;
//
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { -1,1,0,0 };
//
//int map[MAX][MAX];
//int visited[MAX][MAX];
//
//queue<pair<int, int>> q;
//
//int N;
//
//bool Cango(int x, int y) {
//	if (x < 0 || x >= N || y < 0 || y >= N) {
//		return false;
//	}
//	else if (visited[x][y] || map[x][y] == 0) {
//		return false;
//	}
//	return true;
//}
//
//void bfs(int& count) {
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//
//		int x = cur.first;
//		int y = cur.second;
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (Cango(nx, ny)) {
//				visited[nx][ny] = 1;
//				q.push(make_pair(nx, ny));
//				count++;
//			}
//		}
//	}
//}
//
//int main(void) {
//
//	cin >> N;
//
//	string s;
//	for (int i = 0; i < N; i++) {
//		cin >> s;
//		for (int j = 0; j < N; j++) {
//			map[i][j] = s[j] - '0';
//		}
//	}
//
//	vector<int> count_arr;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (Cango(i, j)) {
//				visited[i][j] = 1;
//				q.push(make_pair(i, j));
//
//				int count = 1;
//				bfs(count);
//				count_arr.push_back(count);
//			}
//		}
//	}
//	
//	cout << count_arr.size() << endl;
//
//	sort(count_arr.begin(), count_arr.end());
//
//
//	for (int i = 0; i < count_arr.size(); i++) {
//		cout << count_arr[i] << endl;
//	}
//}