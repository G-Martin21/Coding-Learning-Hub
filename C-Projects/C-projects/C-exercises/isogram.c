#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //bool is_isogram(const char phrase[]){
    char phrase[] = "Emily Jung Schwartzkopf";
    //Emily Jung Schwartzkopf  Alphabet
    if (phrase == NULL)
    {
        return printf("false NULL\n");
    }
    else
    {
        int charsize = strlen(phrase);
        int n = sizeof(phrase) / sizeof(phrase[0]);
        printf("%d charsize\n %d sizeof", charsize, n);
        if (charsize == 0) {
            return printf("true EMPTY\n");
        } else { 
          char newstr[charsize];
          for (int i = 0; i < charsize; i++) {
              newstr[i] = ' ';
          }
          newstr[charsize] = '\0';
          printf("%ld newstr\n", strlen(newstr));

          printf("%s", newstr);
          //strcpy(lowerstr, strlwr(phrase));
          char *ret;  
          char *ret2;
          int i = 0;
          char c;
          for (int i = 0; i < n; i++){
              //if phrase[i] not in newstr => add
            
            c = phrase[i];
            printf("%s value of c", &c);
            //if (isalpha(c) != 0) {
            //if (c >= 65 && Ch <= 90)
            /*{
                Ch = Ch + 32;*/
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                {
                    //char cc = (c >= 'A' && c <= 'Z') ? c + 32 : c; //lower case
                    ret = strchr(newstr, c);
                    if (c >= 'a' && c <= 'z') {
                        ret = strchr(newstr, c-32);  // search in upper case
                    } else {
                        ret = strchr(newstr, c+32);     // search in lower case
                    }
                    //ret = (ret == NULL) ? (ret = strchr(newstr, cc)) : (ret = strchr(newstr, c - 32));
                    //ret2 = strchr(newstr, c);
                    //printf("%s", ret);
                    if (ret == NULL)
                    { // we didn't fint c char
                        newstr[i] = c;
                    }
                }
                else if (c == ' ' || c == '-')
                {
                    newstr[i] = c;
                    //printf("%s", &newstr[i]);
                }
            }
           printf("newstr: %s\n phrase: %s\n", newstr, phrase);
           return (strcmp(newstr, phrase) == 0) ? printf("true equal\n") : printf("false not equal\n");
          }
    }
        return printf("true");
}
