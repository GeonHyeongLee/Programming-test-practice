// 중요한 포인트 1 : DFS에서 재귀를 쓴다고 꼭 종료조건을 명시적으로 해둘 필요는 없다.
// 왜? 어차피 조건을 만족하지 않으면 실행되지 않게 할 수 있기 때문이다. 즉, 암묵적인 종료 조건이 존재한다.
// 여기서는 CAnGo함수가 암묵적인 종료 조건이다.
// 1) inRange를 벗어날 때
// 2) visited[x][y] == 1로 뱀이 나왔을 때
// 3) grid[x][y] == 0 으로 벽이 나왔을 때

// 격자에서 DFS를 만들 때의 과정은 어떻게 진행해야 할까?
// 1. 방문 여부를 표시하는 visited를 2차원 배열로 만든다. x, y축이 존재하기 때문이다.
// 2. DFS가 더 이상 진행되지 않게 하는 조건을 생각한다. 여기서는 벽을 넘거나, 뱀을 만나거나, 범위를 초과하거나
// 3. 만약 진행이 가능하다면 DFS(nx,ny)를 통해 재귀 구조를 완성하자
// 4. 마지막에 출력에서는 만약 경로의 성립 여부를 파악한다면 visited[n-1][m-1] == 1이라면 성립이라고 판단 가능할 
// 것이기에 cout << visited[n-1][m-1]일 것이고, 경로의 개수를 구한다면 도착할 때마다 += 1을 해주는 방식일 것이고,
// 경로의 길이를 구한다면 visited[n-1][m-1]을 구할 때 += 1을 해나가는 방식으로 오른쪽이랑 위를 비교해서 작은 값을
// 택해주는 것을 반복할 것이다.


#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int visited[100][100];

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y) {
    if (!inRange(x, y)) {
        return false;
    }
    if (visited[x][y] || grid[x][y] == 0) {
        return false;
    }

    return true;
}

void DFS(int x, int y) {
    int dx[2] = { 1,0 };
    int dy[2] = { 0,1 };


    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (CanGo(nx, ny)) {
            visited[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(0, 0);

    cout << visited[n - 1][m - 1];

    return 0;
}
