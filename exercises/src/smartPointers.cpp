#include "smartPointers.hpp"

void SmartPointersExamples::autoPtr(void) {
    /*
      Manages the lifetime of dinamically allocated object
      pointer has the ownership of dinamically allocated int
    */

    std::auto_ptr<int> pointer(new int(10));

    std::cout << "Value of pointer: " << *pointer << std::endl;
    std::cout << "auto_ptr address: " << &pointer << std::endl;
    std::cout << "auto_ptr points to: " << pointer.get() << std::endl;
    std::cout << "auto_ptr get value: " << *pointer.get() << std::endl;
}

void SmartPointersExamples::uniquePtr(void) {
    /*
      Cannot copy pointers, only transfer ownership using move().
      This avoids that two pointers share the ownership of an
      object.
    */
    std::unique_ptr<int> pointer(new int(16));

    std::cout << "Value of pointer: " << *pointer << std::endl;

    /* Transfer the ownership to pointer2 */
    std::unique_ptr<int> pointer2 = std::move(pointer);

    /* pointer now points to nullptr, don't attempt dereferencing it */
    //std::cout << "Value of pointer: " << *pointer << std::endl;
    std::cout << "Value of pointer2: " << *pointer2 << std::endl;

}

void SmartPointersExamples::sharedPtr(void) {
    std::shared_ptr<nComplex> ptr1(new nComplex(1, 2));
    std::shared_ptr<nComplex> ptr2;

    std::cout << "ptr1 use count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr1 nComplex: " << ptr1->real << "," << ptr1->imaginary << std::endl;

    ptr2 = ptr1;

    std::cout << "ptr1 use count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr2 nComplex: " << ptr2->real << "," << ptr2->imaginary << std::endl;
}

void SmartPointersExamples::weakPtr(void) {
    std::shared_ptr<nComplex> ptr1(new nComplex(2,3));
    std::weak_ptr<nComplex> ptr2 = ptr1;

    if(auto locked = ptr2.lock()) {
        std::cout << locked->real << "," << locked->imaginary << std::endl;
    }

    /* Release ownership of shared pointer */
    ptr1.reset();

    if(auto locked = ptr2.lock()) {
        std::cout << locked->real << "," << locked->imaginary << std::endl;
    }
}