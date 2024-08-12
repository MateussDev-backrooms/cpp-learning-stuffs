#include <iostream>
using namespace std;

int main()
{
    cout << "Think of a number that is between 0 and 1000. Don't tell me it. \n";
    cout << "Now, I will predict it! At most I will use 10 tries! \n";
    bool found = false;
    int poolS = 0, poolE = 1000;
    int tries = 0;
    while(!found) {
        tries++;
        int prediction = (poolS+poolE)/2;
        cout << "My prediction is: " << prediction << ". Type 'up' if it's higher, 'down' if it's lower and 'real' if it's correct \n";
        string verdict = "";
        cin >> verdict;
        if(verdict == "real") {
            cout << "Yay! I did it in " << tries << " tries!";
            found = true;
        }
        else if(verdict == "up") {
            poolS = prediction;
        }
        else if(verdict == "down") {
            poolE = prediction;
        }
    }
    return 0;
}