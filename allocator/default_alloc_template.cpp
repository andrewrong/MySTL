#include "default_alloc_template.h"

char* default_alloc_template::start_free = 0;
char* default_alloc_template::end_free = 0;
size_t default_alloc_template::heap_size = 0;
default_alloc_template::obj* volatile myFreeList[__NFREELISTS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static void* allocate(size_t n)	
{
    if(n > static_cast<size_t>(__MAX_BYTES))
    {
	return (malloc_allocator::allocate(n));
    }

    obj* volatile * my_free_list = 0;
    obj* result = 0;

    my_free_list = myFreeList + FreeListIndex(n);
    result = *my_free_list;

    if(result == 0)
    {
	void* r = refill(Round_Up(n));
	return r;
    }
    else
    {
	*my_free_list = result->free_list_link;
	return result;
    }
}

//deallocate ptr不能为0，n主要是为了把n放到一定的链表上去
static void deallocate(void* lhs,size_t n)
{
    obj* ptr = (obj*) lhs;

    if(n > __MAX_BYTES)
    {
	free(lhs);
    }

    obj* volatile * myList = myFreeList + FreeListIndex(n);
    obj* result = *myList;

    ptr->free_list_link = result;
    *myList = ptr; 
}
static void* reallocate(void* ptrOld,size_t oldSize,size_t newSize)
{
}

//n是8的倍数,返回是指针，而大小其实要有程序员自己定义相应的数据结构来确定，当然stl是进行封装了;
void* refill(size_t n)
{
    int nobj = 20;
    char* chunk = (char*)chunk_alloc(n,nobj);

    if(nobj == 1)
    {
	return chunk;
    }

    //进行填充操作
    obj* volatile *myList = 0;
    obj* result = static_cast<obj*>(chunk);
    myList = myFreeList + FreeListIndex(n);
    obj* currentObjPtr = static_cast<obj*>(chunk + n)
    *myList = currentObjPtr;
    obj* nextObjPtr = 0;

    for(int i = 1; i < (nobj - 1); i++)
    {
	nextObjPtr = static_cast<obj*>(static_cast<char*>(currentObjPtr) + n);	
	currentObjPtr->free_list_link = nextObjPtr;
	currentObjPtr = nextObjPtr;
    }
    nextObjPtr->free_list_link = 0;

    return (result);
}

void* chunk_alloc(size_t n,int& nobj)
{
    /*
     * 1.计算还剩有多少heap空间可以使用
     * 2.如果大于n*nobj，那么就直接分配，然后修改start_free和end_free
     * 3.如果剩余空间大于n，小于n*nobj，然后进行分配
     * 4.如果小于n的话，那么就把这些空间连接到比n小的链表上去，然后重新使用malloc申请空间
     * 5.如果申请不成功的话就调用第一个内存分配器(这个过程比较麻烦)
     * */
    
    size_t bytesLeft = free_end - start_free;
    size_t bytesTotal = n * nobj;
    char* result = 0;

    if(bytesLeft > bytesTotal)
    {
	result = start_free;
	start_free += bytesTotal;

	return result;
    }
    else if(bytesLeft < bytesTotal && bytesLeft > n)
    {
	nobj = bytesLeft / n;
	result = start_free;
	start_free += nobj * n;

	return result; 
    }
    else
    {
	//剩余的空间连一个n都提供不了了，那就要开始向系统去申请空间了;
	//这个表达式，就让我们知道如果heap越大，那么往后申请的空间也会越来越大
	size_t bytesToGet  = 2 * bytesTotal + Round_Up((heap_size) >> 4);

	if(bytesLeft > 0)
	{
	    //把剩余下来的内存区域放到myFreeList中去
	    obj* volatile * myList = myFreeList + FreeListIndex(bytesLeft);
	    obj* tmp = static_cast<obj*>(start_free);
	    tmp->free_list_link = *myList;
	    *myList = tmp;
	}
	
	start_free = (char*)malloc(bytesToGet);

	if(start_free == 0)
	{
	    int i = 0;  
	    
	    obj* volatile * myList = 0;
	    
	    for(i = n; i <= __MAX_BYTES; i += __ALIGN)
	    {
		myList = FreeListIndex(i) + myFreeList;
		//源码中这里定义了一个临时变量p用来保存*myList,不知为何？
		if(0 != *myList )
		{
		    start_free = *myList;
		    *myList = (*myList)->free_list_link;
		    end_free = start_free + i;

		    return chunk_alloc(n,nobj);
		}
	    }

	    end_free = 0;

	    start_free = (char*)malloc_allocator::allocate(bytesToGet);
	}
	
	heap_size += bytesToGet;
	end_free = start_free + bytesToGet;

	return (chunk_alloc(n,nobj));
    }

}
