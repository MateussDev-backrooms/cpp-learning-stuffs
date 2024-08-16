#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int coin_types = 3;
    int wallet[coin_types];
    for(int i=0; i<coin_types; i++) {
        cin >> wallet[i];
    }

    cout << "What is the target money to get?: ";
    int target;
    cin >> target;
    
    int spec_ways[target+1];
    spec_ways[0] = 1;

    for(int i=1; i<target+1; i++) {
        spec_ways[i] = 0;
        for(int j=0; j<coin_types; j++) {
            if(i-wallet[j]>=0) {
                spec_ways[i] += spec_ways[i-wallet[j]];
            }
        }
    }

    for(int i=0; i<target+1; i++) {
        cout << spec_ways[i] << " ";
    }

    
    return 0;
}