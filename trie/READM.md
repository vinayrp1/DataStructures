Implementation of a basic trie:

- Node consists of 
	- char index
	- Node* array 
	- integer value

- insert() looks for node with each character as char index,
	- if present, it will traverse based on the char in the string
	- else, node is created

- display() invoked recursive function printer() which takes tillNow as
	invariant. A particlar node is considered as end of the string if 
	its value is not 0.