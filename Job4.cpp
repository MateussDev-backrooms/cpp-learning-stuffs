#include <iostream>
using namespace std;

void swap(int arr[], int i_from, int i_to) {
    int temp = arr[i_from];
    arr[i_from] = arr[i_to];
    arr[i_to] = temp;
}
void copy_arr(int from[], int to[], int length) {
    for(int i=0; i<length; i++) {
        to[i] = from[i];
    }
}

void copy_arr_range(int from[], int to[], int start, int end) {
    for(int i=start; i<end; i++) {
        to[i] = from[i];
    }
}

void merge_merge(int a[], int b[], int istart, int icenter, int iend) {
    int c_l = istart;
    int c_r = icenter;
    for(int i=istart; i<iend; i++) {
        if(c_l < icenter && (c_r >= iend || a[c_l] <= a[c_r])) {
            b[i] = a[c_l];
            cout << a[c_l] << " < " << a[c_r] << "\n";
            c_l++;
        } else {
            b[i] = a[c_r];
            cout << a[c_l] << " > " << a[c_r] << "\n";
            c_r++;

        }
    }
    // copy_arr_range(a, b, istart, iend);
    for(int i=istart; i<iend; i++) {
        a[i] = b[i];
    }
}

void merge_split(int a[], int b[], int istart, int iend) {
    cout << "split (" << istart << "-" << iend << ")" << "\n";
    if(iend - istart <= 1) {
        cout << " [One-element arrays are already sorted] \n";
        return;
    }
    
    int icenter = ( istart + iend )/2;
    merge_split(a, b, istart, icenter);
    merge_split(a, b, icenter, iend);

    cout << "merge (" << istart << "-" << iend << ")" << "\n";
    //merge split results
    merge_merge(a, b, istart, icenter, iend);
}

void merge_sort(int a[], int b[], int length) {
    copy_arr(a, b, length);
    merge_split(a, b, 0, length);
}

int main()
{
    cout << "Insert array length: ";
    int l = 0;
    cin >> l;
    cout << "Generating new random array... \n";
    int arr[l];

    for(int i=0; i<l; i++) {
        arr[i] = rand() % l*2;
    }

    cout << "Unsorted array: \n";
    cout << "[ ";
    for(int i=0; i<l; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    cout << "Sorting array via Merge Sort... \n";
    
    int arrw[l];

    merge_sort(arr, arrw, l);
    copy_arr(arrw, arr, l);

    cout << "Sorted array: \n";
    cout << "[ ";
    for(int i=0; i<l; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";


    
    return 0;
}