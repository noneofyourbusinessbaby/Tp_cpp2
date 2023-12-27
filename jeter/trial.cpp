class MyClass {
private:
    static int instanceCount; // Static member to count instances
    int instanceNumber; // Instance-specific number

public:
    MyClass() {
        instanceCount++; // Increment count each time a new instance is created
        instanceNumber = instanceCount; // Assign a unique instance number
    }

    int getInstanceNumber() const {
        return instanceNumber;
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};
#include <iostream>
int MyClass::instanceCount = 0; // Initialize static member
void fun(int num)
{
    MyClass obj;
    std::cout<<obj.getInstanceNumber()<<std::endl;

}

int main() {
    MyClass obj1, obj2, obj3;

    std::cout << "Instance count: " << MyClass::getInstanceCount() << std::endl;

    std::cout << "Instance numbers:" << std::endl;
    std::cout << obj1.getInstanceNumber() << std::endl;
    std::cout << obj2.getInstanceNumber() << std::endl;
    std::cout << obj3.getInstanceNumber() << std::endl;


    fun(4);

    MyClass obj5;

    std::cout << obj5.getInstanceNumber() << std::endl;

    return 0;
}
