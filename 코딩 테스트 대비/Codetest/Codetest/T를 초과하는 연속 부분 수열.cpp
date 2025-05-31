#include <iostream>

using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > t) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);

        }
    }

    cout << ans << endl;

    return 0;
}