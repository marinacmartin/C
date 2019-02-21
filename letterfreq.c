// lab 2 task 8



#include <stdio.h>
#include <string.h>

int main() {
  int i;
  char string[100];
  int c = 0;
  double count[26] = {0};
  unsigned long int charcount = 0;


    //if (argv[1] != NULL)  {

    //FILE *fp = fopen(argv[1],"r");
    //if(fp != NULL) {

    // if there is a file from the command line do this

    if (stdin != NULL) {

       while(fgets (string, sizeof string, stdin) != NULL) {

         // reset c to 0 before we read the next string
         c = 0;

         // printf("%d\n", count[c]);

         //printf("string = %s\n", string);
         // printf("%d %c\n", c, string[c]);

            while (string[c] != '\0') {

              // count total characters:
              // if (c != ' ' || c != '\n') {
              //   charcount++;
              // }

              if (string[c] >= 'a' && string[c] <= 'z' ) {
                 count[string[c]-'a']++;
                 charcount++;
              }

              if ( string[c] >= 'A' && string[c] <= 'Z' ) {
                 count[string[c]-'A']++;
                 charcount++;
              }

               //printf("%d %c\n", c, string[c]);

               //if (string[c] >= 'a' && string[c] <= 'z') {
               //  count[string[c]-'a']++;
               //}

             c++;

            }

       }

       for (c = 0; c < 26; c++) {

          if (count[c] != 0) {
             printf("%c occurs %f times in the entered string.\n",c+'a',count[c]);
             //printf("%c occurs %.4f percent of the time in the file.\n",c+'a', (count[c]/charcount));
             printf("%c %.4f\n",c+'a', (count[c]/charcount));
         }
      }
      //printf("final char count: %lu\n", charcount);




 // otherwise get user input
 } else {

    scanf("%s\n", &string );

    while (string[c] != '\0') {

       if (string[c] >= 'a' && string[c] <= 'z') {
          count[string[c]-'a']++;
          charcount++;

       }
       c++;

     }

       for (c = 0; c < 26; c++) {

         if (count[c] != 0) {
           //printf("%c occurs %.4f times in the entered string.\n",c+'a', (count[c]/charcount));
           printf("%c %.4f\n",c+'a', (count[c]/charcount));
         }

       }
  return 0;
 }

}
