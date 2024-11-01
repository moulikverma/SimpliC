<h1 align="center">SimpliC</h1>
</p>
<p align="center">
  <b>SimpliC is a new programming language developed on the top of C</b>
</p>
<br>
<p>SimpliC is a simplified programming language based on C, designed for educational purpose. The language retains core principles of a interpretated language, focusing on ease of use, readability, and minimized syntax while providing a flexible foundation for learning and development.</p>


## Features

- **Syntax**: Designed for simplicity and readability, making it efficient and lightweight.
- **Interpreted**: Statically typed, with a focus on clear and consistent syntax.
- **Educational-Friendly**: Perfect for beginners to learn programming fundamentals and for quick prototyping.
- **Garbage Collection**: Built-in, automatically manages memory efficiently.


## Prerequisites

- **Compiler**: Requires GCC, G++, or a similar toolchain for compilation.
- **Operating System**: Compatible with Linux Distributions and Debian Systems like Ubuntu, Parrot, Arch Linux, Kali etc.

## File Structure

- **src**: Contains the main source files.
- **include**: Stores all header files required by SimpliC.
- **examples**: Contains example programs demonstrating SimpliC’s features.
- You can use create test samples in examples folder to directly run the command coping from here


<h2 align="center">Installation</h2>

### Clone the Repository
```
git clone https://github.com/rahulchy960/SimpliC.git
```
### Change Directory
```
cd SimpliC
```
### Remove Unwanted Files if any
```
make clean
```
### Installation
``` 
make
```

<h2 align="center">Usage</h2>

<p align="left">Create a new file (<code>file_name.simplic</code>)</p>


<p align="left">Edit the file with a text editor.
</p>

```
function dosomething(x, y){
    print(x,y);
};
dosomething("hello", "world");


function printName(name){
    print(name);
};

printName("Rahul Chowdhury");

```

<p align="left">To Run </p>

```
./simplic.out examples/test.simplic

```


## Language Structure

- **Variable Declaration**: Use `var` to declare variables.  
  Example: `var name = "Rahul";`

- **Function Declaration**: Use `function` to define functions.  
  Example: 
  ```
  function myFunction() {
      // function body
  };
  ```
- **Output Printing**: Use `print()` to display output to the console.  
  Example: `print("Hello, World!");`

- **Multiple Arguments**: You can pass multiple arguments to `print()`, separated by commas.  
  Example: `print("First name:", fname, "Last name:", lname);`

- **Variable Printing**: You can print variables directly.  
  Example: 
  ```plaintext
  var name = "Rahul";
  print(name);

### Basic Variable Declaration and Printing

```
var name = "Rahul";
print(name);
```

### Multiple Variables and Printing

```
var fname = "Rahul";
var lname = "Chowdhury";
print(fname, lname);
```

### Function Definition and Calling

```
function dosomething() {
    print("This is our function calling!");
};

print("Rahul");

dosomething();
dosomething();
dosomething();
dosomething();
dosomething();
dosomething();
dosomething();
```

### Function with Parameters

```
function dosomething(x, y) {
    print(x, y);
};

dosomething("hello", "world");
```

## Limitation

The language currently supports parsing and handling of strings only.  the language does not support numeric parsing or mathematical operations. This feature may be added in future updates.