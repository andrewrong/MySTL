#ifndef NONALGO_H
#define NONALGO_H

namespace mystl
{
    template<class InputIterator,class EqualityComparable>
    InputIterator find(InputIterator first,InputIterator last,const EqualityComparable& value);
    
    template<class InputIterator,class Predicate>
    InputIterator find_if(InputIterator first,InputIterator last,Predicate pred);
    
    template<class ForwardIterator>
    ForwardIterator adjacent_find(ForwardIterator first,ForwardIterator last);
    
    template<class ForwardIterator,class BinaryPredicate>
    ForwardIterator adjacent_find(ForwardIterator first,ForwardIterator last,BinaryPredicate binaryPred);
    
    template<class ForwardIterator,class InputIterator>
    InputIterator find_first_of(InputIterator first1,InputIterator last1,ForwardIterator first2,ForwardIterator last2);
    
    template<class ForwardIterator,class InputIterator,class BinaryPredicate>
    InputIterator find_first_of(InputIterator first1,InputIterator last1,ForwardIterator first2,ForwardIterator last2,BinaryPredicate binaryPred);
    
    template<class ForwardIterator1,class ForwardIterator2>
    ForwardIterator1 search(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2);
    
    template<class ForwardIterator1,class ForwardIterator2,class BinaryPredicate>
    ForwardIterator1 search(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2,BinaryPredicate binaryPred);
    
    //find_end == search_end
    template<class ForwardIterator1,class ForwardIterator2>
    ForwardIterator1 find_end(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2);
    
    template<class ForwardIterator1,class ForwardIterator2,class BinaryPredicate>
    ForwardIterator1 find_end(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2,BinaryPredicate binaryPred);
    template<class ForwardIterator,class Integer,class T>
    ForwardIterator seach_n(ForwardIterator first,ForwardIterator last,Integer n,const T& value);

    template<class ForwardIterator,class Integer,class T,class BinaryPredicate>
    ForwardIterator seach_n(ForwardIterator first,ForwardIterator last,Integer n,const T& value,BinaryPredicate binaryPred);

    template<class InputIterator,class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type count(InputIterator first,InputIterator last,const EqualityComparable& value);

    template<class InputIterator,class Predicate>
    typename iterator_traits<InputIterator>::difference_type count_if(InputIterator first,InputIterator last,Predicate pred);
    
    template<class InputIterator,class UnaryFunction>
    UnaryFunction for_each(InputIterator first,InputIterator last,UnaryFunction unaryFunction);

    template<class InputIterator>
    bool equal(InputIterator first1,InputIterator last1,InputIterator first2);

    template<class InputIterator,class BinaryPredicate>
    bool equal(InputIterator first1,InputIterator last1,InputIterator first2,BinaryPredicate binaryPred);

    template<class InputIterator1,class InputIterator2>
    pair<InputIterator1,InputIterator2> mismatch(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2);

    template<class InputIterator1,class InputIterator2,class BinaryPredicate>
    pair<InputIterator1,InputIterator2> mismatch(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,BinaryPredicate binaryPred);

    template<class InputIterator1,class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2);

    template<class InputIterator1,class InputIterator2,class BinaryPredicate>
    bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,BinaryPredicate binaryPred);

    template<class LessThanComparable>
    LessThanComparable min(const LessThanComparable& lhs,const LessThanComparable& rhs);

    template<class LessThanComparable,class BinaryPredicate>
    LessThanComparable min(const LessThanComparable& lhs,const LessThanComparable& rhs,BinaryPredicate binaryPred);

    template<class LessThanComparable>
    LessThanComparable max(const LessThanComparable& lhs,const LessThanComparable& rhs);

    template<class LessThanComparable,class BinaryPredicate>
    LessThanComparable max(const LessThanComparable& lhs,const LessThanComparable& rhs,BinaryPredicate binaryPred);

    template<class ForwardIterator>
    ForwardIterator min_element(ForwardIterator first,ForwardIterator last);

    template<class ForwardIterator,class BinaryPredicate>
    ForwardIterator min_element(ForwardIterator first,ForwardIterator last,BinaryPredicate cmp);

    template<class ForwardIterator>
    ForwardIterator max_element(ForwardIterator first,ForwardIterator last);

    template<class ForwardIterator,class BinaryPredicate>
    ForwardIterator max_element(ForwardIterator first,ForwardIterator last,BinaryPredicate cmp);
}

#endif
