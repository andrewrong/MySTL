#ifndef MALL1_H
#define MALL1_H

#include <new>
#include <climits> //for UINT_MAX
#include <iostream>
#include <cstdlib> //for exit()
#include <cstddef> //for ptrdiff_t,size_t

namespace mystl
{
    //只分配内存不构造对象
    template<class T>
    inline T* _allocate(size_t n,const void* = 0)
    {
	set_new_handler(0);

	T* tmp = (T*)(::operator new((size_t)(sizeof(T) * n)));

	if(tmp == NULL)
	{
	    std::cerr << "out of memory" << std::endl;
	    exit(1);
	}

	return tmp;
    }
    
    template<class T>
    inline void _deallocate(T* ptr)
    {
	::operator delete(ptr);
    }
    
    template<class T1,class T2>
    inline void _construct(T1* p,const T2& x)
    {
	new(p) T1(x);
    }

    template<class T>
    inline void _destory(T* p)
    {
	p->~T();
    }


    template<class T>
    class allocator
    {
	public:
	    //type
	    typedef T value_type;
	    typedef T* pointer;
	    typedef const T* const_pointer;
	    typedef T& reference;
	    typedef const T& const_reference;
	    typedef size_t size_type;
	    typedef ptrdiff_t difference_type
	    
	    template<class U>
	    struct rebind
	    {
		typedef allocator<U> other;
	    };

	    //constructor destroy copy constructor
	    //allocator();
	    //allocator(const allocator& lhs);
	    //~allocator();

	    //分配内存但不初始化，初始化为未初始化的内存
	    pointer allocate(size_type n,const void* = 0);
	    {
		return ::_allocate<T>(n);
	    }

	    void deallocate(pointer p,size_type n);
	    {
		::_deallocate(p);
	    }

	    void construct(pointer p,const T& x);
	    {
		::_construct(p,x);
	    }

	    void destroy(pointer p);
	    {
		::_destory(p);
	    }

	    //address max_size
	    pointer address(reference x);
	    {
		return (pointer)(&x);
	    }
	    const_pointer address(const_reference x) const;
	    {
		return (const_pointer)(&x);
	    }

	    size_type max_size() const;
	    {
		return (size_type)((UINT_MAX)/sizeof(T));
	    }
    };
}

#endif
