/*

    arr = [1,2,3,4,5,6]
    arr = [1,2,3,4,5,6,7]

    target = integer

    output: index at which the target is present
            if the target is not in the array then return -1


    NOTES:
        1. Never use while(left < right)   -> wrong result
        2. Always use while(left <= right) & right = arr.size()-1   -> correct result

*/

#include<iostream>
using namespace std;

int binarySearch(vector<int>& arr, int target){

    int left = 0;
    int right = arr.size()-1;  // arr.size()

    while( left <= right ){
        int mid = (left + right) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return -1;

}


int main(){

    vector<int> arrOfEvenLength = {1,2,3,4,5,6};
    vector<int> arrOfOddLength = {1,2,3,4,5,6,7}; 

    // if target is present in between the array
    // if target is greater than greatest element of the array
    // if target is smaller than smallest element of the array
    // if the target is the first element
    // if the target is the last element


    cout << "target is present in between somewhere\n";
    cout << "index of target in evenLengthArray: " << binarySearch(arrOfEvenLength, 2) << "\n";
    cout << "index of target in oddLengthArray: " << binarySearch(arrOfOddLength, 2) << "\n\n";

    cout << "if target is not present (greater than greatest element of the array)\n";
    cout << "index of target in evenLengthArray: " << binarySearch(arrOfEvenLength, 100) << "\n";
    cout << "index of target in oddLengthArray: " << binarySearch(arrOfOddLength, 100) << "\n\n";

    cout << "if target is not present (smaller than smallest element of the array)\n";
    cout << "index of target in evenLengthArray: " << binarySearch(arrOfEvenLength, 0) << "\n";
    cout << "index of target in oddLengthArray: " << binarySearch(arrOfOddLength, 0) << "\n\n";

    cout << "target is present at start\n";
    cout << "index of target in evenLengthArray: " << binarySearch(arrOfEvenLength, 1) << "\n";
    cout << "index of target in oddLengthArray: " << binarySearch(arrOfOddLength, 1) << "\n\n";

    cout << "target is present at end\n";
    cout << "index of target in evenLengthArray: " << binarySearch(arrOfEvenLength, 6) << "\n";
    cout << "index of target in oddLengthArray: " << binarySearch(arrOfOddLength, 7) << "\n\n";



}


