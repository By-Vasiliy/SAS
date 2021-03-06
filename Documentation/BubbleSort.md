# Сортировка пузырьком

Сортировка простыми обменами, сортиро́вка пузырько́м (англ. bubble sort) — простой алгоритм сортировки. Для понимания и реализации этот алгоритм — простейший, но эффективен он лишь для небольших массивов. Сложность алгоритма: **O(n^2)**.

Алгоритм считается учебным и практически не применяется вне учебной литературы, вместо него на практике применяются более эффективные алгоритмы сортировки. В то же время метод сортировки обменами лежит в основе некоторых более совершенных алгоритмов, таких как шейкерная сортировка, пирамидальная сортировка и быстрая сортировка.

# Алгоритм
Алгоритм состоит из повторяющихся проходов по сортируемому массиву. За каждый проход элементы последовательно сравниваются попарно и, если порядок в паре неверный, выполняется обмен элементов. Проходы по массиву повторяются **N-1** раз или до тех пор, пока на очередном проходе не окажется, что обмены больше не нужны, что означает — массив отсортирован. При каждом проходе алгоритма по внутреннему циклу, очередной наибольший элемент массива ставится на своё место в конце массива рядом с предыдущим «наибольшим элементом», а наименьший элемент перемещается на одну позицию к началу массива («всплывает» до нужной позиции, как пузырёк в воде, отсюда и название алгоритма).

[![Сортировка пузырьком алгоритм GIF](https://cdn.rawgit.com/vasilyukvasiliy/Sorting-Algorithms-Speed/4a7ae8558ab772f67ac631131bb5a78599662f73/Documentation/images/Bubble-sort-example-300px.gif)](https://github.com/vasilyukvasiliy/Sorting-Algorithms-Speed/blob/master/Documentation/BubbleSort.md#Алгоритм)

# Сортировка пузырьком код C++
~~~
template<typename bubbleSortType, typename bubbleSortCounterType>
void bubbleSort(bubbleSortType *array, bubbleSortCounterType elementsCount) {
    bool sorted = false;
    bubbleSortType temp;
    while (!sorted) {
        sorted = true;
        for (bubbleSortCounterType elementNumber = 0; elementNumber < (elementsCount - 1); elementNumber++)
            if (array[elementNumber] > array[elementNumber + 1]) {
                temp = array[elementNumber + 1];
                array[elementNumber + 1] = array[elementNumber];
                array[elementNumber] = temp;
                sorted = false;
            }
    }
}
~~~