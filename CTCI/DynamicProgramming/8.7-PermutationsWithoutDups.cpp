#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//f(i) = permutations of substring ending at index i
//f(i) = f(i-1) + {character i and every possible position within each string in f(i-1)}
void dp(vector<string>& permutations, string s, int index) {
	if (index < 0)return;
	if (index == 0) {
		string pbVal(1, s[index]);
		permutations.push_back(pbVal);
		return;
	}
	
	dp(permutations, s, index - 1);
	string currChar(1, s[index]);
	vector<string> stringsAdd;

	for (string permString : permutations) {
		for (int counter = 0;counter <= permString.size();counter++) {
			string subOne = permString.substr(0, counter);
			string subTwo = permString.substr(counter, permString.size());
			stringsAdd.push_back(subOne + currChar + subTwo);
		}
	}
	permutations.clear();
	permutations = stringsAdd;
	stringsAdd.clear();


}



int main() {
	string s = "abcdefghij";
	vector<string> permutations;

	dp(permutations, s, 9);

	for (string s : permutations) {
		cout << s << endl;
	}
}
