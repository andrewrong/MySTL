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

//deallocate ptr����Ϊ0��n��Ҫ��Ϊ�˰�n�ŵ�һ����������ȥ
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

//n��8�ı���,������ָ�룬����С��ʵҪ�г���Ա�Լ�������Ӧ�����ݽṹ��ȷ������Ȼstl�ǽ��з�װ��;
void* refill(size_t n)
{
    int nobj = 20;
    char* chunk = (char*)chunk_alloc(n,nobj);

    if(nobj == 1)
    {
	return chunk;
    }

    //����������
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
     * 1.���㻹ʣ�ж���heap�ռ����ʹ��
     * 2.�������n*nobj����ô��ֱ�ӷ��䣬Ȼ���޸�start_free��end_free
     * 3.���ʣ��ռ����n��С��n*nobj��Ȼ����з���
     * 4.���С��n�Ļ�����ô�Ͱ���Щ�ռ����ӵ���nС��������ȥ��Ȼ������ʹ��malloc����ռ�
     * 5.������벻�ɹ��Ļ��͵��õ�һ���ڴ������(������̱Ƚ��鷳)
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
	//ʣ��Ŀռ���һ��n���ṩ�����ˣ��Ǿ�Ҫ��ʼ��ϵͳȥ����ռ���;
	//������ʽ����������֪�����heapԽ����ô��������Ŀռ�Ҳ��Խ��Խ��
	size_t bytesToGet  = 2 * bytesTotal + Round_Up((heap_size) >> 4);

	if(bytesLeft > 0)
	{
	    //��ʣ���������ڴ�����ŵ�myFreeList��ȥ
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
		//Դ�������ﶨ����һ����ʱ����p��������*myList,��֪Ϊ�Σ�
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
