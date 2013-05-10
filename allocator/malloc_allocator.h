#ifndef M_MALLOC_ALLOCATOR
#define M_MALLOC_ALLOCATOR

#include <string.h>
#include <stddef.h>
namespace mystl
{
    #ifndef __THROW_BAD_ALLOC
	#include <new>
	define  __THROW_BAD_ALLOC throw std::bad_alloc()
    #endif
    
    //全是静态的成员函数 
    class malloc_allocator
    {
	/*
	 * 1.allocate
	 * 2.deallocate
	 * 3.reallocate
	 * 4.oom_malloc
	 * 5.oom_realloc
	 * 6.set_malloc_handler
	 * */
	private:
	    static void (*malloc_oom_handler)();
	    static void* oom_malloc(size_t size);
	    static void* oom_realloc(void* ptr,size_t size);

	public:
	static void* allocate(size_t size)
	{
	    void* tmp = malloc(size);

	    if(0 == tmp)
	    {
		tmp = oom_malloc(size);
	    }

	    return tmp;
	}

	static void deallocate(void* ptr)
	{
	    free(ptr);
	}

	static void* reallocate(void* ptr,size_t size)
	{
	    void* tmp = realloc(ptr,size);

	    if(0 == tmp)
	    {
		tmp = oom_realloc(ptr,size);
	    }

	    return tmp;
	}
	
	//这个表示了set_malloc_handler函数的参数是函数指针，返回值也是函数指针的
	static void (*set_malloc_handler(void (*f())))()
	{
	    void (*old)() = malloc_oom_handler;
	    malloc_oom_handler = f;
	    return old;
	}
    };

    void (*malloc_allocator::malloc_oom_handler)() = 0;

    void* malloc_allocator::oom_malloc(size_t size)
    {
	void (* my_handler)();
	void* result = 0;

	for(;;)
	{
	    my_handler = malloc_oom_handler;
	    if(my_handler == 0)
	    {
		__THROW_BAD_ALLOC;
	    }

	    my_handler();
	    result = malloc(size);
	    if(result)
	    {
		return result;
	    }
	}
    }
}
#endif
