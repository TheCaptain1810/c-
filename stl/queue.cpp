#include <iostream>
#include <queue>

using namespace std;

void printElements(queue<int> queue)
{
    while (!queue.empty())
    {
        cout << queue.front() << endl;
        queue.pop();
    }
}

int main()
{
    queue<int> numbersQueue;
    numbersQueue.push(1);
    numbersQueue.push(2);
    numbersQueue.push(3);

    cout << "Size of the queue is: " << numbersQueue.size() << endl;
    cout << "Last element of the queue is: " << numbersQueue.back() << endl;
    cout << "First element of the queue is: " << numbersQueue.front() << endl;

    cout << "My queue: " << endl;
    printElements(numbersQueue);
}