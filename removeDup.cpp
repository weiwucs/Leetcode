#include <iostream>
#include <vector>

using namespace std;

/**
 *use count to remember current position
 */

int removeDupStandard(vector<int> A){
	int cout = 0;
	int len = A.size();

	for(int i = 0; i < len; i++){
		if(cout == 0|| A[i] != A[cout - 1]){//first of not dup
			A[cout++] = A[i];//copy and update count
		}
	}
	return cout;
}

/**
 *use two pointers, one in the first, one for the dups;
 */

int removeDup(vector<int>& A){
	int i = 0;
	int j = 0;
	int pos = i + 1;
	while(i < A.size()){
		j = i + 1;
		while(j < A.size() && A[i] == A[j]){
			j++;
		}

		if(j >= A.size()) break;

		A[pos] = A[j];
		pos++;
		i = j;
	}
	return pos;
}

int main(){
	int A[] = {1, 1, 2, 2, 3};
	vector<int> ts;
	int len = 0;
	ts.assign(A, A + 5);
	len = removeDup(ts);

	for(int i = 0; i < len; i++){
		cout << ts[i] << " ";
	}

	return 0;
}
