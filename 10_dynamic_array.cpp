#include <iostream>
using namespace std;

void fill(int arr[], int length, int min = 1, int max = 10) {
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void print(int arr[], int length, string text ="") {
    cout << text << endl;
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int* createArray(int size) {
    return new int[size];
}

//int* pushBack(int* arr, int* size, int value) {
//    int* tmp = new int[*size + 1];
//    for (size_t i = 0; i < *size; i++)
//    {
//        tmp[i] = arr[i];
//    }
//    tmp[*size] = value;
//    *size += 1;
//    delete[]arr;
//    return tmp;
//}

//void pushBack(int* &arr, int& size, int value) {
//    int* tmp = new int[size + 1];
//    for (size_t i = 0; i < size; i++)
//    {
//        tmp[i] = arr[i];
//    }
//    tmp[size] = value;
//    size++;
//    delete[]arr;
//    arr = tmp;
//}void pushForward(int*& arr, int& size, int value) {
//    int* tmp = new int[++size];
//    tmp[0] = value;
//    for (size_t i = 0; i < size; i++)
//    {
//        tmp[i+1] = arr[i];
//    }
//    delete[]arr;
//    arr = tmp;
//}
//void delLast(int*& arr, int& size) {
//    int* tmp = new int[--size];
//    for (size_t i = 0; i < size; i++)
//    {
//        tmp[i] = arr[i];
//    }
//    delete[]arr;
//    arr = tmp;
//}
//void delFirst(int*& arr, int& size) {
//    int* tmp = new int[size-1];
//    for (size_t i = 1; i < size; i++)
//    {
//        tmp[i-1] = arr[i];
//    }
//    --size;
//    delete[]arr;
//    arr = tmp;
//}
//void insert(int*& arr, int& size, int value, int index) {
//    if (index < 0 || index > size) {
//        cout << "Index error" << endl;
//        return;
//    }
//    int* tmp = new int[size + 1];
//    for (size_t i = 0; i < size; i++)
//    {
//        if (i < index) {
//            tmp[i] = arr[i];
//        }
//        else {
//            tmp[i + 1] = arr[i];
//        };
//    }
//    tmp[index] = value;
//    size++;
//    delete[]arr;
//    arr = tmp;
//}
//void delByIndex(int*& arr, int& size, int index) {
//    if (index < 0 || index > size) {
//        cout << "Index error" << endl;
//        return;
//    }
//    if (size == 1) {
//        delete[]arr;
//        arr = nullptr;
//    }
//    int* tmp = new int[--size];
//    for (size_t i = 0; i < size; i++)
//    {
//        if (i < index) {
//            tmp[i] = arr[i];
//        }
//        else {
//            tmp[i] = arr[i+1];
//        };
//    }
//    delete[]arr;
//    arr = tmp;
//}
//void Swap(int* a, int* b) {
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void Swap(int& a, int& b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
int* unite(int*& arr1, int*& arr2, int size1, int size2) {
    int length = size1 + size2;
    int* tmp = new int[length];
    for (size_t i = 0; i < size1; i++)
    {
        tmp[i] = arr1[i];
    }
    for (size_t i = size1, j = 0; i < length, j < size2; i++, j++)
    {
        tmp[i] = arr2[j];
    }
    return tmp;
}
int commonArrLength = 0;
int uniqueArrALength = 0;
int uniqueArrBLength = 0;
int* commonElem(int*& arr1, int*& arr2, int size1, int size2) {
    
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j]) {
                ++commonArrLength;
                break;
            }
        }
    }

    int* tmp = new int[commonArrLength];
    int x = 0;
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j]) {
                tmp[x++] = arr1[i];
                break;
            }
        }
    }

    return tmp;
}

int* uniqueAElem(int*& arr1, int*& arr2, int size1, int size2) {

    int* commonElemArr = commonElem(arr1, arr2, size1, size2);

    for (size_t j = 0; j < size1; j++)
    {
        bool foundInCommonElem = false;
        for (size_t i = 0; i < commonArrLength; i++) {
            if (arr1[j] == commonElemArr[i]) {
                foundInCommonElem = true;
                break;
            }
        }
        if (!foundInCommonElem) {
            ++uniqueArrALength;
        }
    }

    int* tmp = new int[uniqueArrALength];
    int x = 0;
    for (size_t j = 0; j < size1; j++)
    {
        bool foundInCommonElem = false;
        for (size_t i = 0; i < commonArrLength; i++) {
            if (arr1[j] == commonElemArr[i]) {
                foundInCommonElem = true;
                break;
            }
        }
        if (!foundInCommonElem) {
            tmp[x++] = arr1[j];
        }
    }
    return tmp;
}
int* uniqueBElem(int*& arr1, int*& arr2, int size1, int size2) {

    int* commonElemArr = commonElem(arr1, arr2, size1, size2);

    for (size_t j = 0; j < size2; j++)
    {
        bool foundInCommonElem = false;
        for (size_t i = 0; i < commonArrLength; i++) {
            if (arr2[j] == commonElemArr[i]) {
                foundInCommonElem = true;
                break;
            }
        }
        if (!foundInCommonElem) {
            ++uniqueArrBLength;
        }
    }

    int* tmp = new int[uniqueArrBLength];
    int x = 0;
    for (size_t j = 0; j < size2; j++)
    {
        bool foundInCommonElem = false;
        for (size_t i = 0; i < commonArrLength; i++) {
            if (arr2[j] == commonElemArr[i]) {
                foundInCommonElem = true;
                break;
            }
        }
        if (!foundInCommonElem) {
            tmp[x++] = arr2[j];
        }
    }
    return tmp;
}
int main()
{
    //new
    //delete
    //int counter = 0;
    //while (true)
    //{
    //    cout << ++counter << endl;
    //    int* ptr = new int[10];
    //    delete[]ptr;
    //}


    //int a = 5, b = 7;
    //cout << a << " - " << b << endl;
    //Swap(a, b);
    //cout << a << " - " << b << endl;


    //int size = 5, min, max;
    //cout << "Enter array size: ";
    //cin >> size;
    //cout << "Enter min element of array: ";
    //cin >> min;
    //cout << "Enter max element of array: ";
    //cin >> max;
    srand(unsigned int(time(0)));
    //int* arr = createArray(size);
    ////fill(arr, size, min, max);
    //fill(arr, size);
    //print(arr, size, "Print arr: ");
    //pushBack(arr, size, 33);
    //pushForward(arr, size, 11);
    //print(arr, size, "Print arr: ");
    //insert(arr, size, 22, 1);
    //print(arr, size, "Print arr: ");
    //delByIndex(arr, size, 4);
    //print(arr, size, "Print arr: ");
    //delFirst(arr, size);
    //print(arr, size, "Print arr: ");
    //delLast(arr, size);
    //print(arr, size, "Print arr: ");

    int n = 7, m = 5;
    int* A = createArray(n);
    int* B = createArray(m);
    fill(A, n);
    fill(B, m);
    print(A, n, "Print arr A: ");
    print(B, m, "Print arr B: ");
    int* united = unite(A, B, n, m);
    print(united, m+n, "Print united arr: ");
    int* common = commonElem(A, B, n, m);
    print(common, commonArrLength, "Print common elem arr: ");
    int* uniqueA = uniqueAElem(A, B, n, m);
    print(uniqueA, uniqueArrALength, "Print unique elems of A arr: ");
    int* uniqueB = uniqueBElem(A, B, n, m);
    print(uniqueB, uniqueArrBLength, "Print unique elems of B arr: ");
    int* uniqueAB = unite(uniqueA, uniqueB, uniqueArrALength, uniqueArrBLength);
    print(uniqueAB, uniqueArrBLength+ uniqueArrALength, "Print unique elems of A and B arrs: ");
}


