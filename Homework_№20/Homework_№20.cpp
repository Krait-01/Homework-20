#include <iostream>
#include <cstdlib>
#include <ctime>

/* �������
�������� ������ ������ � 100 ���������. �� ������ ���� �������� ���������� ������� �� -100 �� 100 ������������.
�������� ��������� ������� ��� ������ � ���� ��������:
> showArr() � ������� ������ �� �����;
> searchIndex() � ���������� ������ ������� ��������� �������� � ������. �������� �������� �� ��������� begin = 0;
> searchLastIndex() � ���������� ������ ���������� ��������� �������� � ������. �������� �������� �� ��������� begin = 0;
> maxElement() � ���������� ������������ ������� �������;
> minElement() � ���������� ����������� ������� �������;
> meanValue() � ���������� ������� �������������� ���� ��������� �������;
> range() � ������� ��� �������� �������, ������� ������ � ���������� � ������� ��������;
> counter() � ���������� ���������� ��������� ����������� �������� � ������.*/

using namespace std;
constexpr static int ARRAY_SIZE = 100;
static int s_array[ARRAY_SIZE];

static void showArr()
{
    cout << "������ ������ � 100 ��������� � ����������� ���������� ������� �� -100 �� 100 ������������\n\n����� ������� �� �����:\n";
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
    cout << "������� ������� ������� ��������� �������� � ������:\n";
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
    cout << "\n������� ������� ���������� ��������� �������� � ������:\n";
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
    cout << "\n������� ������������� �������� �������:\n";
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
    cout << "\n������� ������������ �������� �������:\n";
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
    cout << "\n������� �������� ��������������� ���� ��������� �������:\n";
    {
        int mean = 0;
        for (int i = 0; i < ARRAY_SIZE; i++)
            mean += s_array[i];
        return mean / ARRAY_SIZE;
    }
}

static void range(int a, int b)
{
    cout << "\n����� ���� ��������� ������� �������� � ���������� �������� ������� (0, 50):\n";
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
    cout << "\n������� ���������� ��������� ����������� �������� � ������:\n";
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