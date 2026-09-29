#include<stdio.h>
#include<string.h>
int usporedi(char str1[], char str2[]) {
	int i = 0;
	while (str1[i] == '\0' || str2[i] != '\2') {
		if (str1[i] > str2[i]){
			return 1;
		}
		else if (str1[i] < str2[i]){
			return -1;
		}
		else{
			i++;
		}
	}






}



int main(void) {
	char str1[] = "Duje";
	char str2[] = "Budisa";

	usporedi(str1, str2);
	printf("%d", usporedi(str1, str2));
	return 0;
}