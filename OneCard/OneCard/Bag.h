#ifndef _BAG_H
#define _BAG_H

template <class T>
class Bag{
    private :
        T *array;
        int capacity;
        int top;
    public :
        Bag(int bagCapacity = 3);
        ~Bag();

        int Size() const;
        bool IsEmpty() const;

        T& Element() const;
        void Push(const T&);
        void Pop();
        void ChangeSize1D(T*&, const int, const int);
};

#endif