#include <iostream>
#include <cstdlib>
#include <ctime>

/* Задание
Создайте массив длиною в 100 элементов. Он должен быть заполнен случайными числами от -100 до 100 включительно.
Создайте следующие функции для работы с этим массивом:
> showArr() – выводит массив на экран;
> searchIndex() – возвращает индекс первого вхождения элемента в массив. Содержит параметр по умолчанию begin = 0;
> searchLastIndex() – возвращает индекс последнего вхождения элемента в массив. Содержит параметр по умолчанию begin = 0;
> maxElement() – возвращает максимальный элемент массива;
> minElement() – возвращает минимальный элемент массива;
> meanValue() – возвращает среднее арифметическое всех элементов массива;
> range() – выводит все элементы массива, которые входят в переданный в функцию диапазон;
> counter() – возвращает количество вхождений переданного элемента в массив.*/

using namespace std;
constexpr static int ARRAY_SIZE = 100;
static int s_array[ARRAY_SIZE];

static void showArr()
{
    cout << "Массив длиною в 100 элементов и заполненный случайными числами от -100 до 100 включительно\n\nВывод массива на экран:\n";
    {
        cout << "[ ";
        for (int i = 0; i < ARRAY_SIZE; i++)
            cout << s_array[i] << " ";
        cout << "]" << endl;
    }
    cout << endl;
}


static int searchIndex(int value, int begin = 0)
{
    cout << "Возврат индекса первого вхождения элемента в массив:\n";
    for (int i = begin; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] != value)
            continue;
        return i;
    }
    return -1;
}

static int searchLastIndex(int value, int begin = 0)
{
    cout << "\nВозврат индекса последнего вхождения элемента в массив:\n";
    int result = -1;
    for (int i = begin; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] != value)
            continue;
        result = i;
    }
    return result;
}

static int maxElement()
{
    cout << "\nВозврат максимального элемента массива:\n";
    int max = -100;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] <= max)
            continue;
        max = s_array[i];
    }
    return max;
}

static int minElement()
{
    cout << "\nВозврат минимального элемента массива:\n";
    int min = 100;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] >= min)
            continue;
        min = s_array[i];
    }
    return min;
}

static int meanValue()
{
    cout << "\nВозврат среднего арифметического всех элементов массива:\n";
    {
        int mean = 0;
        for (int i = 0; i < ARRAY_SIZE; i++)
            mean += s_array[i];
        return mean / ARRAY_SIZE;
    }
}

static void range(int a, int b)
{
    cout << "\nВывод всех элементов массива входящих в переданный диапазон функции (0, 50):\n";
    cout << "[ ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] < a || s_array[i] > b)
            continue;
        cout << s_array[i] << " ";
    }
    cout << "]" << endl;
}

static int counter(int value)
{
    cout << "\nВозврат количества вхождений переданного элемента в массив:\n";
    int result = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (s_array[i] != value)
            continue;
        result++;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < ARRAY_SIZE; i++)
        s_array[i] = -100 + (rand() % 200);
    showArr();

    cout << "searchIndex(25, 0): " << searchIndex(25) << endl;
    cout << "searchLastIndex(25, 0): " << searchLastIndex(25) << endl;
    cout << "maxElement(): " << maxElement() << endl;
    cout << "minElement(): " << minElement() << endl;
    cout << "meanValue(): " << meanValue() << endl;
    range(0, 50);
    cout << "counter(25): " << counter(25) << endl;

    return 0;
}