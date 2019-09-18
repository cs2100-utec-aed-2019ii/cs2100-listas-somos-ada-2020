template<typename T,typename Y>
class Iterator{
  protected:
    T* pointer;

  public:
    virtual Iterator& operator++(void)const=0;
    virtual Iterator& operator++(int)const=0;
    virtual Iterator& operator--(void)const=0;
    virtual Iterator& operator--(int)const=0;
    virtual Y& operator* (void) = 0;
    virtual bool operator == (const Iterator&) const = 0;
    virtual bool operator != (const Iterator&) const = 0;
    virtual bool operator <= (const Iterator&) const = 0;
    virtual bool operator >= (const Iterator&) const = 0;
    virtual bool operator < (const Iterator&) const = 0;
    virtual bool operator > (const Iterator&) const = 0;
};