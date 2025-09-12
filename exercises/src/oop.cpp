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