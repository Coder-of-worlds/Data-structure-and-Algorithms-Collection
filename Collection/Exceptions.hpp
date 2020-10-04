namespace Collection
{
    namespace Expection
    {
        #include <exception>
        #include <stdio.h>

        struct OutOfRange : public std::exception
        {
        private:
            std::size_t index, size;
        public: 
            OutOfRange (std::size_t index, std::size_t size)
            {
                this->index = index;
                this->size = size; 
            }
            const char * what () const throw ()
            {
                char* expection = new char [2048];
                sprintf (expection, "Expection: Index is out of range (the index is %zu, the size is %zu)", index, size);
                return expection;
            }
        };

        struct PopingOutOfEmptyCollection : public std::exception
        {
        public: 
            PopingOutOfEmptyCollection ()
            {
            }
            const char * what () const throw ()
            {
                char* expection = new char [2048];
                sprintf (expection, "Expection: Poping out of empty collection is not available.");
                return expection;
            }
        };
    }
}