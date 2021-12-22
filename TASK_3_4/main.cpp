//https://contest.yandex.ru/contest/30914/run-report/59443428/

#include <iostream>
#include <random>
#include <vector>

int Partition(std::vector<int>& data, int l, int r) {
    std::random_device a;
    std::mt19937 generator(a());
    std::uniform_int_distribution<int> uniform_dist(l, r - 1);
    int pivot = uniform_dist(generator);
    std::swap(data[pivot], data[l]);

    int i = r - 1, j = r - 1;
    bool f = false;

    while (j != l) {
        if (not f) {
            if (data[l] < data[j]) {
                j--;
                i--;
            } else {
                f = true;
                j--;
            }
        } else {
            if (data[l] < data[j]) {
                std::swap(data[i], data[j]);
                i--;
                j--;
            } else {
                j--;
            }
        }
    }

    std::swap(data[i], data[l]);
    return i;
}

double KStat(std::vector<int>& data, int n, int find) {
    int l = 0, r = n;

    while (true) {
        int pivot_pos = Partition(data, l, r);
        if (pivot_pos == find) {
            return data[find];
        }
        if (pivot_pos < find) {
            l = pivot_pos + 1;
        } else {
            r = pivot_pos;
        }
    }
}

int main() {
    int n, find;
    std::cin >> n >> find;

    std::vector<int> data;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        data.push_back(elem);
    }

    std::cout << KStat(data, n, find);
    return 0;
}
