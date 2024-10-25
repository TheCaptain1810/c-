#include <iostream>
#include <stack>

using namespace std;

void printElements(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}

int main()
{
    stack<int> numbersStack;
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);
    numbersStack.pop();

    printElements(numbersStack);

    cout << "Size of the stack is: " << numbersStack.size() << endl;
}