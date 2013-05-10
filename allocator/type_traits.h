#ifndef M_TYPE_TRAITS
#define M_TYPE_TRAITS

struct __false_type{};
struct __true_type{};

template <class T>
struct __type_traits
{
    typedef __false_type has_trivial_default_constructor;
    typedef __false_type has_trivial_copy_constructor;
    typedef __false_type has_trivial_assignment_operator;
    typedef __false_type has_trivial_default_destructor;
    typedef __false_type is_POD_type;
};

//特化C++内部数据类型

template <>
struct __type_traits<bool>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<signed char>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<unsigned char>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};


template <>
struct __type_traits<char>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};


template <>
struct __type_traits<short>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};


template <>
struct __type_traits<unsigned short>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<int>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};
template <>
struct __type_traits<unsigned int>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<long>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<unsigned long>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};


template <>
struct __type_traits<long long>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};
template <>
struct __type_traits<unsigned long long>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

template <>
struct __type_traits<float>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};
template <>
struct __type_traits<double>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};
template <>
struct __type_traits<long double>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

//特化指针
template <class T>
struct __type_traits<T*>
{
    typedef __true_type has_trivial_default_constructor;
    typedef __true_type has_trivial_copy_constructor;
    typedef __true_type has_trivial_assignment_operator;
    typedef __true_type has_trivial_default_destructor;
    typedef __true_type is_POD_type;
};

#endif
