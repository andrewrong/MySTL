#ifndef MTRAITS
#define MTRAITS
namespace mystl
{
    template <typename iter>
	struct iterator_traits
	{
	    /*
	     * iterator_category
	     * value_type
	     * pointer
	     * const_pointer
	     * reference
	     * const_reference
	     * difference_type
	     * */
	    typedef typename iter::iterator_category iterator_category;
	    typedef typename iter::value_type value_type;

	    typedef typename iter::pointer pointer;
	    typedef typename iter::reference reference;

	    typedef typename iter::difference_type difference_type;
	};

    template <typename iter>
	struct iterator_traits<iter*>
	{
	    typedef random_access_iterator_tag iterator_category;
	    typedef iter value_type;

	    typedef iter* pointer;
	    typedef iter& reference;

	    typedef ptrdiff_t difference_type;
	};
    
    template <typename iter>
	struct iterator_traits<const iter*>
	{
	    typedef random_iterator_tag iterator_category;
	    typedef iter value_type;

	    typedef const iter* pointer;
	    typedef const iter& reference;

	    typedef ptrdiff_t difference_type;
	};

    template<class iter>
    typename iterator_traits<iter>::value_type* __value_type(iter)
    {
	return static_cast<iterator_traits<iter>::value_type*>(0);
    }
}
#endif
