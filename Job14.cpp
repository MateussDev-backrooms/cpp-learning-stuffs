#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> country[1000000];
int main()
{
    
    int n, m;
    cin >> n >> m;

    //n - number of ppl in country
    //m - number of couples

    //insert couples
    for(int i=0; i<m; i++) {
        int c1, c2;
        
        country[i].push_back(c1);
        country[i].push_back(c2);
    }


    return 0;
}