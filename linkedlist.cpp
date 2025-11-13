template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
	itemCount = aList.itemCount;
	if(aList.headPtr == nullptr){ //This means list is empty
		headPtr = nullptr;
	}
	else{
		headPtr = new Node<ItemType>(); 
		headPtr->setItem(aList.headPtr->getItem()); //Head pointer is the node, which has access to the getItem method, sets the first item
		Node<ItemType>* temp = aList.getNodeAt(2); //This is for the original list, no 'new' keyword sinces its for traversal
		Node<ItemType>* current = headPtr; //Pointer to traverse and copy current list, also no 'new' keyword
		while(temp != nullptr){ //Until the end of the originial list is reached
			Node<ItemType>* nextNode = new Node<ItemType>(); //Creates new node, when we setNext, so use 'new' keyword
			nextNode->setItem(temp->getItem());
			current->setNext(nextNode); //Sets current list's next node, from previous list
			current = nextNode; //Shuffles the current by one
			temp = temp->getNext(); //Moves forward for old list
		} 
		current->setNext(nullptr);
	}
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = newPosition >= 1 && newPosition <= itemCount + 1; //Check for valid position
	if(!ableToInsert){ 
		return false; //Item was not successfully added
	}
	Node<ItemType>* newNode = new Node<ItemType>();
	newNode->setItem(newEntry);
	if(newPosition == 1){
		newNode->setNext(headPtr); //The new node points at the old head
		headPtr = newNode; //Assign the head to the newNode, adding it to the list at position 1
		itemCount++;
		return true;
	}
	Node<ItemType>* temp = headPtr; //Node to get to the item  before the desired position
	int currPosition = 1;
	while(temp != nullptr && (currPosition < newPosition - 1)){ //we want the item before to point to the new item at the desired position
		temp = temp->getNext();
		currPosition++;
	} //Temp should be the item before where we want to insert
	newNode->setNext(temp->getNext()); //The new node points the old object that was in the newPosition
	temp->setNext(newNode); //The item at newPosition - 1 now points to the new item
	itemCount++;
	return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear(){
	Node<ItemType>* current = headPtr;
	while(current != nullptr){
		Node<ItemType>* ptrForDelete = current; //Pointer for deleting the current item
		current = current->getNext(); //Move along in the list
		delete ptrForDelete;
	}
	headPtr = nullptr;
	itemCount = 0;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
	bool ableToGet = position >= 1 && position <= itemCount;
	if(!ableToGet){
		throw "Item not found!";
	}
    Node<ItemType>* travelNode = getNodeAt(position); //Node for traversing
    ItemType temp = travelNode->getItem();
    return temp;
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
