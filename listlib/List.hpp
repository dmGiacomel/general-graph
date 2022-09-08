//---------------------------------Classe LIST --------------------------------------------------

//----Cada lista tem um ponteiro para o nó inicial, um ponteiro para o nó final e um campo tamanho

//----classe com getters, setters e métodos espécíficos de manipulação de lista
//----construtor padrao e destrutor padrao
//----nem todos os métodos foram definidos e declarados ainda, apenas os necessários para as finalidades do trabalho 

//----IFNDEF para prevenir múltiplos includes

//CUIDADO AO UTILIZAR O PRINT- pode não funcionar pra todo tipo de dado.

//________OBS: classes que utilizam template não podem ter assinaturas e definições em arquivos diferentes
//------------------------------------------------------------------------------------------------

#ifndef LIST_H
#define LIST_H
#include "Node.hpp"
#include <iostream>

//*******************************************************************************
//------------DECLARACAO DA CLASSE, METODOS E ATRIBUTOS------------------------
//*******************************************************************************
template <typename datatype> 
class List{

private: 
    Node <datatype> *first;
    Node <datatype> *last;
    unsigned long long int size;

    Node<datatype> *getNodeByElementValue();
    Node<datatype> *getFirst();
    Node<datatype> *getLast();

public:
    List();
    ~List();
 
    void setFirst(Node<datatype> *node);
    void setLast(Node<datatype> *node);
    unsigned long long int getSize();

    void append(datatype data);
    void insertFirst(datatype data);
    void insertFirstList(List<datatype> *list);
    void appendList(List<datatype> *list);
    void insertElementIntoPosition(datatype data, unsigned long long int position);

    datatype getElementByPosition(unsigned long long int position);

    bool elementExists(datatype data);
    void deleteElementIfExists();

    datatype removeFirst();
    datatype removeLast();

    void printList();

};


//*************************************************************************
//-----------DEFINICAO DOS METODOS DA CLASSE-------------------------------
//*************************************************************************

//construtor padrao. inicializa uma lista vazia
template <typename datatype>
List<datatype>::List(){
    first = nullptr;
    last = nullptr;
    size = 0;
}

//destrutor padrao. desaloca todos os nós
template <typename datatype>
List<datatype>::~List(){
    Node <datatype> *aux = first;

    while (aux != nullptr){
        first = first->getNext();
        delete(first);
        aux = first;
    }
}

//seta o campo first para o ponteiro para nó recebido
template <typename datatype>
void List<datatype>::setFirst(Node<datatype> *node){
    first = node;
}


template <typename datatype>
Node<datatype>* List<datatype>::getFirst(){
    return first;
}

template <typename datatype>
Node<datatype>* List<datatype>::getLast(){
    return last;
}

//seta o campo last para o ponteiro para nó recebido
template <typename datatype>
void List<datatype>::setLast(Node<datatype> *node){
    last = node;
}

//retorna o valor do campo size
template <typename datatype>
unsigned long long int List<datatype>::getSize(){
    return size;
}

//insere data no início da lista
template <typename datatype>
void List<datatype>::insertFirst(datatype data){

    Node<datatype> *aux = new Node<datatype>(data, nullptr, first);

    if(size > 0){
        first->setPrev(aux);
        first = aux;
    }else{
        first = aux;
        last = aux;
    }

    size++;
}

//insere data no fim da lista
template <typename datatype>
void List<datatype>::append(datatype data){
   
    Node<datatype> *aux = new Node<datatype>(data, last, nullptr);

    if(size > 0){
        last->setNext(aux);
        last = aux;
    }else{
        last = aux; 
        first = aux;
    }

    size++;
    
}

//remove o item à esquerda da lista e retorna o valor do item removido
template <typename datatype>
datatype List<datatype>::removeFirst(){

    datatype data;
    Node<datatype> *aux;

    if(first != nullptr){
        data = first->getData();
        aux = first;
        first = first->getNext();
        delete(aux);
        
        if(first == nullptr){
            last = nullptr;
        }else{
            first->setPrev(nullptr);
        }
    }else{
        data = 0;
        std::cout << "Empty List! Returning default <datatype> 0 value...\n";
    }

    size--;

    return data;
}

template <typename datatype>
datatype List<datatype>::removeLast(){

    datatype data;
    Node<datatype> *aux;

    if(last != nullptr){
        data = last->getData();
        aux = last;
        last = last->getPrev();
        delete(aux);
        
        if(last == nullptr){
            first = nullptr;
        }else{
            last->setNext(nullptr);
        }
    }else{
        data = 0;
        std::cout << "Empty List! Returning default <datatype> 0 value...\n";
    }

    size--;

    return data;
}


//printa a lista usando cout
//CUIDADO AO UTILIZAR - pode não funcionar pra todo tipo de dado.
template <typename datatype>
void List<datatype>::printList(){

    Node<datatype> *aux = first;
    unsigned long long int cont{0};

    if(size == 0){
        std::cout << "[]" << std::endl;
    }else{

        std::cout << "[";
        while(cont < size - 1){
            
            std::cout << aux->getData() << ", "; 
            aux = aux->getNext();
            cont++;
        }
        std::cout << aux->getData() << "]" << std::endl; 
    }
}

//DECISÃO DE PROJETO: isso é diferente de concatenação. A lista copiada será item por item 
//adicionada à nova lista pelo fim e pelo começo.
template <typename datatype>
void List<datatype>::appendList(List<datatype> *list){

    unsigned long long int cont = list->size;
    Node<datatype> *aux = list->getFirst();

    while(cont-- > 0){
        append(aux->getData());
        aux = aux->getNext();
    }
}
template <typename datatype>
void List<datatype>::insertFirstList(List<datatype> *list){

    unsigned long long int cont = list->size;
    Node<datatype> *aux = list->getLast();

    while(cont-- > 0){
        insertFirst(aux->getData());
        aux = aux->getPrev();
    }
}

template <typename datatype>
bool List<datatype>::elementExists(datatype data){

    Node<datatype> *aux = first;
    bool exists = false;

    while(aux != nullptr){

        if(aux->getData() == data){
            exists = true;
            break;
        }

        aux = aux->getNext();
    }

    return exists;

}

#endif