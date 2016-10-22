# Сортировка вставками
Сортировка вставками (англ. Insertion sort) — алгоритм сортировки, в котором элементы входной последовательности просматриваются по одному, и каждый новый поступивший элемент размещается в подходящее место среди ранее упорядоченных элементов. Вычислительная сложность — **O(n^2)**.

# Алгоритм
На вход алгоритма подаётся последовательность **n** чисел. Сортируемые числа также называют ключами. Входная последовательность на практике представляется в виде массива с **n** элементами. На выходе алгоритм должен вернуть перестановку исходной последовательности , чтобы выполнялось что все элементы по порядку равны предыдущему либо больше него.
В начальный момент отсортированная последовательность пуста. На каждом шаге алгоритма выбирается один из элементов входных данных и помещается на нужную позицию в уже отсортированной последовательности до тех пор, пока набор входных данных не будет исчерпан. В любой момент времени в отсортированной последовательности элементы удовлетворяют требованиям к выходным данным алгоритма.
Данный алгоритм можно ускорить при помощи использования бинарного поиска для нахождения места текущему элементу в отсортированной части. Проблема с долгим сдвигом массива вправо решается 

[![Сортировка вставками алгоритм GIF](https://cdn.rawgit.com/By-Vasiliy/SAS/4a7ae8558ab772f67ac631131bb5a78599662f73/Documentation/images/Insertion-sort-example-300px.gif)](https://github.com/By-Vasiliy/SAS/blob/develop/Documentation/InsertionSort.md#Алгоритм)

# Сортировка вставками код C++
~~~
template<typename insertionSortType, typename insertionSortCounterType>
void insertionSort(insertionSortType *array, insertionSortCounterType elementsCount) {
    insertionSortType temp;
    for (insertionSortCounterType firstElementNumber = 1; firstElementNumber < elementsCount; firstElementNumber++) {
        for (insertionSortCounterType elementNumber = firstElementNumber;
             elementNumber > 0 && array[elementNumber - 1] > array[elementNumber];
             elementNumber--) {
            temp = array[elementNumber - 1];
            array[elementNumber - 1] = array[elementNumber];
            array[elementNumber] = temp;
        }
    }
}
~~~