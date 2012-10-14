#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "arrays.h"

// PRINT THE ARRAY
void printArray(struct Array *array) {
    int *pointer = array->values;
    int i = 0;
    printf("Array {\n");
    printf("\tIndex\tAdresse\t\tValue\n");
    for (i = 0;i < array->length ; i++, pointer++) {
        printf("\t%d\t%p\t%d\n", i, pointer, *pointer);
    }
    printf("}\n");
}

// PRINT ONLY THE VALUES
void printValues(struct Array *array) {
    int *pointer = array->values;
    int i;
    printf("Values=[");
    for (i = 0 ; i < array->length ; ++i, ++pointer) {
        printf("%d", *pointer);
        if (i < array->length - 1 ) 
            printf(", ");
    }
    printf("]\n");
}

// --------------------------------- 
// ----------- MAIN MENU -----------
// --------------------------------- 

int main(void) {

    printf("-----------------\n");
    printf("----ArrayTest----\n");
    printf("-----------------\n\n");

    // START SIZE MENU TO GET THE ARRAY SIZE
    struct Array *array = sizeMenu();
    // WRONG OPTION
    if (NULL == array) 
        return EXIT_FAILURE;

    // START FILL MENU TO FILL THE ARRAY
    if (fillMenu(array) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    // PRINT VALUES WHEN THEY ARE ONLY A FEW
    if (array->length <= 20)
        printValues(array);

    // START OPERATION MENU
    if (operationMenu(array) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    // FREE THE MEMORY FOR THE ARRAYS
    free(array->values);
    free(array);
    return EXIT_SUCCESS;
}

// --------------------------------- 
// ------ ARRAY SIZE FUNCTIONS -----
// --------------------------------- 

const int RANDOM_SIZE = 1;
const int GIVEN_SIZE  = 2;

struct Array *sizeMenu() {
    printf("---- Array Size Menu ----\n");
    printf("(%d) - Random Size\n",RANDOM_SIZE);
    printf("(%d) - Size by User\n",GIVEN_SIZE);
    printf("Your option: ");


    int option;
    scanf("%d", &option);
    int length;
    // USER WANT A RANDOM SIZE
    if (option == RANDOM_SIZE) {
        length = randomSize();
    }
    // USER WANT TO SET THE SIZE BY HIMESELF
    else if (option == GIVEN_SIZE) {
        length = readSize();
    }
    // WRONG OPTION
    else {
        printf("Wrong option!\n");
        return NULL;
    }

    if (length <= 0) {
        printf("Length must be positive!");
        return NULL;
    }

    // CREATE THE ARRAY
    struct Array *myArray = malloc(sizeof(struct Array));
    if (NULL == myArray) {
        printf("Not enough memory!");
        return NULL;   
    }
    myArray->length = length;
    myArray->values = malloc(sizeof(int) * length);

    // CAN'T RESERVE ENOUGH MEMORY
    if (NULL == myArray->values) {
        printf("Size is to high!");
        return NULL;
    } 

    return myArray;
}

int randomSize() {
    printf("Size is from 1 until ");
    int max;
    scanf("%d", &max);    
    // GENERATE NUMBER IN [1,MAX]
    srand(time(NULL));
    int    length = rand() % max;
    if (length == 0)
        length = max;
    printf("Size: %d\n", length);
    return length;
}

int readSize() {
    int    length;
    printf("Size: ");
    scanf("%d", &length);
    return length;
}

// --------------------------------- 
// ----- ARRAY VALUE FUNCTIONS -----
// ---------------------------------

const int RANDOM_VALUES         = 1;
const int GIVEN_VALUES         = 2;
const int ASCENDING_VALUES     = 3;
const int DESCENDING_VALUES     = 4;

int fillMenu(struct Array *array) {
    printf("\n---- Fill Array Menu ----\n");
    printf("(%d) - Random Values\n", RANDOM_VALUES);
    printf("(%d) - Given Values\n",GIVEN_VALUES);
    printf("(%d) - Number from 1 to N\n",ASCENDING_VALUES);
    printf("(%d) - Number from N to 1\n",DESCENDING_VALUES);
    printf("Your option: ");
       int option;
    scanf("%d", &option);

    if (option == RANDOM_VALUES) {
         randomArray(array);
    }
    else if (option == GIVEN_VALUES) {
        readArray(array);
    }
    else if (option == ASCENDING_VALUES) {
        createAscArray(array);
    }
    else if (option == DESCENDING_VALUES) {
        createDescArray(array);
    }
    else {
        printf("Wrong option!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void randomArray(struct Array *array) {
    int *pointer = array->values;
    int i;
    srand(time(NULL));
    int value;
    int length = array->length;
    for(i = 0; i < length; ++i, ++pointer) {
        value = rand() % length;
        if (value == 0)
            value = length;
        *pointer = value;
    }
}

void readArray(struct Array *array) {

    printf("Please insert values\n");

    int *pointer = array->values;
    printf("\tPointer:\t%p\n", pointer);
    int i = 0;
    for (i = 0;i < array->length ; i++) {
        printf("%d. Zahl : ", i+1);
        scanf("%d", &pointer[i]);
        printf("\tPointer:\t%p\n", &pointer[i]);
    }
}

void createAscArray(struct Array *array) {

    int *pointer = array->values;
    int i;
    for (i = 1;i <= array->length ; i++, pointer++)
        *(pointer) = i;
}

void createDescArray(struct Array *array) {

    int *pointer = array->values;
    int i;
    for (i = array->length;i > 0 ; i--, pointer++)
        *(pointer) = i;
}
// --------------------------------- 
// --- ARRAY OPERATION FUNCTIONS ---
// --------------------------------- 

const int MAX_OPERATION             = 1;
const int MIN_OPERATION             = 2;
const int SUM_OPERATION             = 3;
const int PRODUCT_OPERATION         = 4;
const int BUBBLE_SORT_OPERATION     = 5;

int operationMenu(struct Array *array) {
    printf("\n---- Fill Array Menu ----\n");
    printf("(%d) - Maximum of array\n", MAX_OPERATION);
    printf("(%d) - Minimum of array\n", MIN_OPERATION);
    printf("(%d) - Sum of array\n", SUM_OPERATION);
    printf("(%d) - Product of array\n", PRODUCT_OPERATION);
    printf("(%d) - Sort array(BubbleSort)\n", BUBBLE_SORT_OPERATION );

    printf("Your option: ");
    int option;
    scanf("%d", &option);

    if (option == MAX_OPERATION) {
        int result = getMax(array);
        printf("Max: %d\n", result);
    }
    else if (option == MIN_OPERATION) {
        int result = getMin(array);
        printf("Min: %d\n", result);
    }
    else if (option == SUM_OPERATION) {
        int result = getSum(array);
        printf("Sum: %d\n", result);
    }
    else if (option == PRODUCT_OPERATION) {
        int result = getProduct(array);
        printf("Product: %d\n", result);
    }
    else if (option == BUBBLE_SORT_OPERATION) {
        clock_t start = clock();
        bubbleSort(array);
        clock_t end = clock();
        double zeit = (double)(end-start) / (double)CLOCKS_PER_SEC;
        printf("Time needed: %.2fs\n", zeit); 
        if(array->length <= 20)
            printValues(array);
    }
    else {
        printf("Wrong option!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int getMax(struct Array *array) {
    int max = INT_MIN;
    int i;
    int *ptr = array->values;
    for(i = 0; i < array->length; ++i, ++ptr) {
        if (*ptr > max)
            max = *ptr;
    }

    return max;
}

int getMin(struct Array *array) {
    int min = INT_MAX;
    int i;
    int *ptr = array->values;
    for(i = 0; i < array->length; ++i, ++ptr) {
        if (*ptr < min)
            min = *ptr;
    }

    return min;
}

int getSum(struct Array *array) {
    int sum = 0;
    int i;
    int *ptr = array->values;
    for(i = 0; i < array->length; ++i, ++ptr) {
        sum += *ptr;
    }

    return sum;
}

int getProduct(struct Array *array) {
    int product;
    int i;
    int *ptr = array->values;
    for(i = 0; i < array->length; ++i, ++ptr) {
        product *= *ptr;
    }

    return product;
}

int bubbleSort(struct Array *array) {
    int i;
    int j;
    int *ptr = array->values;
    for (i = 0 ; i < array -> length ; ++i) {
        for (j = 0;j < i ; ++j) {
            if (ptr[i] < ptr[j])
                swap(i, j, array->values);
        }
    }
}

void swap(int i, int j , int *ptr) {
    int temp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = temp;
}
