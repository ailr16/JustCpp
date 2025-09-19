#ifndef OOP_HPP
#define OOP_HPP

#include <memory>
#include <utility>

void friend_function(void);

class AllAccessModifiers {
    /* Can be accessed from anywhere in the program */
    public:
        int public1;
        float public2;
        void public_method1(void);
    
    /* Can be accessed only by the member functions or friend class/function*/
    private:
        int private1;
        float private2;
        void private_method1(void);

    friend class AllAccessModifiers_friend;
    friend void friend_function(void);

    /* Similar to private, but can be accessed by any sub-class */
    protected:
        int protected1;
        float protected2;
        void protected_method1(void);

};

class AllAccessModifiers_friend {
    public:
        void public_method1(void);
};

class AllAccessModifiers_subclass : AllAccessModifiers {
    public:
        void public_method1(void);
};

class AllAccessModifiers_subclass_public : public AllAccessModifiers {
    public:
        void public_method1(void);
};

class AllAccessModifiers_subclass_protected : protected AllAccessModifiers {
    public:
        void public_method1(void);
};

namespace AccessModifiersExample {
    void example(void);
}


class PolymorphismBase {
    public:
        /* This pure virtual method makes an abstract class */
        virtual int publicMethod1(int a) = 0;
    
    private:
        virtual int privateMethod1(int a) = 0;
};

class PolymorphismDerived1 : public PolymorphismBase {
    public:
        int publicMethod1(int a) override;

    private:
        int privateMethod1(int a) override;
};

class PolymorphismDerived2 : public PolymorphismBase {
    public:
        /* There's no method to override due int vs float declaration */
        //int publicMethod1(float a) override;
};

namespace PolymorphismExample {
    int example(int a);
}

class AbstractionInterface {
    public:
        virtual ~AbstractionInterface() { }
        virtual int method(int a) = 0;
};

class AbstractionDerived : public AbstractionInterface {
    public:
        int method(int a) override;
};

namespace AbstractionExample {
    int example(int a);
}

class DefaultContructor {
    private:
        int private1;

    public:
        DefaultContructor(void) {
            private1 = 0;
        }

        DefaultContructor(int a) : private1(a){ }

        int testClass(void) {
            return private1;
        }
};

class MoveConstructor {
    private:
        int* private1;
        
    public:
        MoveConstructor(int a);
        MoveConstructor(MoveConstructor&& a);
        ~MoveConstructor();

        int getData(void);
};

class CopyConstructor {
    private:
        int private1;
        
    public:
        CopyConstructor(int a);
        CopyConstructor(const CopyConstructor& a);

        int getData(void);
};

namespace ConstructorsExample {
    enum ConstructorType : int {
        c_default = 0,
        c_move,
        c_copy
    };

    std::pair<int, int> example(ConstructorType type, int value);
}

#endif