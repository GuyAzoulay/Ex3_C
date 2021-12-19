#include <stdio.h>
#include "Ex3_C.h"
#include <ctype.h>
#include <string.h>

int main() {

    char word[30];
    char txt[1024];
    char a[] = "abcd";



    scanf("%[^\n]", word);
    scanf("%[^~]", txt);
    printf("Gematria Sequences: ");
    Gimatri(word, txt);
    printf("\n");
    printf("Atbash Sequences: ");
    Atbash(word, txt);
    printf("\n");
    printf("Anagram Sequences: ");
    Anagram(word, txt);
    return 0;

}
