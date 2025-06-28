#include <iostream>
#include <vector>

#define r 31
#define M 1234567891

using namespace std;

int main(void) {
	int L;
	string s;
	cin >> L;
	cin >> s;

	vector<int> arr;

	for (int i = 0; i < s.size(); i++) {
		arr.push_back(s[i] - 96);
	}

	//for (int i = 0; i < s.size(); i++) {
	//	cout << arr[i] << endl;
	//}

	int sum_num = 0;
	int r_num = 1;

	for (int i = 0; i < L; i++) {
		sum_num += ((arr[i] % M) * (r_num % M)) % M;
		r_num *= r;
		r_num %= M;
	}

	sum_num %= M;

	cout << sum_num << endl;


}

