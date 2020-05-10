#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
    size_t size;
    size_t count;
    T * data;
public:
    Queue();
    Queue(size_t size);
    Queue(const Queue &mc);
    ~Queue();

    Queue<T> & operator=(const Queue<T> &mc);

    bool push(T value);
    bool pop(size_t pos,T value);
    bool top(size_t pos,T &value) const;
    void clear();
    bool isEmpty()const;
    size_t Size()const;
    void print() const;
};

template<typename T>
Queue<T>::Queue()
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
Queue<T>::Queue(size_t size)
{
    if(size < 1)
    {
        size = 1;
    }

    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
Queue<T>::Queue(const Queue &mc)
{
    this->size = mc.size;
    this->count = mc.count;
    this->data = new T[mc.size];

    for(size_t i=0;i<mc.count;i++)
    {
        this->data[i]=mc.data[i];
    }
}

template<typename T>
Queue<T>::~Queue()
{
    if(data) delete [] data;
}

template<typename T>
Queue<T> & Queue<T>::operator=(const Queue<T> &mc)
{
    if(data) delete [] data;

    this->size = mc.size;
    this->count = mc.count;
    this->data = new T[mc.size];

    for(size_t i=0;i<mc.count;i++)
    {
        this->data[i]=mc.data[i];
    }
}

template<typename T>
bool Queue<T>::push(T value)
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }   return false;

}

template<typename T>
bool Queue<T>::pop(size_t pos, T value)
{
    if(pos<count && pos >=0)
    {
        data[pos] = value;
        return true;
    }   return false;
}

template<typename T>
bool Queue<T>::top(size_t pos, T &value) const
{
    if(pos<count && pos >=0)
    {
        value = data[pos];
        return true;
    }   return false;
}

template<typename T>
void Queue<T>::clear()
{
    count = 0;
}

template<typename T>
size_t Queue<T>::Size()const
{
    return size;
}

template<typename T>
bool Queue<T>::isEmpty()const
{
    return count == 0;
}

template<typename T>
void Queue<T>::print() const
{
    cout << "Queue size: " << size << ", count: " << count << endl;
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
#endif // QUEUE_H_INCLUDED
