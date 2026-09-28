#include <iostream>
struct Node
{
	int value;
	Node* next;
};
int main()
{
	int n = 0;
	std::cin >> n;
	Node* head = nullptr;
	Node* tail = nullptr;
	for (int i = 0; i < n; i++)
	{
		int v = 0;
		std::cin >> v;
		Node* p = new Node;
		p->value = v;
		p->next = nullptr;
		if (head == nullptr)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	std::cout << "原始: ";
	int sum = 0;
	for (Node* p = head; p != nullptr; p = p->next)
	{
		std::cout << p->value << " ";
		sum += p->value;
	}
	std ::cout << "\n" << "总和" << sum << "\n";
	Node* pre = nullptr, * now = head;
	while (now != nullptr)
	{
		Node* next = now->next;
		now->next = pre;
		pre = now;
		now = next;
	}
	head = pre;
	std::cout << "反转：";
	for (Node* p = head; p != nullptr; p = p->next)
	{
		std::cout << p->value << " ";
	}
	std::cout << "\n";
	Node* p = head;
	while (p != nullptr)
	{
		Node* next = p->next;    
		delete p;                
		p = next;                
	}
}
