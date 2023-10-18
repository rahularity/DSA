
/*
             0 1 2 3 4 5 6 
    arr[] = [1,2,3,5,7,9,12]
    target = 9

    LowerBound -> it is the index of the element in the given arr which is greater than or equal to the target
            (element >= target)
            lowerBound(9) = 5
            lowerBound(10) = 6

    UpperBound -> it is the index of the element on the given array which is greater than the target
            (element > target)
            upperBound(9) = 6
            upperBound(10) = 6
*/

#include<iostream>
using namespace std;

int lowerBound(vector<int>& arr, int target){ // 2

    int left = 0;
    int right = arr.size()-1;

    int ans = -1;
    while( left <= right ){  // 2<=1
        int mid = (left + right)/2;

        // [1,2,3,5,7,9,12]
        if(arr[mid] >= target){
            ans = mid;  // 1
            right = mid-1; // 1
        }
        else{
            left = mid+1; // 2
        }

    }
    return ans;
}

int upperBound(vector<int>& arr, int target){ // 2

    int left = 0;
    int right = arr.size()-1;

    int ans = -1;
    while( left <= right ){  // 
        int mid = (left + right)/2;

        // [1,2,3,5,7,9,12]
        if(arr[mid] > target){ // 2>2
            ans = mid;  // 3
            right = mid-1; // 1
        }
        else{
            left = mid+1; // 1
        }

    }
    return ans;
}


int main(){

    vector<int> arr = {1,2,3,5,7,9,12};
    int target = 8;

    cout << lowerBound(arr, 2) << "\n";
    cout << upperBound(arr, 2);

}



