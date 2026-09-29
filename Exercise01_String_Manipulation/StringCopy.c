#include<stdio.h>
#include<string.h>
void kopiraj(char *str1, char *str2){
	int i=0;
	while (str1[i] != '\0') {
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';

}
int main(void) {
	char str1[] = "Duje";
	char str2[50];
	kopiraj(str1, str2);
	printf("%s", str2);
	return 0;
}






