#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> stones(n);
    for(int i=0 ; i<n ; i++){
        int stoneHeight;
        cin >> stoneHeight;
        stones[i] = stoneHeight;
    }


    //dp[i] = min cost from i to end
    vector<int> dp(n,0);
    // dp[n-1] = 0; fulfilled base condition

    dp[n-2] = dp[n-1] + abs(stones[n-2] - stones[n-1]);

    for(int i=n-3 ; i>=0 ; i--){
        int choice1 = dp[i+1] + abs(stones[i] - stones[i+1]);
        int choice2 = dp[i+2] + abs(stones[i] - stones[i+2]);
        dp[i] = min(choice1, choice2);
    }

    cout << dp[0] << "\n";

}
