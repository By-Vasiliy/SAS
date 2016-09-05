# Sorting-Algorithms-Speed
## Сравнение скорости алгоритмов сортировки


# C++ Быстрая сортировка рекурсией (QSort)
***void quickSort(int *array, int firstElementNumder, int lastElementNumder);***
```
/**
 * @brief quickSort
 * @param array
 * @param firstElementNumder
 * @param lastElementNumder
 */
void quickSort(int *array, int firstElementNumder, int lastElementNumder) {
    int averageElementNumber, temp;
    int f = firstElementNumder, l = lastElementNumder;
    averageElementNumber = array[(f + l) / 2];
    do {
        while (array[f] < averageElementNumber) f++;
        while (array[l] > averageElementNumber) l--;
        if (f <= l) {
            temp = array[f];
            array[f] = array[l];
            array[l] = temp;
            f++;
            l--;
        }
    } while (f < l);
    if (firstElementNumder < l) quickSort(array, firstElementNumder, l);
    if (f < lastElementNumder) quickSort(array, f, lastElementNumder);
}
```

# С++ Сортировка вставками
***void insertionSort(int *array, int elementsCount)***
```
/**
 * @brief insertionSort
 * @param array
 * @param elementsCount
 */
void insertionSort(int *array, int elementsCount) {
    for (int firstElementNumder = 1; firstElementNumder < elementsCount; firstElementNumder++) {
        for (int numberElement = firstElementNumder; numberElement > 0
            && array[numberElement - 1] > array[numberElement]; numberElement--) {
            array[numberElement - 1] = array[numberElement - 1] + array[numberElement];
            array[numberElement] = array[numberElement - 1] - array[numberElement];
            array[numberElement - 1] = array[numberElement - 1] - array[numberElement];
        }
    }
}
```

# С++ сортировка пузырьком
***void bubbleSort(int *array, int elementsCount)***
```
/**
 * @brief bubbleSort
 * @param array
 * @param elementsCount
 */
void bubbleSort(int *array, int elementsCount) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int numberElement = 0; numberElement < (elementsCount - 1); numberElement++)
            if (array[numberElement] > array[numberElement + 1]) {
                array[numberElement + 1] = array[numberElement + 1] + array[numberElement];
                array[numberElement] = array[numberElement + 1] - array[numberElement];
                array[numberElement + 1] = array[numberElement + 1] - array[numberElement];
                sorted = false;
            }
    }
}
```