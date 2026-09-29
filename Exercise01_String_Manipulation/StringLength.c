#include<stdio.h>

int duljina(char str1[]) {
	int i = 0;
	while (str1[i] != '\0') {
		i++;
	}
	return i;


}




int main(void) {
	char str1[] = "Duje";
	int len = duljina(str1);
	printf("%d", len);
	return 0;
}
