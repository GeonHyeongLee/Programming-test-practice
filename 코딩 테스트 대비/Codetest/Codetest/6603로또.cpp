#include <iostream>
#include <vector>

using namespace std;

vector<int> result_v;

void print_num() {
	for (int i = 0; i < result_v.size(); i++) {
		cout << result_v[i] << " ";
	}
	cout << endl;
}

void back_tracking(vector<int> & arr, int cur, int cnt) {

	if (cnt == 6) {
		print_num();
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= cur) {
			cur = arr[i];
			result_v.push_back(cur);
			back_tracking(arr, cur+1, cnt + 1);
			result_v.pop_back();
		}
	}
}

int main(void) {
	string s;

	while (1) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		int num;
		vector<int> arr;
		for (int i = 0; i < k; i++) {
			cin >> num;
			arr.push_back(num);
		}

		back_tracking(arr, arr[0], 0);
		cout << endl;
	}
}