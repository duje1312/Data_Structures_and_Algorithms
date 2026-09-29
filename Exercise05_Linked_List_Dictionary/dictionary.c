#define _CRT_SECURE_NO_WARNINGS
#include "Dictionary.h"
#include<stdlib.h>
#include<string.h>

Dictionary create() {
	Dictionary dict1 = (Dictionary)malloc(sizeof(Word));
	if (dict1 == NULL) {
		return NULL;
	}
	dict1->word = NULL;
	dict1->count = 0;
	dict1->next = NULL;
	return dict1;
}
void add(Dictionary dict1, char* str1) {
	Dictionary rijec = (Dictionary)malloc(sizeof(Word));
	Dictionary tmp = dict1;
	rijec->word = _strdup(str1);
	rijec->count = 1;
	rijec->next = NULL;
	if (dict1->next == NULL) {
		dict1->next = rijec;
	}
	else {
		while (tmp->next != NULL) {
			if (strcmp(tmp->next->word, rijec->word) == 0) {
				tmp->next->count++;
				free(rijec->word);
				free(rijec);
				return;
			}
			else if (strcmp(tmp->next->word, rijec->word) > 0) {
				break;
			}
			tmp = tmp->next;

		}
		rijec->next = tmp->next;
		tmp->next = rijec;
	}

}
void print(Dictionary dic) {
	Dictionary tmp = dic;
	while (tmp != NULL) {
		printf("rijec: %s ,broj ponavljanja: %d\n ", tmp->word, tmp->count);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
void destroy(Dictionary dict) {
	Dictionary tmp = dict;
	while (dict != NULL) {
		Dictionary brisi = dict;
		dict = dict->next;
		free(brisi->word);
		free(brisi);

	}
}
int filter(Word *w) {
	if ((w->count >= 5) && (w->count <= 10) && (strlen(w->word) >= 3)) {
		return 1;
	}
	return 0;
}
Dictionary filterDictionary(Dictionary indict, int(*filter)(Word *w)) {
	Dictionary tmp = indict;
	Dictionary del;
	while (tmp->next != NULL) {
		if (filter(tmp->next) == 0){
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del->word);
		free(del);
		}
		else {
			tmp = tmp->next;
		}
	
	}
	return indict;
}