
// COS30008, Tutorial 11, 2022

#pragma once

#include <stdexcept>
#include <algorithm>

template<typename T>
class BTree
{
private:
    T fKey;                                         // T() for empty BTree
    BTree<T>* fLeft;
    BTree<T>* fRight;
    
    BTree() :fLeft(&NIL), fRight(&NIL),fKey(T()) {}                                       // sentinel constructor

    // tree manipulator auxiliaries
    void attach( BTree<T>** aNode, const BTree<T>& aBTree );
    const BTree<T>& detach( BTree<T>** aNode );

public:
    static BTree<T> NIL;                          	// Empty BTree
    
    BTree( const T& aKey ):fKey(aKey), fLeft(&NIL), fRight(&NIL){}                         // BTree leaf
    BTree( T&& aKey ) :fKey(std::move(aKey)), fLeft(&NIL), fRight(&NIL) {}                              // BTree leaf

    BTree( const BTree& aOtherBTree ):fKey(T()),fLeft(&NIL),fRight(&NIL)
    {
        *this = aOtherBTree;
    }              // copy constructor
    BTree(BTree&& aOtherBTree) :fKey(T()), fLeft(&NIL), fRight(&NIL)
	{
        *this = std::move(aOtherBTree);
    }// move constructor
    
    virtual ~BTree()
    {
        if (!fLeft->empty()) delete fLeft;
        if (!fRight->empty()) delete fRight;
    }                               // destructor
    
    BTree& operator=( const BTree& aOtherBTree )
    {
	    if (this != &aOtherBTree)
	    {
            if (aOtherBTree.empty()) throw std::domain_error("Copying of NIL detected.");
            this->~BTree();
            fKey = aOtherBTree.fKey;

            if (aOtherBTree.fLeft->empty()) fLeft = &NIL;
            else fLeft = aOtherBTree.fLeft->clone();

            if (aOtherBTree.fRight->empty()) fRight = &NIL;
            else fRight = aOtherBTree.fRight->clone();
	    }
        return *this;
    }   // copy assignment operator
    BTree& operator=( BTree&& aOtherBTree )
    {
        if (this != &aOtherBTree)
        {
            if (aOtherBTree.empty()) throw std::domain_error("Copying of NIL detected.");
            this->~BTree();
            fKey = std::move(aOtherBTree.fKey);

            if (aOtherBTree.fLeft->empty()) fLeft = &NIL;
            else fLeft = const_cast<BTree<T>*>(&aOtherBTree.detachLeft());

            if (aOtherBTree.fRight->empty()) fRight = &NIL;
            else fRight = const_cast<BTree<T>*>(&aOtherBTree.detachRight());
        }
        return *this;
    }        // move assignment operator
    
#ifdef Clone
    virtual BTree* clone()
    {
        if (!empty()) return new BTree(*this);
        throw std::domain_error("Cloning of NIL detected");
    }                   		// clone a tree
#endif
    
    bool empty() const { return this == &NIL; }                             // is tree empty
    const T& operator*() const { return fKey; }                     // get key (node value)
    
    const BTree& left() const
    {
        if (empty()) throw std::domain_error("Empty BTree!");
	    return *fLeft;
    }
    const BTree& right() const {
        if (empty()) throw std::domain_error("Empty BTree!");
        return *fRight;
    }
    
    // tree manipulators
    void attachLeft( const BTree<T>& aBTree )
    {
        if (fLeft->empty()) fLeft = const_cast<BTree<T>*>(&aBTree);
        else throw std::domain_error("Non-empty subtree present!");
    }
    void attachRight( const BTree<T>& aBTree )
    {
        if (fRight->empty()) fRight = const_cast<BTree<T>*>(&aBTree);
        else throw std::domain_error("Non-empty subtree present!");
    }
    const BTree& detachLeft()
    {
        if (fLeft->empty()) throw std::out_of_range("Empty subtree");
        const BTree<T>& Result = *fLeft;
        fLeft = &NIL;
        return Result;
    }
    const BTree& detachRight()
    {
        if (fRight->empty()) throw std::out_of_range("Empty subtree");
        const BTree<T>& Result = *fRight;
        fRight = &NIL;
        return Result;
    }
};

template<class T>
BTree<T> BTree<T>::NIL;
