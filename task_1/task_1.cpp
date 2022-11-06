#include <iostream>
#include <vector>
#include<map>
#include <algorithm>


int main()
{
    std::string in = "Hello world!!";
    std::map<char, int> my_map;
    //Заполняем my_map с одновременным подсчетом коичества соответствующих уникальных символов
    for (const char& val : in) {
        my_map.insert(std::make_pair(val,++my_map[val]));
    }

    //Сортируем my_map по значению
    std::vector <std::pair<char, int>> my_vec(my_map.begin(), my_map.end());
    std::sort(my_vec.begin(), my_vec.end(), [](const auto& val1, const auto& val2) {return val2.second < val1.second; });

    //Выводим отсортированный вектор
    for (auto& val : my_vec) {
        std::cout << val.first << ": " << val.second << "\n";
    }
}
