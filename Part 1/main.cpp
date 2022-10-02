#include <iostream>
#include <cstdint>
#include <vector>
#include "ClassExample.h"

void cin_cout_example() {
    int input = 0;
    std::cin >> input;
    std::cout << input << std::endl;
}

void variable_example() {
    // Variable declaration
    int my_var;

    // Variable assignment
    my_var = 123;
}

void pointer_example() {
    // Declare and assign our variable
    int my_var = 1337;
    int my_var_2 = 2448;

    // Get a pointer to our variable
    // Here "*" means the type is a pointer
    // Here "&" is the "address of"
    // This gives us the address in memory to our variable "my_var"
    int* my_ptr = &my_var;

    // Assign a value to the object at the address stored in "my_ptr" (in this case, "my_var")
    // Here "*" will dereference the address stored in "my_ptr"
    *my_ptr = 7331;

    // Assign a different pointer to "my_ptr"
    my_ptr = &my_var_2;
}

void pointer_array_example() {
    // Statically allocated array
    int static_array[3] = {1, 2, 3};

    // A pointer to our array (static_array is of type "int*" so this does not need "&" here)
    int* my_ptr = static_array;

    // Set the 3rd item in the array to 0
    // Here, we dereference the address of the 3rd indexed element
    my_ptr[2] = 0;

    // In memory, the above would look something like the following
    // Note: This is just handy to understand what's going on, it's easier and prettier to do the above

    // Obtain a pointer to our array
    // Verify your machine architecture, the below is an example for a 64-bit machine
    // The following line casts our array to a pointer of uint64_t to represent the data sizes in memory
    auto my_uint_ptr = reinterpret_cast<uint64_t>(static_array);

    // Get the 3rd item in the array
    // *(int*) will dereference the address given, which is the address of the array plus 8 bytes of memory
    // 0 bytes -> first element
    // 4 bytes -> second element
    // 8 bytes -> third element
    // sizeof(int) == 4 bytes (sizeof(int) because the elements in our array are of type "int")
    // sizeof(int) * 2 == third element (can also just do my_uint_ptr + 0x8 or my_uint_ptr + (0x4 * 2))
    int third_item = *(int*)(my_uint_ptr + (sizeof(int) * 2));

    // Set the 3rd item in the array to 1
    *(int*)(my_uint_ptr + (sizeof(int) * 2)) = 1;
}

void arrays_vectors_example() {
    // Define an array (statically) of size 5
    int my_array[5] = {1, 2, 3, 4};

    // Set the first element to 23
    my_array[0] = 23;

    // Define a vector
    std::vector<int> my_vector;

    // Add an element to the end of the vector (result will be 12, 3)
    my_vector.push_back(12);
    my_vector.push_back(3);

    // Get the NUMBER OF ELEMENTS inside the vector (will return 2)
    size_t vector_size = my_vector.size();

    // Insert an element to the beginning of the vector with insert (will return 2, 12, 3)
    my_vector.insert(my_vector.begin(), 2);
}

void dynamic_allocation_example() {
    // Dynamically allocate (then delete) an array of n items
    int size = 3;
    int* dynamic_array_1 = new int[size];
    delete[] dynamic_array_1;

    // Dynamically allocate (then delete) memory for one item
    int* dynamic_array_2 = new int;
    delete dynamic_array_2;
}

void pass_by_value(int val) {
    // Passing by value gives us essentially a "copy" of the value
    // We can modify this value LOCALLY, but it will not change the value outside this scope (this function)
    val = 1;
}

void pass_by_reference(int& ref) {
    // Passing by reference gives us the original variable
    // We can use and modify this value and changes will be made outside this scope
    ref = 3;
}

void pbv_pbr_example() {
    int my_val = 5;

    // Call the function pass_by_value with the argument my_val
    pass_by_value(my_val); // my_val will be 5

    // Call the function pass_by_reference with the argument my_val
    pass_by_reference(my_val); // my_val will be 3
}

void class_example() {
    // Automatically construct a variable of type ClassExample
    // Since we have a constructor with no arguments (or one could make a constructor with default arguments)
    // Then we do not need to do anything here.
    ClassExample first_class;

    // Define a variable of type ClassExample using a manual constructor
    ClassExample second_class = ClassExample(1, 2);

    // "z" is a public member variable, so we can access it outside the scope of the class
    first_class.z = 12;

    first_class.GetX(); // This will return 0 as per our default constructor
    first_class.SetX(12);
    first_class.GetX(); // This will return 12

    // Get a pointer to our variable "second_class" which is type ClassExample
    ClassExample* class_ptr = &second_class;

    // Since it is a pointer, we will need to use -> to dereference and access member variables and functions
    class_ptr->GetX(); // This will return 1
    class_ptr->z = 32;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
