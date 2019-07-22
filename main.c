#include <stdio.h>
#include <stdlib.h>
void main()
{

  FILE *fp, *fp1, *fp2;
  char c;
  int q;
  char s[20];
  int commentStart, commentEnd;
  printf("enter the file name:");
  gets(s);
  if (fp = fopen(s, "r+"))
  {
    q = 1;
  }

  fp1 = fopen("comments.txt", "r+");
  fp2 = fopen("withoutcomments.txt", "r+");
  if (q != 1)
    printf("file not there:");
  else
  {
    while ((c = getc(fp)) != EOF){
      if (c == '/')
      {

        c = getc(fp);
        if (c == '/')
        {
          fseek(fp, -2, SEEK_CUR);
          while ((c = getc(fp)) != '\n')
          {
            //printf("%c",c)
            fputc(c, fp1);
          }
          fputc('\n', fp2);
          fputc('\n', fp1);
        }
        else if (c == '*')
        {

          commentStart = ftell(fp) - 2;
          while ((c = getc(fp)) == '/')
            continue;
          if ((c == getc(fp)) == '/')
            commentEnd = ftell(fp);
          fseek(fp, commentStart, SEEK_SET);
          while (commentStart != commentEnd)
          {

            c = getc(fp);
            //printf("%c",c);
            fputc(c, fp1);
            commentStart++;
            //fseek(fp,commentStart,SEEK_SET);
          }
          //fputc('\n',fp1);
          //fputc('\n',fp2);
        }
        else
        {
          fputc('/', fp2);
          printf("/");
          fputc(c, fp2);
          putchar(c);
        }
      }
      else
      {
        printf("%c", c);
        fputc(c, fp2);
      }
    }
   
    printf("\ndone!!!!!!!");
  }
   fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
