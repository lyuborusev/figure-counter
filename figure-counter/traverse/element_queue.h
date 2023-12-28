
#include <deque>
#include <stack>

namespace FigureCounter
{

    template <typename T>
    class ElementQueue
    {
    public:
        virtual void addElement(T element) = 0;
        virtual T nextElement() = 0;
        virtual bool empty() = 0;

        virtual ~ElementQueue();
    };

    template <typename T>
    class QueueFIFO : public ElementQueue<T>
    {
    public:
        void addElement(T element);
        T nextElement();
        bool empty();

    private:
        std::deque<T> queue;
    };

    template <typename T>
    class QueueStack : public ElementQueue<T>
    {
    public:
        void addElement(T element);
        T nextElement();
        bool empty();

    private:
        std::stack<T> stack;
    };

    typedef ElementQueue<int> ElementQueueType;
    typedef QueueFIFO<int> QueueFIFOType;
    typedef QueueStack<int> QueueStackType;
}