#include <stdio.h>
#include <stdbool.h>             // required for bool type handling

#define MAXARR 20                // maximum array size
typedef float FloatArr[MAXARR];     // define named type of float array


/*
** sort() - return sorted array of floats using efficient bubble-sort algorithm
**          Note: this implementation doesn't require N*N iterations, but N*M
**            iterations only, where M is mininum necessary for sorting. During
**            the outer loop iteration if no element is swapped, it is taken as
**            a hint that array is now already sorted, and no more outer iterations
**            are necessary
*/
int sort(FloatArr *arr, int arrLen) {
    if ((arrLen < 2) || (arr == NULL)) {
        return -1;
    }
    float temp=0;
    bool swapped=false;           // was any element swapped in the list
    for (int outer=0; outer<arrLen; outer++) {
        swapped = false;
        for (int i=0; i<arrLen-1; i++) {
            if ((*arr)[i] > (*arr)[i+1]) {
                temp = (*arr)[i+1];
                (*arr)[i+1] = (*arr)[i];
                (*arr)[i] = temp;
                swapped = true;
            }
        }
        if (!swapped) {         // if no element swapped in this iteration, list is fully sorted now
            break;
        }
    }
    return (arrLen);
}

int main() {
    FloatArr farr = {11.3, 1.6, 5.7, 13.9, 17.2, 18.1, 9.3};
    int len = 7;
    
    if (sort(&farr, len) < 0) {
        printf("Error sorting array");
        return -1;
    }
    printf("Sorted array: ");
    for (int i=0; i<len; i++) {
        printf("%f, ", farr[i]);
    }
}
