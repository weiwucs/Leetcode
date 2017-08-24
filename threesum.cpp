#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threesum(vector<int> num){
	vector<vector<int>> res;
	sort(num.begin(),num.end());
	for(int i = 0; i < num.size() - 2; i++){
		if(i > 0 && num[i] == num[i - 1]) continue; //skip duplicate
		if(num[i] > 0) break;//stop at positive intergers.
		int low = i + 1,high = num.size() - 1,sum = 0 - num[i];
		while(low < high){
			if(low > i + 1 && num[low] == num[low - 1]){
				low++;
				continue;
			}
			if(num[low] + num[i] > 0) break;//already bigger than 0.

			if(num[low] + num[high] < sum) low++;
			else if(num[low] + num[high] > sum) high--;
			else{
				vector<int> triplets;
				triplets.push_back(num[i]);
				triplets.push_back(num[low]);
				triplets.push_back(num[high]);
				res.push_back(triplets);
				low++;high--;
			}
		}

	}
	return res;
}

int main(){
	int nums[] = {-1, 0, 1, 2, -1, -4};
	vector<int> num;
	num.assign(nums,nums + 6);
	vector<vector<int>> res = threesum(num);
	for(vector<int> one : res){
		cout << "{";
		for(int num : one){
			cout << " " << num;
		}
		cout << "}" << endl;
	}
	return 0;
}
