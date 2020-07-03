# CppND-Capstone-Project

The &lt;Insert Project Name&gt; is the project for the Capstone Project in the Udacity C++ Nanodegree Program. <br />

THIS IS A WORK IN PROGRESS. FILL IN DESCRIPTION HERE.<br /><br />

## Dependencies

* cmake >= 3.11.3

* make >= 4.1 (Linux and Mac), 3.81 (Windows)

* gcc/g++ >= 5.4

## Building: Compile and Run

### Compilation

1. Create a `build` directory and enter it: `mkdir build && cd build`
2. Compile the code by using cmake and make with the following line:
```
cmake .. && make
```
### Execution

The executable is called `Capstone` and is placed in the `build` directory. This project must be run only within the `build` directory itself. Within this directory, run the project with the following command:

```
./Capstone
```

# Expected Behavior



# File Structure



# Class Structure



# Rubric Points





# README
	* A README with instructions is included with the project.
		* The README is included with the project and has instructions for building/running the project. <strong>File: README.md. Line Numbers: 15 - 30.</strong>
		* If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. <strong>File: README.md. Line Numbers: 7 - 14.</strong>

		* You can submit your writeup as markdown or pdf. <strong>File: README.md</strong>
	
# Compiling and Testing
	* The submission must compile and run.
		* See instructions above.

# Loops, Functions, I/O
	* The project demonstrates an understanding of C++ functions and control structure.
		* A variety of control structures are used in the project. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
		* The project is clearly organized into functions. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* The project reads data from a file and processes the data, or the program writes data to a file.
		* The project reads data from an external file or writes data to a file as part of the necessary operation of the program. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	
	* The project accepts user input and processes the input.
		* The project accepts input from a user as part of the necessary operation of the program. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

# Object-Oriented Programming
	* The project uses Object Oriented Programming techniques.
		* The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Classes use appropriate access specifiers for class members.
		* All class data members are explicitly specified as `public`, `protected`, or `private`. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Class constructors utilize member initialization lists.
		* All class members that are set to argument values are initialized through member initialization lists. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Classes abstract implementation details from their interfaces.
		* All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Classes encapsulate behavior.
		* Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Classes follow an appropriate inheritance hierarchy.
		* Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Overloaded functions allow the same function to operate on different parameters.
		* One function is overloaded with different signatures for the same function name. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Derived class functions override virtual base class functions.
		* One member function in an inherited class overrides a virtual base class member function. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* Templates generalize functions in the project.
		*One function is declared with a template that allows it to accept a generic parameter. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

# Memory Management
	* The project makes use of references in function declarations.
		* At least two variables are defined as references, or two functions use pass-by-reference in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* The project uses destructors appropriately.
		* At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
		* The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* The project follows the Rule of Five.
		* For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* The project uses move semantics to move data, instead of copying it, where possible.
		* For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* The project uses smart pointers instead of raw pointers.
		* The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. The project does not use raw pointers. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

# Concurrency
	* The project uses multithreading.
		* The project uses multiple threads in the execution. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	
	* A promise and future is used in the project.
		* A promise and future is used to pass data from a worker thread to a parent thread in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

	* A mutex and lock is used in the project.
		* A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* A condition variable is used in the project.
		* A `std::condition_variable` is used in the project code to synchronize thread execution. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
