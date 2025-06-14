#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int grid[50][50];
int visited[50][50];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void initializevisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

bool Cango(int x, int y, int k) {
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return false;
    }
    else if (grid[x][y] <= k || visited[x][y]) {
        return false;
    }
    return true;
}

void dfs(int x, int y, int k) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (Cango(nx, ny, k)) {
            visited[nx][ny] = 1;
            dfs(nx, ny, k);
        }
    }
}



int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }


    vector<int> result;
    for (int k = 1; k <= 100; k++) {
        int count = 0;
        initializevisited();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Cango(i, j, k)) {
                    visited[i][j] = 1;
                    dfs(i, j, k);
                    count++;
                }
            }
        }
        result.push_back(count);
    }

    int max_num = 0;
    int max_index = 0;

    for (int i = 0; i < result.size(); i++) {
        if (result[i] > max_num) {
            max_num = result[i];
            max_index = i;
        }
    }

    cout << max_index + 1 << " " << max_num;

    return 0;
}
