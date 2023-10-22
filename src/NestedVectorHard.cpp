// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#include <NestedVectorHard.hpp>
#include <optional>

NestedVectorHard::NestedVectorHard(size_t depth) : m_depth(depth) {
}

double NestedVectorHard::get(const TensorIndices& indices) {
    // Retrieve data from m_data by referencing NestedVector nodes. Nodes will point to corresponding elements in m_data
    size_t node = 0;
    size_t size = indices.get_dim_count();
    for (size_t index = 0; index < size; index++){
        size_t branchIndex = node + 2 + indices.get_index(index);
        node = m_tree[branchIndex];
        if (index == size-1)
            return m_data[node];
    }
    return m_data[node];
    }

// Calls multiple sub functions to do the following: find an available node on the tree, increment the parent node's size counter, set the address of the new child in the parent node, and append the new node to the main tree. 
void NestedVectorHard::reserve(size_t level, size_t count) {
    
   // Tests if m_tree is empty. If so, reserve() will make the root of the tree. 
   if (m_tree.size() == 0)
      appendNewNodeToMainTree(count);

    else {
        std::optional<size_t> availableNodeIndex = findAvailableNode(level, count);
        size_t existingNodeIndex = availableNodeIndex.value();
        incrementNodeSize(existingNodeIndex);
        setAddressOfChild(existingNodeIndex);
        appendNewNodeToMainTree(count); 
        }
    }

/**
 //Finds the starting index of the next available node in m_tree. Returns nullopt if no available node is found.
std::optional<size_t> NestedVectorHard::findAvailableNode(size_t depth, size_t index){
    int treeDepth = depth;
    for (treeDepth; treeDepth >=1; treeDepth--){
        if (nodeIsAvailable(index) && treeDepth != 1)
            return index;
        else{
            treeDepth--;
            size_t firstChild = index + 2;
            size_t lastChildIndex = index + m_tree[index] + 1;
            for (size_t childIndex = firstChild; childIndex <= lastChildIndex; childIndex++){
                auto result = findAvailableNode(treeDepth, m_tree[childIndex]);
                if (result != std::nullopt) 
                    return result;
            }
        return std::nullopt;
        }
    }
    return std::nullopt;
}
**/
bool NestedVectorHard::nodeIsAvailable(size_t index){
    if (m_tree[index+1] < m_tree[index])
        return true;
    else
        return false;
}

std::optional<size_t> NestedVectorHard::findAvailableNode(size_t reserveDepth, size_t index){
  size_t reserveIndex = index;
  size_t currentDepth = m_depth;

  for (currentDepth; currentDepth >= reserveDepth; currentDepth--){
    if (nodeIsAvailable(reserveIndex) && currentDepth == reserveDepth)
        return reserveIndex;
    else
        reserveIndex = getLastChildAddress(reserveIndex);

  }
  return std::nullopt;
}

// Increments the size counter in the node.
void NestedVectorHard::incrementNodeSize(size_t AvailableNodeIndex)
{
    m_tree[AvailableNodeIndex+1] += 1; // increment size value in available node by 1.
}



// Subtracts the remaining branch slots from the last index in the current node to find which index to branch from.
void NestedVectorHard::setAddressOfChild(size_t indexOfNode) {
    size_t remainingBranches = m_tree[indexOfNode] - m_tree[indexOfNode+1];

    //may need to put this line couple in a separate function.
    size_t sizeOfNode = m_tree[indexOfNode] + 1;
    size_t lastIndexOfNode = indexOfNode + sizeOfNode;

    size_t indexOfAvailableBranch = lastIndexOfNode - remainingBranches; // do I actually have control over the size?
    m_tree[indexOfAvailableBranch] = m_tree.size(); // the address of the child node will be one index past the current m_tree size.
}



void NestedVectorHard::setAddressOfLeaf(size_t indexOfNode) {
    size_t remainingBranches = m_tree[indexOfNode] - m_tree[indexOfNode+1];

    //may need to put this line couple in a separate function.
    size_t sizeOfNode = m_tree[indexOfNode] + 1;
    size_t lastIndexOfNode = indexOfNode + sizeOfNode;

    size_t indexOfAvailableBranch = lastIndexOfNode - remainingBranches; 
    m_tree[indexOfAvailableBranch] = m_data.size()-1; // address this element to the last index in m_data[]
}


// Builds out empty vector to hold node's data.
void NestedVectorHard::appendNewNodeToMainTree(size_t capacity) {
    std::vector<size_t> node(capacity+2);    // creates node with [0,0,0,0,0], pehaps with some constructor.

    // fills the vector with 0s.
    for (auto nodeIterator : node)
            nodeIterator = 0;
    
    // fills first node element with capacity value
    node[0] = capacity;


    // appends new node to m_tree.
    for (auto nodeIterator : node)
        m_tree.push_back(nodeIterator);
}

void NestedVectorHard::append(double data) {
    m_data.push_back(data); // append m_data vector with a value provided


    std::optional<size_t> resultIndex = findNodeToAppend();
    size_t availableIndex = resultIndex.value();
    incrementNodeSize(availableIndex);
    setAddressOfLeaf(availableIndex);
}

// Returns the address of an avaialble node at the bottom of the tree. If the current node is not at the appropriate depth, traverse down the last addressed child to the parent and repeat the search. Depth is decremented by 1 each hop down the tree. 1 is the lowest depth for a node, 0 being the level of a leaf.
// Nullopt will be returned if the tree has not been built to reach a nodes at a depth of 1.
std::optional<size_t> NestedVectorHard::findNodeToAppend(size_t index){
    size_t appendIndex = index;
    size_t treeDepth = m_depth;

    for (treeDepth; treeDepth >= 1; treeDepth--){
        if (nodeIsAvailable(appendIndex) && treeDepth == 1)
            return appendIndex;
        else 
            appendIndex = getLastChildAddress(appendIndex);
    }
    return std::nullopt; // exception value if no available nodes.
    }

size_t NestedVectorHard::getLastChildAddress(size_t index){
    size_t sizeIndex = index + 1;
    size_t sizeValue = m_tree[sizeIndex];
    size_t lastChildAddress = m_tree[sizeIndex + sizeValue]; 
    return lastChildAddress;
}


size_t NestedVectorHard::depth() {
    return m_depth;
}

size_t NestedVectorHard::size(const TensorIndices& indices) {
    // TODO: Implement me!
    return 0;
}

