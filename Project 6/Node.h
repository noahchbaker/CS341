//Assignment #4: Hop Dawg
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

//================================================
/**
 * @file       Node.h
 *
 * rrybarcz
 */
//================================================

#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <fstream>
#include "HashEntry.h"

/**
 * @class Node
 *
 * Implementation of a Node
 */
class Node
{
	public:
		/// Constructor
		Node(HashEntry entry);

		/// Destructor
		virtual ~Node();

		/// Getters/Setters - Accessor Methods

		/**
		 * Gets the Nodes Integer value.
		 *
		 * @return		Integer
		 */
		virtual HashEntry getValue();

		/**
		 * Sets the value of the Node
		 *
		 * @param[in]          Integer		data
		 */
		void setValue(HashEntry entry);

	private:
		/// Private Attributes

		/// Stores the Integer data value
		HashEntry entry_;

	protected:
		// We need to do this to prevent a Node from being
		// created that has no value.

		/// Constructor (Default)
		Node() {}
};

#endif
