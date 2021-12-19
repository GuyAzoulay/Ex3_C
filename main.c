#include <stdio.h>
#include "Ex3_C.h"
#include <ctype.h>
int main(){

    char word[30];
    char txt[1024];
    scanf("%s",word);
    scanf("%s",txt);
    printf("Gematria Sequences: ");
    Gimatri(word,txt);
    printf("\n");
    printf("Atbash Sequences: ");
    abtash(word,txt);
    printf("\n");
    printf("Anagram Sequences: ");
    Anagram(word,txt);


}
