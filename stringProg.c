#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int Anagram_Helper(char *s ,char *e,int,char *w);
int Atbash_Helper(char*s, char*e, char*w,int);
char transfer_Letter_To_Atbash(char a);
void transfer_Word_To_Atbash(char w[30]);




int sum_Total(char word[30]) {
    int x, sum = 0;
    int temp = 0;
    x = strlen(word);
    for (int i = 0; i < x; ++i) {
        if ( word[i] >= 65 && word[i] <= 90) {
            temp = (int) word[i];
            sum += (temp - 64);
        }
        if (word[i] >= 97 && word[i] <= 122) {
            temp = (int) word[i];
            sum += (temp - 96);
        }
    }
    return sum;
}
void Gimatri(char word[30], char txt[1024]){
    int y = strlen(txt);
    int sum = sum_Total(word);
    int a,b=0;
    int temp=0;
    int index=0;
    char helper[1024];
    for (int i = 0; i < y; ++i) {
        int temp_sum = 0;
        for (int j = i; j < y; ++j) {

            temp = (int) txt[j];
            if (temp >= 65 && temp <= 90) {
                temp_sum += (temp - 64);
            }
            else if (temp >= 97 && temp <= 122) {
                temp_sum += (temp - 96);
            }
            if (temp_sum > sum) {
                j=y-1;
            } else if (temp_sum == sum && txt[j] != '~') {
                a = i;
                b = j;
                while (toupper(txt[a]) - 'A' + 1 > 26 || toupper(txt[a]) - 'A' + 1 < 1) {
                    a++;
                    i++;
                }
                while (a < b) {
                    helper[index++] = txt[a++];

                }
                if (1 <= (toupper(txt[b]) - 'A' + 1) && (toupper(txt[b]) - 'A' + 1) <= 26) {
                    helper[index++] = txt[b];

                }
                helper[index++] = '~';
                j=y-1;
            }
        }

         }
    helper[index-1]=0;
    printf("%s", helper);
}
char transfer_Letter_To_Atbash(char a){
    int pos= a;
    if(97<=pos && pos<=122){
        a='z'-a +'a';
        return a;
    }
    else if(65<= pos && pos<= 90){
        a = 'Z'-a+'A';
        return a;
    }
    else{
        pos=0;
        return pos;
    }
}

void transfer_Word_To_Atbash(char w[30]){
    int i,a;
    char temp;


    for ( i = 0; i< strlen(w) ; ++i) {
        a=w[i];
        if(65<=a&& a<=90) {
            a = 'Z' - (a - 'A');
            temp = a;
            w[i] = temp;
        } else if(97<=a && a<=122){
            a= 'z'-(a-'a');
            temp = a;
            w[i] = temp;
        }
    }

}
void Atbash(char word[], char txt[]){
    char new[strlen(word)];
    char transNew[strlen(word)];
    for(int i =0 ;i< strlen(word);i++) new[i] = '\000';
    for (int i = 0; i < strlen(word) ; ++i) {
        new[i]=word[i];
    }
    char helper[1024];
    int index=0;
    for(int i =0 ;i<1024;i++) helper[i] = '\000';
    transfer_Word_To_Atbash(new);
    if(strstr(txt,new)){
        for (int i = 0; i < strlen(txt); ++i) {
            if(i == strlen(new)) break;
            helper[index++]= new[i];
        }
        helper[index++]= '~';
        for(int i = strlen(new) ;i>0 ; i--) transNew[strlen(new) - i ] = new[i];
        if(strstr(txt,transNew)) {
            for (int i = 0; i < strlen(txt); ++i) {
                if (i == strlen(transNew)) break;
                helper[index++] = transNew[i];
            }
        }
    }

    printf("%s",helper);
}

void Anagram (char word[], char txt[]){
    char helper[1024];
    char *t =txt;
    int txtlen= strlen(txt);
    int wordlen = strlen(word);
    int sum = sum_Total(word);
    int  a=0 , b= 0 ,index = 0;



    for(int i =0 ;i<1024;i++) helper[i] = '\000';

    for (char *i = (char *) t; *i!=*(t + txtlen); i++) {

        int new_sum = 0;
        for (char *j = (char *) i; *j!=*(t + txtlen) ; ++j) {

            a = (int) *j;
            if (a >= 65 && a <= 90) {
                new_sum += (a - 64);
            } else if (a >= 97 && a <= 122) {
                new_sum += (a - 96);
            }


            if(new_sum > sum) break;
            else if(new_sum == sum) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;

                int boll_A = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int bool_B = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));

                //helper function to see if the new word is anagram
                if (!Anagram_Helper((char *)start,(char*)end,wordlen,(char *)word)) break;

                if(boll_A && bool_B){
                    if(index != 0){
                        helper[index++] = '~';
                    }
                    while (start <= end) {
                        helper[index++] =  *start++;
                    }
                    break;
                }
                else if(!boll_A && bool_B){
                    if(index != 0){
                        helper[index++] = '~';
                    }
                    while(start<=end)
                    {
                        if((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122)){
                            helper[index++] = *start++;
                        }
                        else {
                            start++;
                            i++;
                            boll_A = ((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122));
                        }
                    }
                    break;
                }
            }
        }

    }

    printf("%s", helper);

}

//this function check if there are sub-sequences in the txt of the given word but as anagram
// it an int function because we refer to it as a boolean answer

int Anagram_Helper(char *w, char *t, int wordl, char *word) {
    int fin[26] = {0}, temp[26] = {0};
//    char *s= word;
//    char *e= txt;
    //checking is the start of the word is a letter
    if ((*w >= 65 && *w <= 90) || (*w >= 97 && *w <= 122)) {
        while (w < t + 1) {
            // checking if it is a small letter
            if ((*w >= 97 && *w <= 122)){
                temp[*w - 'a']++;
                w++;
                //checking if it is a big letter
            }else if((*w >= 65 && *w <= 90)){
                temp[*w - 'A']++;
                w++;
            }
            else return 0;
        }
    }else{
        //going through the word to check for other chars which is not letters
        while((*w < 65  || *w > 122|| (*w > 90 && *w < 97))){
            w++;}

        while ( w < t+ 1) {
            if ((*w >= 97 && *w <= 122)){
                temp[*w - 'a']++;
                w++;
            }else if((*w >= 65 && *w <= 90)){
                temp[*w - 'A']++;
                w++;
            }
            else return 0;
        }
    }
    for (int i = 0; i < wordl; ++i) {
        if((*word >= 97 && *word <= 122)) {
            fin[*word - 'a']++;
            word++;
        }else if((*word >= 65 && *word <= 90)) {
            fin[*word - 'A']++;
            word++;
        }
        else return 0;
    }

    for (int counter = 0; counter < 26 ; ++counter) {
        if(fin[counter]!= temp[counter]) return 0;
    }
    return 1;
}




