// lab 2 task 6
// counting chars lines and words in a file



#include <stdio.h>

int main(int argc, char *argv[]) {
 FILE *fp;
 //char filename[100];
 char ch;
 unsigned long int linecount = 0;
 unsigned long int wordcount = 0;
 unsigned long int charcount = 0;

 // Initialize counter variables
 // linecount = 0;
 // wordcount = 0;
 // charcount = 0;

 // // Prompt user to enter filename
 //  printf("Enter a filename : ");
 //  gets(filename);

    // Open file in read-only mode
   fp = fopen(argv[1],"r");

   // If file opened successfully, then write the string to file
   if ( fp ) {
   //scanf("%s\n", &fp);
        //Repeat until End Of File character is reached.
           while ((ch=getc(fp)) != EOF) {
                  // increment character count if NOT new line or space
                   if (ch != ' ' && ch != '\n') { ++charcount; }

                  // increment word count if new line or space character
                   if (ch == ' ' || ch == '\n') { ++wordcount; }

                  // increment line count if new line character
                   if (ch == '\n') { ++linecount; }
     }

           if (charcount > 0) {
                     ++linecount;
                     ++wordcount;
           }

   }
    // } else {
    //      printf("Failed to open the file\n");
    //     }

    // printf("Lines : %d \n", linecount-1);
    // printf("Words : %d \n", wordcount-1);
    // printf("Characters : %d \n", charcount);

    printf( "%lu %lu %lu\n", charcount, wordcount, linecount);

    getchar();
return(0);
}





#include <stdio.h>

int main(int argc, char *argv[]) {
 FILE *fp;
 //char filename[100];
 char ch;
 unsigned long int linecount = 0;
 unsigned long int wordcount = 0;
 unsigned long int charcount = 0;

 // Initialize counter variables
 // linecount = 0;
 // wordcount = 0;
 // charcount = 0;

 // // Prompt user to enter filename
 //  printf("Enter a filename : ");
 //  gets(filename);

    // Open file in read-only mode
   //fp = fopen(argv[1],"r");

   // If file opened successfully, then write the string to file
   //if ( fp ) {
   //scanf("%s\n", &fp);
        //Repeat until End Of File character is reached.
           while ((ch=getc(fp)) != EOF) {
                  // increment character count if NOT new line or space
                   if (ch != ' ' && ch != '\n') { ++charcount; }

                  // increment word count if new line or space character
                   if (ch == ' ' || ch == '\n') { ++wordcount; }

                  // increment line count if new line character
                   if (ch == '\n') { ++linecount; }
     }

           if (charcount > 0) {
                     ++linecount;
                     ++wordcount;
           }

   }
    // } else {
    //      printf("Failed to open the file\n");
    //     }

    // printf("Lines : %d \n", linecount-1);
    // printf("Words : %d \n", wordcount-1);
    // printf("Characters : %d \n", charcount);

    printf( "%lu %lu %lu\n", charcount, wordcount, linecount);

    getchar();
return(0);
}








// most recent submission:

// lab 2 task 6
// counting chars lines and words in a file

// final version i think

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
 //FILE *fp;

 char ch;
 unsigned long int linecount = 0;
 unsigned long int wordcount = 0;
 unsigned long int charcount = 0;
 bool character = false;


   ch = getchar();

        while (ch != EOF) {


            // increment character count if not a space but yes if there is a $
            if (ch != ' ' || ch == '\n') {
               charcount++;
            }

             // if ch is an uppercase letter or lowercase letter or an apostro$
            if (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 3$
                  character = true;

            } else {
                  if (character) {
                      wordcount++;
                      character = false;
                   }
              }

            // increment line count if new line character
             if (ch == '\n') {
               linecount++;

             }


      ch = getchar();


// printf("Lines : %lu \n", linecount);
// printf("Words : %lu \n", wordcount);
// printf("Characters : %lu \n", charcount);

printf("%lu %lu %lu\n", charcount, wordcount, linecount);

ch = getchar();

}
