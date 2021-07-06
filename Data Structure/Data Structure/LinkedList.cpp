#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size = 0;

public:
	LinkedList(): head(nullptr), tail(nullptr){} // ������
	~LinkedList() {} //�Ҹ���

	// ��� �߰��ϱ�(back)
	void addNode(int value) {
		Node* node = new Node;

		size++;
		node->data = value;
		node->next = nullptr;

		//ù��° �Է�
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		//ó�� �Է��� �ƴ϶��
		else {
			tail->next = node;
			tail = tail->next;
		}
	}

	//ã�� �� ��� �����
	void deleteNode(int value) {
		Node* ptr = head;
		Node* tmp = ptr;

		while (ptr != nullptr) {
			// ���� ã�Ҵٸ�
			if (ptr->data == value) {
				break;
			}
			else {
				tmp = ptr;
				ptr = ptr->next;
			}
		}

		if (ptr == nullptr) {
			cout << "�ش� ���� �������� �ʽ��ϴ�." << endl;
		}
		else {
			size--;
			cout << "������ ����� ���� " << ptr->data << "�Դϴ�." << endl;
			tmp->next = ptr->next;
			delete ptr;
		}
	}

	//List ���� �����ֱ�
	void showList() {
		Node* node = head;

		while (node != nullptr) {
			cout << node->data << "->";
			node = node->next;
		}
		cout << endl;
	}

	//Linked List ��ü ����(Clear)
	void clearList() {
		Node* ptr = head;

		while (ptr != nullptr) {
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
		delete head;
		size = 0;
		cout << "List�� �����Ͽ����ϴ�." << endl;
	}

	//������(Tail) ��� ����
	void deleteTail() {
		Node* ptr = head;
		Node* tmp = ptr;

		//����ã��
		while (ptr->next != nullptr) {
			tmp = ptr;
			ptr = ptr->next;
		}
		size--;
		tail = tmp;
		tail->next = nullptr;
		delete ptr;
	}

	//ó��(head) ��� ����
	void deleteHead() {
		Node* ptr = head;
		head = ptr->next;
		size--;
		delete ptr;
	}

	//ó��(head)�� �� �ֱ�
	void addHead(int value) {
		Node* ptr = new Node();

		size++;
		ptr->data = value;
		ptr->next = head;
		head = ptr;
	}

	//��� ã��
	void searchValue(int value) {
		Node* ptr = head;
		int index = 0;
		bool flag = false; // ã���� true

		while (ptr != nullptr) {
			index++;
			if (ptr->data == value) {
				cout << value << "���� " << index << "��°�� �ֽ��ϴ�." << endl;

				flag = true;
				break;
			}
			ptr = ptr->next;
		}

		//flag == false
		if (!flag) {
			cout << value << "���� Linked List�� �������� �ʽ��ϴ�." << endl;
		}
	}

	//list size
	int sizeList() {
		return size;
	}

};