#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    int min_num = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sum += abs((A[j]) * (j - i));
            }
        }
        min_num = min(min_num, sum);
    }

    cout << min_num;

    return 0;
}