// discussion w/ Jim on pointers, in c and c++ syntax

// c:
char charUpdateFunc(char input){
	return 'a';
}
char myUpdatedChar = charUpdateFunc(myOriginalChar); // after charUpdateFunc() runs, myUpdatedChar = 'a'

void charUpdateInFunc(char * input){
	* input = 'a';
}
charUpdateInFunc(& myOriginalChar); // after charUpdateInFunc() runs, myOriginalChar = 'a'

// c++ new option: 
void charUpdateInFunc(char & input){
	input = 'a';
}
charUpdateInFunc(myOriginalChar); // after charUpdateInFunc() runs, myOriginalChar = 'a'
// the new c++ magic is hidden in '&' on line 13: the c-style logic/magic is HIDDEN, for writing simplicity


