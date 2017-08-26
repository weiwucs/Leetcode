#include <iostream>
#include <string>

using namespace std;

int numdecodings(string s){
	int len = s.length();
	if(s.empty()) return 0;

	int ways[len + 1];

	ways[0] = 1;
	ways[1] = s.at(0) != '0' ? 1 : 0;
	for(int i = 2; i <= len; i++){
		if(s.at(i - 1) != '0'){
			ways[i] = ways[i - 1];
		}
		int val = (s.at(i - 2) - '0') * 10;
		if(val <= 26 && val >= 10){
			ways[i] += ways[i - 2];
		}
	}
	return ways[len];
}


int main(){
	string ts = "123";
	int ans = numdecodings(ts);
	cout << ans << endl;
	return 0;
}
