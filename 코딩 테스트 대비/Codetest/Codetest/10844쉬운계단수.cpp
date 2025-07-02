#include <iostream>
#include <vector>

#define MAX_N 101
#define MAX 10
using namespace std;

// 최초 풀이
// 
// 조건1. 맨 앞 숫자에는 0이 안 들어간다.
// 조건2. 두 번째 숫자부터 0 뒤는 무조건 1, 9 뒤는 무조건 8이다.

// 두 조건을 반영하여 식을 짜면
// 9 => 17 => 33 => 65 
// 하지만, 이 조건은 틀렸다. 
// 9 => 17까지는 맞지만 그 다음이 33이 아닌 32이기 때문이다.
// 그 이유는 89 뒤에 올 수 있는 숫자가 898로 하나 밖에 없기 때문이다.
// 그렇기에 우리가 알 수 있는 사실은 규칙에서 중요한 것은 조건1, 조건2라는 것이다.
// 전 숫자의 마지막 숫자가 0이면 1 밖에 가지 못한다. 마지막 숫자가 9이면 8 밖에
// 가지 못한다. 이 둘을 신경 써서 DP로 문제를 푸는 것이다.


//길이 N일 때, 뒤에 마지막 숫자가 무엇인지를 알아내야 한다.



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// dp 배열을 만들었다면 초기화를 해줘야 한다.
	// 초기화를 안할 시 쓰레기 값이 들어가게된다.
	long long dp[MAX_N][MAX] = { 0 };

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				// 나머지 연산은 중간마다 해줘야 한다.
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}
	
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[N][i]) % 1000000000;
	}
	cout << sum << endl;
}