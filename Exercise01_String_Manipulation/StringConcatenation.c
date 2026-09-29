#include<stdio.h>
#include<string.h>
void spoji(char str1[], char str2[]) {
	char* ptr=str1;
	while (*ptr != '\0') {
		ptr++;
	}
	while (*str2 != '\0') {
		*ptr = *str2;
		ptr++;
		str2++;
	}

	*ptr = '\0';


}



int main(void) {
	char str1[100] = "Duje";
	char str2[] = "Budisa";
	spoji(str1, str2);
	printf("%s",str1);
	return 0;
}