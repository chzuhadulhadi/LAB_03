//BSEF19M016
//ZUHAD UL HADI
#include <iostream>
#include <cstdlib>
#include<regex>
using namespace std;

#define SIZE 10

template <class X>
class stack
{
    X* arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE);         

    void push(X);
    void pop();
    X peek();

    int size();
    bool isEmpty();
    bool isFull();
    void resize();
    ~stack() 
    {
        delete[] arr;
    }
};


template <class X>
stack<X>::stack(int size)
{
    arr = new X[size];
    capacity = size;
    top = -1;
}


template <class X>
void stack<X>::push(X x)
{
    if (isFull())
    {
        resize();
    }
    arr[++top] = x;
}
template <class X>
void stack<X>::pop()
{
 
    if (isEmpty())
    {
        return;
    }
    else if((capacity/4)+1>top)
    {
        resize();
    }
   top--;
    
}
template <class X>
X stack<X>::peek()
{
    if (!isEmpty())
    {
        return arr[top];
    }
}
template <class X>
int stack<X>::size() {
    return top + 1;
}
template <class X>
bool stack<X>::isEmpty() {
    return top == -1;             
}


template <class X>
bool stack<X>::isFull() 
{
    return top == capacity - 1;     
}
template<class X>
void stack<X>::resize() 
{
   if (isFull())
   {
       int j = capacity;
       capacity *= 2;
       X* tem = new X[capacity];
       for (int i = 0; i < j; i++)
       {
           tem[i] = arr[i];
       }
       delete[] arr;
       arr = tem;
   }
   else
   {
       capacity /= 2;
       X* tem = new X[capacity];
       for (int i = 0; i < capacity; i++)
       {
           tem[i] = arr[i];
       }
       delete[] arr;
       arr = tem;
      
   }
}

 
bool balancer(string str)
{
    string n_str;

    for (int i = 0; i < str.size(); i++)
    {

        switch (str[i])
        {
        case'(':
            n_str += str[i];
            break;
        case ')':
            n_str += str[i];
            break;
        case '[':
            n_str += str[i];
            break;
        case']':
            n_str += str[i];
            break;
        case'{':
            n_str += str[i];
            break;
        case '}':
            n_str += str[i];
            break;
        default:
            break;
        }
    }
    
    int open = 0;
    int count = 0;

    for (int i = 0; i < n_str.length(); i++) {
        if (n_str[i] == '(') {
            open++;
        }
        else if (n_str[i] == ')') {
            open--;
        }
        if (open < 0)
        {
            count++;
            open++;
        }
    }
    cout<<"Brackets needed to balance: "<<count + open;
    return 0;
}


int main()
{
    cout << "Enter String:";

    string str;
    cin >> str;
    
  
  (balancer(str));

}