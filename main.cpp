#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;

/**
 * Functions initialization
 */
void quickSort(int *array, int firstElementNumber, int lastElementNumber);

void insertionSort(int *array, int elementsCount);

template<typename bubbleSortType,typename bubbleSortCounterType>
void bubbleSort(bubbleSortType *array, bubbleSortCounterType elementsCount);

template<typename fillArrayType,typename fillArrayCounterType>
void fillArray(fillArrayType *array, fillArrayCounterType elementsCount);

void print(int *array, int elementsCount);

void arrayDuplicator(int arrayIn[], int arrayOut[], int elementsCount);

void write(int *array, int elementsCount, char *fileName);


int main() {
    int elementsCount;
    cout << "Enter array elements count: ";
    cin >> elementsCount;

    srand(time(NULL));
    clock_t timerClock = clock();
    double sortTime[3];
    int *array = new int[elementsCount];
    double *arrayd= new double[elementsCount];
    int *arrayTemp = new int[elementsCount];
    fillArray(array, elementsCount);
    fillArray(arrayd, elementsCount);
    bubbleSort(arrayd,elementsCount);

    write(array, elementsCount, "array");
    arrayDuplicator(array, arrayTemp, elementsCount);

    timerClock = clock();
    quickSort(arrayTemp, 0, elementsCount - 1);
    timerClock = clock() - timerClock;
    write(arrayTemp, elementsCount, "quickSort");
    sortTime[0] = (((double) timerClock) / (double) CLOCKS_PER_SEC) * 1000;
    cout << "Clock quickSort: " << sortTime[0] << " milliseconds" << "\n";

    arrayDuplicator(array, arrayTemp, elementsCount);

    timerClock = clock();
    insertionSort(arrayTemp, elementsCount);
    timerClock = clock() - timerClock;
    write(arrayTemp, elementsCount, "insertionSort");
    sortTime[1] = (((double) timerClock) / (double) CLOCKS_PER_SEC) * 1000;
    cout << "Clock insertionSort: " << sortTime[1] << " milliseconds" << "\n";

    arrayDuplicator(array, arrayTemp, elementsCount);

    timerClock = clock();
    bubbleSort(arrayTemp, elementsCount);
    timerClock = clock() - timerClock;
    write(arrayTemp, elementsCount, "bubbleSort");
    sortTime[2] = (((double) timerClock) / (double) CLOCKS_PER_SEC) * 1000;
    cout << "Clock bubbleSort: " << sortTime[2] << " milliseconds" << "\n";

    system("pause");
    return 0;
}


/**
 * @brief quickSort
 * @param array
 * @param firstElementNumber
 * @param lastElementNumber
 */
void quickSort(int *array, int firstElementNumber, int lastElementNumber) {
    int averageElementNumber, temp;
    int leftElementNumber = firstElementNumber, rightElementNumber = lastElementNumber;
    averageElementNumber = array[leftElementNumber + (rightElementNumber - leftElementNumber) / 2];
    do {
        while (array[leftElementNumber] < averageElementNumber) leftElementNumber++;
        while (array[rightElementNumber] > averageElementNumber) rightElementNumber--;
        if (leftElementNumber <= rightElementNumber) {
            temp = array[leftElementNumber];
            array[leftElementNumber] = array[rightElementNumber];
            array[rightElementNumber] = temp;
            leftElementNumber++;
            rightElementNumber--;
        }
    } while (leftElementNumber < rightElementNumber);
    if (firstElementNumber < rightElementNumber) quickSort(array, firstElementNumber, rightElementNumber);
    if (leftElementNumber < lastElementNumber) quickSort(array, leftElementNumber, lastElementNumber);
}

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

/**
 * @brief bubbleSort
 * @param array
 * @param elementsCount
 */
template<typename bubbleSortType,typename bubbleSortCounterType>
void bubbleSort(bubbleSortType *array, bubbleSortCounterType elementsCount) {
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

/**
 * @brief fillArray
 * @param array
 * @param elementsCount
 */
template<typename fillArrayType,typename fillArrayCounterType>
void fillArray(fillArrayType *array, fillArrayCounterType elementsCount) {
    for (int elementNumber = 0; elementNumber < elementsCount; elementNumber++) {
        array[elementNumber] = rand() % 65535;
    }
}

/**
 * @brief print
 * @param array
 * @param elementsCount
 */
void print(int *array, int elementsCount) {
    for (int elementNumber = 0; elementNumber < elementsCount; elementNumber++) {
        cout << setw(2) << array[elementNumber] << "  ";
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
    for (int elementNumber = 0; elementNumber < elementsCount; elementNumber++) {
        arrayOut[elementNumber] = arrayIn[elementNumber];
    }
}

/**
 * @brief write
 * @param array
 * @param elementsCount
 * @param fileName
 */
void write(int *array, int elementsCount, char *fileName) {
    ofstream fileStream;

    char fileTimePrefix[256];
    time_t seconds = time(NULL);
    tm *timeinfo = localtime(&seconds);
    strftime(fileTimePrefix, 128, "%d%m%Y_%I%M%S-", timeinfo);

    strcat(fileTimePrefix, fileName);
    strcat(fileTimePrefix, ".csv");

    fileStream.open(fileTimePrefix, ios_base::out | ios_base::trunc);
    for (int i = 0; i < elementsCount; i++) {
        fileStream << array[i] << ';' << endl;
    }
    fileStream.close();
}

void show(int *array, int elementsCount) {
    for (int i = 0; i < elementsCount; i++) {
        std::cout << array[i] << ';';
    }
    std::cout << endl;
}
