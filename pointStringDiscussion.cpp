// Chante's digestion of code as explained and explored in TLAP ch 4

// p 91
typedef char * arrayString; 

// p 92
char characterAt(arrayString s, int position) {
	return s[position];
}

// p 97
int length(arrayString s) {
	int count = 0;
	while (s[count] != 0) {
		count ++;
	}
	return count;
}

// p 94
void append(arrayString& s, char c) {	
	int oldLength = length(s);z
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;	
	s = newS;
}

// p 98
// first variable is reference b/c it'll be changed by func; second variable is literal value b/c it's just referenced by func and won't be changed (just like append() )
void concatenate(arrayString& s1, arrayString s2) {
}

