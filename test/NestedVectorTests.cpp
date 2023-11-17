// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <NestedVectorHard.hpp>

TEST_CASE("NestedVector_BasicExample") {

    //std::cout << "testing the cout function." << std::endl;

    NestedVectorHard v(3);
    //REQUIRE(v.depth() == 2);

    // Test reserving and appending


    v.reserve(3, 2); // Reserve space for items at the outer level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;
    std::cout << "m_tree[] size: " << v.m_tree.size() << std::endl;

    v.reserve(2, 2); // Reserve space for two items at the next slot in the inner level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

     v.reserve(1, 2); // Reserve space for two items at the next slot in the inner level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;


    std::vector<double> data1 = {4,3,5,1,2};
    v.append(data1);

    for (auto itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl;


    std::vector<double> data2 = {9,8,7,6,5};
    v.append(data2);

    for (auto itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl;


    v.reserve(1, 2); // Reserve space for two items at the next slot in the inner level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;


    TensorIndices data4({5,4});
    std::cout << "data4 dimensions: " << data4.get_dim_count() << std::endl;
    std::vector<double> data3 = {2.2, 4.4, 5.5, 1.2, 5.9};
    v.append(data3);

    std::cout << "m_data[] = ";
    for (auto itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl;


    std::cout << "m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;


}

//TEST_CASE("NestedVector_AnotherExample") {

//}


