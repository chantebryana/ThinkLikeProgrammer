//func to compare; 1 is "true", 0 is "false"z
int compLogicFunc(int * intArrayA, int * intArrayB) {
	if (* intArrayA > * intArrayB) {
		return 1;
	} else { 
		return 0;
	}
}

int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//goal: to sort like this: [8, 6, 4, 2, 1, 3, 5, 7, 9]

//1 is "true", 0 is "false"
if (num[i] % 2 == 0) {					//if first element's even
	if (num[i+1] % 2 == 0) {			//if second element's even
		if (num[i] > num[i+1]) {		//if first element's larger than second
			return 1;
		} else {								//if first element's smaller than second
			return 0;
		}
	} else if (num[i+1] % 2 == 1) {	//if second element's odd
		return 0;
	}
} else if (num[i] % 2 == 1) {			//if first element's odd
	if (num[i+1] % 2 == 1) {			//if second element's odd
		if (num[i] > num[i+1]) {		//if first element's larger than second
			return 1;
		} else {								//if first element's smaller than second
			return 0;
		}
	} else if (num[i+1] % 2 == 0) {	//if second element's even
		return 1;
	}
}
