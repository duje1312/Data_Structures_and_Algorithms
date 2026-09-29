#include <stdio.h>

char* mystrstr(char* string, char* string2) {
	int flag = 0;
	for (int i = 0; string[i]!='\0' ; i++) {
		for (int j = 0; j < string2[j] != '\0'; j++) {
			if (string[i + j] == string2[j]) {
				flag = 1;
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			return string + i;
		}
	}
	return NULL;
}

int main() {
	char* string2 = "aaab";
	char* string1 = "xxxabaaaaabaa";
	char* rez = mystrstr(string1, string2);

	if (rez != NULL) {
		printf("pokazivac: %s", rez);
	}
	else {
		printf("Nema pojavljivanja");
	}
	return 0;
}