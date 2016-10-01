

#include<stdio.h>
#include<string.h>
#include <regex.h>
void main ()
{
//char* aa= "/opt/vc/bin/./vcgencmd measure_temp";
 system("/opt/vc/bin/./vcgencmd measure_temp > tempet.txt");

   FILE *fp;
   char buff[255];
   char ch_num[5];
   float real_num;
   int lop=0;
   int lop2=0;
   fp = fopen("tempet.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   for(;lop!=20;lop++)
   {
       if(buff[lop]=='=')
       {
           for(;lop2!=10;lop2++)
           {
                
                if(buff[lop1]=='&#39;')
                      {
                           real_num = atof(ch_num);
                           lop1=20;
                           break;
                      }
                 ch_num[lop2]=buff[lop1];
                 lop1++;     

           }

       }

   }
   printf('%f',real_num);
   fclose(fp);

   

}




