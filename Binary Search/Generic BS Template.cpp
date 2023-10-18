/*
Generalized Binary Search:
        0 1 2 3 4 5 6 
arr[] = [1,2,3,5,7,9,12]
        [F,T,T,T,T,T,T]
        [F,F,T,T,T,T,T]
target = 2

LowerBound -> it is the index of the element in the given arr which is greater than or equal to the target
        (element >= target)
        lowerBound(9) = 5
        lowerBound(10) = 6

UpperBound -> it is the index of the element on the given array which is greater than the target
        (element > target)
        upperBound(9) = 6
        upperBound(10) = 6

*/
/*
BinarySearch -> search for the target
    [F,F,F,F,F,F,F,T,F]

LowerBound:
    [F,F,F,F,F,T,T,T,T,T]

UpperBound
    [F,F,F,T,T,T,T,T]

*/

#include<iostream>
#include<vector>

using namespace std;

// GENERIC TEMPLATE
bool condition(int midVal, int target){
    return midVal >= target;
}

int BinarySearch(vector<int>& arr, int target){

    int n = arr.size();
    int left = 0;
    int right = n-1;

    int ans = -1; // if everything is F, then return initialized value

    while (left <= right){

        int mid = left + (right-left)/2;

        if( condition(arr[mid], target) ){
            ans = mid;
            right = mid-1; // left = mid+1
        }
        else {
            left = mid + 1; // right = mid-1;
        }

    }

    return ans;
}

/*
    NOTES:
    1. left=0 and right=n-1
    2. while(left <= right)
    3. left = mid+1 and right = mid-1  
    4. (left = mid || right = mid) -> not allowed
*/
