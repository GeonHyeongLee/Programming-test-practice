#include <iostream>

using namespace std;

int N, M, K;
int student[10000];

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> student[i];
    }

    int st_cnt[101] = { 0 }; // 각 학생들 벌칙 받은 횟수

    for (int i = 0; i < M; i++) {
        st_cnt[student[i]] += 1;
        if (st_cnt[student[i]] >= K) {
            cout << (student[i]);
            return 0;
        }
    }

    cout << -1;


    return 0;
}