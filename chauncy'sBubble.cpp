//func to compare; 1 is "true", 0 is "false"z
int compLogicFunc(int * intArrayA, int * intArrayB) {
	if (* intArrayA > * intArrayB) {
		return 1;
	} else { 
		return 0;
	}
}

int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

if (num[i] % 2 == 0) {
	if (num[i+] % 2 == 0) {
		if (num[i] > num[i+1]) {
			return 1;
		} else {
			return 0;
		}
	} else if (num[i+1] % 2 == 1) {
		return 0;
	}
} else if (num[i] % 2 == 1) {
	if (num[i+1] % 2 == 1) {
		if (num[i] > num[i+1]) {
			return 1;
		} else {
			return 0;
		}
	} else if (num[i+1] % 2 == 0) {
		return 1;
	}
}
