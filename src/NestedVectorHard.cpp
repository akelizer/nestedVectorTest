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


    indexType BranchingNode = findNextAvailableNode(startOfTree) // recursive function to find the next available node to branch from in m_tree and return its starting index value
    
    incrementNodeSize(BranchingNodeIndex)
    // updates values in node to reflect increase in its size. In this test case, it will be root node.
    // std::vector<int>::iterator treeIterator <----- may use iterator to perform operation outside of this specific test case.
        if (m_tree[1] < m_tree[0])
            m_tree[1] += 1; // increment size parameter in parent node
    
    setAddressOfChildOffset(BranchingNodeIndex)
        // sets the child node offset value within the branching node.
        availableBranchIndex = findAvailableBranch(BranchingNodeIndex)
        // finds index of next available branch in the node
        stepAmount = BranchingNodeCapacity - BranchingNodeSize;
        BranchIndex = m_tree[m_tree.end() - stepAmount];

        m_tree[BranchingNodeIndex] = m_tree.length() + 1; // assigns node offset to the previous length of m_tree + 1.
        

    appendNewNodeToMainTree(capacity);
    // build out empty vector to hold node's data.
    std::vector<size_t> node(count+2);    // creates node with [0,0,0,0,0], pehaps with some constructor.
    std::vector<size_t>::iterator nodeIterator;

    // fills the vector with 0s on first initialzation except the first index.
    for (nodeIterator = node.begin()+1; nodeIterator != node.end(); nodeIterator++)
        *nodeIterator = 0; // fills the vector with 0s on first initialzation except the first index.
    
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

