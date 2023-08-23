/* Sample solution for the Nested Dolls problem in NCPC'07 by Andreas Björklund */
#include <stdio.h>

#define MAXM (20001)

struct dim
{
    int w,h;
};

struct dim dims[MAXM];
int size[MAXM+1];
int anti_chain_size;

int cmp(void *a,void *b)
{
  struct dim* ta=((struct dim*)a);
  struct dim* tb=((struct dim*)b);
  

  if (ta->w != tb->w)
    return ta->w - tb->w;
  return tb->h  - ta->h;

}
  
int main(void)
{
  int n,m,i,j;
  scanf("%d",&n);
  while(n--)
  {
    
    scanf("%d",&m);
    for (i=0;i<m;i++)
      scanf("%d %d",&dims[i].w,&dims[i].h);
    qsort(dims,m,sizeof(struct dim),cmp);
    anti_chain_size=0;
    for (i=0;i<m;i++)
    {
      int hi=anti_chain_size;
      int lo=0;
      while (hi>lo)
      {
        int mid=(hi+lo)/2;
        if (size[mid]>=dims[i].h)
          lo=mid+1;
        else
          hi=mid;  
      }
      size[lo]=dims[i].h;
      anti_chain_size+=(lo==anti_chain_size);
    }  
    printf("%d\n",anti_chain_size);
  }
  return 0;
}
