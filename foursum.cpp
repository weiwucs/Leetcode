#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> foursum(vector<int> num, int target){
	vector<vector<int>> res;
	if(num.empty() || num.size() < 4) return res;
	sort(num.begin(), num.end());

	for(int i = 0; i < num.size() - 3; i++){
		if(i > 0 && num[i] == num[i - 1]) continue;
		for(int j = i + 1; j < num.size() - 2; j++){
			if(j > i + 1 && num[j] == num[j - 1]) continue;
			int newtar = target - num[i] - num[j];
			int low = j + 1;
			int high = num.size() - 1;
			while(low < high){
				if(low > j + 1 && num[low] == num[low - 1]){
					low++;
					continue;
				}
				if(high < num.size() - 1 && num[high] == num[high + 1]){
					high--;
					continue;
				}
				int sum = num[low] + num[high];
				if(sum < newtar) low++;
				else if(sum > newtar) high--;
				else{
					vector<int> fourplets;
					fourplets.push_back(num[i]);
					fourplets.push_back(num[j]);
					fourplets.push_back(num[low]);
					fourplets.push_back(num[high]);
					res.push_back(fourplets);
					low++;high--;
				}
			}
		}
	}
	return res;
}

int main(){
	int nums[] = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<int> num;
	num.assign(nums, nums + 6);
	vector<vector<int>> res = foursum(num, target);

	for(vector<int> one : res){
		cout << "{";
		for(int num : one){
			cout << " " << num;
		}
		cout << "}" << endl;
	}
		
	return 0;
}
