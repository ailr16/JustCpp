#include <gtest/gtest.h>
#include "oop.hpp"

TEST(OOP, testAccessModifiers){
    AccessModifiersExample::example();
}

TEST(OOP, testPolymorphism){
    int a = 16;
    ASSERT_EQ(PolymorphismExample::example(a), a*2);
}

TEST(OOP, testAbstraction){
    int a = 1;
    ASSERT_EQ(AbstractionExample::example(a), a*3);
}

TEST(OOP, testConstructors){
    std::pair<int, int> returnedValue;
    int a = 1;

    returnedValue = ConstructorsExample::example(
                        ConstructorsExample::ConstructorType::c_default,
                        a
    );

    ASSERT_EQ(returnedValue.first, a * 4);
    ASSERT_EQ(returnedValue.second, 0);

    returnedValue = ConstructorsExample::example(
                        ConstructorsExample::ConstructorType::c_move,
                        a
    );
    
    ASSERT_EQ(returnedValue.first, a * 4);
    ASSERT_EQ(returnedValue.second, 0);

    returnedValue = ConstructorsExample::example(
                        ConstructorsExample::ConstructorType::c_copy,
                        a
    );
    
    ASSERT_EQ(returnedValue.first, returnedValue.second);
}

TEST(OOP, testStaticMember){
    int a = 4;

    ASSERT_EQ(StaticMembersExample::example(a), a*2);

    a = 44;
    ASSERT_EQ(StaticMembersExample::example(a), a*2);
}

TEST(OOP, testOperatorOverload){
    OpOverload::Complex result;

    result = OpOverload::example();

    std::cout << result << std::endl;

    ASSERT_EQ(result.real, 3);
    ASSERT_EQ(result.imaginary, 3);
}

TEST(OOP, testTemplates){
    Templates::example();
}