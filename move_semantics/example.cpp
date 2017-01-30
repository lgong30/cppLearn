#include <iostream>
#include <vector>

class exampleA {
    int *x;
    int size;
public:
    // default constructor
    exampleA(): x(NULL), size(0) {
        std::cout << "Default constructor is called" << std::endl;
    }
    // constructor from a std::vector
    exampleA(const std::vector<int>& vec){
        size = vec.size();
        x = new int[size];
        for (int i = 0;i < size;++ i) x[i] = vec[i];
        std::cout << "Create exampleA object from vector" << std::endl;
    }
    // copy constructor
    exampleA(const exampleA& other) 
    {
        std::cout << "Copy constructor is called" << std::endl;
        size = other.size;
        if (size > 0) {
            x = new int[size];
            for (int i = 0;i < size;++ i) x[i] = other.x[i];
        }else 
        {
            x = NULL;
        }     
    }
    // move constructor
    exampleA(exampleA&& other) 
    {
        std::cout << "Move constructor is called" << std::endl;
        size = other.size;
        x = other.x;
        // for (int i = 0;i < size;++ i) x[i] *= 3;
        other.size = 0;
        other.x = NULL;        
    }
    // deconstructor
    ~exampleA() {
        if (x != NULL) delete [] x;
        x = NULL;
        size = 0;
        std::cout << "Deconstructor is called" << std::endl;
    }
    // overloading operator <<
    friend std::ostream& operator<<(std::ostream& os, const exampleA& a);
};


std::ostream& operator<<(std::ostream& os, const exampleA& a){
    for (int i = 0;i < a.size;++ i) os << a.x[i] << " ";
    return os;
}

exampleA createObject(){
    exampleA a(std::vector<int>(10, 1));
    return a;
}

void passByValue(exampleA a) {
    std::cout << a << std::endl;
}


int main()
{
    exampleA a(std::vector<int>(10, 1));

    passByValue(a);
    std::cout << "======================================\n\n";
    passByValue(createObject());


    return 0;
}