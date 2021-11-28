#include <iostream>
#include <vector>

struct Point {
    int Coord;
    bool IsBegin;
};

void SiftDown(std::vector <Point>& arr, int m, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < m && arr[left].Coord > arr[largest].Coord)
        largest = left;
    if (right < m && arr[right].Coord > arr[largest].Coord)
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        SiftDown(arr,m,largest);
    }
}

void HeapSort(std::vector<Point>& arr, int m) {
    for (int i = m / 2 - 1; i >= 0; i--) {
        SiftDown(arr, m, i);
    }

    for (int i = m - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        SiftDown(arr, i, 0);
    }
}

int main()
{
    int n;
    std::cin >> n;
    int m = n*2;
    std::vector <Point> arr(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> arr[i].Coord;
        if (i % 2 == 0)  arr[i].IsBegin = true;
        else arr[i].IsBegin = false;
    }
    HeapSort(arr,m);
    int k = 1;
    int l = 0;
    while (k != 0)
    {
        for (int i = 1; i < m; i++)
        {
            if (k == 1) l += arr[i].Coord - arr[i-1].Coord;
            if (arr[i].IsBegin) k++;
            else k--;
        }
    }
    std::cout << l;
    return 0;
}