#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
 
 
int legitPower(int checkme)
{
if (checkme == 0)
   return 1;
 while (checkme != 1)
 {
     if (checkme%2 != 0)
        return 1;
     checkme = checkme/2;
 }
 return 2;
}
 
 
 
struct blockline
{
       int ok;
       unsigned long numT;
       int i;
};
 
 
void set(struct blockline** cache, int one, int two, int time, unsigned long tVal)
{
  cache[one][two].numT = tVal;
    cache[one][two].i = time;
    cache[one][two].ok = 1;
}
 
 
 
 
 
 
 
void W(struct blockline** cache, char* pol, int checkda, int* hitC, int* missC, int iSett, unsigned long tVal,int* writeM, int* readM, int ADA, int time, int setN)
 
{
    int ynchk = 0;
    int bl = 0;
    int iterate =0;
  if (ADA == 10)
  {
    
 
    while ((iterate<setN) && (bl == 0))
    {
 	if (cache[iterate][0].ok == 1 && cache[iterate][0].numT == tVal)
                       {
                              
                               *writeM = *writeM + 1;
        *hitC = *hitC + 1;
 
         int temp3 = 90;
         if (strcmp("lru", pol) == 0)
         {
           temp3 = 91;
         }
         switch(temp3)
         {
           case 91:
           cache[iterate][0].i = time;
           break;
         }
                               ynchk = 1;
                               bl = 1;;
                       }
   int dad = log2(2);
    iterate = iterate + dad;
    }
 
    switch(ynchk)
    {
     case 0:
      *writeM = *writeM + 1;
      *missC = *missC + 1;
      *readM = *readM + 1;
      
    
      int itr=0;
      int bl = 0;
      int j = -1;
      while ((itr<setN) && (bl == 0))
      {
   	if (cache[itr][0].ok == 0)
                               {
                                       j = itr;
                                       bl = 1;
                               }
 
        itr++;
      }
      
      if (j < 0)
      {
        int itrr=0;
        j = 0;
        int min = cache[0][0].i;
        while (itrr<setN)
        {
        if (cache[itrr][0].i < min)
                                       {
                                               j = itrr;
                                               min = cache[itrr][0].i;
                                       }
        itrr++;
        }
      } 

      set(cache, j, 0, time, tVal);
      
     break;
    }
  }
  
  else
  {
    
    int ynchk = 0;
 
    if (ADA == 1000)
    {
      if (cache[iSett][0].ok == 1 && cache[iSett][0].numT == tVal)
      {
        
        *writeM = *writeM + 1;
        *hitC = *hitC + 1;
 
        if (strcmp("lru", pol) == 0)
        cache[iSett][0].i = time;
        
        ynchk = 1;
      }
    }
 
    else
          {
    int iteratee=0;
    while (iteratee<checkda)
    {
 	if (cache[iSett][iteratee].ok == 1 && cache[iSett][iteratee].numT == tVal)
                       {
                             
                               *writeM = *writeM + 1;
     	                       *hitC = *hitC + 1;
                               int mom = 0;
                               if (strcmp("lru", pol) == 0)
                                 mom = 1;
 
                               switch(mom)
                               {
                                 case 1:
                                 cache[iSett][iteratee].i = time;
                                 break;
                               }
                                      
                               ynchk = 1;
                       }
   int add = 5;
   int subtractionfour = 4;
    iteratee=iteratee+ (add-subtractionfour);
    }
    } 
    if (ynchk == 0)
    {
   	*writeM = *writeM + 1;
      *readM = *readM + 1;
      *missC = *missC + 1;
    
      int tem = -1;
      int outItr =0;
   	int min = cache[iSett][0].i;
      int inItr=0;
      while (outItr<checkda)
      {
 
     	if (cache[iSett][outItr].ok == 0)
                                       tem = outItr;
      outItr++;
      }
 
      if (tem < 0)
      {
        tem = 0;
        while (inItr<checkda)
        {
     	if (cache[iSett][inItr].i < min)
                                       {
                                               tem = inItr;
                                               min = cache[iSett][inItr].i;
                                       }
 
        inItr++;
        }
      }
      
      set(cache, iSett, tem, time, tVal);
    } 
 
  }
} 
 
 
 
 
 
 
 
 
 
void R(struct blockline** cache, char* pol, int checkda, int* hitC, int* missC, int iSett, unsigned long tVal,int* writeM, int* readM, int ADA, int time, int setN)
{
    int iterate=0;
    int ynchk = 0;
 
  if (ADA == 10)
  {
    
 	while (iterate<setN)
 	{
 	if (cache[iterate][0].ok == 1 && cache[iterate][0].numT == tVal)
                       {
                               *hitC = *hitC + 1;
                               if (strcmp("lru", pol) == 0)
                                       cache[iterate][0].i = time;
                               ynchk = 1;
                               break;
                       }
 
   	iterate++;
 	}
 
 
    switch(ynchk)
    {
      case 0:
      *readM = *readM + 1;
      *missC = *missC + 1;
      int x =0;
      int tempp = -1;
 
      while (x<setN)
      {
   	 if (cache[x][0].ok == 0)
                               {
 
                                       tempp = x;
                                       break;
                               }
        x++;
      }
    
      if (tempp < 0)
      {
        tempp = 0;
        int x=0;
        int min = cache[0][0].i;
 
        while (x<setN)
        {
        if (cache[x][0].i < min)
                                       {
                                               tempp = x;
                                               min = cache[x][0].i;
                                       }
          x++;
        }
      } 

      set(cache, tempp, 0, time, tVal);
      
     break;
    }
  }
 
  else
  {
    
    int ynchk = 0;
 
    if (ADA == 1000 && ynchk==0)
    {
      if (cache[iSett][0].ok ==1 && cache[iSett][0].numT == tVal)
      {
        *hitC = *hitC + 1;
        if (strcmp("lru", pol) == 0)
          cache[iSett][0].i = time;
 
        ynchk = 1;
      }
    }
 
    else {
      int iterate=0;
    while (iterate<checkda)
    {
 	 if (cache[iSett][iterate].ok == 1 && cache[iSett][iterate].numT == tVal)
                       {
                               *hitC = *hitC + 1;
                               if (strcmp("lru", pol) == 0)
                                       cache[iSett][iterate].i = time;
 
                               ynchk = 1;
                       }
      iterate++;
    }
    }
    if (ynchk == 0)
    {
      
      *readM = *readM + 1;
      *missC = *missC + 1;
      int min = cache[iSett][0].i;
      int i = -1;
      int iter =0;
    
 
      while (iter<checkda)
      {
 
     	if (cache[iSett][iter].ok == 0)
                                       i = iter;
      iter++;
      }
      
      if (i < 0)
      {
        i = 0;
        int iterr=0;
        while (iterr<checkda)
        {
     	 if (cache[iSett][iterr].i < min)
                                       {
                                               min = cache[iSett][iterr].i;
                                               i = iterr;
                                       }
 
        iterr++;
        }   
      }
      set(cache, iSett, i, time, tVal);      
    } 
 
  }
}
 
 
 
 
 
 
 
 
 
 
int legitString(int x, char* given)
  {
 if(x==2){
   if(strcmp(given, "direct")==0 || strcmp(given, "assoc")==0 || strncmp(given, "assoc:", 6)==0){
     return 2;
   }
   else{
     return 1;
   }
 }
 else if(x==3){
   if(strcmp(given, "lru")==0 || strcmp(given, "fifo")==0){
     return 2;
   }
   else{
     return 1;
   }
 }
 return 1;
}
 
 
 
 
 
 
 
int main(int argc, char* argv[argc + 1])
{
int ADA = 0;
 
FILE* f = fopen(argv[5], "r");
 
  int cacheSize = atoi(argv[1]);
 
  char* checkda = argv[2];
  char* pol = argv[3];
 
  int blockSize = atoi(argv[4]);
  
  int aN = 0;
       int setN = 0;
 
  struct blockline** cache = 0; 
 
  int tfItr = cacheSize;
  int tfB=blockSize;
 
  if ((legitPower(tfItr)==1)||(legitString(2, checkda)==1)||argc!=6||(legitString(3,pol)==1)||(legitPower(tfB)==1))
  {
  printf("error\n");
  exit(0);
  }
  
  if (strcmp(checkda, "assoc") == 0)
  {
    
    setN = 1;
    ADA = 10;
  }
  else if (strcmp(checkda, "direct") == 0)
       {
 
               setN = cacheSize/blockSize;
 
               ADA = 1000;
       }
  else
  {
  
    int hold= checkda[6] - 48;
    aN = hold;
    setN = cacheSize/(blockSize*hold);
    ADA = 100;
  }
 
  if (ADA == 10)
  {
  
    int hold= cacheSize/blockSize;
    cache = (struct blockline**) malloc(hold *sizeof(struct blockline*));
    int fillUp=0;
 
    while (fillUp<hold)
    {
 	cache[fillUp] = (struct blockline*) malloc(sizeof(struct blockline));
                       cache[fillUp][0].ok = 0;
                       cache[fillUp][0].numT = 0;
                       cache[fillUp][0].i = 0;
      fillUp++;
    }
    setN = hold;  
  }
  
  else
  {
  
    cache = (struct blockline**) malloc(setN * sizeof(struct blockline*));
    int fill=0;
 
    while (fill<setN)
    {
 	 if (ADA == 1000)
                       {
                               cache[fill] = (struct blockline*) malloc(sizeof(struct blockline) *1);
                       }
                       else
                       {
                               cache[fill] = (struct blockline*) malloc(sizeof(struct blockline) * (checkda[6] - 48));
                       }
 
                       if (ADA == 1000)
                       {
                               cache[fill][0].ok = 0;
                               cache[fill][0].numT = 0;
                               cache[fill][0].i = 0;
                       }
                       else
                       {
        int fill2=0;
        while (fill2< (checkda[6] - 48))
        {
        cache[fill][fill2].ok = 0;
                               cache[fill][fill2].numT = 0;
                               cache[fill][fill2].i = 0;
        fill2++;
        }
                       }
 
    fill++;
    }
 
  } 
 
  
  char readOrWrite = 0;
  char addr[48] = "";
  int time = 0;
  int readM = 0;
  int writeM = 0;
  int hitC = 0;
  int missC = 0;
 
  while (fscanf(f, "%c %s\n", &readOrWrite, addr) != EOF)
  {
    
    int s = log2(setN);
    if (ADA == 10)
      s = 0;
    int zeros=0;
 
    int b = log2(blockSize);    
    int length = (strlen(addr) - 2)*4;
 
    int t = length - s - b;
 
    char* str = (char*) malloc(length);
  
    while (zeros<length)
    {
    str[zeros]= '0';
    zeros++;
    }
 
    int meadd = 0;  
    int binaryFill=2;
 
    while (binaryFill<strlen(addr))
    {
      char binarydo;
      binarydo= addr[binaryFill];
 
  if (binarydo=='0')
{  str[meadd] = '0';
                       str[meadd+1] = '0';
                       str[meadd+2] = '0';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='f')
{
str[meadd] = '1';
                       str[meadd+1] = '1';
                       str[meadd+2] = '1';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='e')
{
str[meadd] = '1';
                       str[meadd+1] = '1';
                       str[meadd+2] = '1';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='d')
{
 str[meadd] = '1';
                       str[meadd+1] = '1';
                       str[meadd+2] = '0';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='c')
{
 str[meadd] = '1';
                       str[meadd+1] = '1';
                       str[meadd+2] = '0';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='b')
{
str[meadd] = '1';
                       str[meadd+1] = '0';
                       str[meadd+2] = '1';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='a')
{
   str[meadd] = '1';
                       str[meadd+1] = '0';
                       str[meadd+2] = '1';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='9')
{
  str[meadd] = '1';
                       str[meadd+1] = '0';
                       str[meadd+2] = '0';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='8')
{
str[meadd] = '1';
                       str[meadd+1] = '0';
                       str[meadd+2] = '0';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='7')
{
str[meadd] = '0';
                       str[meadd+1] = '1';
                       str[meadd+2] = '1';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='6')
{
str[meadd] = '0';
                       str[meadd+1] = '1';
                       str[meadd+2] = '1';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='5')
{
   str[meadd] = '0';
                       str[meadd+1] = '1';
                       str[meadd+2] = '0';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='4')
{
  str[meadd] = '0';
                       str[meadd+1] = '1';
                       str[meadd+2] = '0';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='3')
{
str[meadd] = '0';
                       str[meadd+1] = '0';
                       str[meadd+2] = '1';
                       str[meadd+3] = '1';
 
}
else if(binarydo=='2')
{
str[meadd] = '0';
                       str[meadd+1] = '0';
                       str[meadd+2] = '1';
                       str[meadd+3] = '0';
 
}
else if(binarydo=='1')
{str[meadd] = '0';
                       str[meadd+1] = '0';
                       str[meadd+2] = '0';
                       str[meadd+3] = '1';
}
    meadd = meadd + 4;
 
    binaryFill++;
    }
 
 
    meadd = t;
    int iSett = 0;  
    if (ADA != 10)
    {
      int i=0;
      char* iso = (char*) malloc(s);
      while (i<s)
      {
     	iso[i] = str[meadd];
                               meadd++;
      i++;
      }
      
      int tmp=0;
      int ii=s-1;
      while (ii>=0)
      {
   	if (iso[ii] == '1')
                                      {
 
long temp = 2;
  long answer = 2;
  int iterat =0;
 
  if (tmp == 0)
  answer= 1;
  
  if (2==0)
  answer= 0;
 
  while (iterat<tmp-1)
  {
  answer=answer*temp;
  iterat++;
  }
 
iSett +=answer;
}
                              tmp++; 
        ii--;
      } 
      free(iso);  
    } 
      
    
    unsigned long tagV = 0; 
    
    
    char* iso = (char*) malloc(t);
    int ite=0;
    while (ite<t)
{
iso[ite] = str[ite];
ite++;
}
  
    int tmp = 0;  
    int itee=t-1;
    while (itee>=0)
{
if (iso[itee] == '1')
tagV += pow(2, tmp);
tmp++;
itee--;
}
 

    
    if (readOrWrite == 'W')
    {
    W(cache, pol, aN, &hitC, &missC, iSett, tagV, &writeM, &readM, ADA, time,setN);
  
    }
    else if (readOrWrite == 'R')
               {
 
                       R(cache, pol, aN, &hitC, &missC, iSett, tagV, &writeM, &readM, ADA, time,setN);
 
               }
    time++; 
    free(str);
  free(iso);
  } 
  
printf("memread:%d\n", readM);
 
printf("memwrite:%d\n", writeM);
 
printf("cachehit:%d\n", hitC);
 
printf("cachemiss:%d\n", missC);
 
   int freethis=0;
 
  while(freethis<setN)
{
free(cache[freethis]);
freethis=freethis+1;
}

int tot = 33;
if (tot > 100)
  tot = 99;

switch(tot)
{
  case 33:
  free(cache);
  break;
}
  fclose(f);
  return EXIT_SUCCESS;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


