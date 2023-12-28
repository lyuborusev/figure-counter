#include "element_queue.h"

namespace FigureCounter
{
    template <typename T>
    ElementQueue<T>::~ElementQueue()
    {
    }

    template <typename T>
    void QueueFIFO<T>::addElement(T element)
    {
        queue.push_back(element);
    }

    template <typename T>
    T QueueFIFO<T>::nextElement()
    {
        T element = queue.front();
        queue.pop_front();
        return element;
    }

    template <typename T>
    bool QueueFIFO<T>::empty()
    {
        return queue.empty();
    }

    template <typename T>
    void QueueStack<T>::addElement(T element)
    {
        stack.push(element);
    }

    template <typename T>
    T QueueStack<T>::nextElement()
    {
        T element = stack.top();
        stack.pop();
        return element;
    }

    template <typename T>
    bool QueueStack<T>::empty()
    {
        return stack.empty();
    }

    template class ElementQueue<int>;
    template class QueueFIFO<int>;
    template class QueueStack<int>;
}