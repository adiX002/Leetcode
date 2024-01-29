class MyQueue
{
private:
    stack<int> st1, st2;

public:
    MyQueue() { }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        int poppedElement = -1;

        if (!st2.empty()) {
            poppedElement = st2.top();
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }

            poppedElement = st2.top();
        }

        st2.pop();

        return poppedElement;
    }

    int peek()
    {
        int peekElement = -1;

        if (!st2.empty()) {
            peekElement = st2.top();
        } else {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }

            peekElement = st2.top();
        }

        return peekElement;
    }

    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */