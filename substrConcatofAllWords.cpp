#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> findSubstring(string S, vector<string> L){
        vector<int> res;
        if(S.empty() || L.empty() || L.size()) return res;
        int len = L[0].length();

        map<string, int> maps;
        for(string w : L) maps.insert(pair<string, int>(w, maps.find(w) != NULL ? maps.at(w) + 1 : 1));

        for(int i = 0; i <= S.length() - len * L.size(); i++) {
                map<string, int> copy(maps);
                for(int j = 0; j < L.size(); j++) {
                        string str = S.substr(i + j*len, i + j*len + len);
                        if(copy.find(str)!= NULL) {
                                int cout = copy.at(str);
                                if(cout == 1) copy.erase(str);
                                else copy.insert(str, cout - 1);
                                if(copy.empty()) {
                                        res.push_back(i);
                                        break;
                                }
                        }else break;
                }
        }
        return res;
}

int main(){
        string S = "barfoothefoobarman";
        string exm[] = {"foo", "bar"};
        vector<string> L;
        L.assign(exm, exm + 2);
        vector<int> res;
        res = findSubstring(S, L);

        for(int l : res) {cout << l << " " << endl;}
        return 0;
}
