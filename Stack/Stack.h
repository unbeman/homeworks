//
// Created by devernua on 27.12.16.
//

#ifndef HOMEWORKS_STACK_H
#define HOMEWORKS_STACK_H

#include <cstddef>
#include <cassert> // для assert
#include <iostream>

#include <iomanip> // для setw

template <typename T>
class Stack
{
private:
    T *_data;                      // указатель на стек
    size_t _size;                   // максимальное количество элементов в стеке
    size_t _len;                          // номер текущего элемента стека
public:
    Stack(size_t = 16);                  // по умолчанию размер стека равен 16 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор

    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void print();         // вывод стека на экран
    //inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline size_t size() const;  // получить размер стека
    inline T *data() const;         // получить указатель на стек
    inline size_t length() const;        // получить номер текущего элемента в стеке
    inline void resize(size_t);
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(size_t maxSize) :
        _size(maxSize) // инициализация константы
{
    _data = new T[_size]; // выделить память под стек
    _len = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
        _size(otherStack.size()) // инициализация константы
{
    _data = new T[_size]; // выделить память под новый стек
    _len = otherStack.length();

    for(size_t ix = 0; ix < _len; ix++)
        _data[ix] = otherStack._data[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] _data; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    //assert(_len < _size); // номер текущего элемента должен быть меньше размера стека
    if (_len == _size) { resize(_size * 2); }
    _data[_len++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(_len > 0); // номер текущего элемента должен быть больше 0
    if (_len < _size / 2) { resize(_size / 2); }
    return _data[--_len]; // удаляем элемент из стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::print()
{
    for (size_t ix = _len; ix > 0; ix--)
        std::cout << "|" << std::setw(4) << _data[ix-1] << std::endl;
}

// вернуть размер стека
template <typename T>
inline size_t Stack<T>::size() const
{
    return _size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::data() const
{
    return _data;
}

// вернуть размер стека
template <typename T>
inline size_t Stack<T>::length() const
{
    return _len;
}

template <typename T>
inline void Stack<T>::resize(size_t new_size) {
    if(_len > new_size) return;

    T* new_data = new T[new_size];

    for(size_t ix = 0; ix < _len; ix++)
        new_data[ix] = _data[ix];

    delete [] _data;
    _data = new_data;
    _size = new_size;
}

#endif //HOMEWORKS_STACK_H
