#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int maxarea(vector<int> height){
	if(height.size() == 0) return 0;
	int ans = 0;
	int low = 0, high = height.size() - 1;
	while(low < high){
		//update answer.
		ans = max(ans, (high - low) * min(height[low],height[high]));
	       	//move lower pointer towards center.
		if(height[low] < height[high]) low++;
		else high--;	
	}
	return ans;
}

int main(){
	vector<int> height;
	int myint;
	cout << "Please enter some integers." << endl;

	do{
		cin>>myint;
		height.push_back(myint);
	}while(myint);
	cout << maxarea(height) << endl;
	return 0;
}
