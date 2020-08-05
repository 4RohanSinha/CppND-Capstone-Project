# CppND Capstone Project

The &lt;Insert Project Name&gt; is the project for the Capstone Project in the Udacity C++ Nanodegree Program. <br />

THIS IS A WORK IN PROGRESS. FILL IN DESCRIPTION HERE.<br /><br />

## Dependencies

* cmake >= 3.11.3

* make >= 4.1 (Linux and Mac), 3.81 (Windows)

* gcc/g++ >= 5.4

* SDL2 library and extension libraries
	* SDL2
		* The SDL wiki contains install instructions for the SDL 2 library <a href="https://wiki.libsdl.org/Installation">here</a>.
			* Note that on Ubuntu, this package can be installed with the following command: `sudo apt install libsdl2-2.0-0 libsdl2-dev`
	* SDL2 extension libraries: SDL image, SDL ttf, and SDL mixer are all required for this project to run.
		* TO BE CONTINUED		

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

## Expected Behavior


## File Structure
* CppND-Capstone Project/
	* assets/
		* audio/
		* fonts/ 
			* Note: the fonts in this directory are copied from /usr/share/fonts/truetype/ubuntu
		* photos/
			* alligator.png
			* ball.png
			* bird.png
			* paddle1.jpg
			* paddle2.png
		
	* CMakeLists.txt
	* README.md
	* src/
		* audio/
			* Audio.h
			* Audio.cpp
			* AudioManager.h
			* AudioManager.cpp
		* CollisionDetector.h
		* CollisionDetector.cpp
		* CollisionManager.h
		* CollisionManager.cpp
		* Color.h
		* Color.cpp
		* Controller.h
		* Controller.cpp
		* Engine.h
		* Engine.cpp
		* EventHandler.h
		* EventHandler.cpp
		* Font.h
		* Font.cpp
		* Game.h
		* Game.cpp
		* games/
			* ObstacleCourse/
				* ObstacleCourse.h
				* ObstacleCourse.cpp
				* Projectile.h
				* Projectile.cpp
				* Wall.h
				* Wall.cpp
			* Pong/
				* Ball.h
				* Ball.cpp
				* Pong.h
				* Pong.cpp
		* Input.h
		* Input.cpp
		* Keyboard.h
		* Keyboard.cpp
		* main.cpp
		* Mouse.h
		* Mouse.cpp
		* NGCollisionDetector.h
		* NGCollisionDetector.cpp
		* Node.h
		* Node.cpp
		* NodeGroup.h
		* NodeGroup.cpp
		* Renderer.h
		* Renderer.cpp
		* Scene.h
		* Scene.cpp
		* SceneManager.h
		* SceneManager.cpp
		* Sprite.h
		* Sprite.cpp
		* SpriteManager.h
		* SpriteManager.cpp
		* Surface.h
		* Surface.cpp
		* SurfaceManager.h
		* SurfaceManager.cpp
		* Text.h
		* Text.cpp
		* TextManager.h
		* TextManager.cpp
		* Texture.h
		* Texture.cpp
		* TextureManager.h
		* TextureManager.cpp
		* Timer.h
		* Timer.cpp
		* Window.h
		* Window.cpp

## Class Structure



## Rubric Points




### README
* <strong>A README with instructions is included with the project.</strong>
	* The README is included with the project and has instructions for building/running the project. <strong>File: README.md. Line Numbers: 15 - 30.</strong>
	* If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. <strong>File: README.md. Line Numbers: 7 - 14.</strong>

	* You can submit your writeup as markdown or pdf. <strong>File: README.md</strong>
	
### Compiling and Testing
* <strong>The submission must compile and run.</strong>
	* See instructions above.

### Loops, Functions, I/O
* <strong>The project demonstrates an understanding of C++ functions and control structure.</strong>
	* A variety of control structures are used in the project. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
	* The project is clearly organized into functions. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>The project reads data from a file and processes the data, or the program writes data to a file.</strong>
	* The project reads data from an external file or writes data to a file as part of the necessary operation of the program. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>The project accepts user input and processes the input.</strong>
	* The project accepts input from a user as part of the necessary operation of the program. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

### Object-Oriented Programming
* <strong>The project uses Object Oriented Programming techniques.</strong>
	* The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Classes use appropriate access specifiers for class members.</strong>
	* All class data members are explicitly specified as `public`, `protected`, or `private`. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Class constructors utilize member initialization lists.</strong>
	* All class members that are set to argument values are initialized through member initialization lists. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Classes abstract implementation details from their interfaces.</strong>
	* All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Classes encapsulate behavior.</strong>
	* Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Classes follow an appropriate inheritance hierarchy.</strong>
	* Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Overloaded functions allow the same function to operate on different parameters.</strong>
	* One function is overloaded with different signatures for the same function name. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Derived class functions override virtual base class functions.</strong>
	* One member function in an inherited class overrides a virtual base class member function. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>Templates generalize functions in the project.</strong>
	*One function is declared with a template that allows it to accept a generic parameter. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

### Memory Management
* <strong>The project makes use of references in function declarations.</strong>
	* At least two variables are defined as references, or two functions use pass-by-reference in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
* <strong>The project uses destructors appropriately.</strong>
	* At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
* <strong>The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.</strong>
	* The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
* <strong>The project follows the Rule of Five.</strong>
	* For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
* <strong>The project uses move semantics to move data, instead of copying it, where possible.</strong>
	* For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>The project uses smart pointers instead of raw pointers.</strong>
	* The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. The project does not use raw pointers. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

### Concurrency
* <strong>The project uses multithreading.</strong>
	* The project uses multiple threads in the execution. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>A promise and future is used in the project.</strong>
	* A promise and future is used to pass data from a worker thread to a parent thread in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

* <strong>A mutex and lock is used in the project.</strong>
	* A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>
* <strong>A condition variable is used in the project.</strong>
	* A `std::condition_variable` is used in the project code to synchronize thread execution. <strong>File: &lt;filename&gt;. Line numbers: &lt;line numbers&gt;.</strong>

