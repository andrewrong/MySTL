#ifndef MTAGS
#define MTAGS
namespace mystl
{
    struct input_iterator_tags{};
    struct output_iterator_tags{};
    struct forward_iterator_tags:public input_iterator_tags{};
    struct bidirection_iterator_tags:public forward_iterator_tags{};
    struct random_access_iterator_tags:public bidirection_iterator_tags{};
}
#endif
