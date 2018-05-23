#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//if all elements are distinct (not repeating) - answer can be found through Binary Search
int magicIndex(vector<int>& index, int start, int end) {

	if (end < start) {
		return -1;
	}

	int mid = (start + end) / 2;
	if (index[mid] == mid) {
		return mid;
	}

	int midValue = index[mid];
	
	int leftSearchMin = min(mid, midValue);
	int rightSearchMax = max(mid, midValue);


	if (index[mid] > mid) {
		return magicIndex(index, rightSearchMax, end);

	}

	if (index[mid] < mid) {
		int searchLeft = index[mid];
		return magicIndex(index, leftSearchMin, searchLeft);
	}


}


int main() {
	
	vector<int> index = { -10,-5,2,2,2,3,4,7,9,12,13 };
	cout<<magicIndex(index, 0, index.size()-1);

										
}
