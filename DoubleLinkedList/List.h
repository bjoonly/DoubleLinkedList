#pragma once
#include <iostream>
using namespace std;
template<class T>
class List{
	struct Node{
		T value;	
		Node* next;	
		Node* prev;	
	};

	Node* head;	
	Node* tail;
	int size;
public:
	List() : head(nullptr), tail(nullptr), size(0) { }
	List(const List& other) {
		head = tail = nullptr;
		size = other.size;
		for (Node* elem = other.head; elem != nullptr; elem = elem->next)
			AddToTail(elem->value);
	}
	List(List&& other) {
		size = other.size;
		head = other.head;
		tail = other.tail;
		other.head = other.tail = nullptr;
		other.size = 0;
	}
	List& operator=(const List& other) {
		if (this != &other) {
			if (!IsEmpty())
				DeleteAll();
			head = tail = nullptr;
			size = other.size;
			for (Node* elem = other.head; elem != nullptr; elem = elem->next)
				AddToTail(elem->value);
		}
		return *this;
	}
	List& operator=(List&& other) {
		if (this != &other) {
			if (!IsEmpty())
				DeleteAll();
			size = other.size;
			head = other.head;
			tail = other.tail;
			other.head = other.tail = nullptr;
			other.size = 0;
		}
		return *this;
	}
	void DeleteAll() {
		while (!IsEmpty()) {
			DeleteHead();
		}
	}
	~List(){
		DeleteAll();
	}

	bool IsEmpty() const{
		return head==nullptr;
	}
	int GetCount() const{
		return size;
	}

	void AddToHead(const T&value){
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		newElem->prev = nullptr;
		
		if (IsEmpty()){
			head = tail = newElem;
		}
		else{
			head->prev = newElem;
			head = newElem;
		}
		++size; 
	}
	void AddToTail(const T&value){
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;
		newElem->prev = tail;
		if (IsEmpty()) 
			head = tail = newElem;	
		else {
			tail->next = newElem;
			tail = newElem;
		}
		++size; 
	}


	void DeleteHead(){
		if (IsEmpty())
			return;
		Node* temp = head->next;
		delete head;
		if (temp == nullptr)
			head = tail = nullptr;
		else{
			temp->prev = nullptr;
			head = temp;
		}
		--size; 
	}

	
	void DeleteTail(){	
		if (IsEmpty()) 
			return;
		Node* temp = tail->prev;
		delete tail;
		if (temp == nullptr)
			head = tail = nullptr;
		else{
			temp->next = nullptr;
			tail = temp;
		}
		--size; 
	}

	
	void Add(const T&value, int pos){
		if (pos <= 0 || pos > size + 1) 
			return;
		if (pos == 1) {
			AddToHead(value);
			return;
		}
		else if (pos == size + 1) {
			AddToTail(value);
			return;
		}
		Node* newElem = new Node;
		newElem->value = value;
		Node* current=nullptr;
		if (pos > size/2 ) {
			current = tail;
			for (int i = size-pos; i >0 ; i--)
				current = current->prev;
		}
		else {
			current = head;
			for (int i = 0; i < pos - 1; ++i)
				current = current->next;
		}
		newElem->prev = current->prev;
		current->prev->next = newElem;
		current->prev = newElem;
		newElem->next = current;
		++size;
	}

	
	void Delete(T pos){	
		if (pos <= 0 || pos > size) 
			return;
		if (pos == 1) {
			DeleteHead();
			return;
		}
		else if (pos == size) {
			DeleteTail();
			return;
		}
		Node* current = nullptr;
		if (pos > size / 2) {
			current = tail;
			for (int i = size - pos; i > 0; i--)
				current = current->prev;
		}
		else {
			 current = head;
			for (int i = 0; i < pos - 1; ++i)
				current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		--size;
	}

	
	void Show() const {
		for (Node* current = head; current != nullptr; current = current->next)
			cout << current-> value << " ";
		cout << endl;

	}
	List operator+(const List& l2)const{
		List res(*this);
		for (Node* elem = l2.head; elem != nullptr; elem = elem->next)
			res.AddToTail(elem->value);
		return res;
	}
	List operator-()const {
		List res;
		for (Node* elem = head; elem != nullptr; elem = elem->next)
			res.AddToHead(elem->value);
		return res;
	}
	int Search(T value)const {
		int pos =1;
		for (Node* current = head; current != nullptr; current = current->next,pos++) 
			if (current->value == value) 
				return pos;
		return -1;
	}
	List operator*(const List& l2)const {
		List res;
		for (Node* elem = head; elem != nullptr; elem = elem->next) 
			if(res.Search(elem->value)==-1)
				res.AddToTail(elem->value);

			for (Node* elem = l2.head; elem != nullptr; elem = elem->next) 
				if (res.Search(elem->value) == -1)
					res.AddToTail(elem->value);
		return res;
	}
};



