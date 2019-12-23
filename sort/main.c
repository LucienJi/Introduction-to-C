#include <stdio.h>
#include "sort.c"
int main() {
    int array[] = {4,2,5,1,3,6,7,3,45,27,4,3978,44,1,1,1,2};
    Quicksort(array,17);
    print(array,17);
    return 0;
}