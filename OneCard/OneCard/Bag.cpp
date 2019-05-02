#include <iostream>
#include <cstring>
#include "Bag.h"

// using namespace std;
using std :: cout;
using std :: endl;
using std :: min;
using std :: copy;

class Bizcard {
    private :
        char *name;
        char *phone;
    public :
        Bizcard();
        Bizcard(const char *, const char *);
        Bizcard(const Bizcard &);
        ~Bizcard();

        Bizcard& operator= (const Bizcard &);

        void Allocate(const char *, const char *);   
        void ShowInfo();    
};

        Bizcard :: Bizcard() : name(NULL), phone(NULL) {}

        Bizcard :: Bizcard(const char *myname, const char *myphone){ 
            Allocate(myname, myphone);
        }

        Bizcard :: Bizcard(const Bizcard &copy){
            Allocate(copy.name, copy.phone);
        }

        Bizcard :: ~Bizcard(){
            if (name != NULL)
                delete[] name;
            if (phone != NULL)
                delete[] phone;
            name = phone = NULL;
        }

        Bizcard& Bizcard :: operator= (const Bizcard &ref){
            this -> ~Bizcard();

            Allocate(ref.name, ref.phone);
            return *this;
        }

        void Bizcard :: Allocate(const char *myname, const char *myphone){
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
            phone = new char[strlen(myphone) + 1];
            strcpy(phone, myphone);
        }       

        void Bizcard :: ShowInfo(){
            cout<<"이름 : "<<name<<endl;
            cout<<"전화번호 : "<<phone<<endl;
        }      

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

template <class T>
Bag<T> :: Bag(int bagCapacity) : capacity(bagCapacity), top(-1){
    if (capacity < 1){
        throw "Capacity must be > 0";
    }
    array = new T[capacity];
}

template <class T>
Bag<T> :: ~Bag(){
    delete[] array;
}

template <class T>
inline int Bag<T> :: Size() const{
    return top + 1;
}

template <class T>
inline bool Bag<T> :: IsEmpty() const{
    return top == -1;
}

template <class T>
T& Bag<T> :: Element() const{
    if (IsEmpty()){
        throw "Bag is empty";
    }
    return array[rand() % (top + 1)];
}

template <class T>
void Bag<T> :: Push(const T& x){
    if (capacity == top + 1){
        ChangeSize1D(array, capacity, 2 * capacity);
        capacity *= 2;
    }
    array[++top] = x;
}

template <class T>
void Bag<T> :: Pop(){
    if (IsEmpty())
        throw "Bag is empty, cannot delete";
    int deletePos = rand() % (top + 1);
    copy(array + deletePos + 1, array + top + 1, array + deletePos);
    array[top--].~T();
}

template <class T>
void Bag<T> :: ChangeSize1D(T*& a, const int oldSize, const int newSize){
    if (newSize < 0)
        throw "New length must be >= 0";
    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}
