
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

template<typename T>
class DoublyLinkedList
{
private:
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;
    
public:
    // l-value constructor and r-value constructor
    explicit DoublyLinkedList(const T& aPayload) :
        fPayload(aPayload),
        fNext(this),
		fPrevious(this)
    {}
    explicit DoublyLinkedList( T&& aPayload ) :
		fPayload(std::move(aPayload)),
		fNext(this),
		fPrevious(this)
    {}

    // link functions
    DoublyLinkedList& push_front( DoublyLinkedList& aNode )
    {
        aNode.fNext = this;
        aNode.fPrevious = fPrevious;
        fPrevious->fNext = &aNode;
        fPrevious = &aNode;

        return *this;
    }
    DoublyLinkedList& push_back( DoublyLinkedList& aNode )
    {
        aNode.fNext = fNext;
        aNode.fPrevious = this;
        fNext->fPrevious = &aNode;
        fNext = &aNode;


        return *this;
    }

    // unlink list node
    void isolate()
    {
        fNext->fPrevious = fPrevious;
        fPrevious->fNext = fNext;
        fNext = this;
        fPrevious = this;
    }
    
    // exchance payload positions of list nodes
    void swap( DoublyLinkedList& aNode )
    {
        std::swap(aNode.fPayload, fPayload);
    }
    
    // getters
    const T& operator*() const
    {
        return fPayload;
    }

    const T& getPayload() const
    {
        return *(*this);
    }
    const DoublyLinkedList& getNext() const
    {
        return *fNext;
    }
    const DoublyLinkedList& getPrevious() const
    {
        return *fPrevious;
    }
};
