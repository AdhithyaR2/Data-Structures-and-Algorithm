#include <stdio.h>
#include <string.h> // Include the string.h header for working with strings

// Define a structure for a person
struct Person {
    char name[60];
    int age;
    char address[100];
};

int main() {
    // Declare a structure variable
    struct Person person1;

    // Initialize the structure members
    strcpy(person1.name, "Adhithya");
    person1.age = 18;
    strcpy(person1.address, "279 Main Street, City, Country");

    // Accessing and displaying structure members
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address: %s\n", person1.address);

    return 0;
}
