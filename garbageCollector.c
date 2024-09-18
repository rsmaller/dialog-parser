#include <stdlib.h>
int currentFreeArrayIndex = 0;
int freeArraySize = 4;
void **nodeFreeArray;

void *smartMalloc(size_t size) {
	void *mallocedPointer = malloc(size);
    if (currentFreeArrayIndex >= (int)(freeArraySize / 2)) {
        freeArraySize *= 2;
        nodeFreeArray = (void **)realloc(nodeFreeArray, sizeof(void *) * freeArraySize);
    }
	nodeFreeArray[currentFreeArrayIndex++] = mallocedPointer;
	return mallocedPointer;
}

void freeFromArray(void **arrayToFree) {
	for (int i=0; i<currentFreeArrayIndex; i++) {
		free(arrayToFree[i]);
	}
	free(arrayToFree);
}

int main() {
    nodeFreeArray = (void **)malloc(sizeof(void *) * freeArraySize);

	int *myPointer = (int *)smartMalloc(sizeof(int)*4);
	// go ham here
	freeFromArray(nodeFreeArray);
}