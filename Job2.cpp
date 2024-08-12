#include <iostream>
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

    cout << "Insertion of complete. Finding largest element..."  << "\n";

    int largest = -1;
    int largest_i = 0;
    for(int i=0; i<l; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
            largest_i = i;
        }
    }

    cout << "Largest element is: " << largest << " At index: " << largest_i << "\n";
    cout << "Looking for largest sum..."  << "\n";

    int lar_sum = -1;
    int lar_a = 0;
    int lar_b = 0;

    for(int i=0; i<l; i++) {
        if(arr[i] > lar_a) {
            lar_a = arr[i];
        }
        if(arr[i] > lar_b && arr[i] < lar_a) {
            //second largest element
            lar_b = arr[i];
        }
    }
    lar_sum = lar_a + lar_b;

    cout << "Largest sum of 2 elements is: " << lar_a << "+" << lar_b << " = " << lar_sum;

    return 0;
}