 template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	maxCount = DEFAULT_CAPACITY;
	itemCount = aList.itemCount;
	for(int i = 1; i < itemCount; i++){ //Ignoring the item at 0'th index
		items[i] = aList.items[i];
	}
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	return (itemCount == 0); //Returns true if 0, and false if not 0
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1) && (itemCount < maxCount);
	if (ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
			items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
        	itemCount++;
    	}
    	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	bool ableToAccess = (position >= 1) && (position <= itemCount);
	if(!ableToAccess){ //Check for valid item position
		return false; //Indicates that there was no item removal
	}
    for(int i = position; i < itemCount; i++){
		items[i] = items[i+1];
	}
	itemCount--;
	return true; //Indicates the item has been successfully removed
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if(!ableToReplace){ //Check for valid item position
		throw "Item not found"; //Indicates that there was no item found to replace
	}
    ItemType temp = items[position]; //Stores old item
	items[position] = newEntry; //Substitutes new item
    return temp; //Returns the old item
}
