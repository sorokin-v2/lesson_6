#include <iostream>
#include <set>
#include<vector>

int main()
{
    std::vector<int> in = { 6, 1, 5, 1, 3, 4, 4 };
    std::set<int, std::greater<int>> my_set;
    for (int i = 1; i < in.size(); ++i) {
        my_set.insert(in.at(i));
    }

    for (auto& val : my_set) {
        std::cout << val << "\n";
    }

}

