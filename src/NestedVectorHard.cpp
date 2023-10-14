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
    }

// new version of findAvailableNode(). Returns the starting index of the next available node in m_tree
auto NestedVectorHard::findAvailableNode(size_t index) {
    if (m_tree[index+1] < m_tree[index])
        return index;
    else 
        index += m_tree[index]+2;
        findAvailableNode(index);
    }


    //indexType AvailableNodeIndex = findNextAvailableNode(startOfTree) 
        // recursive function to find the next available node to branch from in m_tree and return its starting index value. The available node must not be filled to capacity.
    
    // updates values in node to reflect increase in its size.
void NestedVectorHard::incrementNodeSize(AvailableNodeIndex)
{
    m_tree[AvailableNodeIndex+1] += 1; // increment size value in available node by 1.
}



// new version of setAddressOfChild().
auto NestedVectorHard::setAddressOfChild(size_t index) {
    size_t remainingBranches = m_tree[index] - m_tree[index+1]
    size_t indexOfAvailableBranch = m_tree.length() - remainingBranches;
    m_tree[indexOfAvailableBranch] = m_tree.size()+1; // the address of the child node will be one index past the current m_tree size.
}

/**
// OLD Version ::::
sets the child node offset value within the available node.
//auto NestedVectorHard::setAddressOfChildOffset(AvailableNodeIndex) {
        availableBranchIndex = findAvailableBranch(AvailableNodeIndex)  // sub function to retrieve this index??
            // finds index of next available branch in the node
            stepAmount = m_tree[AvailableNodeIndex] - m_tree[AvailableNodeIndex+1]; 
            BranchIndex = m_tree[m_tree.end() - stepAmount];

        m_tree[BranchIndex] = m_tree.length() + 1; // assigns node offset to the previous length of m_tree + 1.
}  
**/ 

void NestedVectorHard::appendNewNodeToMainTree(capacity) {
    // build out empty vector to hold node's data.
    std::vector<size_t> node(count+2);    // creates node with [0,0,0,0,0], pehaps with some constructor.

    // fills the vector with 0s on first initialzation except the first index.
    for (auto nodeIterator : node)
            nodeIterator = 0;
    
    // fills first node index with capacity value
    node[0] = capacity;


    // appends new node values to m_tree. Maybe put this routine towards the bottom after main tree has updated its child offsets. 
    for (auto nodeIterator : node)
        m_tree.push_back(nodeIterator);




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

