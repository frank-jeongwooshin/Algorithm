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
	LinkedList(): head(nullptr), tail(nullptr){} // 생성자
	~LinkedList() {} //소멸자

	// 노드 추가하기(back)
	void addNode(int value) {
		Node* node = new Node;

		size++;
		node->data = value;
		node->next = nullptr;

		//첫번째 입력
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		//처음 입력이 아니라면
		else {
			tail->next = node;
			tail = tail->next;
		}
	}

	//찾는 값 노드 지우기
	void deleteNode(int value) {
		Node* ptr = head;
		Node* tmp = ptr;

		while (ptr != nullptr) {
			// 값을 찾았다면
			if (ptr->data == value) {
				break;
			}
			else {
				tmp = ptr;
				ptr = ptr->next;
			}
		}

		if (ptr == nullptr) {
			cout << "해당 노드는 존재하지 않습니다." << endl;
		}
		else {
			size--;
			cout << "삭제된 노드의 값은 " << ptr->data << "입니다." << endl;
			tmp->next = ptr->next;
			delete ptr;
		}
	}

	//List 값들 보여주기
	void showList() {
		Node* node = head;

		while (node != nullptr) {
			cout << node->data << "->";
			node = node->next;
		}
		cout << endl;
	}

	//Linked List 자체 삭제(Clear)
	void clearList() {
		Node* ptr = head;

		while (ptr != nullptr) {
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
		delete head;
		size = 0;
		cout << "List를 삭제하였습니다." << endl;
	}

	//마지막(Tail) 노드 삭제
	void deleteTail() {
		Node* ptr = head;
		Node* tmp = ptr;

		//꼬리찾기
		while (ptr->next != nullptr) {
			tmp = ptr;
			ptr = ptr->next;
		}
		size--;
		tail = tmp;
		tail->next = nullptr;
		delete ptr;
	}

	//처음(head) 노드 삭제
	void deleteHead() {
		Node* ptr = head;
		head = ptr->next;
		size--;
		delete ptr;
	}

	//처음(head)에 값 넣기
	void addHead(int value) {
		Node* ptr = new Node();

		size++;
		ptr->data = value;
		ptr->next = head;
		head = ptr;
	}

	//노드 찾기
	void searchValue(int value) {
		Node* ptr = head;
		int index = 0;
		bool flag = false; // 찾으면 true

		while (ptr != nullptr) {
			index++;
			if (ptr->data == value) {
				cout << value << "값은 " << index << "번째에 있습니다." << endl;

				flag = true;
				break;
			}
			ptr = ptr->next;
		}

		//flag == false
		if (!flag) {
			cout << value << "값은 Linked List에 존재하지 않습니다." << endl;
		}
	}

	//list size
	int sizeList() {
		return size;
	}

};