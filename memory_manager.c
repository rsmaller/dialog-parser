#include <stdlib.h>
#include <stdio.h>

int pointerInArray(void *ptrArg, void **ptrArray, int pointerArrayLength) {
    for (int i=0; i<pointerArrayLength; i++) {
        if (ptrArray[i] == ptrArg) {
            return 1;
        }
    }
    return 0;
}

int main() {
    void **myArray = (void**)malloc(sizeof(void *) * 5000);
    void *myPtr;
    myArray[0] = myPtr;
    printf("%p\n", myArray[0]);
    printf("%d\n", pointerInArray(myPtr, myArray, 5000));
}