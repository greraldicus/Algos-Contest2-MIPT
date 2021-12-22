//https://contest.yandex.ru/contest/30914/run-report/62362233/

#include <iostream>
#include <vector>
#include <algorithm>

int64_t merge_sort_private(std::vector<int>& data,
                           int left, int right)
{
    if (right - left <= 1) {
        return 0;
    }
    const int mid = (left + right) / 2;
    int64_t inversionsCount = merge_sort_private(data, left, mid);
    inversionsCount += merge_sort_private(data, mid, right);

    int merge_left = left;
    int merge_right = mid;

    std::vector<int> buffer(right - left);
    int merge_index = 0;

    while (merge_left < mid
           || merge_right < right)
    {
        if (merge_left < mid
            && merge_right < right)
        {
            if (data[merge_left] <= data[merge_right]) {

                inversionsCount += merge_right - mid;

                buffer[merge_index++] = data[merge_left++];
            }
            else {
                buffer[merge_index++] = data[merge_right++];
            }
        }
        else if (merge_left < mid) {

            inversionsCount += right - mid;
            buffer[merge_index++] = data[merge_left++];
        }
        else {
            buffer[merge_index++] = data[merge_right++];
        }
    }

    for (int i = 0; i < buffer.size(); i++) {
        data[left + i] = buffer[i];
    }
    return inversionsCount;
}

int64_t merge_sort(std::vector<int>& data)
{
    return merge_sort_private(data, 0, data.size());
}

int main()
{
    int a;
    std::vector <int> data;
    while (std::cin >> a) {
        data.push_back(a);
    }
    std::cout << merge_sort(data);
}
