#include "pch.h"
#include "CircList.h"
template <typename T> CircLinkNode<T>::CircLinkNode(CircLinkNode<T> *ptr)
{
	link = ptr;
}
template <typename T> CircLinkNode<T>::CircLinkNode(const T &item, CircLinkNode<T> *ptr)
{
	data = item;
	link = ptr;
}
template <typename T> CircLinkNode<T>::~CircLinkNode()
{
}
template <typename T> CircList<T>::CircList()
{
	last = first = new CircLinkNode<T>;
	first->link = first;
}
template <typename T> CircList<T>::CircList(const T &x)
{
	first = last = new CircLinkNode<T>(x);
	first->link = first;
}
template <typename T> CircList<T>::CircList(CircList<T> &L)
{
	//复制循环链表
	CircLinkNode<T> *srcptr = L.first;
	CircLinkNode<T> *destptr = first = new CircLinkNode<T>(srcptr->data);
	while (srcptr != L.last)
	{
		srcptr = srcptr->link;
		destptr->link = new CircLinkNode<T>(srcptr->data);
		destptr = destptr->link;
	}
}
template <typename T> CircList<T>::~CircList()
{
	makeEmpty();
}

template<typename T>void CircList<T>::makeEmpty()
{
	CircLinkNode<T> *q;
	while (first->link != first)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
	last = first;
}

template<typename T>
int CircList<T>::Length() const
{
	int count = 0;
	CircLinkNode<T> *p = first->link;
	while (p != first)
	{
		count++;
		p = p->link;
	}
	return count;
}

template<typename T>
CircLinkNode<T>* CircList<T>::getHead() const
{
	return first;
}

template<typename T>
CircLinkNode<T>* CircList<T>::Search(T x)
{
	CircLinkNode<T> *p = first->link;
	while (p != first)
	{
		if (p->data == x)
		{
			return p;
		}
	}
	return nullptr;
}

template<typename T>
CircLinkNode<T>* CircList<T>::Locate(int i)
{
	if (i < 0)
		return nullptr;
	if (i == 0)
		return first;
	int count = 1;
	CircLinkNode<T> *p = first->link;
	while (p != first && count < i)
	{
		p = p->link;
		count++;
	}
	return (count == i) ? p : nullptr;
}

template<typename T>
bool CircList<T>::getData(int i, T & x) const
{
	if (i <= 0) {
		return false;
	}
	CircLinkNode<T> *current = Locate(i);
	if (current == first || !current) {
		return false;
	}
	else {
		x = current->data;
		return true;
	}
}

template<typename T>
void CircList<T>::setData(int i, T & x)
{
	if (i <= 0)	return;
	CircLinkNode<T> *current = Locate(i);
	if (current == first || !current) return;
	else current->data = x;
}

template<typename T>
bool CircList<T>::Insert(int i, T & x)
{
	return false;
}

template<typename T>
bool CircList<T>::Remove(int i, T & x)
{
	CircLinkNode<T> *current = Locate(i - 1);//定位在待删除结点的前一结点
	if (!current || current->link == first)	return false;
	CircLinkNode<T> *del = current->link;
	if (del == last) last = current;//被删结点为尾结点，重置尾指针
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}

template<typename T>
bool CircList<T>::IsEmpty() const
{
	return (first->link == first) ? true : false;
}

template<typename T>ostream & operator<<(ostream & out, CircList<T>& L)
{
	CircLinkNode<T> *current = L.first->link;
	while (current != L.first) {
		out << current->data << '\t';
		current = current->link;
	}
	out << endl;
	return out;
}

template<typename T>istream & operator>>(istream & in, CircList<T>& L)
{
	T val;
	L.makeEmpty();//先清空
	while (!in.eof()) {
		in >> val;
		L.last->link = new CircLinkNode<T>(val);
		assert(L.last->link);
		L.last = L.last->link;
	}
	L.last->link = L.first;
	in.clear(0);//当以ctrl_Z结束，流关闭，必须重新打开
	return in;
}
