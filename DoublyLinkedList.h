#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

template <class T>
struct Node {
	T obj;
	Node<T> * next;
	Node<T> * prev;
};

template <class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() { head = tail = curr = nullptr; }
    DoublyLinkedList(const DoublyLinkedList<T> & other) { deepCopy(other); }
    DoublyLinkedList<T> & operator = (const DoublyLinkedList<T> & other);
    ~DoublyLinkedList() { makeEmpty(); }

	// iterator in order: getFirst, getNext
	bool getFirst(T & el);			// O(1) -- no changes to code for singly linked list
	bool getNext(T & el);			// O(1) -- no changes to code for singly linked list

	// iterator in reverse order: getLast, getPrev
	bool getLast(T & el);			// O(1)	-- to be done
	bool getPrev(T & el);			// O(1) -- to be done

    void insert(const T & el);      // O(1) steps -- code for singly lined list to be modified
    bool find(const T & el);        // O(n) steps -- no changes to code for singly linked list
    bool retrieve(T & el);          // O(n) steps -- no changes to code for singly linked list
    bool replace(const T & el);     // O(1) steps -- no changes to code for singly linked list
    bool remove(T & el);            // O(n) steps -- code for singly linked list must be modified.
	// Hint for remove: use find or retrieve, then use prev and next pointers to remove a node..

    bool isEmpty() const { return (head == nullptr); }
    void makeEmpty();				// code changed. Already done for you.
private:
	Node<T> * head;
    Node<T> * tail;
    Node<T> * curr;
    void deepCopy(const DoublyLinkedList<T> & other);	// code changed. Already done for you.
};

template <class T>
bool DoublyLinkedList<T>::getFirst(T & el) {
	if (head == nullptr) return false;
	el = head->obj;
	curr = head;
	return true;
}

template <class T>
bool DoublyLinkedList<T>::getNext(T & el) {
	if (curr == nullptr) return false;
	curr = curr->next;
	if (curr == nullptr) return false;
	el = curr->obj;
	return true;
}

template <class T>
bool DoublyLinkedList<T>::getLast(T & el) {// If the tail is pointing to null ptr return false similar to get first however it would point the 
											//current to the tail instead of the head.
	if (tail == nullptr) 
	return false;

	el = tail->obj;
	curr = tail;
	return true;
}

template <class T>
bool DoublyLinkedList<T>::getPrev(T & el) { //This will try to get the last element before the current node.
	if (tail == nullptr) 
	return false;

	curr = curr->prev;
	if (curr == nullptr) return false;
	el = curr->obj;
	return true;
}

template <class T>
void DoublyLinkedList<T>::insert(const T & el) {
	Node<T> * newNode = new Node<T>;
	newNode->next = head; //This will have a similar setup to the singular linked list with add element
	newNode->obj = el;
	newNode->prev = nullptr; //Setting previous pointer to null for the new head.
	if (head != nullptr) {
		head->prev = newNode; //Update previous heads prev pointer to the new node instead of the nullptr
	}
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
		//If list was empty this will make the tail of the node as the newnode instead of the nullptr
	}
	curr = nullptr;
}

template <class T>
bool DoublyLinkedList<T>::find(const T & el) {
	T currEl;
	if (!getFirst(currEl)) return false;
	if (currEl == el) return true;
	while (getNext(currEl)) {
		if (currEl == el) return true;
	}
	return false;
}

template <class T>
bool DoublyLinkedList<T>::retrieve(T & el) {
	if (find(el)) {
		el = curr->obj;
		return true;
	}
	return false;
}

template <class T>
bool DoublyLinkedList<T>::replace(const T & el) {
	if (curr == nullptr) return false;
	curr->obj = el;
	return true;
}

template <class T>
bool DoublyLinkedList<T>::remove(T & el) { //New
	if (head == nullptr) return false;

    if (head->obj == el) {
        el = head->obj;
        Node<T> *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // This will set the tail to nullptr as well in case there is only one element in the linked list.
            tail = nullptr;
        }
        delete temp;
        curr = nullptr;
        return true;
    }
	//For the previous Node function
	Node<T> *prev = head; //New
    curr = prev->next;
    while (curr != nullptr) {
        if (curr->obj == el) {
            el = curr->obj;
            prev->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = prev;
            } else {
                // If the removed node was the last node, update tail
                tail = prev;
            }
            delete curr;
            curr = nullptr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
	return false;
}

template <class T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator = (const DoublyLinkedList<T> & other) {
	if (this == &other) return (*this);
	makeEmpty();
	deepCopy(other);
	return (*this);
}

template <class T>
void DoublyLinkedList<T>::makeEmpty() {
	curr = head;
	while (curr != nullptr) {
		Node<T> * temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::deepCopy(const DoublyLinkedList<T> & other) {
	Node<T> * otherNode = other.head;
	curr = nullptr;
	if (otherNode == nullptr) { head = tail = nullptr; return; }
	Node<T> * prevNode = new Node<T>;
	head = prevNode;
	prevNode->obj = otherNode->obj;
	prevNode->prev = nullptr;
	if (other.curr == otherNode) curr = prevNode;
	otherNode = otherNode->next;
	while (otherNode != nullptr) {
		Node<T> * currNode = new Node<T>;
		prevNode->next = currNode;
		currNode->obj = otherNode->obj;
		currNode->prev = prevNode;
		if (other.curr == otherNode) curr = currNode;
		otherNode = otherNode->next;
		prevNode = currNode;
	}
	prevNode->next = nullptr;
	tail = prevNode;
}

#endif // DOUBLYLINKEDLIST_H_INCLUDED
