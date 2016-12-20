#include <iostream>

using::std::cout;
using::std::endl;

#define QUEUE_MAX 10

template<typename T>
struct Node
{
	T value;
	Node<T>* front;
	Node<T>* back;
};

template<typename T>
class Queue
{
private:
	int count;
public:
	Node<T> *head, *tail;

	Queue<T>()
	{
		count = 0;
	}

	int push_front(T value)
	{
		if (count > QUEUE_MAX)
			return 0;

		Node<T>* n = new Node<T>();
		n->value = value;

		//ù push��
		if (count <= 0)
		{
			//�յ� ��� null pointer
			n->front = nullptr;
			n->back = nullptr;

			head = new Node<T>();
			tail = new Node<T>();
			head = n;
			tail = n;
		}
		//���� ������ 1���� ��(head = tail�� ��)
		else if (count == 1)
		{
			head->back = n;
			n->front = head;

			head = n;
			tail->back = head;
		}
		else
		{
			//��� ��� ����
			head->back = n;

			//���� ��� ����
			n->front = head;
			n->back = nullptr;

			head = n;
		}

		count++;

		return 1;
	}

	int pop_back()
	{
		if (count == 1)
		{
			count--;
			cout << "pop " << tail->value << endl;

			head = tail = nullptr;
			return 1;
		}
		else if (count > 0)
		{
			Node<T>* bTail = tail->back;
			bTail->front = nullptr;

			cout << "pop " << tail->value << endl;

			tail = bTail;

			count--;
			return 1;
		}
		else
			return 0;
	}
};

int main(int argc, char* argv[])
{
	Queue<int>* q = new Queue<int>();
	for (int i = 0; i < 10; i++)
	{
		q->push_front(i);
	}

	int ret = 0;
	while (q->pop_back())
	{
	}

	getchar();

	return 0;
}

