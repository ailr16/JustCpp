#include "oop.hpp"

void friend_function(void) {
    AllAccessModifiers a;
    /* This friend function can access to private and protected members */
    (void)a.private1;
    (void)a.protected2;
}

void AllAccessModifiers::public_method1(void) {}
void AllAccessModifiers::private_method1(void) {}
void AllAccessModifiers::protected_method1(void) {}

void AccessModifiersExample::example(void) {
    AllAccessModifiers class1;

    /* Cannot access private and protected members from here: */
    /* Uncommenting these lines will break compilation! */
    //class1.private1;
    //class1.private_method1();
    
    //class1.protected1;
    //class1.protected_method1();

    /* But public members are accessible from here: */
    (void)class1.public1;
    (void)class1.public2;
    class1.public_method1();
    
    AllAccessModifiers_friend class2;
    class2.public_method1();

    friend_function();

    /* This is a default inherited class, all members will be private*/
    AllAccessModifiers_subclass class3;
    class3.public_method1();

    /* This class has public inheritance, so, public members remain public: */
    AllAccessModifiers_subclass_protected class5;
    /* The program has no access to any public member */
    //(void)class5.public1;
}

void AllAccessModifiers_friend::public_method1(void) {
    AllAccessModifiers class1;
    
    /* This friend class can access private and protected members: */
    (void)class1.private1;
    (void)class1.private2;
    class1.private_method1();

    (void)class1.protected1;
    (void)class1.protected2;
    class1.protected_method1();
}

void AllAccessModifiers_subclass::public_method1(void) {
    /* This sub-class has access only protected, no private:*/
    (void)protected1;
    (void)protected2;
    protected_method1();
}

int PolymorphismDerived1::publicMethod1(int a) {
    return privateMethod1(a);
}

int PolymorphismDerived1::privateMethod1(int a) {
    return a * 2;
}

int PolymorphismExample::example(int a) {
    /* PolymorphismBase cannot be instantiated due it's an abstract class */
    //PolymorphismBase class1;
    PolymorphismDerived1 class2;
    return class2.publicMethod1(a);
}

int AbstractionDerived::method(int a) {
    return a*3;
}

int AbstractionExample::example(int a) {
    AbstractionDerived class1;

    return class1.method(a);
}

MoveConstructor::MoveConstructor(int a) {
    private1 = new int(a);
}

MoveConstructor::MoveConstructor(MoveConstructor&& a) {
    private1 = a.private1;
    a.private1 = nullptr;
}

MoveConstructor::~MoveConstructor() {
    if(private1 != nullptr)
        delete private1;
}

int MoveConstructor::getData() {
    if(private1 == nullptr)
        return 0;

    return *private1;
}

CopyConstructor::CopyConstructor(int a) {
    private1 = a;
}

CopyConstructor::CopyConstructor(const CopyConstructor& a) {
    private1 = a.private1;
}

int CopyConstructor::getData(void) {
    return private1;
}

std::pair<int, int> ConstructorsExample::example(ConstructorType type, int value) {
    std::pair<int, int> result;
    DefaultContructor class1(value);

    MoveConstructor class2(value);
    MoveConstructor class3 = std::move(class2);

    CopyConstructor class4(value);
    CopyConstructor class5(class4);

    switch(type){
        case ConstructorsExample::ConstructorType::c_default:
            result.first = class1.testClass() * 4;
            result.second = 0;
            break;

        case ConstructorsExample::ConstructorType::c_move:
            result.first = class3.getData() * 4;
            result.second = class2.getData();   // Must be zero
            break;
        
        case ConstructorsExample::ConstructorType::c_copy:
            result.first = class4.getData();
            result.second = class5.getData();
            break;

        default:
            result.first = 0;
            result.second = 0;
    }

    return result;
}