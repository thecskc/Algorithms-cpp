#include<iostream>
#include<vector>
using namespace std;

//Assumptions: n>=0, dp's return value won't overflow int.
//Bottom-Up Recursion.
int dp(int n) {
	vector<int> memo;
	memo.push_back(1);
	memo.push_back(1);
	memo.push_back(2);
	for (int i = 3;i <= n;i++) {
		memo.push_back(memo[i - 1] + memo[i - 2] + memo[i - 3]);
	}
	
	return memo[n];

}


int main() {
	int n = 10;
	cout << dp(n);
}
