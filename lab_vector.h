#ifndef LAB_VECTOR_H
#define LAB_VECTOR_H
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct lab__vector_st
{
    int data; 
	void *begin;
    void *end;
    void *store;
    int maxSize;
    
};

struct lab__vector_iter_st
{
	int data;
	void *pointer;

};

// NOT MODIFY BELOW
typedef struct lab__vector_st VectorDescriptor;
typedef struct lab__vector_iter_st VectorIterator;

struct lab__vector_api_st{
    VectorDescriptor (*constructor)();
    void (*push_back)(VectorDescriptor* desc,void* elem,int size);
    VectorIterator (*begin)(VectorDescriptor* desc);
    VectorIterator (*end)(VectorDescriptor* desc);
    void* (*iter_dereference)(VectorIterator iter);
    VectorIterator (*iter_move)(VectorIterator iter,int delta); // simulates: iter+8;
    int (*size)(VectorDescriptor* desc);
    void (*pop_back)(VectorDescriptor* desc);
    void (*erase)(VectorDescriptor* desc,VectorIterator iter);
    void (*clear)(VectorDescriptor* desc);
    void (*destructor)(VectorDescriptor* desc);
    int (*capacity)(VectorDescriptor* desc);
    void (*shrink_to_fit)(VectorDescriptor* desc);
    void (*reserve)(VectorDescriptor* desc,int resv_size);
    int (*VectorMaxSize)(VectorDescriptor* desc) ;
	int  (*VectorGet)(VectorDescriptor* desc, int index);
	
};

typedef struct lab__vector_api_st VectorAPI;

extern VectorAPI vector;

 VectorDescriptor (*constructor)()
{ 
    VectorDescriptor desc;
    desc->begin=NULL;
    desc->store=NULL;
    desc->end=NULL;
    desc->data=0;
    return desc;    
}  

void (*push_back)(VectorDescriptor* desc,void* elem,int size)
{
 	assert(desc->data != NULL);
 	if (desc->data >= desc->maxSize) {  
  
        desc->maxSize *= 2;  
        desc->data = (char *)realloc(desc->data, desc->maxSize * sizeof(char));  
        assert(desc->data_size != NULL);  
    }  
  
    desc->data[desc->size++] = elem;  
}

VectorIterator (*begin)(VectorDescriptor* desc)
{
   VectorIterator term;
   term->pointer=desc->begin;
   return term; 
}

VectorIterator (*end)(VectorDescriptor* desc)
{
	VectorIterator term;
   term->pointer=desc->end;
   return term;
}

void* (*iter_dereference)(VectorIterator iter)
{
	VectorIterator iter;
    return iter->pointer;
}

VectorIterator (*iter_move)(VectorIterator iter,int delta)
{
	VectorIterator iter;
	iter->pointer+=iter->data;
    return iter;
}
 
int (*size)(VectorDescriptor* desc)  
{  
    assert(desc != NULL);
	int desc->data_size=((char*)desc->end-(char*)desc->begin);  
    return desc->size;  
}   

void pop_back(VectorDescriptor* desc)
{
    desc->end-=desc->data;
}

void erase(VectorDescriptor* desc,VectorIterator iter)
{
    int data_size=desc->data;
    for(;iter->pointer<desc->end;)
    {
        memcpy(iter->pointer,iter->pointer+data,data_size);
        iter->pointer+=data;
    }
    desc->end-=data_size;
}

void clear(VectorDescriptor* desc)
{
   desc->end=desc->begin; 
}
 
void destructor(VectorDescriptor* desc)
{
    free(desc->begin);
}

int capacity(VectorDescriptor* desc)
{
    return ((char*)desc->store-(char*)desc->begin+desc->data)/(desc->data);
}

void shrink_to_fit(VectorDescriptor* desc)
{
    desc->store=desc->end;
}

void (*reserve)(VectorDescriptor* desc,int resv_size)
{
	 int data=desc->data;
    int now_size=(char*)desc->end-(char*)desc->begin+data;
    if(now_size<resv_size)
    {
        void *temp=malloc(resv_size);
        for(int i=0;i<now_size;i+=desc->data_size)
        {
            memcpy(temp+i,desc->begin+i,data_size);
        }
        free(desc->begin);
        desc->begin=temp;
        desc->end=temp+now_size-data;
        desc->store=temp+resv_size-data;
    }
}

int (*VectorMaxSize)(VectorDescriptor* desc)
{
	 assert(desc->maxSize != NULL);  
     return desc->maxSize;  
}

int  (*VectorGet)(VectorDescriptor* desc, int index)
{  
    assert(desc->data_size != NULL && index >= 0 && index < desc->data_size);  
    return desc->data_size[index]; 
}

#endif
