/*! @file List.h
 * @brief 双方向リストノード
 */
#include "Type.h"

namespace List {

template<class T>
class Node
{
public:
	Node(){
		prev = NULL;
		next = NULL;
	}
	virtual ~Node(){ Unlink(); }

	bool Link (T *node) {
		if (!node) return false;
		node->Unlink();

		T *tmp = this->next;
		this->next = node;
		node->prev = reinterpret_cast<T *>(this);
		node->next = tmp;
		if (tmp) tmp->prev = node;

		return true;
	}
	
	bool Unlink () {
		if (this->prev) this->prev->next = this->next;
		if (this->next) this->next->prev = this->prev;

		return true;
	}

	virtual void Print(){;}
public:
	T *prev;
	T *next;
};

template<class T>
class Root
{
public:
	class Iterator 
	{
	public:
		Iterator(T *node):m_Node(node){;}
		virtual ~Iterator(){;}

		bool operator==(Iterator it) {
			return it.m_Node == this->m_Node;
		}
		bool operator!=(Iterator it) {
			return it.m_Node != this->m_Node;
		}

		T *operator->() {
			return m_Node;
		}

		Iterator operator++() {
			this->m_Node = m_Node->next;
			return Iterator(m_Node);
		}

		void operator++(int n) {
			this->m_Node = m_Node->next;
		}

	private:
		T *m_Node;
	};
public:
	Root(){ 
		m_Root.next = &m_Root;
		m_Root.prev = &m_Root;
		m_Num = 0;
	}
	virtual ~Root(){;}

	bool PushFront(T *node) {
		if (!m_Root.Link(node)) {
			return false;
		}

		m_Num++;
		return true;
	}

	bool PushBack(T *node) {
		if (!m_Root.prev->Link(node)) {
			return false;
		}

		m_Num++;
		return true;
	}

	bool Remove(T *node) {
		if (isRoot(node)) {
			return false;
		}

		node->Unlink();
		m_Num--;
		return true;
	}

	unsigned int Size() {
		return m_Num;
	}

	Iterator Begin() {
		return Iterator(m_Root.next);
	}
	Iterator End() {
		return Iterator(&m_Root);
	}

	void Show() {
		T *node = m_Root.next;

		for (T* node = m_Root.next; node != &m_Root; node = node->next) {
			node->Print();
		}
	}
private:
	bool isRoot(T *node) {
		return node == &m_Root;
	}
private:
	T   m_Root;
	u32 m_Num;
};

} // List
