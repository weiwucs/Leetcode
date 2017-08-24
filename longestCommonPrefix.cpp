#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> strs){
	if(strs.size() == 0) return "";
	if(strs.size() == 1) return strs[0];

	string word = strs[0];
	int prefixlen = word.length();

	for(int i = 1; i < strs.size(); i++){
		string nextword = strs[1];
		prefixlen = min(prefixlen, (int)nextword.length());
		for(int j = 0; j < prefixlen; j++){
			if(word.at(j) != nextword.at(j)){
				prefixlen = j;
				break;
			}
		}
	}
	return word.substr(0,prefixlen);
}

int main(){
	vector<string> strs;//"aaacbb","aabcc","aacba","aaa"
	strs.push_back("aaacbb");
	strs.push_back("aabcc");
	strs.push_back("aacba");
	strs.push_back("aaa");
	cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
	return 0;
}
