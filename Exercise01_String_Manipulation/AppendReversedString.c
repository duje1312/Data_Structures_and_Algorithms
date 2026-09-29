#include <stdio.h>

char* reverse(char* string, char* string2) {
	char* point = string;
	char* end = string2;

	while (*point != '\0') {
		point++;
	}
	while (*end != '\0') {
		end++;
	}

	while (end != string2) {
		end--;
		*point = *end;
		point++;
	}
	*point = '\0';
	return string;
}

int main() {
	char string[100] = "prvi";
	char* string2 = "drugi";
	printf("String: %s", reverse(string, string2));
	return 0;
}