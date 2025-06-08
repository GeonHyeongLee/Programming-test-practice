#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int x[100];
int y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int min_dis = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        int dis = 0;
        dis += (abs(x[i + 2] - x[i]) + abs(y[i + 2] - y[i]));

        for (int j = 0; j < n - 1; j++) {
            if (j != i && j != (i + 1)) {
                dis += (abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]));
            }
        }
        min_dis = min(min_dis, dis);
    }

    cout << min_dis;
    return 0;
}