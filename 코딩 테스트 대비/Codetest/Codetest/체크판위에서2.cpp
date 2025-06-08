// ù ��° ������ �ٸ� ������ [i][j] ����
// ������ ������ �ٸ� ������ [k][l] ����
// �̷��� �ؼ� �߰� �̵��� �� ������ ������ �����ϰ�
// k, l�� i+1, j+1���� �����Ͽ� �ּ� ������ �Ʒ����� ������ �� �ֵ��� �Ѵ�


// ����, i,j�� 0,0 ������ �Ʒ��������� �����ϰ� �Ʒ��� �� �� �� �̵��ؾ� �Ǳ� ������
// ������ 1���� �����ؼ� R-2, C-2������ ��ƾ� �ϰ�
// k,l�� i,j�� ������ �Ʒ����� �����ϱ⿡ i +1, j+1���� �����ؼ� R-1,C-1������ ��ƾ� �Ѵ�.
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