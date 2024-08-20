#include <iostream>
using namespace std;


//bgwzabyetzazapte

int main()
{
    int lA = 0;
    cout << "Insert array A length: ";
    cin >> lA;
    cout << "Insert array A elements (char): "  << "\n";

    char arrA[lA];

    for(int i=0; i<lA; i++) {
        cout << "Element " << i << ": ";
        cin >> arrA[i];
    }
    int lB = 0;
    cout << "Insert array B length: ";
    cin >> lB;
    cout << "Insert array B elements (char): "  << "\n";

    char arrB[lB];

    for(int i=0; i<lB; i++) {
        cout << "Element " << i << ": ";
        cin >> arrB[i];
    }

    cout << "Finding longest substring that is contained in both arrays \n";

    int dp[lA][lB];
    int max = 0;
    int maxEndA, maxEndB;
    string longest_substring = "";

    //model of how it may work
    //arrA = kzaz, arrB = bazaz
    //[[0,0,0,0,0], [0,0,1 "z" ,0,1 "z"], [0,1 "a",1 "z",(1)+1 "za",1 "z"], [0,1 "a",(1)+1 "az",2 "za",(2)+1 "zaz"]]
    //damn das smart

    //dp represents the mutual substring present in arrA[0...i] and arrB[0...j]

    for(int i=0; i<lA; i++) {
        //for every letter in arrA check every other letter in arrB

        for(int j=0; j<lB; j++) {
            if(arrA[i] == arrB[j]) {
                if(i ==0 || j==0) {
                    dp[i][j] = 1; //if the first elements are equal, then sequence already is with length 1
                } else {
                    dp[i][j] = dp[i-1][j-1] + 1; //Current substring can be extended by one. Done by taking the length of the last + 1
                    if(dp[i][j] > max) {
                        max = dp[i][j];
                        maxEndA = i;
                        maxEndB = j;
                    }
                }
            } else {
                dp[i][j] = 0; //end of substring
            }
        }
    }
    
    if(max > 0) {
        for(int i = maxEndA-max+1; i<=maxEndA; i++) {
            longest_substring += arrA[i];
        }
    }

    cout << "Longest common substring is : '" << longest_substring << "'";
    
    return 0;
}