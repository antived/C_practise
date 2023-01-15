/******************************************************************************
** Program to compute mean, median, mode of array of floats
******************************************************************************/
#include <stdio.h>

#define MAXARR 20                // maximum array size
typedef float FloatArr[MAXARR];     // define named type of float array


/*
** sort() - return sorted array of floats
*/
int sort(FloatArr *arr, int arrLen) {
    if ((arrLen < 2) || (arr == NULL)) {
        return -1;
    }
    float temp=0;
    for (int i=0; i<arrLen-1; i++) {
        if ((*arr)[i] > (*arr)[i+1]) {
            temp = (*arr)[i+1];
            (*arr)[i+1] = (*arr)[i];
            (*arr)[i] = temp;
        }
    }
    
    return arrLen;
}

/*
** mean() - return float value that is a mean i.e. average of an array of floats
**          arguments are array of float values, and integer length of array
**          returns -1 in case of error
*/
float mean(float arr[], int arrLen) {
    if ((arrLen < 1) || (arr == NULL)) {
        return -1;
    }
    float sum=0;
    for (int i=0; i<arrLen; i++) {
        sum = sum + arr[i];
    }
    return (sum/arrLen);
}

/*
** median() - return float value that is the median value of an array of floats
**          arguments are array of float values, and integer length of array
**          returns -1 in case of error
*/
float median(float arr[], int arrLen) {
    
    return 1.0;
}

/*
** mode() - return float value that is the mode of an array of floats
**          arguments are array of float values, and integer length of array
**          returns -1 in case of error
*/
float mode(float arr[], int arrLen) {
    return 1.0;
}

/*
** readArr() - return a float array read-in from the keyboard entered by user
**          interactively. returns the length of array, or -1 in case of error
**          Note: Maximum array length is defined by MAXARR constant
*/
int readArr(FloatArr* arr, int arrLen) {
    if (arrLen < 1) {
        return -1;
    }
    
    printf("Enter %d floating point values one by one as prompted below:\n", arrLen);
    float val=0;
    for (int i=0; i<arrLen; i++) {
        printf("%d> ", i);
        fflush(stdin);
        scanf("%f", &val);
        (*arr)[i] = val;
    }
    
    return arrLen;
}

int main()
{
    int len=0;
    float res=0;
    FloatArr farr;
    
    printf("This program computes mean, median, mode for a list of float values.\n");
    printf("Enter the length of the list of values (<= 20): ");
    fflush(stdin);
    scanf("%d", &len);
    if ((len < 1) || (len > 20)) {
        printf("Invalid length of list entered. It's value can only be between 1 and 20.\n");
        return(-1);
    }

    res = readArr(&farr, len);
    if (res < 0) {
        printf("Error: Unable to read array from user\n");
        return(-1);
    }
    
    int choice=0;
    while (1) {
        printf("\nWhich one would you like to do ?\n");
        printf("1. Calculate mean\n");
        printf("2. Calculate median\n");
        printf("3. Calculate mode\n");
        printf("4. Sort list\n");
        printf("5. Stop program\n");
        printf("        Enter your choice [1 / 2 / 3 / 4 / 5]: ");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                res = mean(farr, len);
                printf("The mean value for the list is: %f\n", res);
                break;
            case 2:
                res = median(farr, len);
                printf("The median value for the list is: %f\n", res);
                break;
            case 3:
                res = mode(farr, len);
                printf("The mode value for the list is: %f\n", res);
                break;
            case 4:
                res = sort(&farr, len);
                if (res < 0) {
                    printf("Issue sorting array\n");
                    return(-1);
                }
                printf("Sorted array: ");
                for (int i=0; i<len; i++) {
                    printf("%f, ", farr[i]);
                }
                printf("\n");
                break;
            case 5:
                return(0);
                break;
            default:
                printf("Entered unrecognized choice..\n\n");
                continue;
        }
    }
    return 0;
}
