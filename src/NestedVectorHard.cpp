// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#include <NestedVectorHard.hpp>

NestedVectorHard::NestedVectorHard(size_t depth) : m_depth(depth) {
}

double NestedVectorHard::get(const TensorIndices& indices) {
    // TODO: Implement me!
    // Retrieve data from m_data by referencing NestedVector nodes. Nodes will point to corresponding elements in m_data

    return 0.0;
}

void NestedVectorHard::reserve(size_t level, size_t count) {
    // TODO: Implement me!
    // After some thinking, this function may need to have recursive controls in order to update the nodes along the tree in addition to appending m_tree
    
    if (m_depth - 1 <= level)
    m_level = level;
    else   
        return error "out of depth";

    std::vector<size_t> node(count+2);    // creates node with [3,0,0,0,0], pehaps with some constructor.
    std::vector<size_t>::iterator nodeIterator;

    //append m_tree with newly created node
    int size = node.size();

    
    // maybe some vector initialization function?
    nodeIterator = node.begin();
    *nodeIterator = count;

    // fills the vector with 0s on first initialzation except the first index.
    for (nodeIterator = node.begin()+1; nodeIterator != node.end(); nodeIterator++)
        *nodeIterator = 0; // fills the vector with 0s on first initialzation except the first index.
    
    // appends m_tree with new node values
    for (nodeIterator = node.begin(); nodeIterator != node.end(); nodeIterator++)
        m_tree->push_back(*nodeIterator);



    //need to delete node



}

void NestedVectorHard::append(double data) {

    m_data.push_back(data); // append m_data vector with a value provided
    m_tree.insert(currentNodeAndBranch(), m_data.size()-1) // stores the index of m_data[] into the appropriate node value within m_tree

}

size_t NestedVectorHard::depth() {
    return m_depth;
}

size_t NestedVectorHard::size(const TensorIndices& indices) {
    // TODO: Implement me!

    return 0;
}

