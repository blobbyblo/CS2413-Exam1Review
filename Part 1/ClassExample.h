#ifndef PART_1_CLASSEXAMPLE_H
#define PART_1_CLASSEXAMPLE_H


class ClassExample {
public:
    ClassExample() {
        // This is a class constructor
        x = 0;
        z = 0;
    }

    ClassExample(int _x, int _z) {
        // This is a class constructor with arguments
        x = _x;
        z = _z;
    }

    // This is a public member variable
    int z;

    // We can define inline functions inside the class header file
    void SetX(int i) {
        // We can access member variables with this->
        // We can also access private member variables as long as we are within the scope of the class
        this->x = i;
    }

    // We can also declare functions then write their bodies inside the .cpp file associated with the class
    int GetX() const;

private:
    // This is a private member variable
    int x;
};


#endif //PART_1_CLASSEXAMPLE_H
