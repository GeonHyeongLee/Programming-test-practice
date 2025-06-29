#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int L;
	cin >> L;

	for (int i = 0; i < L; i++) {
		int N;
		cin >> N;
		string s;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			cin >> s;
			if (s == "sheep") {
				cnt += 1;
			}
		}
		cout << "Case " << i + 1 << ": This list contains " << cnt << " sheep." << endl << endl;
	}
}