#include "MagicalContainer.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>

bool isprime(int num){
    bool is_prime = true;

    // 0 and 1 are not prime numbers
    if (num == 0 || num == 1) {
        is_prime = false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}


namespace ariel {
    /*--------------------------------------MAGICAL-CONTAINER-------------------------------------*/
    MagicalContainer::MagicalContainer::~MagicalContainer(){
    }

    MagicalContainer::MagicalContainer::MagicalContainer(){
    }

    int MagicalContainer::MagicalContainer::operator[](size_t index)const{
        int res;
        if (index>=magical_vector. size()) {
            throw std::runtime_error("index out of bound");
        }

        
        return magical_vector.at(index);     
    }

    vector<int> MagicalContainer::getElements() const
    {
        return magical_vector;
    }

    void MagicalContainer::MagicalContainer::addElement(int element){
        this->magical_vector.push_back(element);
        std::sort(magical_vector.begin(),magical_vector.end());

        prime_vector.clear();
        for (size_t i=0;i<magical_vector.size();i++) {
            if (isprime(magical_vector.at(i))) {
                prime_vector.push_back(&magical_vector.at(i));
            }  
        }
        
            
    }

    void MagicalContainer::MagicalContainer::removeElement(int element){
        bool found=false;
        for(auto it=magical_vector.begin();it!=magical_vector.end();++it){
            if (*it==element) {
                magical_vector.erase(it);
                found=true;
            }
        }
        for(auto it=prime_vector.begin();it!=prime_vector.end();++it){
            if (**it==element) {
                prime_vector.erase(it);
                found=true;
            }
        }
        if (!found) {
            throw std::runtime_error("the number does not exist");
        }

    }

    

    size_t MagicalContainer::size()const{
        return this->magical_vector.size();
    }

 /*------------------------------------------Ascending-Iterator--------------------------------------*/
    MagicalContainer::AscendingIterator::~AscendingIterator(){}
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magicalcontainer)
    :container(magicalcontainer),position(0){}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magicalcontainer,size_t position)
    :container(magicalcontainer),position(position){}
    
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& ascending)
    :container(ascending.container),position(ascending.position){}

  

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::
    operator=(const AscendingIterator & other){
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this!= &other) {
            container=other.container;
            position=other.position;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const{
        return !(*this==other);
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other)const{
        return &container==&other.container && position==other.position;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator & other)const{
        return this->position>other.position;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator & other)const{
        return this->position<other.position;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return container[position];
    }

    MagicalContainer::AscendingIterator & MagicalContainer::AscendingIterator::operator++(){
        if (*this==end() || position>=container.size()) {
            throw runtime_error(" out of bounds!!");
        }
        position++;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return AscendingIterator(container,0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        return AscendingIterator(container,this->container.size());

    }



 /*------------------------------------------SideCross-Iterator--------------------------------------*/

    MagicalContainer::SideCrossIterator::~SideCrossIterator(){

    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer)
    :container(magicalContainer),position(0) {
        reverse_position=magicalContainer.size()-1;
     
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer,size_t position)
    :container(magicalContainer),position(position) {
        reverse_position=magicalContainer.size()-1;
    }

    

    

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this != &other)
        {
            container = other.container;
            position = other.position;
        }
        return *this;
    }
   
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator & other)const{
        return !(*this==other);
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator & other)const{
        return &container == &other.container && position == other.position;
    }
    
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator & other)const{
        return position>other.position;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator & other)const{
        return position<other.position;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        if (position%2==0) {
            return container[position/2];
        
        }
        return container[reverse_position];
    }

    MagicalContainer::SideCrossIterator & MagicalContainer::SideCrossIterator::operator++(){
        if (*this==end() || position>=container.size()) {
            throw std::runtime_error("index out of bound");
        }
        if (position%2!=0) {
            reverse_position--;
        
        }
        position++;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        return SideCrossIterator(container,0);

    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        return SideCrossIterator(container,container.size());

    }


/*------------------------------------------PRIME-Iterator------------------------------------*/
    MagicalContainer::PrimeIterator::~PrimeIterator(){

    }
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer)
    :container(magicalContainer),position(0) {
        
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer,size_t position)
    :container(magicalContainer),position(position) {
     
    }

    
   

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (&container != &other.container)
        { // throw error if we try to assign different containers
            throw runtime_error(" they belong to different containers.");
        }
        if (this != &other)
        {
            container = other.container;
            position = other.position;
        }
        return *this;
    }
    
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other)const{
        return !(*this==other);

    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other)const{
        return &container == &other.container && position == other.position;

    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)const{
        return position>other.position;

    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator & other)const{
        return  position<other.position;;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
       return *container.prime_vector.at(position);
    }

    MagicalContainer::PrimeIterator & MagicalContainer::PrimeIterator::operator++(){
        if (*this==end() || position>=container.prime_vector.size()) {
            throw std::runtime_error("out of bounds");
        }
        position++;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return PrimeIterator(container,0);

    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        return PrimeIterator(container,container.prime_vector.size());

    }





}





