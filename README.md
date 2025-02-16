# Expense Management System (C)

This C program implements a binary search tree-based expense management system, allowing users to add and search for categories and expenses, as well as view or clear the entire tree.

## Features

- **Tree Initialization**: The tree can be initialized (all nodes can be deleted).
- **Category Management**: Categories can be added, and each category can store up to two expenses.
- **Search Functionality**: Users can search for a specific category and view its expenses.
- **Display Tree**: Display all categories and their associated expenses in sorted order.
- **Exit**: Gracefully exit the program.

## Commands

- **i)** Initialize the tree (clear all nodes).
- **n)** Add a new category or add a new expense to an existing category.
- **s)** Search for a category and display its expenses.
- **d)** Display the entire tree of categories and expenses.
- **e)** Exit the program.

## Structure

The program uses a binary search tree (BST) to store categories, where each node contains:
- **name**: The category name (string).
- **expense[2]**: An array holding up to two expenses for the category.
- **left**: Pointer to the left child node.
- **right**: Pointer to the right child node.

## Installation

No installation is required. To compile and run the program, use the following commands:

```bash
gcc -o expense_manager expense_manager.c
./expense_manager
