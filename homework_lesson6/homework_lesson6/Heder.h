#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include < stdbool.h >

void Swap_any(void* p_var1, void* p_var2, int size);
int GetAsciSum(const char* str, int size);
int sum(const char* str, int (*getSum)(const char*,int));
int* SearchNum(int num, int numOfElements, const int* arr);
void printArr(const int* arr, int numOfElements);
int compareNum(const void* a, const void* b);
int* findNumberInArrays();

