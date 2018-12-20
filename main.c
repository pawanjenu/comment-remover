#include<stdio.h>
#include<stdlib.h>

void single(){
FILE *fp,*fp1,*fp2;
    char c;
     fp = fopen("File1.txt", "r+");
          fp1 = fopen("File.txt", "r+");
                    fp2 = fopen("f.txt", "r+");
      while( (c = getc(fp)) != EOF)
      if ( c == '/'){
        c = getc(fp);
        if ( c == '/'){
          fseek(fp,-2, SEEK_CUR);

           while ( (c = getc(fp)) != '\n'){
                 printf("%c",c);
                fputc(c,fp1);
           }

        }

      }
    else{

          printf("%c",c);
           fputc(c,fp2);
    }

      fclose(fp);
      fclose(fp1);

}


void multi(){


FILE *fp,*fp1,*fp2;
    char c;
     int commentStart, commentEnd;
     fp = fopen("File1.txt", "rw+");
          fp1 = fopen("File.txt", "r+");
                    fp2 = fopen("f.txt", "r+");

         while( (c = getc(fp)) != EOF){
               printf("sdfg");
      if (c == '/'){
        c = getc(fp);
       // putchar(c);
        if ( c == '*'){
          commentStart = ftell(fp) - 2;
          while( (c = getc(fp)) != '*')
            continue;
          if( (c = getc(fp)) == '/')
            commentEnd = ftell(fp);

          fseek( fp, commentStart, SEEK_SET );
          while( commentStart != commentEnd ){
                c = getc(fp);
                 printf("%c",c);
           fputc(c, fp1);
           commentStart++;
          // fseek( fp, commentStart, SEEK_SET );
          }
        }
      }

      else{

        printf("%c",c);
           fputc(c,fp2);
      }

         }
        fclose(fp);
      fclose(fp1);
fclose(fp2);

}
void main(){
void multi();
printf("done!!!!!!!!!!!!!!!!");
}