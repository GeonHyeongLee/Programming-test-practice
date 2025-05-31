#include <iostream>

#define MAX 1000000
using namespace std;

int n, m;
int t[50000];
char d[50000];
int t_b[50000];
char d_b[50000];

int main() {
    cin >> n >> m;

    int robot_A[2 * MAX + 1];
    int robot_B[2 * MAX + 1];

    int offset = MAX;

    int idx_A = 0;
    int cur_A = offset;
    int idx_B = 0;
    int cur_B = offset;

    int last_index_A = 0;
    int last_index_B = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
        last_index_A += t[i];
        if (d[i] == 'L') {
            while (t[i]--) {
                robot_A[idx_A++] = cur_A--;
            }
        }
        else {
            while (t[i]--) {
                robot_A[idx_A++] = cur_A++;
            }
        }
    }


    for (int i = last_index_A; i < 2 * MAX + 1; i++) {
        robot_A[i] = cur_A;
    }

    // for (int i = 0; i < 2 * MAX + 1; i++) {
    //     cout << robot_A[i] << " ";
    // }

    for (int i = 0; i < m; i++) {
        cin >> t_b[i] >> d_b[i];
        last_index_B += t_b[i];
        if (d_b[i] == 'L') {
            while (t_b[i]--) {
                robot_B[idx_B++] = cur_B--;
            }
        }
        else {
            while (t_b[i]--) {
                robot_B[idx_B++] = cur_B++;
            }
        }
    }

    for (int i = last_index_B; i < 2 * MAX + 1; i++) {
        robot_B[i] = cur_B;
    }
    // cout << endl;
    // for (int i = 0; i < 2 * MAX + 1; i++) {
    //     cout << robot_B[i] << " ";
    // }

    int same_position = 0;

    if (robot_A[1] == robot_B[1]) {
        same_position = 1;
    }

    int result = 0;

    for (int i = 2; i < 2 * MAX + 1; i++) {
        if (same_position == 1 && (robot_A[i] != robot_B[i])) {
            same_position = 0;
        }
        else if (same_position == 0 && (robot_A[i] == robot_B[i])) {
            same_position = 1;
            result += 1;
        }
    }

    cout << result;
    return 0;
}