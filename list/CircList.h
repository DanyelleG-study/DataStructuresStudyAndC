#pragma once
#include <iostream>
#include <cassert>
#define CIRCLIST_H
#ifndef INSMOD_INF_INR
#define INSMOD_INF_INR
enum InsMod { INF, INR };//��ǰ�����������
#endif
using namespace std;
template <typename T> class CircLinkNode
{
public:
	CircLinkNode(CircLinkNode<T> *ptr = NULL);
	CircLinkNode(const T &item, CircLinkNode<T> *ptr = NULL);
	~CircLinkNode();

private:
	T data;//������
	CircLinkNode<T> *link;//ָ����
};
template<typename T>class CircList
{
public:
	CircList();
	CircList(const T &x);
	CircList(CircList<T> &L);
	~CircList();
	void makeEmpty();
	int Length()const;
	CircLinkNode<T> *getHead()const;
	CircLinkNode<T> *Search(T x);
	CircLinkNode<T> *Locate(int i);
	bool getData(int i, T&x)const;
	void setData(int i, T &x);
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	bool IsEmpty()const;
	bool IsFull()const;
	void Sort();
	void Inverse();//��Ҫ����
	void input(T endTag, InsMod im = INR);
	void output();
	CircList<T> &operator = (CircList<T> &L);
	friend ostream& operator << (ostream &out, CircList<T> &L);
	friend istream& operator >> (istream &in, CircList<T> &L);
	void inputFront(T endTag);
	void inputRear(T endTag);
private:
	CircLinkNode<T> *first, *last;//ͷָ�롢βָ��
};

template<typename T>
inline bool CircList<T>::IsFull() const
{
	return false;
}

template<typename T>
inline void CircList<T>::Sort()
{
}

template<typename T>
inline void CircList<T>::Inverse()
{
}

template<typename T>
inline void CircList<T>::input(T endTag, InsMod im)
{
}

template<typename T>
inline void CircList<T>::output()
{
}

template<typename T>
inline CircList<T>& CircList<T>::operator=(CircList<T>& L)
{
	// TODO: �ڴ˴����� return ���
}

template<typename T>
inline void CircList<T>::inputFront(T endTag)
{
}

template<typename T>
inline void CircList<T>::inputRear(T endTag)
{
}
