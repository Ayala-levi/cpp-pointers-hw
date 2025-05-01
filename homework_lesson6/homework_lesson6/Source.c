#include "Heder.h"

//1
void Swap_any(void* p_var1, void* p_var2, int size) {
    char* ptr1 = (char*)p_var1;
    char* ptr2 = (char*)p_var2;
    char temp;
    int i;

    for (i = 0; i < size; i++) {
        temp = ptr1[i];
        ptr1[i] = ptr2[i];
        ptr2[i] = temp;
    }
}

//2
int GetAsciSum(const char* str, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum +=str[i];
    }
    return sum;
}

int sum(const char* str, int (*getSum)(const char*, int)) {
    return getSum(str,strlen(str));
}

//3
int* findNumberInArrays() {
    int numToSearch;
    printf("Enter a number to search for: ");
    if (scanf_s("%d", &numToSearch) != 1) return NULL;

    int arrayLength;
    while (true) {
        printf("Enter the number of elements in the array (or -1 to finish): ");
        if (scanf_s("%d", &arrayLength) != 1) return NULL;

        if (arrayLength == -1) {
            break;
        }

        int* arr = (int*)malloc(arrayLength * sizeof(int));
        if (arr == NULL) {
            perror("Failed to allocate memory");
            return NULL;
        }

        printf("Enter the array elements (%d numbers separated by spaces): ", arrayLength);
        for (int i = 0; i < arrayLength; i++) {
            if (scanf_s("%d", &arr[i]) != 1) {
                free(arr);
                return NULL;
            }
        }

        int* foundPtr = SearchNum(numToSearch, arrayLength, arr);
        if (foundPtr != NULL) {
            return arr; // החזרת מצביע לזיכרון המוקצה
        }
        else {
            free(arr); // שחרור זיכרון אם המספר לא נמצא
            printf("The number %d was not found in this array.\n", numToSearch);
        }
    }

    printf("No array contained the number %d.\n", numToSearch);
    return NULL;
}

int* SearchNum(int num,int numOfElements,const int* arr) {
    printf("The array before sorting:\n");
    printArr(arr, numOfElements);

    printf("The sorted array:\n");
    qsort(arr, numOfElements, sizeof(int), compareNum);
    printArr(arr, numOfElements);
  
    int* found=bsearch(&num, arr, numOfElements, sizeof(int), compareNum);
    if (found!=NULL)
        return found;
    else
        return NULL;
}

void printArr(const int* arr, int numOfElements) {
    for (int i = 0; i <numOfElements; i++)
    {
        printf("arr[i]: %d\n", arr[i]);
    }
}
int compareNum(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}



int main() {
    char str1[20] = "ayala";
    char str2[21] = "efrat";

    printf("str1 befor change:  %s\n", str1);
    printf("str2 befor change: %s\n", str2);

    Swap_any(str1, str2, strlen(str1));

    printf("str1 after change: %s\n", str1);
    printf("str2 after change: %s\n", str2);

    printf("The asci sum of str1: %d\n", sum(str1, GetAsciSum));
    printf("The length of str1: %d\n", sum(str1, strlen));

    int arr[6] = { 3,5,2,4,1,8 };
    int* ptr = SearchNum(5, 6, arr);
    if (ptr != NULL) {
        printf("The number %d is found\n", *ptr);
    }
    else
        printf("not found\n");


    int* foundArrayPtr = findNumberInArrays();

    if (foundArrayPtr != NULL) {
        printf("The number was found in the array at address: %p\n", (void*)foundArrayPtr);
        printArr(foundArrayPtr, 3);
        free(foundArrayPtr);
    }

    return 0;
}