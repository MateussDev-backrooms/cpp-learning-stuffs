#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int baba_amount;

    cout << "How many babas are in the queue? - ";
    cin >> baba_amount;

    int baba_time_alone[baba_amount];
    int baba_time_duo[baba_amount-1];

    cout << "How long each baba will get their groceries alone? \n";
    for(int i=0; i<baba_amount; i++) {
        cout << "Baba " << i << ": ";
        cin >> baba_time_alone[i];
    }

    cout << "How long do adjacent babas ( 0&1 or 1&2 ) take to get groceries? \n";
    for(int i=0; i<baba_amount-1; i++) {
        cout << "Baba " << i << " and " << i+1 << ": ";
        cin >> baba_time_duo[i];
    }

    bool baba_entered[baba_amount];
    int dynamic_baba[baba_amount];

    for(int i=0; i<=baba_amount; i++) {
        baba_entered[i] = false;
    }

    //attempt 1
    //idea is to compare whether the adjacent babas are faster separately or together
    //if the baba at i and i+1 time is faster than the duo, then add the first one to the time and mark i for entered
    //if it's faster together, then add the duo to the time and mark both for entered

    //attempt 2
    //Use dynamic programming duh

    dynamic_baba[0] = baba_time_alone[0];

    if(baba_amount > 1) {
        dynamic_baba[1] = min(baba_time_alone[0] + baba_time_alone[1], baba_time_duo[0]);
    }

    for(int i=2; i<baba_amount; i++) {
        dynamic_baba[i] = min(dynamic_baba[i-1] + baba_time_alone[i], dynamic_baba[i-2] + baba_time_duo[i-1]);
    }

    int time = dynamic_baba[baba_amount-1];
    cout << "Fastest time babas can go through the queue is: " << time;

    return 0;
}