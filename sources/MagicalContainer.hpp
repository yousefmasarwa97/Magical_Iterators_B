#pragma once

#include <cstddef>
#include <vector>

using namespace std;

namespace ariel {
    class MagicalContainer{
        private:
        vector<int> magical_vector;
        vector<int*> prime_vector;

        public:
        ~MagicalContainer();
        MagicalContainer();
       


        void addElement(int);
        void removeElement(int);
        size_t size() const;
        int operator[](size_t)const;
        //vector<int> sort();
        vector<int> getElements() const;

        class AscendingIterator{
            private:
            MagicalContainer &container;
            size_t position;

            public:
            AscendingIterator();
            ~AscendingIterator();
            AscendingIterator operator&(AscendingIterator &&) = delete;
            AscendingIterator(MagicalContainer& container);
            AscendingIterator(MagicalContainer& container,size_t current_index);
            AscendingIterator(const AscendingIterator&);
            


            AscendingIterator &operator=(const AscendingIterator& );
            bool operator==(const AscendingIterator&)const;
            bool operator!=(const AscendingIterator&)const;
            bool operator>(const AscendingIterator&)const;
            bool operator<(const AscendingIterator&)const;
            int operator*() const;
            

            AscendingIterator &operator++();

            AscendingIterator begin();
            AscendingIterator end();

      




        };

        class SideCrossIterator{
            private:
            
            MagicalContainer &container;
            size_t position;
            size_t reverse_position;


            public:
            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(MagicalContainer& container,size_t current_index);
            SideCrossIterator();
            
            ~SideCrossIterator();


            SideCrossIterator &operator=(const SideCrossIterator& );
            bool operator==(const SideCrossIterator&)const;
            bool operator!=(const SideCrossIterator&)const;
            bool operator>(const SideCrossIterator&)const;
            bool operator<(const SideCrossIterator&)const;
            int operator*() const;

            SideCrossIterator& operator++();

            SideCrossIterator begin();
            SideCrossIterator end();

           
            SideCrossIterator operator&(SideCrossIterator &&) = delete;
        };

        
        class PrimeIterator{
            private:
            
            MagicalContainer &container;
            size_t position;


            public:
            PrimeIterator(MagicalContainer& container);
            PrimeIterator(MagicalContainer& container,size_t current_index);
            PrimeIterator();
            ~PrimeIterator();


            PrimeIterator &operator=(const PrimeIterator& );
            bool operator==(const PrimeIterator&)const;
            bool operator!=(const PrimeIterator&)const;
            bool operator>(const PrimeIterator&)const;
            bool operator<(const PrimeIterator&)const;
            int operator*() const;

            PrimeIterator& operator++();

            PrimeIterator begin();
            PrimeIterator end();

          
            PrimeIterator operator&(PrimeIterator &&) = delete;

            void add(int);
        };

    };
    

}