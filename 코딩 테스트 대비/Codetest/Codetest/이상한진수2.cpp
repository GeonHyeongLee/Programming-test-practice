#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

string a;

int main() {
    cin >> a;

    int max_num = INT_MIN;

    for (int i = 0; i < a.size(); i++) {
        a[i] = '1' + '0' - a[i];

        int num = 0;
        for (int j = 0; j < a.size(); j++) {
            num = num * 2 + (a[j] - '0');
        }

        max_num = max(max_num, num);

        a[i] = '1' + '0' - a[i];
    }

    cout << max_num;


    return 0;
}