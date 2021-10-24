/*
 *  Stacks Using Queue
 *  Implement Stack data structure using Queue
 *  Author: Shakti Raj Pandey
 *
 */

#include<bits/stdc++.h>
using namespace std;

// Algorithm
// 1) PUSH: Push an element involves shifting Queue q1 data to Queue q2 
//    and then add the element to Queue q1, after this again push q2 data to q1
// 2) POP: Popping an element requires to pop element from q1 directly 


// Implement stack using two queues
class Stack
{
    queue<int> q1, q2;
 
public:
    // Insert an item into the stack
    void push(int data)
    {
        // Move all elements from the first queue to the second queue
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
 
        // Push the given item into the first queue
        q1.push(data);
 
        // Move all elements back to the first queue from the second queue
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
 
    // Remove the top item from the stack
    int pop()
    {
        // if the first queue is empty
        if (q1.empty())
        {
            cout << "Underflow!!";
            exit(0);
        }
 
        // return the front item from the first queue
        int front = q1.front();
        q1.pop();
 
        return front;
    }
};
 
int main()
{
    vector<int> keys = { 1, 2, 3, 4, 5 };
 
    // insert the above keys into the stack
    Stack s;
    for (int key: keys) {
        s.push(key);
    }
 
    for (int i = 0; i <= keys.size(); i++) {
        cout << s.pop() << endl;
    }
 
    return 0;
}