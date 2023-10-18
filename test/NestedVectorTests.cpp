// Copyright 2023, Jefferson Science Associates, LLC.
// Subject to the terms in the LICENSE file found in the top-level directory.

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <NestedVectorHard.hpp>

TEST_CASE("NestedVector_BasicExample") {

    //std::cout << "testing the cout function." << std::endl;

    NestedVectorHard v(2);
    REQUIRE(v.depth() == 2);

    // Test reserving and appending

    // std::cout << "m_tree[] size: " << v.m_tree.size() << std::endl;

    v.reserve(0, 3); // Reserve space for three items at the outer level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;
    std::cout << "m_tree[] size: " << v.m_tree.size() << std::endl;


    v.reserve(1, 3); // Reserve space for three items at the next slot in the inner level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;
    // std::cout << "available node: " << v.findAvailableNode() << std::endl;
    std::cout << "m_tree[] size: " << v.m_tree.size() << std::endl;

    v.append(7.7); 
    std::cout << "appended 7.7 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 


    v.append(7.7);
    std::cout << "appended 7.7 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl; 

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 


    v.append(7.7); 
     std::cout << "appended 7.7 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 

    

    v.reserve(1, 2); // Reserve space for two items at the next slot in the inner level
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    v.append(7.7); 
    std::cout << "appended 7.7 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 

    v.append(1.9);
    std::cout << "append 1.9 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 


    v.reserve(1, 2); // Reserve space for two items at the next slot in the inner level. The tree should now be full.
    std::cout << "reserved node on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;


     v.append(5.7); 
    std::cout << "appended 5.7 on m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 

    v.append(9.9);
    std::cout << "appended 9.9 at m_tree[] = ";
    for (auto itr : v.m_tree)
        std::cout << itr << ",";
    std::cout << std::endl;

    std::cout << "m_data[] = ";
    for (size_t itr : v.m_data)
        std::cout << itr << ",";
    std::cout << std::endl; 


    

    // Test that our NestedVector understands its own sizes

    REQUIRE(v.size({}) == 3);
    REQUIRE(v.size({0}) == 3);
    REQUIRE(v.size({1}) == 2);
    REQUIRE(v.size({2}) == 1);

    // Test that we can correctly retrieve data

    REQUIRE(v.get({0,0}) == 7.7);
    REQUIRE(v.get({1,1}) == 0.8);
    REQUIRE(v.get({2,0}) == 3.141592);

}

TEST_CASE("NestedVector_AnotherExample") {

}


