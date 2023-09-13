# Binary Search Tree (BST) Project

A Binary Search Tree (BST) implementation in C++.

## Table of Contents

- [Binary Search Tree (BST) Project](#binary-search-tree-bst-project)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Features](#features)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
  - [Usage](#usage)
  - [Examples](#examples)
  - [Contributing](#contributing)
  - [Acknowledgments](#acknowledgments)

## Description

This project is an implementation of a Binary Search Tree (BST) in C++. A BST is a widely used data structure that allows for efficient insertion, deletion, and retrieval of elements in a sorted order. This implementation provides a comprehensive set of operations and functionalities for working with BSTs.

## Features

- **BST Operations**: Supports essential BST operations such as insertion, deletion, search, and traversal (inorder, preorder, postorder).
- **Element Retrieval**: Allows you to find the minimum and maximum elements in the BST.
- **Predecessor and Successor**: Provides functions to find the predecessor and successor of a given element in the BST.
- **Height Calculation**: Calculates the height of the BST.
- **Copy and Assignment**: Supports copying and assignment of BSTs.
- **Memory Management**: Proper memory management to prevent memory leaks.

## Getting Started

Follow these instructions to get the Binary Search Tree project up and running on your local machine.

### Prerequisites

Before you begin, ensure you have the following:

- C++ compiler (e.g., g++) installed on your system.

### Installation

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/RazmikManukyan/BST
   ```

2. Navigate to the project directory:

   ```shell
   cd BST
   ```

3. Compile the code:

   ```shell
   g++ -o main main.cpp BST.tpp
   ```

4. Run the executable:

   ```shell
   ./main
   ```

## Usage

To use this BST implementation in your own C++ projects, include the "BST.h" header file and create BST objects as needed. You can perform various operations on the BST using the provided member functions.

```cpp
#include "BST.h"

int main() {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    // Perform more operations...
    return 0;
}
```

## Examples

For code examples and usage demonstrations, refer to the "examples" directory in this repository.

## Contributing

If you'd like to contribute to this project, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your changes to your fork.
5. Create a pull request to merge your changes into the main branch.


## Acknowledgments

- This project was inspired by the need for a reliable BST implementation in C++.
- We'd like to thank the C++ community for their valuable contributions to the field of data structures and algorithms.

Feel free to customize this README to add more details about your specific BST project, and make sure to include any necessary documentation and examples to help users understand and use your code effectively.
