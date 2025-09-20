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