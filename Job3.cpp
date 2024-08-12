#include <iostream>
using namespace std;

int main()
{
    int l = 0;
    cout << "Insert array length: ";
    cin >> l;
    cout << "Insert an array element for each item. Make sure it's sorted: "  << "\n";

    int arr[l];

    for(int i=0; i<l; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }

    int q_sum = 0;
    int q_a, q_b;
    int i_inv = 0;
    int i_start = 0; 
    int i_end = l-1;
    bool found = false;
    cout << "Insert the sum to find in this array: ";
    cin >> q_sum;
    cout << "Insertion of complete. Finding sum..."  << "\n";

    for(int i=0; i<l; i++) {
        
        if(arr[i_start] + arr[i_end] > l) {
            i_end -= 1;
        }
        if(arr[i_start] + arr[i_end] < l) {
            i_start += 1;
        }
        if(arr[i_start] + arr[i_end] == q_sum) {
            found = true;
            q_a = arr[i_start];
            q_b = arr[i_end];
            break;
        }
        // 1, 2, 3, 4, 5, 6, 7, 8, 9

    }

    if(found) {
        cout << "Found your sum as " << q_a << "+" << q_b << " = " << q_sum;
    } else {
        cout << "Sum not present in array";
    }

    return 0;
}