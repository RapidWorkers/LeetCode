#include <iostream>
#include <string>

using namespace std;

class MyCircularDeque {
private:
    size_t k;
    int front, last;
    int* values;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        this->k = k + 1;
        this->front = 0;
        this->last = 0;
        values = new int[k + 1];
    }

    ~MyCircularDeque()
    {
        delete[] values;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        values[front] = value;
        front = (front - 1 + k) % k;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        last = (last + 1) % k;
        values[last] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        last = (last - 1 + k) % k;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return values[(front + 1) % k];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return values[last];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (front == last);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((last + 1) % k == front);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    MyCircularDeque mCD(N);
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push")
        {
            cnt++;
            int num;
            cin >> num;
            mCD.insertLast(num);
        }
        else if (cmd == "pop")
        {
            if(cnt) cnt--;
            cout << mCD.getFront() <<'\n';
            mCD.deleteFront();
        }
        else if (cmd == "size")
        {
            cout << cnt << '\n';
        }
        else if (cmd == "empty")
        {
            cout << mCD.isEmpty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << mCD.getFront() << '\n';
        }
        else if (cmd == "back")
        {
            cout << mCD.getRear() << '\n';
        }

    }
}
