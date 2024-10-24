#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    numbers.push_back(0);

    for (int i = 1; i <= 10; ++i)
    {
        numbers.push_back(i);
    }

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Size of this vector is: " << numbers.size() << std::endl;
}