#include <iostream>
#include <vector>

struct Point{
    int X;
    int Y;
};


void InsertionSort(std::vector<Point>& a, int n) {
    for (int i = 1; i < n; ++i) {
        Point tmp = a[i];
        int j = i - 1;
        for (; j >= 0 && tmp.X < a[j].X; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
    for (int i = 1; i < n; ++i) {
        Point tmp = a[i];
        int j = i - 1;
            for (; j >= 0 && tmp.X == a[j].X && tmp.Y < a[j].Y ; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = tmp;
    }
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<Point> a(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin >> a[i].X >> a[i].Y;
    }
    InsertionSort(a,n);
    for (Point& x: a)
    {
        std::cout << x.X << " " << x.Y << std::endl;
    }
    return 0;
}
