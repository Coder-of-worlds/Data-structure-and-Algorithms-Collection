#include "Exceptions.hpp"
namespace Collection
{
    namespace DataStructure
    {
        template <typename T> class Stack
        {
        public:
            class Iterator
            {
                T value;
                Iterator* next;
                Iterator* prev;
                bool nan;
                friend class Stack <T>;

                Iterator (const char* x __attribute__((unused)))
                {
                    nan = true;
                    value = T();
                    next = prev = nullptr;
                }
            public:
                Iterator (const T& val)
                {
                    nan = false;
                    value = val;
                    next = prev = nullptr;
                }
                Iterator ()
                {
                    nan = false;
                    value = T();
                    next = prev = nullptr;
                }
                T& operator () () 
                {
                    return value;
                }
                bool operator != (Iterator x) const
                {
                    return value != x.value or prev != x.prev or next != x.next or this->nan != x.nan;
                }
                Iterator& Next ()
                {
                    if (next == nullptr)
                        throw Collection::Expection::OutOfRange(1, 0);
                    return *next;
                }
                Iterator& Prev ()
                {
                    if (prev == nullptr)
                        throw Collection::Expection::OutOfRange(-1, 0);
                    return *prev;
                }
                inline bool isNone () const
                {
                    return nan;
                }
                friend std::ostream& operator << (std::ostream& out, Iterator it)
                {
                    if (it.isNone())
                        out << "None";
                    else
                        out << it();
                    return out;
                }
                Iterator& insertAfter (const T& value)
                {
                    if (nan == true)
                        throw Collection::Expection::OutOfRange (0, 0);
                    Iterator* x = new Iterator (value);
                    x->next = this->next;
                    this->next = x;
                    x->prev = this;
                    return *x;
                }
                Iterator& insertBefore (const T& value)
                {
                    if (nan == true)
                        throw Collection::Expection::OutOfRange (0, 0);
                    Iterator* x = new Iterator (value);
                    x->prev = this->prev;
                    this->prev = x;
                    x->next = this;
                    return *x;
                }
            };
        private:
            Iterator* head;
            Iterator* tail;
            std::size_t _size;
            Iterator NaN;
            inline std::size_t size () const
            {
                return _size;
            }
        public: 
            const Iterator& None () const
            {
                return NaN;
            }
            Stack ()
            {
                NaN = Iterator ("NaN");
                head = nullptr;
                tail = nullptr;
                _size = 0;
            }
            void push (const T& val)
            {
                NaN = Iterator ("NaN");
                _size ++;
                Iterator* node = new Iterator (val);
                if (head == nullptr and tail == nullptr)
                    head = tail = node;
                else
                {
                    node->prev = tail;
                    node->next = nullptr;
                    tail->next = node;
                    tail = node;
                }
                return ;
            }
            const T pop ()
            {
                T val;
                if (head == nullptr and tail == nullptr)
                    throw Collection::Expection::PopingOutOfEmptyCollection ();
                else
                {
                    _size --;
                    Iterator* x = tail;
                    tail = tail->prev;
                    if (tail != nullptr)
                    {
                        tail->next = nullptr;
                    }
                    val = (*x)();
                    delete x;
                }
                return val;
            }
            inline bool empty () const 
            {
                return size () == 0;
            }
            inline const T& top () const 
            {
                return (*tail)();
            }
        };
    }
}