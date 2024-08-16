#include <iostream>
#include <cmath>
using namespace std;

int main()
{
     int l = 0;
    cout << "Insert array length: ";
    cin >> l;
    cout << "Insert an array element for each item: "  << "\n";

    int arr[l];

    for(int i=0; i<l; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }

    cout << "Insertion of complete. Finding longest sequence..."  << "\n";
    int curr_sequenceSum;
    int curr_sequenceBegin;
    int LsequenceSum = -999999999;
    int LsequenceBegin;
    int LsequenceEnd;

    cout << "Skip mode? (y/n)"  << "\n";
    string _skp;
    bool skip_mode = false;
    cin >> _skp;
    if(_skp == "y") {
        skip_mode = true;
    }

    if(!skip_mode) {
        for(int i=0; i<l; i++) {
            if(i > 0) {
                cout << "==========\n";
                //at least second element
                bool condition ;
                bool conditionPos = abs(arr[i]) - abs(arr[i-1]) == 1;
                bool conditionNeg = abs(arr[i-1]) - abs(arr[i]) == 1;

                // if(arr[i-1] < 0 && arr[i]<0) {
                //     condition = conditionNeg;
                // } else {
                //     condition = conditionPos;
                // }
                if(conditionPos) {
                    //the number is the next number
                    //increase sum
                    curr_sequenceSum += arr[i];
                    cout << "{ "<< arr[i-1] << " - " << arr[i] << "} sequence {" << curr_sequenceBegin  << " - " << i << "} = " << curr_sequenceSum << "\n";

                    //check current sum
                    if(curr_sequenceSum > LsequenceSum) {
                        cout << "the current sum is larger than the largest before \n";
                        LsequenceSum = curr_sequenceSum;
                        LsequenceBegin = curr_sequenceBegin;
                        // cout << "L sequence {" << LsequenceBegin  << " - " << i << "} = " << LsequenceSum << "\n";
                        LsequenceEnd = i;
                    }

                } else {
                    //not next number
                    cout << "{ "<< arr[i-1] << " - " << arr[i] << " } are not an adjacent number... {broken} \n";
                    curr_sequenceSum = arr[i];
                    curr_sequenceBegin = i;
                    //check size
                    if(curr_sequenceSum > LsequenceSum) {
                        cout << "the current sum is larger than the largest before \n";
                        LsequenceSum = curr_sequenceSum;
                        LsequenceBegin = curr_sequenceBegin;
                        LsequenceEnd = i;
                    }
                    //begin new sequence
                    cout << "sequence begin {" << curr_sequenceBegin  << " - " << i << "} = " << curr_sequenceSum << "\n";

                }
            } else if(i == 0) {
                curr_sequenceSum = arr[i];
                curr_sequenceBegin = i;
                LsequenceBegin = i;
            }
        }

        //render result
        cout << "Largest sequence is: (" << LsequenceBegin << " - " << LsequenceEnd << ") \n" ;
        cout << "[ ";
        for(int i=LsequenceBegin; i<LsequenceEnd+1; i++) {
            cout << arr[i];
            if(i<LsequenceEnd) {
                cout << " + ";
            }
        }
        cout << " ] ";
        cout << " = " << LsequenceSum;
    } else {
        int curr_seq_end = 0;
        cout << "Largest sequence is: (" << LsequenceBegin << " - " << LsequenceEnd << ") \n" ;
        cout << "[ ";
        for(int i=0; i<l; i++) {
            if(i > 0) {
                //at least second element
                if(abs(arr[i]) - abs(arr[curr_seq_end]) == 1) {
                    //the number is the next number
                    //increase sum
                    // curr_sequenceSum += arr[i];
                    curr_seq_end = i;
                    cout << arr[i];
                    if(i<l-1) {
                        cout << " + ";
                    }
                    //check current sum

                } else {
                    //not next number
                    // cout << "not an adjacent number... skipping... \n";
                    // //check size
                    // if(curr_sequenceSum > LsequenceSum) {
                    //     LsequenceSum = curr_sequenceSum;
                    //     LsequenceBegin = curr_sequenceBegin;
                    //     LsequenceEnd = i;
                    // }
                    // //begin new sequence
                    // curr_sequenceSum = arr[i];
                    // curr_sequenceBegin = i;
                    // cout << "sequence begin {" << curr_sequenceBegin  << " - " << i << "} = " << curr_sequenceSum << "\n";

                }
            } else if(i == 0) {
                cout << arr[i];
                if(i<l-1) {
                    cout << " + ";
                }
                // curr_sequenceSum = 1;
                curr_sequenceBegin = 0;
                LsequenceBegin = i;
            }
        }
        cout << " ] ";
    }

    

    return 0;
}