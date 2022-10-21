#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void print(int arr[], int len){
    for (int x = 0; x < len; x ++){
        cout << arr[x] << " ";
    }
    cout << endl;
}

size_t size(int arr[]){
    size_t size = sizeof(arr) / sizeof(arr[0]);
    return size;
}

// Brute Force Impementation
void selectSort(int array[], int length){
    print(array,length);
    for (int x = 0 ; x < length ; x++){
        int LHS = array[x];
        int lower = array[x+1];
        int indexOfLower;
        for (int y = x; y < length; y++){
            if (array[y] <= lower) {
                lower = array[y];
                indexOfLower = y;
            }
        }
        int intermediate = LHS;
        array[x] = lower;
        array[indexOfLower] = intermediate;
        cout << endl;
        print(array,length);
    }
}
void bubbleSort(int arr[],int len){
    // Bubble largest value to top
    const int length = len;
    print(arr,length);
    while(len>0){
        for (int x = 0 ; x < len-1; x++){
            if (arr[x]>arr[x+1]){
                int intermediate = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = intermediate;
                cout << endl;
                print(arr,length);
            }
        }
        len--;
    }
}

// Decrease and Conquer
void insertSort(int arr[], int len){
    // Find where to "insert" last value in array, the shift everything to right

    // Base Case - else
    if (len == 1){
        if (arr[0] > arr[1]) {
            swap(arr[0],arr[1]);
        }
//        cout << "LastVal: " << arr[len] << endl;
        print(arr,len);
    } else {
        // Recurse giving smaller problem
        insertSort(arr, len - 1);
        int lastVal = arr[len];
        int max=arr[0];
        for (int x = 0; x < len; x++) {
            cout << arr[x] << " ";
            if(lastVal<arr[0]){
                for (int y = len; y >0; y--){
//                    arr[y] = arr[y-1];
                }
//                arr[0] = lastVal;
                cout << lastVal << " < " << arr[x] << endl;
            }
            else if (lastVal>arr[x] && lastVal<arr[x+1]){
                cout << "MIDDLE VALUE " << endl;
            }
            else{
                max = arr[x];
                if (x == len-1){
                    // Max is indeed the "largest number"
                }

                cout << lastVal << " > " << arr[x]  << "    MAX: " << max<< endl;
            }
//            else {
//                // found place
//                cout << arr[x] << " < "<< lastVal << " > " << arr[x+1] << endl;
//            }
        }
        cout << endl;
        print(arr,len);
        cout << endl;
//        cout << "LastVal: " << arr[len] << endl;
    }
}
void binarySearch(int arr[], int key, int start, int end){

    if (end < start){
        cout << "Nothing found" << endl;
    }
    int mid = floor((start+end)/2);
    if (key > arr[mid]){
        binarySearch(arr, key, mid+1, end);
    } else if (key < arr[mid]) {
        binarySearch(arr, key, start, mid-1);
    } else {
        cout << "Key: " << key << " = " << mid << endl;
    }

}

int main() {

    int array[] = {6,2,10,1,0,8,3,9,13};
    size_t size = sizeof(array) / sizeof(array[0]);
    sort(array, array+size);
    print(array, size);
//    selectSort(array,6);
//    bubbleSort(array,7);
//    insertSort(array, 6);
    binarySearch(array,3,0,(int)size-1);
    return 0;
}
