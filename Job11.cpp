#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int h[n];
    int a[n];
    int b[n];

    for(int i=0; i<n; i++) {
        cin >> h[i];
        cin >> a[i];
        cin >> b[i];
    }

    //gained box dimensions

    //task - find the tallest tower we can build without changing the order of the boxes 
    //and without the box above having higher dimensions than the box below (Make a pyramid or tower)
    //we can remove blocks

    //use dynamic table
    int dp[n][n]; //represents the tallest tower we can build from 0 to i with each element

    //init everything with zero
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }

    //i is for the top block and j is for every block that can be placed below it
    //second array contains a number that is the height of the tower
    //eg with boxes that are:
        //(5, 5, 5), (5, 4, 4), (7, 4, 5), (5, 3, 3), (3, 2, 2), (3, 1, 1)
    //[5, 5, 7, 5, 3, 3], [10, 5, 12, 5, 3, 3], [15, 5, 12, 5, 3, 3], [20, 10, 17, 5, 3, 3], [23, 13, 20, 8, 3, 3], [26, 16, 23, 11, 6, 3]

    // bool rm[n]; //represents the removed blocks
    int tallest = 0;

    for(int i=0; i<n; i++) {
        cout << "[ ";
        for(int j=i; j<n; j++) {
            //edge cases
            if(i==0) {
                dp[i][j] = h[j]; //any box can be placed by itself and form a tower
                if(tallest < dp[i][j]) {
                    tallest = dp[i][j];
                }
                cout << dp[i][j] << " ";
                continue;
            }
            if(i==j) {
                dp[i][j] = dp[i-1][j];
                cout << dp[i][j] << " ";
            } else {
                //main comparison
                if(a[i] < a[j] || b[i] < b[j]) {
                    cout << "(" << dp[i-1][j] << ") + " << h[i] << " ";
                    dp[i][j] = dp[i-1][j] + h[i];
                    //add the current box height to it
                    if(tallest < dp[i][j]) {
                        tallest = dp[i][j];
                    }
                } else {
                    //the current box cannot be placed onto the i box
                    //either cuz size is bigger or cuz it's the same box
                    //do not add height. Carry previous
                    dp[i][j] = dp[i-1][j];
                    cout << dp[i][j] << " ";
                }
            }
        }
        cout << " ]\n";
    }

    cout << tallest;

    return 0;
}