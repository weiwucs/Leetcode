#include <iostream>
#include <vector>

using namespace std;

/**
 * Binary Search
 * Check which half is sorted.
 * If target is within that half, search in that half.
 * If not, Search in the other half.
 */
int search(vector<int> A, int target){
        if(A.empty() || A.size() == 0) return -1;
        int l = 0;
        int r = A.size() - 1;
        int m;

        while(l <= r) {
                m = l + (r - l) / 2;
                if(A[m] == target) return m;
                if(A[m] >= A[l]) {//left half sorted
                        if(target >= A[l] && target < A[m]) {//
                                r = m - 1;
                        }else l = m + 1;
                }else{//right half sorted
                        if(target > A[m] && target <= A[r]) {//
                                l = m + 1;
                        }else r = m - 1;
                }
        }
        return -1;
}

int main(){
        int exm[] = {4, 5, 6, 7, 0, 1, 2};
        vector<int> A;
        A.assign(exm, exm + 7);
        int res = search(A, 1);
        cout << res << endl;
        return 0;
}
