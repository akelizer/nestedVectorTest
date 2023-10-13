// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#include "TensorIndices.hpp"
#include <vector>

class NestedVectorHard {
private:
    size_t m_depth;// Indicates the height of the tree.
    // TODO: Add data structures here!
    std::vector <double> v;
    double m_data[];

public:
    NestedVectorHard(size_t depth);

    size_t depth();
    size_t size(const TensorIndices& indices);

    double get(const TensorIndices& indices);
    void reserve(size_t level, size_t count);
    void append(double data);
};


