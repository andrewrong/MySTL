#ifndef DEF_ALLOC_TEMP
#define DEF_ALLOC_TEMP
class default_alloc_template
{
    private:
	//8字节对齐
	enum{__ALIGN = 8};
	//小型内存块
	enum{__MAX_BYTES = 128};
	//free_lists 的个数
	enum{__NFREELISTS = __MAX_BYTES / __ALIGN};
	
	static char* start_free;
	static char* end_free;
	static size_t heap_size;

	union obj
	{
	    union obj* free_list_link;
	    char client_data[1];
	};
	
	static obj* volatile myFreeList[__NFREELISTS];
	static size_t FreeListIndex(size_t n)
	{
	    return ((n + __ALIGN - 1) / __ALIGN - 1);
	}

	static size_t Round_Up(size_t n)
	{
	    return (n + __ALIGN - 1) & ~(__ALIGN);
	}
	
	//重新填满空链表
	void* refill(size_t n);
	//重新分配内存，这是这个分配器的核心
	void* chunk_alloc(size_t n,int& nobj);

    public:
	static void* allocate(size_t n);	
	//deallocate ptr不能为0，n主要是为了把n放到一定的链表上去
	static void deallocate(void* lhs,size_t n);
	static void* reallocate(void* ptrOld,size_t oldSize,size_t newSize);
};
#endif
