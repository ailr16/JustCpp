#include <sequenceContainers.hpp>

void ArrayExamples::example(void) {
    std::array<int, 4> a = {1, 2, 3, 4};

    std::cout << "No overhead sizeof: " << sizeof(a) << std::endl;
    std::cout << "The array stores 4 ints, so 16 total bytes are expected!\n";
    
    std::array<int, 4>::iterator i = a.begin();
    std::cout << "Traverse the array with iterator:\n";
    while(i < a.end()){
        std::cout << *i << " ";
        i++;
    }
    std::cout << std::endl;
}

void VectorExamples::example(void) {
    std::vector<int> v = {1, 2, 3, 4};

    std::cout << "Sizeof: " << sizeof(v) << std::endl;
    std::cout << "The object stores a pointer, size and capacity. 24B in total!\n";

    std::cout << "Capacity: " << v.capacity() << std::endl;
    std::cout << "Size: " << v.size() << std::endl;
    v.insert(v.begin() + 1, 99);
    std::cout << "Size after one insertion: " << v.size() << std::endl;

    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    v.reserve(44);
    std::cout << "Capacity after reserve 44: " << v.capacity() << std::endl;
}

void DequeExamples::example(void) {
    std::deque<int> d = {1, 2, 3, 4};
    std::deque<int> d2 = {55, 56};

    std::cout << "Sizeof: " << sizeof(d) << std::endl;
    std::cout << "Size: " << d.size() << std::endl;

    d.push_front(-1);
    std::cout << d.back() << std::endl;
    std::cout << d.front() << std::endl;

    
    for(auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for(auto it2 = d2.begin(); it2 != d2.end(); ++it2)
        std::cout << *it2 << " ";
    std::cout << std::endl;

    d.swap(d2);

    for(auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for(auto it2 = d2.begin(); it2 != d2.end(); ++it2)
        std::cout << *it2 << " ";
    std::cout << std::endl;
}

void ListExamples::example(void) {
    std::list<int> l = {1, 2, 3};
    
    
}

void FwListExamples::example(void) {
    std::array<int, 4> a = {1, 2, 3, 4};
    
}