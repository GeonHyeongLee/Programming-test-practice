#include <iostream>
#include <vector>

#define MAX 10
using namespace std;

int main(void) {
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			sum += 3;
		}
		else if (s[i] == 'B') {
			sum += 3;
		}
		else if (s[i] == 'C') {
			sum += 3;
		}
		else if (s[i] == 'D') {
			sum += 4;
		}
		else if (s[i] == 'E') {
			sum += 4;
		}
		else if (s[i] == 'F') {
			sum += 4;
		}
		else if (s[i] == 'G') {
			sum += 5;
		}
		else if (s[i] == 'H') {
			sum += 5;
		}
		else if (s[i] == 'I') {
			sum += 5;
		}
		else if (s[i] == 'J') {
			sum += 6;
		}
		else if (s[i] == 'K') {
			sum += 6;
		}
		else if (s[i] == 'L') {
			sum += 6;
		}
		else if (s[i] == 'M') {
			sum += 7;
		}
		else if (s[i] == 'N') {
			sum += 7;
		}
		else if (s[i] == 'O') {
			sum += 7;
		}
		else if (s[i] == 'P') {
			sum += 8;
		}
		else if (s[i] == 'Q') {
			sum += 8;
		}
		else if (s[i] == 'R') {
			sum += 8;
		}
		else if (s[i] == 'S') {
			sum += 8;
		}
		else if (s[i] == 'T') {
			sum += 9;
		}
		else if (s[i] == 'U') {
			sum += 9;
		}
		else if (s[i] == 'V') {
			sum += 9;
		}
		else if (s[i] == 'W') {
			sum += 10;
		}
		else if (s[i] == 'X') {
			sum += 10;
		}
		else if (s[i] == 'Y') {
			sum += 10;
		}
		else if (s[i] == 'Z') {
			sum += 10;
		}
	}
	cout << sum << endl;

}