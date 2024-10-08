#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int currentFreeArrayIndex = 0;
int freeArraySize = 4;
void **nodeFreeArray;

void *smartMalloc(size_t size) {
	void *mallocedPointer = malloc(size);
	memset(mallocedPointer, 0, size);
    if (currentFreeArrayIndex >= (int)(freeArraySize / 2)) {
        freeArraySize *= 2;
        nodeFreeArray = (void **)realloc(nodeFreeArray, sizeof(void *) * (size_t)freeArraySize);
    }
	nodeFreeArray[currentFreeArrayIndex++] = mallocedPointer;
	return mallocedPointer;
}

void *smartRealloc(void *oldMallocedPointer, size_t oldSize, size_t newSize) {
	void *newMallocedPointer = realloc(oldMallocedPointer, newSize);
	memset((char *)newMallocedPointer+oldSize, 0, (size_t)(newSize-oldSize));
	for (int i=0; i<freeArraySize; i++) {
		if (nodeFreeArray[i] == oldMallocedPointer) {
			nodeFreeArray[i] = newMallocedPointer;
		}
	}
	return newMallocedPointer;
}

void freeFromArray(void **arrayToFree) {
	for (int i=0; i<currentFreeArrayIndex; i++) {
		free(arrayToFree[i]);
	}
	free(arrayToFree);
}

int main() {
    nodeFreeArray = (void **)malloc(sizeof(void *) * (size_t)freeArraySize);
	memset(nodeFreeArray, 0, sizeof(void *)*(size_t)freeArraySize);
	// go ham here
	freeFromArray(nodeFreeArray);
}