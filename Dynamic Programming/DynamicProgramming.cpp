
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int happiness[n+1][3];
    int day = 1;

    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        happiness[day][0] = a;
        happiness[day][1] = b;
        happiness[day][2] = c;
        day++;
    }

    int dp[n+1][3];

    dp[1][0] = happiness[1][0];
    dp[1][1] = happiness[1][1];
    dp[1][2] = happiness[1][2];

    for(int i=2 ; i<=n ; i++){
        dp[i][0] = happiness[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = happiness[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = happiness[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    return max(max(dp[n][0], dp[n][1]), dp[n][2]);

}

