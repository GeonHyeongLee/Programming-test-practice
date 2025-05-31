#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int ans = 1, cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] > arr[i - 1]) {
            cnt++;
            ans = max(ans, cnt);
        }
        else if (arr[i] == arr[i - 1]) {
            if (i == N) {
                ans = max(ans, cnt);
            }
            else {
                continue;
            }
        }
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}