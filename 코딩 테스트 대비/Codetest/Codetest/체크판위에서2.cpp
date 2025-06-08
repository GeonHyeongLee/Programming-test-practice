// 첫 번째 지점과 다른 지점인 [i][j] 설정
// 마지막 지점과 다른 지점인 [k][l] 설정
// 이렇게 해서 중간 이동은 두 번으로 설정이 가능하고
// k, l은 i+1, j+1부터 시작하여 최소 오른쪽 아래에서 시작할 수 있도록 한다


// 또한, i,j는 0,0 오른쪽 아래에서부터 시작하고 아래로 두 번 더 이동해야 되기 때문에
// 범위를 1부터 시작해서 R-2, C-2까지로 잡아야 하고
// k,l은 i,j의 오른쪽 아래부터 시작하기에 i +1, j+1부터 시작해서 R-1,C-1까지로 잡아야 한다.
#include <iostream>

using namespace std;

int R, C;
char grid[15][15];

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < R - 2; i++) {
        for (int j = 1; j < C - 2; j++) {
            for (int k = i + 1; k < R - 1; k++) {
                for (int l = j + 1; l < C - 1; l++) {
                    if (grid[0][0] != grid[i][j] && grid[i][j] != grid[k][l] && grid[k][l] != grid[R - 1][C - 1]) {
                        res += 1;
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}