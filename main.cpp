#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sys/time.h>
#include <QtCore/QCoreApplication>
#include <QElapsedTimer>


using namespace std;


void insertionSort(int* array,int elementsCount){
    for(int i=1;i<elementsCount;i++){
        for(int numberElement=i; numberElement>0 && array[numberElement-1]>array[numberElement];numberElement--){
            int tmp=array[numberElement-1];
            array[numberElement-1] = array[numberElement-1] + array[numberElement];
            array[numberElement] = array[numberElement-1] - array[numberElement];
            array[numberElement-1] = array[numberElement-1] -array[numberElement];
        }
    }
}

void bubbleSort(int* array, int elementsCount)
{
 bool exit = false;
 while (!exit)
 {
  exit = true;
  for (int numberElement = 0; numberElement < (elementsCount - 1); numberElement++)
    if (array[numberElement] > array[numberElement + 1])
    {
        array[numberElement+1] = array[numberElement+1] + array[numberElement];
        array[numberElement] = array[numberElement+1] - array[numberElement];
        array[numberElement+1] = array[numberElement+1] - array[numberElement];
        exit = false;
    }
 }
}

void fillArray(int* array, int elementsCount){
    for (int numberElement = 0; numberElement < elementsCount; numberElement++)
    {
        array[numberElement] = rand() % 65535;
    }
}

void print(int* array, int elementsCount){
    for (int numberElement = 0; numberElement < elementsCount; numberElement++)
    {
        cout << setw(2) << array[numberElement] << "  ";
    }
}

int main()
{
    srand(time(NULL));
    cout << "Enter arrayay elements count: ";
    int elementsCount;
    cin >> elementsCount;


    int *randomarrayay = new int [elementsCount];
    int *bubbleSortarrayay = new int [elementsCount];
    int *insertionSortarrayay = new int [elementsCount];
    fillArray(randomarrayay,elementsCount);
    cout << "\n\n";


    fillArray(bubbleSortarrayay,elementsCount);
    fillArray(insertionSortarrayay,elementsCount);
    QElapsedTimer timer;
    timer.start();
    cout << "Start: " << timer.elapsed() << " milliseconds"<< "\n\n";
    bubbleSort(bubbleSortarrayay, elementsCount);

    cout << "bubbleSort: " << timer.elapsed() << " milliseconds"<< "\n\n";
    timer.restart();
    insertionSort(insertionSortarrayay, elementsCount);

    cout << "insertionSort: " << timer.elapsed() << " milliseconds"<< "\n\n";


    for (int numberElement = 0; numberElement < elementsCount; numberElement++)
    {

    }
    cout << "\n";

    system("pause");
    return 0;
}


