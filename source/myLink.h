#pragma once

template <typename T>
class myLink
{
public:
	myLink()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	~myLink()
	{
		
		while (tail!=nullptr)
		{
			Node* tmp = tail;
			tail = tail->prev;
			delete tmp;
		}
	}

	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	void insertFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;

		if (head == nullptr)
		{
			tail = newNode;
		}
		else
		{
			head->prev = newNode;
		}

		head = newNode;
		
		count++;
	}

	void insertAfter(Node* prev_node, T data)
	{
		if (prev_node == nullptr)
		{
			return;
		}

		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = prev_node->next;
		prev_node->next = newNode;
		newNode->prev = prev_node;

		if (newNode->next != nullptr)
		{
			(newNode->next)->prev = newNode;
		}

		count++;
	}

	void insertEnd(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = tail;


		if (head == nullptr)
		{
			newNode->prev = nullptr;
			head = newNode;
			tail = newNode;
			count++;
			return;
		}

		tail->next = newNode;
		tail = newNode;
		count++;
	}

	Node* getHead()
	{
		return head;
	}

	Node* getTail()
	{
		return tail;
	}
	
	int size()
	{
		return count;
	}

	void deleteNode(Node* delNode)
	{
		if (head == nullptr || delNode == nullptr)
		{
			return;
		}
		if ((delNode == head) && (delNode == tail))
		{
			head = nullptr;
			tail = nullptr;
			count = 0;
			delete delNode;
			return;
		}
		//head
		if (delNode == head)
		{
			head = delNode->next;
			head->prev = nullptr;
			delete delNode;
			count--;
			return;
		}
		if (delNode == tail)
		{
			tail = delNode->prev;
			tail->next = nullptr;
			delete delNode;
			count--;
			return;
		}
		if (delNode->next != nullptr)
		{
			delNode->next->prev = delNode->prev;
		}
		if (delNode->prev != nullptr)
		{
			delNode->prev->next = delNode->next;
		}

		delete delNode;
		count--;
	}

	Node* getIndex(int index)
	{
		Node* tmp;
		if (index <= (count / 2))
		{
			tmp = head;
			for (size_t i = 0; i < index; i++)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tail;
			for (size_t i = 0; i < ((count - 1) - index); i++)
			{
				tmp = tmp->prev;
			}
		}
		return tmp;
	}


private:
	Node* head;
	Node* tail;
	int count;

};