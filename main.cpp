#include <iostream>
#include <iomanip>
#include <QElapsedTimer>


using namespace std;

/**
 * @brief quickSort
 * @param array
 * @param firstElementNumder
 * @param lastElementNumder
 */
void quickSort(int *array, int firstElementNumder, int lastElementNumder) {
    int mid, count;
    int f = firstElementNumder, l = lastElementNumder;
    mid = array[(f + l) / 2];
    do {
        while (array[f] < mid) f++;
        while (array[l] > mid) l--;
        if (f <= l) {
            count = array[f];
            array[f] = array[l];
            array[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (firstElementNumder < l) quickSort(array, firstElementNumder, l);
    if (f < lastElementNumder) quickSort(array, f, lastElementNumder);
}

/**
 * @brief insertionSort
 * @param array
 * @param elementsCount
 */
void insertionSort(int *array, int elementsCount) {
    for (int firstElementNumder = 1; firstElementNumder < elementsCount; firstElementNumder++) {
        for (int numberElement = firstElementNumder; numberElement > 0
                                                     &&
                                                     array[numberElement - 1] > array[numberElement]; numberElement--) {
            array[numberElement - 1] = array[numberElement - 1] + array[numberElement];
            array[numberElement] = array[numberElement - 1] - array[numberElement];
            array[numberElement - 1] = array[numberElement - 1] - array[numberElement];
        }
    }
}

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

/**
 * @brief fillArray
 * @param array
 * @param elementsCount
 */
void fillArray(int *array, int elementsCount) {
    for (int numberElement = 0; numberElement < elementsCount; numberElement++) {
        array[numberElement] = rand() % 65535;
    }
}

/**
 * @brief print
 * @param array
 * @param elementsCount
 */
void print(int *array, int elementsCount) {
    for (int numberElement = 0; numberElement < elementsCount; numberElement++) {
        cout << setw(2) << array[numberElement] << "  ";
    }
    cout << endl;
}

/**
 * @brief arrayDuplicator void
 * @param arrayIn array
 * @param arrayOut array
 * @param elementsCount int
 */
void arrayDuplicator(int arrayIn[], int arrayOut[], int elementsCount) {
    for (int numberElement = 0; numberElement < elementsCount; numberElement++) {
        arrayOut[numberElement] = arrayIn[numberElement];
    }
}


int main() {
    srand(time(NULL));

    int elementsCount;
    cout << "Enter array elements count: ";
    cin >> elementsCount;

    QElapsedTimer timer;

    int *array = new int[elementsCount];
    int *arrayTemp = new int[elementsCount];
    fillArray(array, elementsCount);

    arrayDuplicator(array, arrayTemp, elementsCount);
    timer.start();
    quickSort(arrayTemp, 0, elementsCount - 1);
    cout << "quickSort: " << timer.elapsed() << " milliseconds" << "\n\n";

    arrayDuplicator(array, arrayTemp, elementsCount);
    timer.restart();
    insertionSort(arrayTemp, elementsCount);
    cout << "insertionSort: " << timer.elapsed() << " milliseconds" << "\n\n";

    arrayDuplicator(array, arrayTemp, elementsCount);
    timer.restart();
    bubbleSort(arrayTemp, elementsCount);
    cout << "bubbleSort: " << timer.elapsed() << " milliseconds" << "\n\n";

    system("pause");
    return 0;
}
