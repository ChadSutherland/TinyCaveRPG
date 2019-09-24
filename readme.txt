RPG Project
Chad Sutherland, Felipe Oliveira, Daniyar Aubekerov


Binary I/O:
Takes place in the map load and save functions. Saving is fully functional, but loading files results in an unhandled exception. The runtime error has something to do with memory allocation of Enemies and Enemy weapons. 

Text I/O:
Map class creates a 2D map array with geographical data by reading in a txt file.

Passwords:
Password class is implemented with save files. There are password creation rules. When loading a save file, if the user does not enter the correct password the file is not accessable. Throws exceptions.

Exceptions: 
Password class throws an exception for invalid password.
Position class throws an exception for invalid new position.

Overloaded Operators:
Position overrides stream operators
Item overrides comparison operators

Template function:
Map addItem and deleteItem are both template functions that can take any kind of Item as an argument.

Enumerator:
Direction enumerator functions like a compass enumerating cardinal directions to integers

Queue of Spells:
Member of map, spells get added when the hero levels up, and removed when the hero casts to attack an enemy.

Linked List of Weapons:
Class ItemLinkedList creates a linked list of item pointers. The linked list is a member of the map class.

Friend Class:
Inner class ListNode in ItemLinkedList is a friend class implemented as an interface.

BONUS?: 
getDescriptions and writeSerializedItem functions in ItemLinkedList are both recursive.



