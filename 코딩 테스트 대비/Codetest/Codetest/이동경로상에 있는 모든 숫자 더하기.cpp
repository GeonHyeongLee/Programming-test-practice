// 상하좌우가 헷갈릴 때가 많다.
// 특히 이번 문제에서는 행렬을 받을 때 나는 행을 y, 열을 x라 생각했는데
// 문제에서는 행을 x = i, 열을 y = j로 받았었다.
// 이 부분은 문제를 풀면서 신경을 써줘야 할 것 같다.
#include <iostream>
#include <string>

using namespace std;

int N, T;
string str;
int board[100][100];

int dx[4] = { 0,1,0,-1 }; // N -> E -> S -> W
int dy[4] = { -1,0,1,0 };

int main() {
    cin >> N >> T;
    cin >> str;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[j][i];
        }
    }

    int dir_idx = 0;



    int res = 0;
    int st_pt = (N / 2);
    int cur_x = st_pt;
    int cur_y = st_pt;
    res += board[st_pt][st_pt];

    for (int i = 0; i < T; i++) {
        if (str[i] == 'R') {
            dir_idx += 1;
            if (dir_idx > 3) {
                dir_idx = 0;
            }
        }
        else if (str[i] == 'L') {
            dir_idx -= 1;
            if (dir_idx < 0) {
                dir_idx = 3;
            }
        }
        else if (str[i] == 'F') {
            cur_x = cur_x + dx[dir_idx];
            cur_y = cur_y + dy[dir_idx];

            if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N) {
                cur_x -= dx[dir_idx];
                cur_y -= dy[dir_idx];
            }
            else {
                res += board[cur_x][cur_y];
            }
        }
    }

    cout << res << endl;

    return 0;
}