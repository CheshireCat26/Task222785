#include <iostream>
#include <algorithm>

using namespace std;

bool isFull ( const int &numElements, const int CAPACITY);
bool isEmpty (const int &numElements);
int getIndex (const int numbers[],const int &numElements,const int value);
int getIndexWrap (const int numbers[],const int &numElements);
void output(const int numbers[],const int &numElements);
void append(int numbers[], int &numElements,const int CAPACITY, const int value);
void appendWrap(int numbers[], int &numElements,const int CAPACITY);
void instertAt(int *numbers, int &numElements, const int CAPACITY, const int value, const int index);
bool willSort(const int *numbers, const int &numElements, const int value, const int index);
void instertAtWrap(int *numbers, int &numElements, const int CAPACITY);
bool removeElement (int numbers[], int &numElements, const int value);
bool removeElementWrap (int numbers[], int &numElements);
bool removeFirst (int numbers[], int &numElements);
bool removeLast (int &numElements);




int main()
{
    constexpr int CAPACITY = 100;
    int numbers[CAPACITY];
    int numElements = 0;

    append(numbers, numElements, CAPACITY, 10);
    append(numbers, numElements, CAPACITY, 20);
    append(numbers, numElements, CAPACITY, 30);
    append(numbers, numElements, CAPACITY, 40);
    append(numbers, numElements, CAPACITY, 50);
    append(numbers, numElements, CAPACITY, 60);
    append(numbers, numElements, CAPACITY, 70);
    append(numbers, numElements, CAPACITY, 80);
    append(numbers, numElements, CAPACITY, 90);
    append(numbers, numElements, CAPACITY, 100);


    unsigned short choice;
    do
    {
        cout << "Array Manipulation: " << endl;
        cout << "-----------------" << endl;
        cout << "1. Get Index"    << endl
             << "2. Append"       << endl
             << "3. Insert"       << endl
             << "4. Remove"       << endl
             << "5. Remove First" << endl
             << "6. Remove Last"  << endl
             << "7. Output"       << endl
             << "8. Exit program" << endl;
        cout << "Select: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << getIndexWrap(numbers, numElements) << endl;
                break;
            case 2:
                appendWrap(numbers, numElements, CAPACITY);
                break;
            case 3:
                instertAtWrap(numbers, numElements, CAPACITY);
                break;
            case 4:
                removeElementWrap(numbers, numElements);
                break;
            case 5:
                removeFirst(numbers, numElements);
                break;
            case 6:
                removeLast(numElements);
                break;
            case 7:
                output(numbers, numElements);
                break;
            case 8:
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }while (choice != 8);


    return 0;
}

int getIndexWrap (const int numbers[],const int &numElements)
{
    int value;
    cin >> value;
    return  getIndex(numbers, numElements, value);
}

void appendWrap(int numbers[], int &numElements,const int CAPACITY)
{
    int value;
    cin >> value;
    append(numbers, numElements, CAPACITY, value);
}

void instertAtWrap(int *numbers, int &numElements, const int CAPACITY)
{
    int value, index;
    cin >> value >> index;
    instertAt(numbers, numElements, CAPACITY, value, index);
}

bool removeElementWrap (int numbers[], int &numElements)
{
    int value;
    cin >> value;
    return removeElement(numbers, numElements, value);
}

bool removeFirst (int numbers[], int &numElements)
{
    if (isEmpty(numElements))
        return false;
    else
    {
        numElements--;
        for (int i = 0; i < numElements; i++)
            numbers[i] = numbers[i + 1];
    }
    return true;
}

bool removeLast(int &numElements)
{
    if (isEmpty(numElements))
        return false;
    else
        numElements--;

    return true;
}

void output(const int numbers[],const int &numElements)
{
    cout << "Array: ";
    for (int i = 0; i < numElements; i++)
        cout << numbers[i] << " ";

    cout << "Size: " << numElements << endl;
}

int getIndex (const int numbers[],const int &numElements,const int value)
{
    const int* iter = find(numbers, numbers + numElements, value);
    if (iter == numbers + numElements)
        return -1;
    else
        return iter - numbers;
}

void append(int numbers[], int &numElements, const int CAPACITY, const int value)
{

    if (!isFull(numElements, CAPACITY) && (numElements == 0 ||  numbers[numElements - 1] <= value))
    {
        numbers[numElements] = value;
        numElements++;
    }
}

void instertAt(int *numbers, int &numElements, const int CAPACITY, const int value, const int index)
{
    if (numElements < CAPACITY && index >= 0 && index < numElements)
    {
        if (willSort(numbers, numElements, value, index))
        {
            for (int i = numElements; i > index; i--)
                numbers[i] = numbers[i - 1];

            numbers[index] = value;
            numElements++;
        }

    }
}

bool willSort(const int *numbers,const int &numElements, const int value, const int index)
{
    return (index == 0 && value <= numbers[0])||
           (index == numElements - 1 && value >= numbers[numElements - 1])||
           (value >= numbers[index - 1] && value <= numbers[index]);
}

bool removeElement (int numbers[], int &numElements, const int value)
{
    int index = getIndex(numbers, numElements, value);
    if (index != - 1)
    {
        if (index == 0)
            return removeFirst(numbers, numElements);
        else if (index == numElements - 1)
            return removeLast(numElements);
        else
        {
            for (int i = index; i < numElements; i++)
                numbers[i] = numbers[i + 1];
            numElements--;
            return true;
        }
    }
    else
        return false;
}

bool isFull ( const int &numElements, const int CAPACITY)
{
    return numElements == CAPACITY;
}

bool isEmpty (const int &numElements)
{
    return numElements == 0;
}