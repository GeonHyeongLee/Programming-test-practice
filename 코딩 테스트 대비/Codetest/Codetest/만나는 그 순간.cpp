#include <iostream>
#define offset 1000000

using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++) cin >> d2[i] >> t2[i];

    int A_p[2 * offset + 1];
    int B_p[2 * offset + 1];

    int cur_A_p = offset;
    int cur_B_p = offset;

    int index_A = 0;
    int index_B = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] == 'L') {
            while (t[i]--) {
                A_p[index_A] = cur_A_p--;
                index_A++;
            }
        }
        else {
            while (t[i]--) {
                A_p[index_A] = cur_A_p++;
                index_A++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (d2[i] == 'L') {
            while (t2[i]--) {
                B_p[index_B] = cur_B_p--;
                index_B++;
            }
        }
        else {
            while (t2[i]--) {
                B_p[index_B] = cur_B_p++;
                index_B++;
            }
        }
    }

    for (int i = 1; i < 2 * offset + 1; i++) {
        if (A_p[i] != 0 && B_p[i] != 0 && A_p[i] == B_p[i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}