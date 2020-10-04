#include "Expections.hpp"

namespace Collection
{
    namespace DataStructure
    {
        template <typename T> class DynamicArray
        {
        private:
            T* array;
            std::size_t _size;
            std::size_t _capacity;
        public:
            DynamicArray ()
            {
                array = new T [1];
                _capacity = 1;
                _size = 0;
            }
            void resize (std::size_t new_size)
            {
                T* tmp = new T [new_size];
                _size = ((_size < new_size) ? _size : new_size);
                _capacity = new_size;
                for (std::size_t i = 0 ; i < size () ; i ++)
                    tmp [i] = get (i);
                delete[] array;
                array = tmp;
            }
            inline std::size_t size () const
            {
                return _size;
            }
            inline std::size_t capacity () const
            {
                return _capacity;
            }
            T& get (const std::size_t index) const
            {
                if (index >= size())
                    throw Collection::Expection::OutOfRange (index, size());
                return array [index];
            }
            void push (const T& val)
            {
                if (size() == capacity())
                {
                    resize (capacity() * 2);
                }
                _size ++;
                array [_size - 1] = val;
            }
            const T pop ()
            {
                const T x = get (size () - 1);
                _size --;
                return x;
            }
        };
    }
}