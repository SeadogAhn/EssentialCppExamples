#pragma once

#ifndef __MYVEC_H__
#define __MYVEC_H__

template <class T>
class myVec {
private:
    int sz;
    T *v;
public:
    myVec();
    explicit myVec(int n);      // ������� ����, 0���� �ʱ�ȭ
    myVec(const T &a, int n);   // ������ n ��ŭ�� ũ�⸦ ����� �ʱ�ȭ
    myVec(const T *a, int n);   // �����ͷ� n ��ŭ�� ũ�⸦ ����� �ʱ�ȭ
    myVec(const myVec &rhs);    // ���� ������
    myVec & operator=(const myVec &rhs); // ���� ������
    myVec & operator=(const T &a);       // ��ü ��Ҹ� a�� ����
    inline T & operator[](const int i);  // �ε��� ������ [i] �� ��ȯ
    inline const T & operator[](const int i) const;
    inline int size() const;
    ~myVec();
};

template <class T>
myVec<T>::myVec() : sz(0), v(0) {}

template <class T>
myVec<T>::myVec(int n) : sz(n), v(new T[n]) {}

template <class T>
myVec<T>::myVec(const T& a, int n) : sz(n), v(new T[n])
{
    for(int i=0; i<n; i++)
        v[i] = a;
}

template <class T>
myVec<T>::myVec(const T *a, int n) : sz(n), v(new T[n])
{
    for(int i=0; i<n; i++)
        v[i] = *a++;
}

template <class T>
myVec<T>::myVec(const myVec<T> &rhs) : sz(rhs.sz), v(new T[sz])
{
    for(int i=0; i<sz; i++)
        v[i] = rhs[i];
}

template <class T>
myVec<T> & myVec<T>::operator=(const myVec<T> &rhs)
{
    if (this != &rhs)
    {
        if (sz != rhs.sz) {
            if (v != 0) delete [] (v);
            sz=rhs.sz;
            v= new T[sz];
        }
        for (int i=0; i<sz; i++)
            v[i]=rhs[i];
    }
    return *this;
}

template <class T>
myVec<T> & myVec<T>::operator=(const T &a)
{
    for (int i=0; i<sz; i++)
        v[i]=a;
    return *this;
}

template <class T>
inline T & myVec<T>::operator[](const int i)
{
    return v[i];
}

template <class T>
inline const T & myVec<T>::operator[](const int i) const
{
    return v[i];
}

template <class T>
inline int myVec<T>::size() const
{
    return sz;
}

template <class T>
myVec<T>::~myVec()
{
    if (v != 0)
        delete[] (v);
}

#endif //__MYVEC_H__
