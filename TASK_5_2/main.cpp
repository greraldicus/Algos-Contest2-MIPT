//https://contest.yandex.ru/contest/30914/run-report/58942163/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int getDigit(long long number, int rank, int rankSize) {
    return (number >> (rank * rankSize) & ((1 << rankSize) - 1));
}

void countingSort(std::vector<long long>& data, int rank, int rankSize)
{
    std::vector<int> buckets(1 << rankSize, 0);
    for (int i = 0; i < data.size(); i++) {
        buckets[getDigit( data[i], rank, rankSize )]++;
    }

    std::vector<int> borders(1 << rankSize, 0);
    for (int i = 1; i < buckets.size(); i++) {
        borders[i] = borders[i - 1] + buckets[i - 1];
    }

    std::vector<long long> sortedData(data.size());
    for (long long number : data) {
        sortedData[borders[getDigit(number, rank, rankSize)]++] = number;
    }

    std::swap(data, sortedData);
}

int getRanksCount(long long number, int rankSize) {
    int ranksCount = 0;
    while (number > 0) {
        number = number >> rankSize;
        ranksCount++;
    }
    return ranksCount;
}

void sortLSD(std::vector<long long>& data, int rankSize)
{
    const long long maxElement = *std::max_element(data.begin(), data.end());
    const int ranksCount = getRanksCount(maxElement, rankSize);

    for (int rank = 0; rank < ranksCount; rank++) {
        countingSort(data, rank, rankSize);
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<long long> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    sortLSD(v, 8);

    for (long long el : v) {
        std::cout << el << "\n";
    }

    return 0;
}
