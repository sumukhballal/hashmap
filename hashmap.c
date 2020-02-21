#include<stdio.h>

struct hashNode {
int key;
int value;
struct hashNode *next;
};
struct hashMap {
int size;
struct hashNode **map;
};

int hashCode(struct hashMap *hm,int key)
{
if(key)
{
	return key%hm->size;
}
else if(key < 0)
{
	return -(key%hm->size);
}
return -1;
}

int getValue(struct hashMap *hm, int key)
{
int nodeNum = hashCode(hm,key);

if(nodeNum<0)
	return -1;

return hm->map[nodeNum]->value;
}


void insertKeyValue(struct hashMap *hm,int key,int value)
{
if(hm->size==0)
{
return ;
}

int nodeNum=hashCode(hm,key);
if(nodeNum<0 || nodeNum > hm->size)
	return ;
//malloc should be only for a new node
struct hashNode *hn = (struct hashNode *)malloc(sizeof(struct hashNode));
hn->key=key;
hn->value=value;
hn->next=NULL;
hm->map[nodeNum]=hn;
}

int main(int argc,int argv[])
{
int size=atoi(argv[1]);
int getVal=atoi(argv[2]);
struct hashMap *hm=(struct hashMap *)malloc(sizeof(struct hashMap));
hm->size=size;
hm->map=(struct hashNode **)malloc(sizeof(struct hashNode)*size);

for(int i=0;i<size;i++)
hm->map[i]=NULL;

insertKeyValue(hm,1,10);
insertKeyValue(hm,2,11);
insertKeyValue(hm,3,12);
printf("Key : %d Value : %d",getVal,getValue(hm,getVal));
}
