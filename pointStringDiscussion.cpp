// Chante's digestion of code as explained and explored in TLAP ch 4, pgs 91 - 95

// test diagram / example: take word "test" and append with "!" 
// [t, e, s, t, 0] to [t, e, s, t, !, 0]

int length(arrayString s) {
	int count = 0;
	while (s[count] != 0) {
		count ++;
	}
	return count;
}

void append(arrayString& s, char c) {
	int oldLength = 
	arrayString newS = new char[oldLength + 2];

	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;	
	s = newS;
}

