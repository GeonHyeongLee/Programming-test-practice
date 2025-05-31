#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> v[i] >> t[i];

    for (int i = 0; i < M; i++) cin >> v2[i] >> t2[i];

    int A[1000 * 1000];
    int B[1000 * 1000];

    int idx_A = 0;
    int move_A = 0;
    int idx_B = 0;
    int move_B = 0;
    for (int i = 0; i < N; i++) {
        while (t[i]--) {
            move_A += v[i];
            idx_A++;
            A[idx_A] = move_A;
        }
    }

    // for (int i = 0; i < 100; i++) {
    //     cout << A[i] << " ";
    // }

    for (int i = 0; i < M; i++) {
        while (t2[i]--) {
            move_B += v2[i];
            idx_B++;
            B[idx_B] = move_B;
        }
    }

    // cout << endl;
    // for (int i = 0; i < 100; i++) {
    //     cout << B[i] << " ";
    // }

    int res = 0;
    int compare = 0; // compare = 0 동일, compare = 1 A가 더 큼, compare = 2 B가 더 큼

    if (A[1] > B[1]) {
        compare = 1;
    }
    else if (A[1] < B[1]) {
        compare = 2;
    }

    for (int i = 2; i < idx_A; i++) {

        if (compare == 1 && A[i] < B[i]) {
            compare = 2;
            res += 1;
        }
        else if (compare == 2 && A[i] > B[i]) {
            compare = 1;
            res += 1;
        }
        else if (compare == 0 && A[i] < B[i]) {
            compare = 2;
        }
        else if (compare == 0 && A[i] > B[i]) {
            compare = 1;
        }

    }

    cout << res << endl;
    return 0;
}