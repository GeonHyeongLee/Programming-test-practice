// �����¿찡 �򰥸� ���� ����.
// Ư�� �̹� ���������� ����� ���� �� ���� ���� y, ���� x�� �����ߴµ�
// ���������� ���� x = i, ���� y = j�� �޾Ҿ���.
// �� �κ��� ������ Ǯ�鼭 �Ű��� ����� �� �� ����.
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