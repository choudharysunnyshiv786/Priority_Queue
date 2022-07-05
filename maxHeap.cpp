#include <iostream>
#include <vector>
using namespace std;

class maxHeap
{
private:
    int heapSize = 0;
    vector<int> heap{-1};

    int parentIndex(int i)
    {
        return i >> 1;
    }
    int leftChildIndex(int i)
    {
        return i << 1;
    }
    int rightChildIndex(int i)
    {
        return (1 << i) + 1;
    }

    void heapifyUp(int i)
    {
        if (i == 1)
            return;
        if (heap[i] > heap[parentIndex(i)])
        {
            swap(heap[i], heap[parentIndex(i)]);
            heapifyUp(parentIndex(i));
        }
    }

    void heapifyDown(int i)
    {
        if (i > heapSize)
            return;
        int swapInd = i;
        if (leftChildIndex(i) <= heapSize and heap[swapInd] < heap[leftChildIndex(i)])
        {
            swapInd = leftChildIndex(i);
        }
        if (rightChildIndex(i) <= heapSize and heap[swapInd] < heap[rightChildIndex(i)])
        {
            swapInd = rightChildIndex(i);
        }
        if (swapInd != i)
        {
            swap(heap[i], heap[swapInd]);
            heapifyDown(swapInd);
        }
    }

public:
    bool empty()
    {
        return heapSize == 0;
    }
    int size()
    {
        return heapSize;
    }
    int top()
    {
        return heap[1];
    }
    void push(int x)
    {
        heapSize++;
        heap.push_back(x);
        heapifyUp(heapSize);
    }
    void pop()
    {
        swap(heap[1], heap[heapSize]);
        heapSize--;
        heapifyDown(1);
    }
    void show()
    {
        for (int i = 1; i <= heapSize; i++)
            cout << heap[i] << ' ';
        cout << '\n';
    }
};

int main()
{
    maxHeap pq;
    pq.push(10);

    pq.push(30);

    pq.push(20);

    pq.push(5);

    pq.push(1);

    pq.show();
    
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}
