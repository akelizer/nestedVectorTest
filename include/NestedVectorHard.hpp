// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#include "TensorIndices.hpp"
#include <vector>

class NestedVectorHard {
private:
    /**
    size_t m_depth; // Indicates the height of the tree. where are pointers being directed? The leaves or a node?
    size_t m_level;
    std:: vector<double> m_data;
    std:: vector<int> m_tree;
    **/
    
public:
    NestedVectorHard(size_t depth);

    size_t depth();
    size_t size(const TensorIndices& indices);

    double get(const TensorIndices& indices);
    void reserve(size_t level, size_t count);
    void append(double data);

    size_t findAvailableNode(size_t index = 0);
    bool nodeIsAvailable(size_t index);
    void incrementNodeSize(size_t index);
    void setAddressOfLeaf(size_t index);
    void setAddressOfChild(size_t index);
    void appendNewNodeToMainTree(size_t index);



    size_t m_depth; // Indicates the height of the tree. where are pointers being directed? The leaves or a node?
    size_t m_level;
    std:: vector<double> m_data;
    std:: vector<int> m_tree;
};


