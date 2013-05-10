#ifndef MUTALGO
#define MUTALGO

/*
 * 下面的这些算法是会改变操作对象的值，主要包含有
 * 1. range1的数据copy到range2
 * 2. 给range中的iterator所指对象赋值
 * 3. 将某一个值覆盖为另一个值
 *
 * 但是值得注意：这里的算法只会更改range中的值，而不会更改range的iterator，也不会更改range本身，也就是所谓的range的个数之类的性质
 * */

//copy的返回值是result的past the end 的iterator
template <class InputIterator,class OutputIterator>
OutputIterator copy(InputIterator first,InputIterator last,OutputIterator result);

//resultshi 是一个尾端,也就是是一个past the end的iterator,这个要注意
template <class BidirectionIterator1,class BidirectionIterator2>
BidirectionIterator2 copy_backward(BidirectionIterator1 first,BidirectionIterator1 last,BidirectionIterator2 result);

template<class Assignable>
void swap(Assignable& lhs,Assignable& rhs);

template<class ForwardIterator1,class ForwardIterator2>
void iter_swap(ForwardIterator1 lhs,ForwardIterator2 rhs);

template<class ForwardIterator1,class ForwardIterator2>
ForwardIterator2 swap_ranges(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2);

template<class ForwardIterator1,class OutputIterator,class UnaryFunction>
OutputIterator transform(ForwardIterator1 first,ForwardIterator1 last,OutputIterator result,UnaryFunction func);

template<class ForwardIterator1,class ForwardIterator2,class OutputIterator,class BinaryFunction>
OutputIterator transform(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,OutputIterator result,BinaryFunction func);

template<class ForwardIterator,class T>
void replace(ForwardIterator first,ForwardIterator last,const T& oldValue,const T& newValue);

template<class ForwardIterator,class Predicate,class T>
void replace_if(ForwardIterator first,ForwardIterator last,Predicate pFunc,const T& newValue);

template<class ForwardIterator,class OutputIterator,class T>
replace_copy(ForwardIterator first,ForwardIterator last,OutputIterator result,const T& oldValue,const T& newValue);

template<class ForwardIterator,class OutputIterator,class Predicate,class T>
void replace_copy_if(ForwardIterator first,ForwardIterator last,OutputIterator result,Predicate pFunc,const T& newValue);

template<class ForwardIterator,class T>
void fill(ForwardIterator first,ForwardIterator last,const T& t);

template<class OutputIterator,class Size,class T>
OutputIterator fill_n(OutputIterator first,Size n,const T& t);

template<class ForwardIterator,class Generator>
void generate(ForwardIterator first,ForwardIterator last,Generator gen);

template<class OutputIterator,class Size,class Generator>
OutputIterator generate_n(OutputIterator first,Size n,const Generator gen);

template<class ForwardIterator,class T>
ForwardIterator remove(ForwardIterator first,ForwardIterator last,const T& t);

template<class ForwardIterator,class Predicate>
ForwardIterator remove_if(ForwardIterator first,ForwardIterator last,Predicate pfunc);

template<class ForwardIterator,class OutputIterator,class T>
OutputIterator remove_copy(ForwardIterator first,ForwardIterator last,OutputIterator result,const T& t);

template<class ForwardIterator,class OutputIterator,class Predicate>
OutputIterator remove_copy_if(ForwardIterator first,ForwardIterator last,OutputIterator result,Predicate pfunc);

template<class ForwardIterator>
ForwardIterator unique(ForwardIterator first,ForwardIterator last);

template<class ForwardIterator,class BinaryPredicate>
ForwardIterator unique(ForwardIterator first,ForwardIterator last,BinaryPredicate bpfunc);

template<class ForwardIterator,class OutputIterator>
ForwardIterator unique_copy(ForwardIterator first,ForwardIterator last,OutputIterator result);

template<class ForwardIterator,class OutputIterator,class BinaryPredicate>
ForwardIterator unique_copy(ForwardIterator first,ForwardIterator last,OutputIterator result,BinaryPredicate bpfunc);

template<class BidirectionIterator>
void reverse(BidirectionIterator first,BidirectionIterator last);

template<class BidirectionIterator,class OutputIterator>
OutputIterator reverse_copy(BidirectionIterator first,BidirectionIterator last,OutputIterator result);

template<class ForwardIterator>
inline void rotate(ForwardIterator first,ForwardIterator middle,ForwardIterator last);

template<class ForwardIterator,class OutputIterator>
OutputIterator rotate_copy(ForwardIterator first,ForwardIterator middle,ForwardIterator last,OutputIterator result);

template<class BidirectionIterator>
bool next_permutation(BidirectionIterator first,BidirectionIterator last);

template<class BidirectionIterator,class StrictWeakOrdering>
bool next_permutation(BidirectionIterator first,BidirectionIterator last,StrictWeakOrdering comp);

template<class BidirectionIterator>
bool prev_permutation(BidirectionIterator first,BidirectionIterator last);

template<class BidirectionIterator,class StrictWeakOrdering>
bool prev_permutation(BidirectionIterator first,BidirectionIterator last,StrictWeakOrdering comp);

template<class BidirectionIterator,class Predicate>
BidirectionIterator partition(BidirectionIterator first,BidirectionIterator last,Predicate pfunc);

template<class ForwardIterator,class Predicate>
ForwardIterator stable_partition(ForwardIterator first,ForwardIterator last,Predicate pfunc);

template<class RandomAccessIterator>
void random_shuffle(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first,RandomAccessIterator last,RandomAccessIterator& rand);

template<class InputIterator,class RandomAccessIterator>
void random_sample(InputIterator first,InputIterator last,RandomAccessIterator ofirst,RandomAccessIterator olast);

template<class InputIterator,class RandomAccessIterator,class RandomNumberGenerator>
void random_sample(InputIterator first,InputIterator last,RandomAccessIterator ofirst,RandomAccessIterator olast,RandomNumberGenerator& rand);

template<class InputIterator,class RandomAccessIterator,class OutputIterator,class Distance>
OutputIterator random_sample_n(InputIterator first,InputIterator last,RandomAccessIterator ofirst,Distance n);

template<class InputIterator,class RandomAccessIterator,class OutputIterator,class Distance,class RandomNumberGenerator>
OutputIterator random_sample_n(InputIterator first,InputIterator last,RandomAccessIterator ofirst,Distance n,RandomNumberGenerator& rand);


template<class InputIterator,class T>
T accumulate(InputIterator first,InputIterator last,T init);

template<class InputIterator,class T,class BinaryFunction>
T accumulate(InputIterator first,InputIterator last,T init,BinaryFunction bfunc);

template<class InputIterator1,class InputIterator2,class T>
T inner_product(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,T init);

template<class InputIterator1,class InputIterator2,class T,class BinaryFunction1,class BinaryFunction2>
T inner_product(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,T init,BinaryFunction1 bfunc1,BinaryFunction2 bfunc2);

template<class InputIterator,class OutputIterator>
OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result);

template<class InputIterator,class OutputIterator>
OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result);

template<class InputIterator,class OutputIterator,class BinaryFunction>
OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result,BinaryFunction bfunc);

template<class InputIterator,class OutputIterator>
OutputIterator adjacent_difference(InputIterator first,InputIterator last,OutputIterator result);

template<class InputIterator,class OutputIterator,class BinaryFunction>
OutputIterator adjacent_difference(InputIterator first,InputIterator last,OutputIterator result,BinaryFunction bfunc);

//sort and search

template<class RandomAccessIterator>
void sort(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void sort(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void stable_sort(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void stable_sort(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void partial_sort(RandomAccessIterator first,RandomAccessIterator middle,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void partial_sort(RandomAccessIterator first,RandomAccessIterator middle,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class InputIterator,class RandomAccessIterator>
OutputIterator partial_sort_copy(InputIterator first,InputIterator last,RandomAccessIterator result_first,RandomAccessIterator result_last);

template<class InputIterator,class RandomAccessIterator,class StrictWeakOrdering>
OutputIterator partial_sort_copy(InputIterator first,InputIterator last,RandomAccessIterator result_first,RandomAccessIterator result_last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void nth_element(RandomAccessIterator first,RandomAccessIterator nth,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void nth_element(RandomAccessIterator first,RandomAccessIterator nth,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class ForwardIterator>
bool is_sorted(ForwardIterator first,ForwardIterator last);

template<class ForwardIterator,class StrictWeakOrdering>
bool is_sorted(ForwardIterator first,ForwardIterator last,StrictWeakOrdering cmp);

//search

template<class ForwardIterator,class StrictWeaklyComparable>
bool binary_search(ForwardIterator first,ForwardIterator last,const StrictWeaklyComparable& value);


template<class ForwardIterator,class T,class StrictWeakOrdering>
bool binary_search(ForwardIterator first,ForwardIterator last,const T& value,StrictWeakOrdering cmp);

template<class ForwardIterator,class StrictWeaklyComparable>
ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const StrictWeaklyComparable& value);

template<class ForwardIterator,class T,class StrictWeakOrdering>
ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T& value,StrictWeakOrdering cmp);

template<class ForwardIterator,class StrictWeaklyComparable>
ForwardIterator upper_bound(ForwardIterator first,ForwardIterator last,const StrictWeaklyComparable& value);

template<class ForwardIterator,class T,class StrictWeakOrdering>
ForwardIterator upper_bound(ForwardIterator first,ForwardIterator last,const T& value,StrictWeakOrdering cmp);

template<class ForwardIterator,class StrictWeaklyComparable>
pair<ForwardIterator,ForwardIterator> equal_range(ForwardIterator first,ForwardIterator last,const StrictWeaklyComparable& value);

template<class ForwardIterator,class T,class StrictWeakOrdering>
pair<ForwardIterator,ForwardIterator> equal_range(ForwardIterator first,ForwardIterator last,const T& value,StrictWeakOrdering cmp);

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator merge(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result);

template<class InputIterator1,class InputIterator2,class OutputIterator,class StrictWeakOrdering>
OutputIterator merge(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,StrictWeakOrdering cmp);

template<class BidirectionIterator>
inline void inplace_merge(BidirectionIterator first,BidirectionIterator middle,BidirectionIterator last);

template<class BidirectionIterator,class StrictWeakOrdering>
inline void inplace_merge(BidirectionIterator first,BidirectionIterator middle,BidirectionIterator last,StrictWeakOrdering cmp);

//集合操作

template<InputIterator1,class InputIterator2>
bool includes(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2);

template<InputIterator1,class InputIterator2,class StrictWeakOrdering>
bool includes(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,StrictWeakOrdering cmp);

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_union(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result);

template<class InputIterator1,class InputIterator2,class OutputIterator,class StrictWeakOrdering>
OutputIterator set_union(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,StrictWeakOrdering cmp);

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_intersection(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result);

template<class InputIterator1,class InputIterator2,class OutputIterator,class StrictWeakOrdering>
OutputIterator set_intersection(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,StrictWeakOrdering cmp);

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_difference(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result);

template<class InputIterator1,class InputIterator2,class OutputIterator,class StrictWeakOrdering>
OutputIterator set_difference(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,StrictWeakOrdering cmp);

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_symmetric_difference(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result);

template<class InputIterator1,class InputIterator2,class OutputIterator,class StrictWeakOrdering>
OutputIterator set_symmetric_difference(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void make_heap(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void make_heap(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void push_heap(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void push_heap(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void pop_heap(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void pop_heap(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
void sort_heap(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
void sort_heap(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);

template<class RandomAccessIterator>
bool is_heap(RandomAccessIterator first,RandomAccessIterator last);

template<class RandomAccessIterator,class StrictWeakOrdering>
bool is_heap(RandomAccessIterator first,RandomAccessIterator last,StrictWeakOrdering cmp);
#endif

