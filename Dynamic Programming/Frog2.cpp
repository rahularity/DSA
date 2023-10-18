#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n,k;
    cin >> n >> k;

    vector<int> stones(n);
    for(int i=0 ; i<n ; i++){
        int stoneHeight;
        cin >> stoneHeight;
        stones[i] = stoneHeight;
    }


    //dp[i] = min cost from i to end
    vector<int> dp(n,1e9);
    dp[n-1] = 0; // fulfilled base case

    for(int i=n-2 ; i>=0 ; i--){
        for(int j=1 ; j<=k ; j++){
            if(i+j < n){
                dp[i] = min(dp[i+j] + abs(stones[i] - stones[i+j]), dp[i]);
            }
        }
    }

    cout << dp[0] << "\n";

}
