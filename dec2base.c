#include <stdio.h>
#include <math.h>

/*
** dec2base() - function that takes as input a decimal number, a base, and
**              returns the equivalent rebased number.
**              Note that this function works for base < 10 only
*/
int dec2base(int num, int base) {
    int quo;
    int digCount;
    int digArr[10];
    
    if (base >= 10)
        return -1;
    
    digCount=0;
    quo=base+1;
    
    while (1) {
        quo = num / base;
        digArr[digCount++] = num % base;    // remainder is a digit
        num = quo;
        if (quo <= base) {
            digArr[digCount++] = quo;
            break;
        }
    }
    
    num = 0;    // reuse this to assemble together rebased number
    
    for (int i=0; i<digCount; i++) {
        num = num + (digArr[i]*pow(10, i));
    }
    
    return num;
}

int main() {
    int decnum;
    int base;
    
    printf("Enter decimal number to rebase: ");
    fflush(stdin);
    scanf("%d", &decnum);
    
    printf("Enter base to rebase to: ");
    fflush(stdin);
    scanf("%d", &base);
    
    printf("Decimal %d rebased to base %d, is = %d\n", decnum, base, dec2base(decnum, base));
}