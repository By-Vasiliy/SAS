# Sorting-Algorithms-Speed
## Сравнение скорости алгоритмов сортировки


# C++ Быстрая сортировка рекурсией (QSort)
***void quickSort(int *array, int firstElementNumber, int lastElementNumber);***
```
/**
 * @brief quickSort
 * @param array
 * @param firstElementNumber
 * @param lastElementNumber
 */
void quickSort(int *array, int firstElementNumber, int lastElementNumber) {
    int averageElementNumber, temp;
    int f = firstElementNumber, l = lastElementNumber;
    averageElementNumber = array[f + (l - f) / 2];
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
    if (firstElementNumber < l) quickSort(array, firstElementNumber, l);
    if (f < lastElementNumber) quickSort(array, f, lastElementNumber);
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
    int temp;
    for (int firstElementNumber = 1; firstElementNumber < elementsCount; firstElementNumber++) {
        for (int elementNumber = firstElementNumber;
             elementNumber > 0 && array[elementNumber - 1] > array[elementNumber];
             elementNumber--) {
            temp = array[elementNumber - 1];
            array[elementNumber - 1] = array[elementNumber];
            array[elementNumber] = temp;
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
    int temp;
    while (!sorted) {
        sorted = true;
        for (int elementNumber = 0; elementNumber < (elementsCount - 1); elementNumber++)
            if (array[elementNumber] > array[elementNumber + 1]) {
                temp = array[elementNumber + 1];
                array[elementNumber + 1] = array[elementNumber];
                array[elementNumber] = temp;
                sorted = false;
            }
    }
}
```