#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H
#include "Iterators.h"
    
    
    template<typename T>
    class  IteratorForward:public Iterator<T>
    {
    private:
        typedef T node_t;
	    typedef typename node_t::value_t value_t;

    protected:
	node_t * pointer; 

    public:
         IteratorForward(node_t* _pointer = nullptr):pointer(_pointer){};
        ~ IteratorForward();
        
        virtual value_t& operator* (void) {
		return **pointer;
	    }   


        Iterator<T>& operator++(void) const{
            
        }
        Iterator<T>& operator++(int) const{

        }

        Iterator<T>& operator--(void) const{

        }
        
        Iterator<T>& operator--(int) const{
            
        }

        virtual bool operator == (const Iterator<T>&) const{
            return pointer == 
        }
        virtual bool operator != (const Iterator<T>&) const{
            
        }
        virtual bool operator <= (const Iterator<T>&) const{

        }
        virtual bool operator >= (const Iterator<T>&) const{

        }
        virtual bool operator < (const Iterator<T>&) const{

        }
        virtual bool operator > (const Iterator<T>&) const{

        }

    };
    
     
    
    



 #endif