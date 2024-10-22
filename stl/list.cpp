#include <iostream>
#include <list>

void insertPlayerIntoSortedList(int rating, std::list<int> &playersList)
{
    for (std::list<int>::iterator it = playersList.begin(); it != playersList.end(); it++)
    {
        if (*it > rating)
        {
            playersList.insert(it, rating);
            return;
        }
    }
    playersList.push_back(rating);
}

void displayPlayers(const std::list<int> &playersList)
{
    for (std::list<int>::const_iterator it = playersList.begin(); it != playersList.end(); it++)
    {
        std::cout << "Player rating: " << *it << std::endl;
    }
}

int main()
{
    std::list<int> allPlayers = {2, 5, 8, 5, 3, 1, 8, 9, 4, 4, 8, 7, 1, 3, 2};
    std::list<int> beginners;
    std::list<int> pros;

    for (std::list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++)
    {
        int rating = *it;
        if (rating >= 1 && rating <= 5)
            insertPlayerIntoSortedList(rating, beginners);
        else if (rating >= 6 && rating <= 10)
            insertPlayerIntoSortedList(rating, pros);
    }

    std::cout << "Beginners: " << std::endl;
    displayPlayers(beginners);
    std::cout << "Pros: " << std::endl;
    displayPlayers(pros);

    std::cin.get();
}