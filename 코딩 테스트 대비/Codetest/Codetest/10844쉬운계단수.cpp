//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//#define MAX_N 101
//#define MAX 10
//
//int main(void) {
//	int N;
//	cin >> N;
//
//	// dp[계단수길이][계단수의 끝자리 0 ~ 9 => 0이라면 다음은 1, 9라면 다음은 8 확정]
//	long long int dp[MAX_N][MAX] = { 0, };
//
//
//	for (int i = 1; i <= 9; i++) {
//		dp[1][i] = 1;
//	}
//
//	for (int i = 2; i <= N; i++) {
//		for (int j = 0; j <= 9; j++) {
//			if (j == 0) {
//				dp[i][j] = dp[i - 1][j + 1];
//			}
//			else if (j == 9) {
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else {
//				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
//			}
//		}
//	}
//
//	int sum_num = 0;
//	for (int i = 0; i <= 9; i++) {
//		sum_num += dp[N][i];
//		sum_num %= 1000000000;
//	}
//
//	cout << sum_num;
//
//}