#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int grid[25][25];
int visited[25][25];


vector<int> village;
int people_num;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool Cango(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    else if (grid[x][y] == 0 || visited[x][y]) {
        return false;
    }

    return true;
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (Cango(nx, ny)) {
            visited[nx][ny] = 1;
            people_num += 1;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Cango(i, j)) {
                visited[i][j] = 1;
                people_num = 1;

                dfs(i, j);

                village.push_back(people_num);
            }
        }
    }

    sort(village.begin(), village.end());

    cout << village.size() << endl;

    for (int i = 0; i < village.size(); i++) {
        cout << village[i] << endl;
    }

    return 0;
}
