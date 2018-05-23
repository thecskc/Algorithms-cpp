#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//dp(index) = all entries in dp(index-1) + current character
void dp(string str, vector<string>& output, int index) {
	if (index < 0) {
		return;
	}
	if (index == 0) {
		string pushValue(1, str[0]);
		output.push_back(pushValue);
		return;
	}
	dp(str, output, index - 1);
	vector<string> addTo;
	string pushVal(1, str[index]);
	addTo.push_back(pushVal);
	for (int counter = 0;counter < output.size();counter++) {
		addTo.push_back(output[counter] + str[index]);
	}
	for (string val: addTo) {
		output.push_back(val);
	}
}


int main() {
	
	string str = "123";
	vector<string> output;
	dp(str, output, 2);
	output.push_back("Empty Set {} "); //empty set
	for (string val : output) {
		cout << val << endl;
	}
}
