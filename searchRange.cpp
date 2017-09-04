#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * suppose we have a binary search helper method
 * with array, start index, end index, and target as arguments
 * we can first search for the target in the whole array
 * if found, then search for its starting position
 * then search for its ending position
 * update range with search result and return
 */

int binarySearch(vector<int> A, int left, int right, int target){
        while(left <= right) {
                int mid = left + (right - left) / 2;
                //low <= mid < high
                if(A[mid] == target) return mid;
                else if(A[mid] > target) right = mid - 1;
                else left = mid + 1;
        }
        return -1;
}

vector<int> searchRange(vector<int> A, int target){
        vector<int> range;
        range.push_back(-1); range.push_back(-1);
        if(A.empty() || A.size() == 0) return range;
        int index = binarySearch(A, 0, A.size() - 1, target);
        if(index != -1) {
                int left = index;
                int right = index;
                range[0] = left;//if no more occurrence, set left and right first.
                range[1] = right;
                while((left = binarySearch(A, 0, left - 1, target)) != -1) range[0] = left;
                while((right = binarySearch(A, right + 1, A.size() - 1, target)) != -1) range[1] = right;
        }
        return range;
}



/**
 * find the first number that is greater than or equal to target.
 * could return A.length if target is greater than A[A.length - 1].
 * actually this is the same as lower_bound in C++ STL.
 */

int firstGreatEqual(vector<int> A, int target){
        int low = 0, high = A.size();
        while(low < high) {
                int mid = low + ((high - low) >> 1);
                //low <= mid < high
                if(A[mid] < target) {
                        low = mid + 1;
                }else {
                        //should not be mid-1 when A[mid] == target.
                        //could be mid even if A[mid] > target because mid < high.
                        high = mid;
                }
        }
        return low;
}

int main(){
        int exm[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        vector<int> A;
        vector<int> rangeA,rangeB;
        A.assign(exm, exm + 19);
        rangeA = searchRange(A, 3);
        cout << rangeA[0] << " " << rangeA[1] << endl;

        int start = firstGreatEqual(A, 3);
        if(start == A.size() || A[start] != 3) {
                rangeB.push_back(-1);rangeB.push_back(-1);
        }
        rangeB.push_back(start);
        rangeB.push_back(firstGreatEqual(A, 4) - 1);
        cout << rangeB[0] << " " << rangeB[1] << endl;
        return 0;
}
