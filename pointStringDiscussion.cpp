// Chante's digestion of code as explained and explored in TLAP ch 4, pgs 91 - 95

// test diagram / example: take word "test" and append with "!" 
// [t, e, s, t, 0] to [t, e, s, t, !, 0]

void append(arrayString& s, char c) {				// pass arguments of full word arrayString ("test") plus added character c ("!")
	int oldLength = 0;
	while (s[oldLength] != 0) {						// ie, till the last element of array, since last element will be null character (0)
		oldLength++;										// makes oldLength the same length (minus 1) as your dynamically-created array
	}
	arrayString newS = new char[oldLength + 2];	// newS is new variable. arrayString already defined as typedef char * 
																// "new char" array points to dynamically-allocated heap memory 
																// (of length 1 byte * oldLength + 2)
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];									// assigns defintions of newS elements to be equivelant as elements of s array
	}
	newS[oldLength] = c;									// in the case of "test": element at newS[4] = new character "!" 
	newS[oldLength + 1] = 0;							// in the case of "test!": element at newW[5] = 0 or null
	delete[] s;												// deallocate the memory location pointed to by s variable
	s = newS;												// redefine variable s to equal array newS
}

