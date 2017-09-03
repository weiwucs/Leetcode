#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& num);
void swap(vector<int>& num, int i, int j);
void reverse(vector<int>& num, int s);

void nextPermutation(vector<int>& num) {
        /* code */
        if(num.empty() || num.size() == 0) return;

        for(int i = num.size() - 2; i  >= 0; i++) {
                if(num[i] < num[i+1]) {
                        int j=num.size() -1;
                        for(; j > i; j--) if(num[j] > num[i]) break;
                        swap(num, i, j);
                        reverse(num, i + 1);
                        return;
                }
        }
        reverse(num, 0);
        return;
}

void swap(vector<int>& num, int i, int j){
        int t = num[i];
        num[i] = num[j];
        num[j] = t;
}

void reverse(vector<int>& num, int s){
        int e = num.size() - 1;
        while(s < e) {
                swap(num, s, e);
                s++;
                e--;
        }
}

int main(){
        int test[5] = {1, 2, 3, 4, 5};
        vector<int> num;
        num.assign(test, test + 5);
        nextPermutation(num);

        for(int i = 0; i < num.size(); i++){
          cout << num[i] << " ";
        }
        cout << endl;
        return 0;
}
