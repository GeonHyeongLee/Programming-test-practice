// �ִ�, �ּ� ���� ��� �� #include <climits>�� ���ؼ�
// INT_MAX, INT_MIN���� int������ ���� �� �ִ� ���� ���� ��, ���� ū ���� �־��� �� �ִ�.

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