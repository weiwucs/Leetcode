#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> A, int target){
        if(A.empty() || A.size() == 0) return 0;
        int l = 0;
        int r = A.size() - 1;
        int m;
        while(l <= r) {
                m = l + (r - l) / 2;
                if(A[m] == target) return m;
                else if(A[m] > target) r = m - 1;
                else l = m + 1;
        }
        return l;
}

int  main(){
        int exm[] = {1, 3, 5, 6};
        vector<int> A;
        A.assign(exm, exm + 4);
        cout << searchInsert(A, 5) << endl;
        cout << searchInsert(A, 2) << endl;
        cout << searchInsert(A, 7) << endl;
        cout << searchInsert(A, 0) << endl;
        return 0;
}
