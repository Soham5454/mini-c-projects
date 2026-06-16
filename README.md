# 🚀 Mini C Projects Collection

> A curated collection of **14 mini C projects** ranging from beginner to advanced — great for learning, revising, and impressing interviewers!

![C Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-14-orange?style=for-the-badge)
![Level](https://img.shields.io/badge/Level-Beginner%20to%20Advanced-purple?style=for-the-badge)

---

## 📁 Project List

| # | Project | Level | Concepts Covered |
|---|---------|-------|-----------------|
| 01 | 🔢 [Calculator](#01-calculator) | 🟢 Beginner | Switch-case, Math library |
| 02 | 🎯 [Number Guessing Game](#02-number-guessing-game) | 🟢 Beginner | Rand, Loops, Structs |
| 03 | 🌡️ [Temperature Converter](#03-temperature-converter) | 🟢 Beginner | Functions, Formulas |
| 04 | 🌀 [Fibonacci Explorer](#04-fibonacci-explorer) | 🟢 Beginner | Recursion, Iteration, Time |
| 05 | 📊 [Sorting Algorithms](#05-sorting-algorithms) | 🟡 Intermediate | Bubble, Selection, Merge, Quick |
| 06 | 🔗 [Linked List](#06-linked-list) | 🟡 Intermediate | Pointers, Dynamic Memory |
| 07 | 📦 [Stack & Queue](#07-stack-and-queue) | 🟡 Intermediate | Data Structures, Arrays |
| 08 | 🗂️ [File Manager](#08-file-manager) | 🟡 Intermediate | File I/O, fopen/fclose |
| 09 | 🎓 [Student Database](#09-student-database) | 🟡 Intermediate | Structs, Arrays, File I/O |
| 10 | ❌ [Tic Tac Toe](#10-tic-tac-toe) | 🟡 Intermediate | 2D Arrays, Game Logic, AI |
| 11 | 🐍 [Snake Game](#11-snake-game) | 🔴 Advanced | Terminal, Linked List, Real-time |
| 12 | 🌳 [Binary Search Tree](#12-binary-search-tree) | 🔴 Advanced | Trees, Recursion, Traversal |
| 13 | 🔢 [Matrix Operations](#13-matrix-operations) | 🔴 Advanced | 2D Arrays, Determinants |
| 14 | 🧠 [Memory Allocator](#14-memory-allocator) | 🔴 Advanced | Heap, Pointers, malloc internals |

---

## 🛠️ How to Compile & Run

### Prerequisites
- GCC compiler installed
- Linux / macOS / Windows (with MinGW or WSL)

### Compile any project
```bash
gcc filename.c -o output -lm
./output
```

### Example
```bash
cd 01_calculator
gcc calculator.c -o calculator -lm
./calculator
```

---

## 📌 Project Details

### 01 Calculator
**File:** `01_calculator/calculator.c`
A feature-rich calculator with addition, subtraction, multiplication, division, modulus, power, square root, and factorial — all in a clean menu-driven interface.
```bash
gcc calculator.c -o calculator -lm && ./calculator
```

---

### 02 Number Guessing Game
**File:** `02_number_guessing_game/guessing_game.c`
Guess the secret number with 3 difficulty levels (Easy/Medium/Hard), hot/cold hints, attempt tracking, and a score system.
```bash
gcc guessing_game.c -o guessing_game && ./guessing_game
```

---

### 03 Temperature Converter
**File:** `03_temperature_converter/temp_converter.c`
Convert between Celsius, Fahrenheit, Kelvin, and Rankine with a clean menu and validation.
```bash
gcc temp_converter.c -o temp_converter && ./temp_converter
```

---

### 04 Fibonacci Explorer
**File:** `04_fibonacci/fibonacci.c`
Explore Fibonacci numbers — print series, find the Nth term, approximate the Golden Ratio (φ), and compare recursive vs iterative speed.
```bash
gcc fibonacci.c -o fibonacci && ./fibonacci
```

---

### 05 Sorting Algorithms
**File:** `05_sorting_algorithms/sorting.c`
Visualize and compare 5 classic sorting algorithms side-by-side: Bubble, Selection, Insertion, Merge, and Quick Sort — with step counts and complexity info.
```bash
gcc sorting.c -o sorting && ./sorting
```

---

### 06 Linked List
**File:** `06_linked_list/linked_list.c`
Full singly linked list with insert at beginning/end/position, delete, search, reverse, and display — all menu-driven.
```bash
gcc linked_list.c -o linked_list && ./linked_list
```

---

### 07 Stack and Queue
**File:** `07_stack_queue/stack_queue.c`
Interactive demo of both Stack (push/pop/peek) and Queue (enqueue/dequeue/peek) in one program with visual display.
```bash
gcc stack_queue.c -o stack_queue && ./stack_queue
```

---

### 08 File Manager
**File:** `08_file_manager/file_manager.c`
A terminal-based file manager to create, read, write, append, copy, delete files, and count words/lines — all without leaving the terminal.
```bash
gcc file_manager.c -o file_manager && ./file_manager
```

---

### 09 Student Database
**File:** `09_student_database/student_db.c`
Manage student records with add, view, search, update, delete, sort by average, and export to file. Calculates grades automatically.
```bash
gcc student_db.c -o student_db && ./student_db
```

---

### 10 Tic Tac Toe
**File:** `10_tic_tac_toe/tic_tac_toe.c`
Play Tic Tac Toe in two-player mode or against a smart AI that blocks your moves and tries to win. Includes score tracking and replay.
```bash
gcc tic_tac_toe.c -o tic_tac_toe && ./tic_tac_toe
```

---

### 12 Binary Search Tree
**File:** `12_binary_search_tree/bst.c`
Full BST with insert, delete, search, inorder/preorder/postorder traversal, height calculation, min/max finder, and tree visualization.
```bash
gcc bst.c -o bst && ./bst
```

---

### 13 Matrix Operations
**File:** `13_matrix_operations/matrix.c`
Perform matrix addition, subtraction, multiplication, transpose, determinant, and trace on user-defined matrices up to 5×5.
```bash
gcc matrix.c -o matrix && ./matrix
```

---

### 14 Memory Allocator
**File:** `14_memory_allocator/memory_allocator.c`
A custom heap allocator implementing `my_malloc()`, `my_free()`, and `my_realloc()` from scratch — with free-list coalescing, double-free detection, and heap statistics. A must-see for systems programming enthusiasts.
```bash
gcc memory_allocator.c -o memory_allocator && ./memory_allocator
```

---

## 📚 Concepts Covered

- ✅ Variables, Loops, Functions
- ✅ Pointers & Dynamic Memory Allocation
- ✅ Structs & Arrays
- ✅ File I/O
- ✅ Recursion
- ✅ Data Structures (Linked List, Stack, Queue, BST)
- ✅ Sorting & Searching Algorithms
- ✅ Game Logic & AI
- ✅ Matrix Mathematics
- ✅ Systems Programming (Memory Allocator)

---

## 🤝 Contributing

Pull requests are welcome! If you have a cool mini C project to add:
1. Fork this repository
2. Create a new folder with your project
3. Add your `.c` file with clear comments
4. Update the README
5. Submit a pull request

---

## 📄 License

This project is licensed under the **MIT License** — free to use, modify, and share.

---

## 🌟 If this helped you, please give it a ⭐ on GitHub!

> Made with ❤️ in C — the language that powers the world.
