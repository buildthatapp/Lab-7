/** Implementation file for the class ArrayList.
 @file ArrayList.cpp */

//#include "ArrayList.h"  // Header file

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1)
                           && (newPosition <= itemCount + 1)
                           && (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1)
      for (int entryPosition = itemCount; entryPosition >= newPosition; entryPosition--)
         items[entryPosition + 1] = items[entryPosition]; // copy the entry right
         
      // Insert new entry
      items[newPosition] = newEntry;
      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array
      // (no shift if position == itemCount)
      for (int entryPosition = position; entryPosition < itemCount; entryPosition++)
         items[entryPosition] = items[entryPosition + 1]; // copy entry on the right to left
         
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void ArrayList<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      return items[position];
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void ArrayList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      items[position] = newEntry;
   }
   else
   {
      std::string message = "replace() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end replace

template<class ItemType>
void ArrayList<ItemType>::displayList()
{
	for (int x = 1; x <= itemCount; x++)
	{
		std::cout << items[x] << std::endl;
	}

}

template<class ItemType>
void ArrayList<ItemType>::sort()
{
	if (itemCount != 0)
	{
		quickSort(items, 1, itemCount);
	}
	else
	{
		std::string message = "Can't sort an empty List";
		throw(PrecondViolatedExcep(message));
	}
}
template<class ItemType>
	void ArrayList<ItemType>::swap(ItemType arr[], int k, int small) {
		int temp;
		temp = arr[k];
		arr[k] = arr[small];
		arr[small] = temp;
	}

	template<class ItemType>
	int ArrayList<ItemType>::partition(ItemType arr[], int i, int j) {
		int pivot = arr[j];
		int small = i - 1;

		for (int k = i; k < j; k++) {
			if (arr[k] <= pivot) {
				small++;
				swap(arr[], k, small);
			}
		}

		swap(arr[], j, small + 1);
		return small + 1;
	}

template<class ItemType>
	void ArrayList<ItemType>::quickSort(ItemType arr[], int i, int j) {
		if (i < j) {
			int pos = partition(arr[], i, j);
			quickSort(arr[], i, pos - 1);
			quickSort(arr[], pos + 1, j);
		}
	}



//  End of implementation file.
