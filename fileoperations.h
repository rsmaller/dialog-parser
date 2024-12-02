#pragma 1
#include <stdio.h>
#include <stdlib.h>

char message[] = {72, 105, 32, 74, 97, 115, 111, 110, 44, 10, 10, 72, 97, 112, 112, 121, 32, 66, 105, 114, 116, 104, 100, 97, 121, 33, 33, 33, 32, 73, 32, 104, 111, 112, 101, 32, 116, 104, 105, 115, 32, 109, 101, 115, 115, 97, 103, 101, 32, 114, 101, 97, 99, 104, 101, 115, 32, 121, 111, 117, 32, 119, 101, 108, 108, 46, 32, 73, 32, 119, 114, 111, 116, 101, 32, 116, 104, 105, 115, 32, 115, 111, 109, 101, 32, 116, 105, 109, 101, 32, 10, 98, 101, 102, 111, 114, 101, 32, 121, 111, 117, 32, 119, 105, 108, 108, 32, 40, 111, 114, 32, 97, 108, 114, 101, 97, 100, 121, 32, 104, 97, 118, 101, 44, 32, 114, 97, 116, 104, 101, 114, 41, 32, 114, 101, 99, 101, 105, 118, 101, 32, 121, 111, 117, 114, 32, 103, 105, 102, 116, 32, 111, 110, 32, 121, 111, 117, 114, 32, 98, 105, 114, 116, 104, 100, 97, 121, 46, 32, 73, 32, 10, 119, 97, 110, 116, 101, 100, 32, 116, 111, 32, 99, 114, 101, 97, 116, 101, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 116, 104, 97, 116, 32, 119, 101, 108, 108, 32, 101, 110, 99, 97, 112, 115, 117, 108, 97, 116, 101, 115, 32, 111, 117, 114, 32, 102, 114, 105, 101, 110, 100, 115, 104, 105, 112, 44, 32, 115, 111, 32, 73, 32, 100, 105, 100, 32, 116, 104, 97, 116, 46, 32, 10, 77, 97, 121, 98, 101, 32, 109, 97, 107, 105, 110, 103, 32, 121, 111, 117, 114, 32, 103, 105, 102, 116, 32, 105, 110, 32, 67, 32, 119, 97, 115, 32, 97, 32, 98, 97, 100, 32, 105, 100, 101, 97, 46, 32, 79, 104, 32, 119, 101, 108, 108, 46, 32, 73, 116, 32, 100, 111, 101, 115, 110, 39, 116, 32, 109, 97, 116, 116, 101, 114, 46, 32, 84, 104, 101, 32, 10, 112, 111, 105, 110, 116, 32, 105, 115, 44, 32, 73, 32, 112, 117, 116, 32, 97, 32, 108, 111, 116, 32, 111, 102, 32, 116, 104, 111, 117, 103, 104, 116, 32, 98, 101, 104, 105, 110, 100, 32, 116, 104, 105, 115, 46, 32, 73, 32, 116, 104, 105, 110, 107, 32, 105, 116, 39, 115, 32, 116, 111, 111, 32, 101, 97, 115, 121, 32, 116, 111, 32, 108, 111, 115, 101, 32, 10, 116, 111, 117, 99, 104, 32, 119, 105, 116, 104, 32, 112, 101, 111, 112, 108, 101, 32, 97, 110, 100, 32, 98, 101, 99, 111, 109, 101, 32, 100, 105, 115, 99, 111, 110, 110, 101, 99, 116, 101, 100, 32, 119, 104, 101, 110, 32, 101, 105, 116, 104, 101, 114, 32, 121, 111, 117, 32, 111, 114, 32, 116, 104, 101, 121, 32, 97, 114, 101, 32, 98, 117, 115, 121, 46, 32, 73, 39, 109, 32, 10, 104, 111, 110, 101, 115, 116, 108, 121, 32, 107, 105, 110, 100, 32, 111, 102, 32, 97, 102, 114, 97, 105, 100, 32, 111, 102, 32, 116, 104, 97, 116, 32, 119, 105, 116, 104, 32, 97, 108, 108, 32, 111, 102, 32, 109, 121, 32, 102, 114, 105, 101, 110, 100, 115, 46, 32, 73, 32, 100, 111, 110, 39, 116, 32, 119, 97, 110, 116, 32, 112, 101, 111, 112, 108, 101, 32, 116, 111, 32, 10, 102, 101, 101, 108, 32, 100, 105, 115, 116, 97, 110, 116, 46, 32, 83, 111, 44, 32, 73, 39, 109, 32, 103, 111, 105, 110, 103, 32, 116, 111, 32, 97, 100, 100, 114, 101, 115, 115, 32, 97, 32, 102, 101, 119, 32, 116, 104, 105, 110, 103, 115, 32, 105, 110, 32, 116, 104, 105, 115, 32, 34, 108, 101, 116, 116, 101, 114, 34, 32, 119, 101, 39, 108, 108, 32, 99, 97, 108, 108, 32, 10, 105, 116, 44, 32, 115, 105, 110, 99, 101, 32, 116, 104, 105, 115, 32, 115, 101, 109, 101, 115, 116, 101, 114, 32, 104, 97, 115, 32, 98, 101, 101, 110, 32, 107, 105, 110, 100, 97, 32, 109, 101, 115, 115, 121, 32, 102, 111, 114, 32, 109, 101, 46, 32, 70, 105, 114, 115, 116, 108, 121, 44, 32, 73, 32, 119, 97, 110, 116, 101, 100, 32, 116, 111, 32, 116, 104, 97, 110, 107, 32, 10, 121, 111, 117, 32, 97, 32, 109, 105, 108, 108, 105, 111, 110, 32, 116, 105, 109, 101, 115, 32, 111, 118, 101, 114, 32, 102, 111, 114, 32, 116, 104, 101, 32, 103, 105, 102, 116, 46, 32, 73, 32, 110, 101, 118, 101, 114, 32, 101, 120, 112, 101, 99, 116, 101, 100, 32, 116, 111, 32, 104, 97, 118, 101, 32, 97, 32, 102, 114, 105, 101, 110, 100, 32, 119, 104, 111, 32, 10, 119, 111, 117, 108, 100, 32, 103, 111, 32, 111, 117, 116, 32, 111, 102, 32, 116, 104, 101, 105, 114, 32, 119, 97, 121, 32, 97, 110, 100, 32, 115, 112, 101, 110, 100, 32, 97, 32, 115, 105, 103, 110, 105, 102, 105, 99, 97, 110, 116, 32, 112, 97, 114, 116, 32, 111, 102, 32, 116, 104, 101, 105, 114, 32, 100, 97, 121, 32, 108, 111, 111, 107, 105, 110, 103, 32, 102, 111, 114, 32, 10, 97, 32, 103, 105, 102, 116, 32, 116, 111, 32, 108, 101, 116, 32, 116, 104, 101, 105, 114, 32, 102, 114, 105, 101, 110, 100, 32, 107, 110, 111, 119, 32, 116, 104, 101, 121, 32, 97, 114, 101, 32, 97, 112, 112, 114, 101, 99, 105, 97, 116, 101, 100, 46, 32, 65, 110, 100, 32, 106, 117, 115, 116, 32, 102, 111, 114, 32, 116, 104, 101, 32, 115, 97, 107, 101, 32, 111, 102, 32, 10, 112, 117, 116, 116, 105, 110, 103, 32, 105, 116, 32, 111, 117, 116, 32, 116, 104, 101, 114, 101, 44, 32, 121, 111, 117, 114, 32, 109, 101, 115, 115, 97, 103, 101, 32, 119, 97, 115, 32, 118, 101, 114, 121, 32, 109, 117, 99, 104, 32, 119, 101, 108, 108, 32, 114, 101, 99, 101, 105, 118, 101, 100, 46, 32, 73, 116, 39, 115, 32, 102, 117, 110, 110, 121, 32, 116, 104, 97, 116, 32, 10, 121, 111, 117, 32, 103, 111, 116, 32, 109, 101, 32, 116, 104, 101, 32, 66, 114, 101, 97, 116, 104, 32, 111, 102, 32, 116, 104, 101, 32, 87, 105, 108, 100, 32, 112, 111, 115, 116, 101, 114, 32, 115, 112, 101, 99, 105, 102, 105, 99, 97, 108, 108, 121, 59, 32, 73, 39, 118, 101, 32, 119, 97, 108, 107, 101, 100, 32, 112, 97, 115, 116, 32, 116, 104, 97, 116, 32, 10, 112, 111, 115, 116, 101, 114, 32, 109, 97, 110, 121, 32, 116, 105, 109, 101, 115, 32, 105, 110, 32, 78, 101, 119, 98, 117, 114, 121, 32, 67, 111, 109, 105, 99, 115, 32, 119, 111, 110, 100, 101, 114, 105, 110, 103, 32, 104, 111, 119, 32, 105, 116, 32, 119, 111, 117, 108, 100, 32, 108, 111, 111, 107, 32, 105, 110, 32, 109, 121, 32, 114, 111, 111, 109, 44, 32, 98, 117, 116, 32, 10, 73, 32, 110, 101, 118, 101, 114, 32, 104, 97, 100, 32, 116, 104, 101, 32, 103, 117, 116, 115, 32, 116, 111, 32, 98, 117, 121, 32, 105, 116, 32, 97, 110, 100, 32, 112, 117, 116, 32, 105, 116, 32, 111, 110, 32, 109, 121, 32, 119, 97, 108, 108, 46, 32, 83, 116, 105, 108, 108, 32, 119, 111, 114, 107, 105, 110, 103, 32, 111, 117, 116, 32, 116, 104, 101, 32, 10, 34, 112, 117, 116, 116, 105, 110, 103, 32, 105, 116, 32, 111, 110, 32, 109, 121, 32, 119, 97, 108, 108, 34, 32, 112, 97, 114, 116, 32, 98, 101, 99, 97, 117, 115, 101, 32, 73, 32, 100, 111, 32, 110, 111, 116, 32, 104, 97, 118, 101, 32, 97, 32, 108, 111, 116, 32, 111, 102, 32, 119, 97, 108, 108, 32, 115, 112, 97, 99, 101, 32, 97, 116, 32, 97, 108, 108, 46, 32, 10, 73, 39, 108, 108, 32, 102, 105, 103, 117, 114, 101, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 111, 117, 116, 46, 32, 65, 110, 121, 119, 97, 121, 44, 32, 109, 121, 32, 112, 111, 105, 110, 116, 32, 119, 105, 116, 104, 32, 119, 104, 121, 32, 105, 116, 39, 115, 32, 105, 110, 116, 101, 114, 101, 115, 116, 105, 110, 103, 32, 105, 115, 32, 116, 104, 97, 116, 32, 73, 32, 10, 110, 101, 118, 101, 114, 32, 108, 105, 107, 101, 100, 32, 112, 111, 115, 116, 101, 114, 115, 32, 111, 114, 32, 103, 105, 102, 116, 115, 32, 97, 108, 108, 32, 116, 104, 97, 116, 32, 109, 117, 99, 104, 46, 32, 73, 32, 111, 102, 116, 101, 110, 32, 114, 101, 99, 101, 105, 118, 101, 100, 32, 103, 105, 102, 116, 115, 32, 111, 117, 116, 32, 111, 102, 32, 10, 111, 98, 108, 105, 103, 97, 116, 105, 111, 110, 32, 111, 114, 32, 115, 105, 109, 112, 108, 121, 32, 116, 104, 101, 32, 105, 100, 101, 97, 32, 116, 104, 97, 116, 32, 105, 116, 32, 119, 97, 115, 32, 119, 114, 111, 110, 103, 32, 116, 111, 32, 103, 101, 116, 32, 109, 101, 32, 110, 111, 116, 104, 105, 110, 103, 46, 32, 71, 105, 102, 116, 115, 32, 97, 108, 119, 97, 121, 115, 32, 10, 109, 97, 100, 101, 32, 109, 101, 32, 102, 101, 101, 108, 32, 100, 105, 115, 116, 97, 110, 116, 44, 32, 108, 105, 107, 101, 32, 110, 105, 99, 101, 32, 103, 101, 115, 116, 117, 114, 101, 115, 32, 119, 101, 114, 101, 32, 111, 110, 108, 121, 32, 103, 105, 118, 101, 110, 32, 116, 111, 32, 109, 101, 32, 98, 101, 99, 97, 117, 115, 101, 32, 73, 32, 119, 97, 115, 32, 97, 32, 10, 99, 104, 105, 108, 100, 32, 111, 102, 32, 109, 121, 32, 112, 97, 114, 101, 110, 116, 115, 44, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 111, 117, 116, 115, 105, 100, 101, 32, 111, 102, 32, 109, 121, 32, 99, 111, 110, 116, 114, 111, 108, 44, 32, 102, 114, 111, 109, 32, 109, 121, 32, 105, 109, 109, 101, 100, 105, 97, 116, 101, 32, 97, 110, 100, 32, 10, 101, 120, 116, 101, 110, 100, 101, 100, 32, 102, 97, 109, 105, 108, 121, 46, 32, 73, 116, 39, 115, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 73, 32, 97, 109, 32, 115, 116, 105, 108, 108, 32, 119, 111, 114, 107, 105, 110, 103, 32, 111, 110, 44, 32, 98, 117, 116, 32, 114, 101, 97, 108, 105, 122, 101, 32, 105, 116, 32, 111, 114, 32, 110, 111, 116, 44, 32, 10, 121, 111, 117, 39, 118, 101, 32, 104, 101, 108, 112, 101, 100, 32, 109, 101, 32, 97, 32, 108, 111, 116, 32, 98, 121, 32, 103, 105, 102, 116, 105, 110, 103, 32, 109, 101, 32, 116, 104, 97, 116, 32, 112, 111, 115, 116, 101, 114, 46, 32, 89, 111, 117, 32, 119, 101, 110, 116, 32, 111, 117, 116, 32, 111, 102, 32, 121, 111, 117, 114, 32, 119, 97, 121, 32, 116, 111, 32, 10, 103, 101, 116, 32, 109, 101, 32, 97, 32, 103, 105, 102, 116, 32, 111, 102, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 121, 111, 117, 32, 107, 110, 101, 119, 32, 73, 32, 108, 105, 107, 101, 100, 44, 32, 97, 110, 100, 32, 105, 116, 32, 119, 97, 115, 32, 105, 114, 111, 110, 105, 99, 97, 108, 108, 121, 32, 116, 119, 111, 32, 116, 104, 105, 110, 103, 115, 32, 73, 32, 10, 119, 111, 117, 108, 100, 32, 110, 111, 114, 109, 97, 108, 108, 121, 32, 100, 105, 115, 108, 105, 107, 101, 46, 32, 84, 104, 97, 110, 107, 32, 121, 111, 117, 32, 102, 111, 114, 32, 115, 104, 111, 119, 105, 110, 103, 32, 109, 101, 32, 116, 104, 101, 32, 103, 111, 111, 100, 32, 115, 105, 100, 101, 32, 111, 102, 32, 116, 104, 105, 110, 103, 115, 46, 32, 73, 32, 10, 115, 117, 112, 112, 111, 115, 101, 32, 116, 104, 97, 116, 39, 115, 32, 121, 111, 117, 114, 32, 116, 97, 108, 101, 110, 116, 44, 32, 105, 115, 110, 39, 116, 32, 105, 116, 63, 32, 84, 104, 101, 32, 119, 101, 105, 103, 104, 116, 32, 98, 101, 104, 105, 110, 100, 32, 34, 73, 39, 109, 32, 104, 111, 110, 111, 114, 101, 100, 32, 116, 111, 32, 98, 101, 32, 121, 111, 117, 114, 32, 10, 102, 114, 105, 101, 110, 100, 34, 32, 107, 101, 101, 112, 115, 32, 103, 114, 111, 119, 105, 110, 103, 46, 32, 68, 111, 110, 39, 116, 32, 116, 104, 105, 110, 107, 32, 73, 32, 102, 111, 114, 103, 111, 116, 32, 73, 32, 115, 97, 105, 100, 32, 116, 104, 97, 116, 44, 32, 101, 105, 116, 104, 101, 114, 46, 32, 73, 32, 107, 110, 111, 119, 32, 73, 32, 102, 111, 114, 103, 101, 116, 32, 10, 116, 104, 105, 110, 103, 115, 32, 73, 32, 116, 101, 108, 108, 32, 112, 101, 111, 112, 108, 101, 32, 97, 32, 108, 111, 116, 44, 32, 98, 117, 116, 32, 116, 104, 97, 116, 39, 115, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 73, 39, 108, 108, 32, 114, 101, 109, 101, 109, 98, 101, 114, 32, 102, 111, 114, 32, 97, 32, 108, 111, 110, 103, 32, 116, 105, 109, 101, 46, 10, 83, 112, 101, 97, 107, 105, 110, 103, 32, 111, 102, 32, 116, 104, 105, 110, 103, 115, 32, 73, 32, 114, 101, 109, 101, 109, 98, 101, 114, 44, 32, 73, 32, 109, 101, 116, 32, 83, 107, 121, 108, 97, 114, 32, 97, 110, 100, 32, 83, 108, 97, 116, 101, 114, 32, 40, 65, 115, 115, 117, 109, 105, 110, 103, 32, 73, 39, 109, 32, 115, 112, 101, 108, 108, 105, 110, 103, 32, 10, 116, 104, 101, 105, 114, 32, 110, 97, 109, 101, 115, 32, 114, 105, 103, 104, 116, 32, 97, 110, 100, 32, 110, 111, 116, 32, 108, 105, 107, 101, 32, 97, 110, 32, 105, 100, 105, 111, 116, 41, 32, 97, 115, 32, 111, 102, 32, 119, 114, 105, 116, 105, 110, 103, 32, 116, 104, 105, 115, 46, 32, 87, 104, 97, 116, 32, 121, 111, 117, 32, 115, 97, 105, 100, 32, 116, 111, 100, 97, 121, 32, 10, 115, 116, 111, 111, 100, 32, 111, 117, 116, 32, 116, 111, 32, 109, 101, 46, 32, 89, 111, 117, 32, 99, 97, 109, 101, 32, 105, 110, 116, 111, 32, 116, 104, 101, 32, 83, 116, 111, 117, 103, 104, 116, 111, 110, 32, 84, 97, 114, 103, 101, 116, 32, 116, 111, 32, 118, 105, 115, 105, 116, 32, 109, 101, 46, 32, 65, 32, 115, 109, 97, 108, 108, 32, 100, 101, 116, 97, 105, 108, 32, 10, 109, 97, 121, 98, 101, 44, 32, 98, 117, 116, 32, 73, 32, 103, 114, 101, 97, 116, 108, 121, 32, 97, 112, 112, 114, 101, 99, 105, 97, 116, 101, 100, 32, 116, 104, 101, 32, 103, 101, 115, 116, 117, 114, 101, 46, 32, 73, 116, 32, 105, 109, 112, 114, 111, 118, 101, 100, 32, 109, 121, 32, 100, 97, 121, 46, 32, 89, 111, 117, 39, 118, 101, 32, 98, 101, 101, 110, 32, 10, 116, 104, 101, 114, 101, 32, 97, 110, 100, 32, 109, 97, 100, 101, 32, 97, 110, 32, 101, 102, 102, 111, 114, 116, 32, 116, 111, 32, 101, 120, 105, 115, 116, 32, 105, 110, 32, 109, 121, 32, 108, 105, 102, 101, 46, 32, 73, 39, 118, 101, 32, 116, 104, 111, 117, 103, 104, 116, 32, 97, 98, 111, 117, 116, 32, 116, 104, 105, 115, 32, 97, 32, 108, 111, 116, 44, 32, 10, 97, 99, 116, 117, 97, 108, 108, 121, 44, 32, 115, 105, 110, 99, 101, 32, 98, 101, 99, 111, 109, 105, 110, 103, 32, 97, 32, 112, 97, 114, 116, 32, 111, 102, 32, 116, 104, 105, 115, 32, 102, 114, 105, 101, 110, 100, 32, 103, 114, 111, 117, 112, 46, 32, 84, 104, 111, 117, 103, 104, 32, 116, 104, 105, 115, 32, 105, 115, 110, 39, 116, 32, 97, 98, 111, 117, 116, 32, 10, 116, 104, 101, 32, 102, 114, 105, 101, 110, 100, 32, 103, 114, 111, 117, 112, 32, 114, 105, 103, 104, 116, 32, 110, 111, 119, 44, 32, 116, 104, 105, 115, 32, 105, 115, 32, 97, 98, 111, 117, 116, 32, 121, 111, 117, 46, 32, 89, 111, 117, 32, 105, 110, 32, 112, 97, 114, 116, 105, 99, 117, 108, 97, 114, 46, 32, 73, 39, 118, 101, 32, 116, 104, 111, 117, 103, 104, 116, 32, 10, 97, 98, 111, 117, 116, 32, 97, 32, 102, 101, 119, 32, 116, 104, 105, 110, 103, 115, 46, 32, 73, 32, 116, 104, 111, 117, 103, 104, 116, 32, 97, 98, 111, 117, 116, 32, 104, 111, 119, 32, 121, 111, 117, 32, 106, 117, 115, 116, 32, 114, 97, 110, 100, 111, 109, 108, 121, 32, 115, 116, 97, 114, 116, 101, 100, 32, 115, 97, 121, 105, 110, 103, 32, 104, 105, 32, 116, 111, 32, 10, 109, 101, 32, 101, 97, 99, 104, 32, 99, 108, 97, 115, 115, 32, 105, 110, 32, 80, 104, 105, 108, 111, 115, 111, 112, 104, 121, 32, 97, 102, 116, 101, 114, 32, 108, 101, 97, 114, 110, 105, 110, 103, 32, 109, 121, 32, 110, 97, 109, 101, 46, 32, 73, 32, 116, 104, 111, 117, 103, 104, 116, 32, 97, 98, 111, 117, 116, 32, 116, 104, 101, 32, 116, 105, 109, 101, 32, 121, 111, 117, 32, 10, 97, 115, 107, 101, 100, 32, 109, 101, 32, 116, 111, 32, 115, 105, 116, 32, 119, 105, 116, 104, 32, 121, 111, 117, 32, 97, 110, 100, 32, 65, 110, 100, 121, 32, 97, 116, 32, 116, 104, 101, 32, 108, 117, 110, 99, 104, 32, 116, 97, 98, 108, 101, 46, 32, 73, 32, 116, 104, 111, 117, 103, 104, 116, 32, 97, 98, 111, 117, 116, 32, 101, 97, 99, 104, 32, 116, 105, 109, 101, 32, 10, 121, 111, 117, 32, 97, 115, 107, 101, 100, 32, 109, 101, 32, 104, 111, 119, 32, 73, 32, 119, 97, 115, 32, 100, 111, 105, 110, 103, 32, 119, 104, 101, 110, 32, 73, 32, 115, 97, 116, 32, 100, 111, 119, 110, 44, 32, 97, 110, 100, 32, 104, 111, 119, 32, 121, 111, 117, 32, 97, 112, 111, 108, 111, 103, 105, 122, 101, 100, 32, 119, 104, 101, 110, 32, 121, 111, 117, 32, 10, 102, 111, 114, 103, 111, 116, 32, 116, 111, 32, 111, 114, 32, 103, 111, 116, 32, 115, 117, 112, 101, 114, 32, 122, 111, 110, 101, 100, 32, 105, 110, 116, 111, 32, 115, 111, 109, 101, 116, 104, 105, 110, 103, 32, 97, 110, 100, 32, 100, 105, 100, 110, 39, 116, 32, 110, 111, 116, 105, 99, 101, 32, 73, 32, 115, 97, 116, 32, 100, 111, 119, 110, 46, 32, 73, 32, 10, 110, 111, 116, 105, 99, 101, 100, 32, 121, 111, 117, 39, 100, 32, 116, 114, 121, 32, 116, 111, 32, 115, 109, 105, 108, 101, 32, 97, 116, 32, 109, 101, 32, 119, 104, 101, 110, 32, 121, 111, 117, 32, 115, 97, 119, 32, 109, 101, 44, 32, 111, 114, 32, 109, 97, 121, 98, 101, 32, 73, 39, 109, 32, 106, 117, 115, 116, 32, 116, 104, 97, 116, 32, 103, 111, 111, 100, 32, 10, 116, 104, 97, 116, 32, 73, 32, 109, 97, 107, 101, 32, 121, 111, 117, 32, 115, 109, 105, 108, 101, 32, 40, 118, 101, 114, 121, 32, 115, 111, 114, 114, 121, 44, 32, 101, 109, 111, 116, 105, 111, 110, 97, 108, 32, 102, 105, 108, 116, 101, 114, 32, 105, 115, 32, 103, 111, 110, 101, 32, 114, 105, 103, 104, 116, 32, 110, 111, 119, 41, 46, 32, 65, 108, 108, 32, 111, 102, 32, 10, 116, 104, 111, 115, 101, 32, 116, 104, 105, 110, 103, 115, 32, 109, 111, 116, 105, 118, 97, 116, 101, 100, 32, 109, 101, 32, 116, 111, 32, 99, 111, 110, 116, 105, 110, 117, 101, 32, 116, 114, 121, 105, 110, 103, 32, 116, 111, 32, 98, 101, 32, 112, 97, 114, 116, 32, 111, 102, 32, 116, 104, 101, 32, 102, 114, 105, 101, 110, 100, 32, 103, 114, 111, 117, 112, 46, 32, 66, 117, 116, 32, 10, 97, 98, 111, 118, 101, 32, 97, 108, 108, 32, 101, 108, 115, 101, 44, 32, 73, 32, 100, 111, 110, 39, 116, 32, 116, 104, 105, 110, 107, 32, 73, 32, 119, 111, 117, 108, 100, 32, 104, 97, 118, 101, 32, 98, 101, 99, 111, 109, 101, 32, 97, 32, 112, 97, 114, 116, 32, 111, 102, 32, 116, 104, 101, 32, 102, 114, 105, 101, 110, 100, 32, 103, 114, 111, 117, 112, 32, 104, 97, 100, 32, 10, 121, 111, 117, 32, 110, 111, 116, 32, 97, 115, 107, 101, 100, 32, 109, 101, 32, 116, 111, 32, 115, 105, 116, 32, 97, 116, 32, 116, 104, 101, 32, 116, 97, 98, 108, 101, 32, 105, 110, 32, 116, 104, 101, 32, 102, 111, 111, 100, 32, 99, 111, 117, 114, 116, 32, 116, 104, 101, 32, 102, 105, 114, 115, 116, 32, 116, 105, 109, 101, 32, 119, 101, 32, 104, 97, 100, 32, 97, 32, 10, 102, 117, 108, 108, 32, 99, 111, 110, 118, 101, 114, 115, 97, 116, 105, 111, 110, 46, 32, 73, 32, 100, 111, 110, 39, 116, 32, 107, 110, 111, 119, 32, 104, 111, 119, 32, 73, 32, 119, 111, 117, 108, 100, 39, 118, 101, 32, 102, 105, 116, 32, 105, 110, 32, 97, 116, 32, 97, 108, 108, 46, 32, 73, 116, 32, 119, 111, 117, 108, 100, 32, 104, 97, 118, 101, 32, 98, 101, 101, 110, 32, 10, 105, 110, 102, 105, 110, 105, 116, 101, 108, 121, 32, 104, 97, 114, 100, 101, 114, 32, 102, 111, 114, 32, 109, 101, 32, 116, 111, 32, 115, 97, 121, 32, 116, 104, 101, 32, 108, 101, 97, 115, 116, 44, 32, 119, 105, 116, 104, 32, 109, 121, 32, 115, 111, 99, 105, 97, 108, 32, 97, 110, 120, 105, 101, 116, 121, 32, 97, 110, 100, 32, 97, 108, 108, 46, 32, 87, 101, 39, 118, 101, 32, 10, 104, 97, 100, 32, 99, 108, 97, 115, 115, 32, 116, 111, 103, 101, 116, 104, 101, 114, 44, 32, 104, 97, 100, 32, 98, 117, 108, 108, 115, 104, 105, 116, 32, 110, 111, 110, 115, 101, 110, 115, 101, 32, 103, 111, 32, 111, 110, 32, 105, 110, 32, 68, 105, 115, 99, 111, 114, 100, 32, 86, 67, 44, 32, 104, 97, 110, 103, 101, 100, 32, 111, 117, 116, 32, 97, 110, 100, 32, 10, 104, 97, 100, 32, 115, 101, 114, 105, 111, 117, 115, 32, 99, 111, 110, 118, 101, 114, 115, 97, 116, 105, 111, 110, 115, 32, 102, 111, 108, 108, 111, 119, 101, 100, 32, 98, 121, 32, 97, 32, 108, 97, 116, 101, 32, 110, 105, 103, 104, 116, 32, 99, 111, 100, 105, 110, 103, 32, 115, 101, 115, 115, 105, 111, 110, 32, 105, 110, 32, 80, 121, 116, 104, 111, 110, 44, 32, 10, 119, 101, 110, 116, 32, 116, 111, 32, 97, 32, 116, 114, 101, 101, 116, 111, 112, 32, 112, 97, 114, 107, 32, 119, 104, 101, 114, 101, 32, 73, 32, 97, 108, 109, 111, 115, 116, 32, 102, 117, 99, 107, 105, 110, 103, 32, 100, 105, 101, 100, 32, 98, 121, 32, 114, 111, 97, 100, 32, 98, 117, 114, 110, 32, 111, 110, 32, 114, 111, 108, 108, 101, 114, 115, 44, 32, 119, 101, 110, 116, 32, 10, 116, 111, 32, 121, 111, 117, 114, 32, 97, 112, 97, 114, 116, 109, 101, 110, 116, 32, 97, 32, 99, 111, 117, 112, 108, 101, 32, 116, 105, 109, 101, 115, 44, 32, 97, 110, 100, 32, 110, 111, 119, 32, 73, 39, 109, 32, 104, 101, 114, 101, 32, 119, 114, 105, 116, 105, 110, 103, 32, 116, 104, 105, 115, 46, 32, 84, 104, 101, 32, 99, 111, 109, 112, 97, 114, 105, 115, 111, 110, 32, 10, 98, 101, 116, 119, 101, 101, 110, 32, 108, 97, 115, 116, 32, 115, 101, 109, 101, 115, 116, 101, 114, 44, 32, 119, 104, 101, 114, 101, 32, 73, 32, 104, 97, 100, 32, 110, 111, 32, 111, 110, 101, 32, 116, 111, 32, 116, 97, 108, 107, 32, 116, 111, 32, 111, 110, 32, 99, 97, 109, 112, 117, 115, 44, 32, 97, 110, 100, 32, 110, 111, 119, 44, 32, 119, 104, 101, 114, 101, 32, 10, 73, 32, 99, 97, 110, 32, 106, 117, 115, 116, 32, 121, 101, 108, 108, 32, 97, 116, 32, 119, 104, 111, 101, 118, 101, 114, 32, 105, 110, 32, 116, 104, 101, 32, 102, 114, 105, 101, 110, 100, 32, 103, 114, 111, 117, 112, 32, 97, 110, 100, 32, 107, 110, 111, 119, 32, 116, 104, 97, 116, 32, 73, 39, 109, 32, 97, 99, 107, 110, 111, 119, 108, 101, 100, 103, 101, 100, 32, 10, 97, 110, 100, 32, 116, 104, 97, 116, 32, 73, 32, 97, 109, 32, 99, 97, 114, 101, 100, 32, 97, 98, 111, 117, 116, 32, 105, 115, 32, 115, 111, 32, 112, 111, 119, 101, 114, 102, 117, 108, 46, 32, 77, 121, 32, 101, 121, 101, 115, 32, 97, 114, 101, 32, 115, 116, 97, 114, 116, 105, 110, 103, 32, 116, 111, 32, 119, 97, 116, 101, 114, 32, 97, 115, 32, 73, 39, 109, 32, 10, 119, 114, 105, 116, 105, 110, 103, 32, 116, 104, 105, 115, 32, 40, 73, 39, 109, 32, 115, 101, 114, 105, 111, 117, 115, 44, 32, 116, 104, 101, 121, 32, 97, 114, 101, 41, 46, 32, 73, 32, 99, 97, 110, 39, 116, 32, 98, 101, 103, 105, 110, 32, 116, 111, 32, 116, 104, 97, 110, 107, 32, 121, 111, 117, 32, 101, 110, 111, 117, 103, 104, 32, 102, 111, 114, 32, 116, 104, 101, 32, 10, 119, 111, 114, 108, 100, 32, 121, 111, 117, 39, 118, 101, 32, 111, 112, 101, 110, 101, 100, 32, 117, 112, 32, 102, 111, 114, 32, 109, 101, 46, 32, 89, 111, 117, 32, 97, 108, 119, 97, 121, 115, 32, 104, 97, 118, 101, 32, 115, 117, 99, 104, 32, 97, 32, 112, 111, 115, 105, 116, 105, 118, 101, 32, 101, 110, 101, 114, 103, 121, 32, 97, 98, 111, 117, 116, 32, 121, 111, 117, 32, 10, 73, 39, 118, 101, 32, 111, 110, 108, 121, 32, 115, 101, 101, 110, 32, 105, 110, 32, 97, 32, 104, 97, 110, 100, 102, 117, 108, 32, 111, 102, 32, 112, 101, 111, 112, 108, 101, 32, 73, 39, 118, 101, 32, 109, 101, 116, 32, 105, 110, 32, 109, 121, 32, 101, 110, 116, 105, 114, 101, 32, 108, 105, 102, 101, 46, 32, 84, 97, 108, 107, 105, 110, 103, 32, 119, 105, 116, 104, 32, 10, 121, 111, 117, 32, 105, 115, 32, 97, 110, 32, 101, 97, 115, 121, 32, 119, 97, 121, 32, 102, 111, 114, 32, 109, 101, 32, 116, 111, 32, 102, 101, 101, 108, 32, 98, 101, 116, 116, 101, 114, 46, 32, 89, 111, 117, 32, 97, 114, 101, 32, 97, 32, 116, 114, 117, 101, 32, 102, 114, 105, 101, 110, 100, 44, 32, 109, 121, 32, 102, 114, 105, 101, 110, 100, 46, 32, 83, 111, 32, 10, 73, 32, 119, 97, 110, 116, 32, 116, 111, 32, 101, 110, 100, 32, 116, 104, 105, 115, 32, 109, 101, 115, 115, 97, 103, 101, 32, 98, 121, 32, 114, 101, 105, 116, 101, 114, 97, 116, 105, 110, 103, 32, 116, 104, 97, 116, 32, 73, 32, 97, 112, 112, 114, 101, 99, 105, 97, 116, 101, 32, 121, 111, 117, 32, 115, 111, 32, 109, 117, 99, 104, 46, 32, 65, 102, 116, 101, 114, 32, 10, 119, 101, 32, 104, 117, 110, 103, 32, 111, 117, 116, 32, 111, 110, 101, 32, 111, 110, 32, 111, 110, 101, 32, 102, 111, 114, 32, 116, 104, 101, 32, 102, 105, 114, 115, 116, 32, 116, 105, 109, 101, 44, 32, 73, 32, 99, 114, 105, 101, 100, 46, 32, 73, 32, 97, 99, 116, 117, 97, 108, 108, 121, 32, 99, 114, 105, 101, 100, 46, 32, 65, 110, 100, 32, 102, 111, 114, 32, 10, 110, 111, 116, 104, 105, 110, 103, 32, 98, 97, 100, 59, 32, 73, 32, 99, 114, 105, 101, 100, 32, 116, 101, 97, 114, 115, 32, 111, 102, 32, 106, 111, 121, 46, 32, 73, 32, 114, 101, 97, 108, 105, 122, 101, 100, 32, 119, 104, 97, 116, 32, 73, 32, 104, 97, 100, 32, 98, 101, 101, 110, 32, 109, 105, 115, 115, 105, 110, 103, 32, 111, 117, 116, 32, 111, 110, 44, 32, 10, 119, 104, 97, 116, 32, 112, 97, 114, 116, 32, 111, 102, 32, 116, 104, 101, 32, 119, 111, 114, 108, 100, 32, 73, 39, 100, 32, 98, 101, 101, 110, 32, 99, 108, 111, 115, 101, 100, 32, 111, 102, 102, 32, 116, 111, 32, 98, 101, 102, 111, 114, 101, 32, 109, 101, 101, 116, 105, 110, 103, 32, 121, 111, 117, 46, 32, 89, 111, 117, 39, 118, 101, 32, 100, 111, 110, 101, 32, 115, 111, 32, 10, 109, 117, 99, 104, 32, 102, 111, 114, 32, 109, 101, 44, 32, 97, 110, 100, 32, 109, 97, 121, 98, 101, 32, 121, 111, 117, 32, 100, 111, 110, 39, 116, 32, 114, 101, 97, 108, 105, 122, 101, 32, 105, 116, 32, 111, 114, 32, 121, 111, 117, 32, 100, 111, 110, 39, 116, 32, 116, 104, 105, 110, 107, 32, 115, 111, 44, 32, 98, 117, 116, 32, 121, 111, 117, 32, 104, 97, 118, 101, 46, 32, 10, 89, 111, 117, 39, 118, 101, 32, 98, 101, 101, 110, 32, 116, 104, 101, 114, 101, 32, 102, 111, 114, 32, 109, 101, 32, 119, 104, 101, 110, 32, 73, 32, 119, 97, 115, 32, 115, 116, 114, 117, 103, 103, 108, 105, 110, 103, 32, 119, 105, 116, 104, 32, 102, 101, 101, 108, 105, 110, 103, 32, 101, 109, 112, 116, 121, 32, 97, 110, 100, 32, 108, 101, 102, 116, 32, 111, 117, 116, 46, 32, 10, 84, 104, 101, 110, 32, 119, 101, 32, 116, 97, 108, 107, 101, 100, 32, 97, 98, 111, 117, 116, 32, 103, 101, 116, 116, 105, 110, 103, 32, 115, 104, 114, 101, 100, 100, 101, 100, 32, 97, 110, 100, 32, 116, 97, 108, 108, 32, 98, 121, 32, 101, 97, 116, 105, 110, 103, 32, 119, 111, 114, 109, 115, 32, 119, 105, 116, 104, 32, 66, 114, 105, 97, 110, 110, 97, 46, 32, 10, 71, 114, 101, 97, 116, 32, 116, 105, 109, 101, 115, 46, 32, 73, 32, 119, 97, 110, 116, 32, 116, 111, 32, 100, 111, 32, 109, 111, 114, 101, 32, 102, 111, 114, 32, 121, 111, 117, 32, 116, 111, 111, 46, 32, 73, 32, 119, 97, 110, 116, 32, 116, 111, 32, 98, 101, 32, 116, 104, 101, 114, 101, 32, 102, 111, 114, 32, 121, 111, 117, 46, 32, 73, 32, 119, 97, 110, 116, 32, 10, 121, 111, 117, 32, 116, 111, 32, 107, 110, 111, 119, 32, 116, 104, 97, 116, 32, 73, 39, 109, 32, 97, 118, 97, 105, 108, 97, 98, 108, 101, 44, 32, 116, 111, 111, 44, 32, 98, 101, 99, 97, 117, 115, 101, 32, 73, 32, 100, 111, 110, 39, 116, 32, 116, 104, 105, 110, 107, 32, 73, 32, 116, 101, 108, 108, 32, 121, 111, 117, 32, 116, 104, 97, 116, 32, 10, 101, 110, 111, 117, 103, 104, 46, 32, 89, 111, 117, 39, 114, 101, 32, 97, 32, 98, 108, 101, 115, 115, 101, 100, 32, 109, 97, 110, 46, 32, 89, 111, 117, 32, 100, 101, 115, 101, 114, 118, 101, 32, 97, 108, 108, 32, 116, 104, 101, 32, 104, 97, 112, 112, 105, 110, 101, 115, 115, 32, 105, 110, 32, 116, 104, 101, 32, 119, 111, 114, 108, 100, 46, 32, 65, 110, 100, 32, 97, 32, 10, 103, 111, 111, 100, 32, 67, 111, 109, 112, 32, 83, 99, 105, 32, 106, 111, 98, 32, 98, 117, 116, 32, 73, 32, 99, 97, 110, 39, 116, 32, 104, 101, 108, 112, 32, 121, 111, 117, 32, 119, 105, 116, 104, 32, 116, 104, 97, 116, 32, 111, 110, 101, 32, 99, 104, 105, 101, 102, 46, 32, 84, 104, 97, 110, 107, 32, 121, 111, 117, 32, 115, 111, 32, 109, 117, 99, 104, 32, 10, 102, 111, 114, 32, 101, 118, 101, 114, 121, 116, 104, 105, 110, 103, 46, 10, 10, 83, 111, 44, 32, 102, 114, 111, 109, 32, 116, 104, 101, 32, 98, 111, 116, 116, 111, 109, 32, 111, 102, 32, 109, 121, 32, 104, 101, 97, 114, 116, 44, 10, 72, 65, 80, 80, 89, 32, 66, 73, 82, 84, 72, 68, 65, 89, 32, 74, 65, 83, 79, 78, 33, 33, 33, 33, 33, 10, 10, 40, 72, 97, 118, 101, 32, 102, 117, 110, 32, 103, 101, 116, 116, 105, 110, 103, 32, 117, 116, 116, 101, 114, 108, 121, 32, 115, 104, 105, 116, 102, 97, 99, 101, 100, 32, 112, 111, 111, 107, 105, 101, 32, 60, 51, 41, 0};

void writeSecretMessageToFile() {
    FILE *jasonDotText = fopen("jasonbday.txt", "wt");
    fwrite(message, sizeof(char), sizeof(message), jasonDotText);
}