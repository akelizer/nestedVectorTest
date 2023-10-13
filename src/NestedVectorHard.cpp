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
    
    // check if branching is allowed on current tree level
    if (m_depth - 1 <= level)
    m_level = level; // update current level on tree
    else   
        return error "out of depth";


    indexType AvailableNodeIndex = findNextAvailableNode(startOfTree) 
        // recursive function to find the next available node to branch from in m_tree and return its starting index value. The available node must not be filled to capacity.
    
    incrementNodeSize(AvailableNodeIndex)
        // updates values in node to reflect increase in its size.
        m_tree[AvailableNodeIndex+1] += 1; // increment size value in available node by 1.
    
    setAddressOfChildOffset(AvailableNodeIndex)
        // sets the child node offset value within the available node.
        availableBranchIndex = findAvailableBranch(AvailableNodeIndex)  // sub function to retrieve this index??
            // finds index of next available branch in the node
            stepAmount = m_tree[AvailableNodeIndex] - m_tree[AvailableNodeIndex+1]; 
            BranchIndex = m_tree[m_tree.end() - stepAmount];

        m_tree[BranchIndex] = m_tree.length() + 1; // assigns node offset to the previous length of m_tree + 1.
        

    appendNewNodeToMainTree(capacity);
    // build out empty vector to hold node's data.
    std::vector<size_t> node(count+2);    // creates node with [0,0,0,0,0], pehaps with some constructor.
    std::vector<size_t>::iterator nodeIterator;

    // fills the vector with 0s on first initialzation except the first index.
    for (nodeIterator = node.begin(); nodeIterator != node.end(); nodeIterator++){
        if (nodeIterator == node.begin())
            *nodeIterator = capacity;   // puts capacity value into first index of vector.
        else 
            *nodeIterator = 0; // fills the vector with 0's except the first index.
        }
    // appends new node values to m_tree. Maybe put this routine towards the bottom after main tree has updated its child offsets. 
    for (nodeIterator = node.begin(); nodeIterator != node.end(); nodeIterator++)
        m_tree->push_back(*nodeIterator);



    delete node;

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

