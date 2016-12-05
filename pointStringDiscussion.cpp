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
	int oldLength = length(s);
	arrayString newS = new char[oldLength + 2];	// I still feel like this should only be oldLength +1, and the p 98 code below is verifying my suspicion that +2 was a typo.  Yay!
	for (int i = 0; i < oldLength; i++) {
		newS[i] = s[i];
	}
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;	
	s = newS;
}

// p 98
void concatenate(arrayString& s1, arrayString s2) {
	int s1_OldLength = length(s1);
	int s2_Length = length(s2);
	int s1_NewLength = s1_OldLength + s2_Length;
	arrayString newS = new char[s1_NewLength + 1];
	for (int i = 0; i < s1_OldLength; i++) {
		newS[i] = s1[i];
	}
	for (int i = 0; i < s1_OldLength; i++) {
		newS[s1_OldLength + i] = s2[i];
	}
	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;
}

