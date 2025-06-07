// 최대, 최소 설정 방법 중 #include <climits>을 통해서
// INT_MAX, INT_MIN으로 int형에서 가질 수 있는 가장 작은 값, 가장 큰 값을 넣어줄 수 있다.

#include <iostream>
#include <climits>

using namespace std;

int main() {

    int max_num = INT_MIN;

    int number[10];

    for (int i = 0; i < 10; i++) {
        cin >> number[i];
    }

    for (int i = 0; i < 10; i++) {
        if (max_num < number[i]) {
            max_num = number[i];
        }
    }

    cout << max_num;
    return 0;
}