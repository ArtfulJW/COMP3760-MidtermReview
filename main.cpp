#include <iostream>

using namespace std;

void print(int arr[], int len){
    for (int x = 0; x < len; x ++){
        cout << arr[x] << " ";
    }
}

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

int main() {

    int array[] = {2,6,10,1,0,8,11};
//    selectSort(array,6);
    bubbleSort(array,7);

    return 0;
}
