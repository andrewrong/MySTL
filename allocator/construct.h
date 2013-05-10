#ifndef M_CONSTRUCT_H
#define M_CONSTRUCT_H

#include <new>

namespace mystl
{
    template <class T1,class T2>
    inline void construct(T1* ptr,const T2& value);
    {
        new(ptr) T2(value);
    }
    
    template <class T>
    inline void destroy(T* ptr)
    {
        ptr->~T();
    }
    
    template<class ForwardIterator>
    inline void _Destroy_aux(ForwardIterator first,ForwardIterator last,__true_type){}
    
    
    inline void _Destroy_aux(ForwardIterator first,ForwardIterator last,__true_type)
    {
        for(ForwardIterator iter = first; first != last; iter++)
        {
    	destroy(&(*iter));
        }
    }
    
    template <class ForwardIterator,class Tp>
    inline void _Destroy(ForwardIterator first,ForwardIterator last,Tp*)
    {
        typedef typename __type_traits<Tp>::has_trivial_destructor trivial_destructor;
        _Destroy_aux(first,last,trivial_destructor());
    }
    
    template <class ForwardIterator>
    inline void destroy(ForwardIterator first,ForwardIterator last)
    {
        _Destroy(first,last,__value_type(first));
    }
    
    //特化内部数据的
    inline void destroy(char* first,char* last){}
    inline void destroy(int* first,int* last){}
    inline void destroy(long* first,long* last){}
    inline void destroy(float* first,float* last){}
    inline void destroy(double* first,double* last){}
}
#endif
