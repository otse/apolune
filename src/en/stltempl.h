/* 
 * File:   stltempl.h
 * Author: Petrus
 *
 * Created on January 11, 2015, 3:40 PM
 */

#ifndef STLTEMPL_H
#define	STLTEMPL_H

template<class T> struct Reorder;

// todo: barf.. burn it.. burn it all to the ground.. Sept 2016
template<class T> struct Vector {
public:
	std::vector<T> v;
	
};

// Situations where you want to insert a lot of items into the middle of a sequence repeatedly.
template<class T> struct List {
public:
	std::list<T> l;
	bool resort = false;
};

template<typename T> struct Reorder
{
	bool operator()(const T a, const T b) const {
	   return a->order < b->order;
	}
};

// Functor for deleting pointers in vector.
template<class T> class DeleteVector
{
	public:
	// Overloaded () operator.
	// This will be called by for_each() function.
	bool operator()(T x) const
	{
		// Delete pointer.
		delete x;
		return true;
	}
};

#endif	/* STLTEMPL_H */

