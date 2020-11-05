#include <iostream>
#include <vector>

using namespace std;

/**
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 *
 */

class MyCircularQueue { 
private:
    vector<int> data;       
    int head = -1, tail = -1;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.reserve(k);
        capacity = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            head = 0;
        }

        tail = (tail + 1) % capacity;
        data[tail] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;

        }
        head = (head + 1) % capacity;
    }

    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (head == -1);
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        int temp = (tail + 1) % capacity;
        if (temp == head) {
            return true;
        }

        return false;
    }

};

class MyCircularQueue2 {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue2(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;

        }
        if (isEmpty()) {
            head = 0;

        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;

    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;

        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;

        }
        head = (head + 1) % size;
        return true;

    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;

        }
        return data[head];

    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;

        }
        return data[tail];

    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;

    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;

    }

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

