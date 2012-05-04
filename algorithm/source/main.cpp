/*! @file main.cpp
 * @brief メインエントリ
 */

#include <cstdio>
#include "structure/List.h"

class MyData : public List::Node<MyData>
{
public:
	MyData(){;}
	virtual ~MyData(){;}

	virtual void Print() {
		printf("%d\n", val);
	}

	int val;
};

int main() {
	MyData *a = new MyData;
	MyData *b = new MyData;
	MyData *c = new MyData;

	a->val = 0;
	b->val = 1;
	c->val = 2;

	List::Root<MyData> root;

	root.PushBack(a);
	root.PushBack(b);
	root.PushBack(c);

	List::Root<MyData>::Iterator it = root.Begin();
	for (; it != root.End(); it++) {
		it->Print();
	}
	return 0;
}
