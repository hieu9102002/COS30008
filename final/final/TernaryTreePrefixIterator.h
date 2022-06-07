
// COS30008, Final Exam, 2022

#pragma once

#include "TernaryTree.h"

#include <stack>

template<typename T>
class TernaryTreePrefixIterator
{
private:
    using TTree = TernaryTree<T>;
    using TTreeNode = TTree*;
    using TTreeStack = std::stack<const TTree*>;

    const TTree* fTTree;                // ternary tree
    TTreeStack fStack;                  // traversal stack

public:

    using Iterator = TernaryTreePrefixIterator<T>;
       
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);
           
        return old;
    }
       
    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

/////////////////////////////////////////////////////////////////////////
// Problem 4: TernaryTree Prefix Iterator

private:
    
    // push subtree of aNode
    void push_subtrees( const TTree* aNode )
    {
        if (!(*aNode).getRight().empty()) fStack.push(const_cast<TTreeNode>(&(*aNode).getRight()));
        if (!(*aNode).getMiddle().empty()) fStack.push(const_cast<TTreeNode>(&(*aNode).getMiddle()));
        if (!(*aNode).getLeft().empty()) fStack.push(const_cast<TTreeNode>(&(*aNode).getLeft()));
    }

public:
    
	// iterator constructor
    TernaryTreePrefixIterator(const TTree* aTTree):fTTree(aTTree),fStack()
    {
        if(!(*fTTree).empty())
			fStack.push(const_cast<TTreeNode>(fTTree));
    }

	// iterator dereference
    const T& operator*() const
    {
    	return **fStack.top();
    }

    // prefix increment
	Iterator& operator++()
    {

    	TTreeNode lPopped = const_cast<TTreeNode>(fStack.top());
    	fStack.pop();
    	push_subtrees(lPopped);
        return *this;
    }

	// iterator equivalence
    bool operator==(const Iterator& aOtherIter) const { return fTTree == aOtherIter.fTTree && fStack.size() == aOtherIter.fStack.size(); }

	// auxiliaries
	Iterator begin() const
    {
        Iterator lTmp = *this;
        lTmp.fStack = TTreeStack();
        lTmp.fStack.push(const_cast<TTreeNode>(lTmp.fTTree));
        return lTmp;
    }
	Iterator end() const
	{
        Iterator lTmp = *this;
        lTmp.fStack = TTreeStack();
        return lTmp;
	}
};
