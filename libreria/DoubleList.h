
#ifndef DOUBLELIST
#define DOUBLELIST
#include "./DoubleListNode.h"
#include "./List.h"

template <typename T>
class DoubleList : public List<T>{
protected:
    DoubleListNode<T> *tail;
public:
    DoubleList(DoubleList &copia) : List<T>(copia)
    {

    }
    DoubleList(T* arreglo, int size) : List<T>(arreglo, size)
    {

    }
    DoubleList(Node<T>* copia) : List<T>(copia)
    {

    }
    DoubleList(int numero_elementos) : List<T>(numero_elementos)
    {

    }
    DoubleList()
    {
        List<T>::head = NULL;
        tail = NULL;
    }
    T front(void)
    {
        if(List<T>::head){
            return List<T>::head->get_value();
        }
        return 0;
    }
    T back(void)
    {
        if(tail){
            return tail->get_value();
        }
        return 0;
    }

    void push_back(const T& element)
    {
        DoubleListNode<T> *nuevo = new DoubleListNode<T>;
        nuevo->set_value(element);

        if(List<T>::head!=NULL){
            tail->next = nuevo;
            nuevo->next = NULL;
            nuevo->prev = tail;
            tail = nuevo;
        }else{
            List<T>::head = nuevo;
            ((DoubleListNode<T>*)List<T>::head)->next = NULL;
            ((DoubleListNode<T>*)List<T>::head)->prev = NULL;
            tail = (DoubleListNode<T>*)List<T>::head;
        }
    }
    void push_front(const T& element)
    {
        DoubleListNode<T> *nuevo = new DoubleListNode<T>;
        nuevo->set_value(element);

        if(List<T>::head!=NULL){

            ((DoubleListNode<T>*)List<T>::head)->prev = nuevo;
            nuevo->next = (DoubleListNode<T>*)List<T>::head;
            List<T>::head = nuevo;

        }else{
            List<T>::head = nuevo;
            ((DoubleListNode<T>*)List<T>::head)->next=NULL;
            ((DoubleListNode<T>*)List<T>::head)->prev=NULL;
            tail = (DoubleListNode<T>*)List<T>::head;
        }
    }

    Node<T>* pop_back(void)
    {
        if(List<T>::head==NULL && tail==NULL){
            return NULL;
        }
        else if(List<T>::head!=NULL && tail!=NULL){
            DoubleListNode<T> *borrar;
            DoubleListNode<T> temp;
            borrar = tail;
            tail = (DoubleListNode<T>*)tail->prev;
            tail->next = NULL;
            temp = *borrar;
            delete borrar;
            return &temp;
        }
    }
    Node<T>* pop_front(void)
    {
        if(List<T>::head!=NULL && tail!=NULL){
            DoubleListNode<T> *borrar;
            DoubleListNode<T> temp;

            borrar = (DoubleListNode<T>*)List<T>::head;
            List<T>::head = ((DoubleListNode<T>*)List<T>::head)->next;
            temp = *borrar;
            delete borrar;
            return &temp;
        }else{
            return NULL;
        }
    }

    T& operator[] (const int& posicion)
    {
        if(List<T>::head){
            int temp1;
            DoubleListNode<T> *aux1 = (DoubleListNode<T>*)List<T>::head;
            for(int i = 0; i < posicion; i++){
                aux1 = (DoubleListNode<T>*)aux1->next;
            }
            temp1 = aux1->get_value();
            return temp1;
            std::cout<<"  ";
        }
        if(tail){
            int temp2;
            DoubleListNode<T> *aux2 = tail;
            for(int i = 0; i < posicion; i++){
                aux2 = (DoubleListNode<T>*)aux2->prev;
            }
            temp2 = aux2->get_value();
            return temp2;
        }
    }

    bool empty(void)
    {
        if(List<T>::head!=NULL && tail!=NULL){
            return true;
        }else{
            return false;
        }
    }
    unsigned int size(void)
    {
        unsigned int size=0;
        DoubleListNode<T> *temp = (DoubleListNode<T>*)List<T>::head;
        while(temp!=NULL){
            size++;
            temp=(DoubleListNode<T>*)temp->next;
        }
        return size;
    }
    void clear(void)
    {
        DoubleListNode<T> *aux = (DoubleListNode<T>*)List<T>::head;

        while(List<T>::head!=NULL) {
            List<T>::head = ((DoubleListNode<T>*)List<T>::head)->next;
            delete aux;
            aux=(DoubleListNode<T>*)List<T>::head;
        }
        tail = NULL;
    }

    void erase(Node<T>* element)
    {
        ForwardListNode<T> *temp = (ForwardListNode<T> *)List<T>::head;
        if(List<T>::head == element){
            List<T>::head = ((DoubleListNode<T> *)List<T>::head)->next;
            delete element;
        }
        else if(tail == element){
            tail = (DoubleListNode<T> *)tail->prev;
            delete element;
        }else{
            while(temp->next!= element){
                temp = (ForwardListNode<T> *)temp->next;
            }
            ForwardListNode<T> *temp1 = temp;
            temp1->next=((ForwardListNode<T> *)temp->next)->next;
            delete temp->next;
        }
    }
    void insert(Node<T>* element, const T& position)
    {
        DoubleListNode<T> *temp = (DoubleListNode<T>*)List<T>::head;

        if(position<=size()) {
            if(position == 0) {
                ((DoubleListNode<T>* )element)->next = (DoubleListNode<T>*)List<T>::head;
                ((DoubleListNode<T>* )element)->prev = NULL;
                ((DoubleListNode<T>*)temp)->prev = (DoubleListNode<T>* )element;
                List<T>::head = (DoubleListNode<T>* )element;
            }
            for (int i = 0; i < position ; i++) {
                temp = (DoubleListNode<T>* )temp->next;

                if (i == position-1) {
                    ((DoubleListNode<T>*)element)->prev = (DoubleListNode<T>*)temp->prev;
                    ((DoubleListNode<T>* )temp->prev)->next = (DoubleListNode<T>* )element;
                    ((DoubleListNode<T>* )element)->next=temp;
                    ((DoubleListNode<T>* )temp)->prev = (DoubleListNode<T>* )element;
                }
            }
        }
    }
    void drop(const T& item)
    {
        DoubleListNode<T>* aux1 = (DoubleListNode<T>*)List<T>::head;
        DoubleListNode<T>* aux2;

        while(aux1->next!=NULL){
            aux2 = aux1;
            aux1 = (DoubleListNode<T>* )aux1->next;

            if(aux2->get_value() == item) {
                if(aux2->prev != NULL) {
                    ((DoubleListNode<T>* )aux2->prev)->next = (DoubleListNode<T>* )aux2->next;
                    ((DoubleListNode<T>* )aux2->next)->prev = (DoubleListNode<T>* )aux2->prev;
                }else{
                    List<T>::head = ((DoubleListNode<T>* )List<T>::head)->next;
                    ((DoubleListNode<T>* )aux2->next)->prev = NULL;
                }
                delete aux2;
            }
        }
    }

    List<T>& sort(void)
    {

    }
    List<T>& reverse(void)
    {
        DoubleListNode<T> *aux1 = (DoubleListNode<T>*)List<T>::head;

        List<T>::head = tail;
        tail = aux1;

        DoubleListNode<T> *temp1;
        DoubleListNode<T> *temp2;

        temp1 = (DoubleListNode<T>*)aux1->next;
        ((DoubleListNode<T>*)List<T>::head)->next = aux1;
        ((DoubleListNode<T>*)List<T>::head)->prev=NULL;
        aux1->next=NULL;
        aux1->prev = (DoubleListNode<T>*)List<T>::head;

        while(temp1!=List<T>::head){
            temp2 = temp1;
            temp1 = (DoubleListNode<T>*)temp1->next;
            temp2->prev = (DoubleListNode<T>*)List<T>::head;
            ((DoubleListNode<T>*)List<T>::head)->next = temp2;
            temp2->next = aux1;
            aux1->prev=temp2;
            aux1=temp2;
        }
        return *this;
    }

};

#endif

