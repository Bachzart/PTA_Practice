#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check(vector<int>& nums) {
	for(int &i: nums)
		if(0 < i && i > 9)
			return false;
	return true;
}

int cal(int n) {
	int ret = 0;
	if(n != 0) {
		int t = 1;
		while(n) {
			t *= pow(n % 10, 3);
			n /= 10;
		}
		while(t) {
			ret += t % 10;
			t /= 10;
		}
	}
	return ret;
}

int main() {
	vector<int> nums;
	int N1, N2;
	cin >> N1 >> N2;
	for(int i = N1; i <= N2; ++i)
		nums.push_back(i);
	
	while(!check(nums)){
		for(int i = 0; i < nums.size(); ++i) 
			nums[i] = cal(nums[i]);
	}
	int ht[10] = {0};
	int maxCount = -1;
	for(int i = 0; i < nums.size(); ++i) {
		ht[nums[i]]++;
		maxCount = max(maxCount, ht[nums[i]]);
	}
	
	vector<int> ans;
	for(int i = 0; i < 10; ++i)
		if(maxCount == ht[i])
			ans.push_back(i);
	
	cout << maxCount << endl;
	if(ans.size() == 1)
		cout << ans[0] << endl;
	else {
		cout << ans[0];
		for(int i = 1; i < ans.size(); ++i)
			cout << " " << ans[i];
		cout << endl;
	} 
	return 0;
}
