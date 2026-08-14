*This project has been created as part of the 42 curriculum by <saalagor>.*

# Libft - Your Very First C Library

## Description

**Libft** (Library C) is a foundational project in the 42 curriculum. The goal of this project is to re-code a selection of standard C library (`libc`) functions—along with additional utility functions and custom data structure manipulators (singly linked lists)—from scratch.

By building this static C library from the ground up, the project provides a deep, hands-on understanding of:
- **Memory Management:** Allocating, freeing, and manipulating dynamic memory blocks directly using standard tools (`malloc`, `free`, `bzero`, `memcpy`).
- **Low-Level Data Structures:** Pointers, double pointers (`t_list **`), pointer arithmetic, and linked list node traversal/manipulation.
- **Function Pointers:** Passing behavior as arguments (`void (*f)(void *)`) for mapped iterations and memory cleanup callbacks.
- **Build Systems:** Automating compilation and archive generation using a POSIX-compliant `Makefile`.

The resulting `libft.a` static library serves as the core toolkit used throughout subsequent projects in the 42 syllabus, such as `ft_printf`, `get_next_line`, and `push_swap`.

---

## Instructions

### Prerequisites
- A Unix-like operating system (Linux or macOS).
- A C compiler (`gcc` or `clang`).
- GNU `make` and `ar` utility tools.

### Compilation & Build Rules
All source files are compiled using `cc` with strict compilation flags (`-Wall -Wextra -Werror`). The static archive `libft.a` is built at the root of the repository.

| Command | Action |
| :--- | :--- |
| `make` / `make all` | Compiles all `.c` files and generates the static library `libft.a`. |
| `make clean` | Deletes all object (`.o`) files. |
| `make fclean` | Deletes all object files and the `libft.a` static library file. |
| `make re` | Performs `fclean` followed by `all` to re-compile the entire library from scratch. |

### Usage in Your Own C Projects
To link `libft.a` with your own main program:

1. Compile the library:
   ```bash
   make

```

2. Include the header file in your C file:
```c
#include "libft.h"

```


3. Compile your program while linking the static library:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

```



---

## Technical Overview & Library Specification

The library consists of **43 functions** grouped logically into memory utilities, string manipulations, conversions, file descriptor outputs, and singly linked list operations.

### 1. Standard C Library Re-implementations (`libc`)

Functions designed to mimic the exact behavior of standard `libc` functions:

* **Memory:**
* `ft_memset` — Fills a memory area with a constant byte.
* `ft_bzero` — Erases data in a memory block by writing zeros.
* `ft_memcpy` — Copies a specified amount of bytes from source to destination memory.
* `ft_memmove` — Safely copies memory blocks even when source and destination overlap.
* `ft_memchr` — Scans memory for a specific byte value.
* `ft_memcmp` — Compares two memory blocks byte-by-byte.
* `ft_calloc` — Allocates memory for an array and initializes all bytes to zero.


* **String Manipulation:**
* `ft_strlen` — Calculates the length of a string.
* `ft_strlcpy` — Size-bounded string copy preventing buffer overflows.
* `ft_strlcat` — Size-bounded string concatenation.
* `ft_strchr` — Locates the first occurrence of a character in a string.
* `ft_strrchr` — Locates the last occurrence of a character in a string.
* `ft_strncmp` — Compares two strings up to N bytes.
* `ft_strnstr` — Locates a substring within a length-bounded string.
* `ft_strdup` — Duplicates a string by allocating dynamic memory.


* **Character Checks & Conversions:**
* `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` — Character classification checks.
* `ft_toupper`, `ft_tolower` — Convert characters between uppercase and lowercase.
* `ft_atoi` — Converts an ASCII string to an integer.



---

### 2. Additional Utility Functions

Useful string manipulation and output functions not found directly in standard `libc`:

* **String Transformation & Splitting:**
* `ft_substr` — Extracts a substring from a given string starting at index `start` with max length `len`.
* `ft_strjoin` — Concatenates two strings into a newly allocated string.
* `ft_strtrim` — Trims a specified set of characters from the beginning and end of a string.
* `ft_split` — Splits a string into an array of strings using a delimiter character.
* `ft_itoa` — Converts an integer to a dynamically allocated ASCII string.
* `ft_strmapi` — Applies a function to each character of a string to construct a new string.
* `ft_striteri` — Applies a function to each character in-place by reference.


* **File Descriptor Writes:**
* `ft_putchar_fd` — Writes a single character to a given file descriptor.
* `ft_putstr_fd` — Writes a string to a given file descriptor.
* `ft_putendl_fd` — Writes a string followed by a newline to a given file descriptor.
* `ft_putnbr_fd` — Writes an integer as text to a given file descriptor.



---

### 3. Linked List Functions (`t_list`)

Singly linked list utilities built around the fundamental node structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

```

* `ft_lstnew` — Allocates and initializes a new list node with given content.
* `ft_lstadd_front` — Inserts a node at the beginning of a linked list.
* `ft_lstsize` — Counts the number of nodes in a linked list.
* `ft_lstlast` — Returns a pointer to the last node of a linked list.
* `ft_lstadd_back` — Appends a node to the end of a linked list.
* `ft_lstdelone` — Frees the content of a single node using a custom `del` function pointer, then frees the node itself.
* `ft_lstclear` — Deletes and frees an entire linked list and its contents.
* `ft_lstiter` — Iterates through a list and applies a function to each node's content.
* `ft_lstmap` — Creates a new list resulting from applying a transformation function `f` to every node's content, with complete memory rollback on failure.

---

## Resources

### References & Documentation

* [Linux man-pages (Section 3)](https://man7.org/linux/man-pages/dir_section_3.html) — Standard C library function behavior specifications.
* [GNU Make Manual](https://www.google.com/search?q=https://www.gnu.org/software/make/manual/) — Guidelines for write rules, phony targets, and Makefile automation.
* [42 C Coding Standard (Norminette)](https://github.com/42School/norminette) — Code structure, variable declarations, and line formatting rules.

### Use of AI Assistance

During the development of this project, AI (Gemini) was utilized as an interactive peer programmer and educational tutor for the following specific tasks:

* **Concept Breakdown:** Explaining low-level memory allocation edge cases, pointer dereferencing safety, and double pointers (`t_list **`).
* **Code Review & Debugging:** Identifying pointer/allocation leaks in complex functions like `ft_lstmap` and verifying edge cases for `ft_split` and `ft_memmove`.
* **Makefile Optimization:** Reviewing build targets, variable syntax, and compliance with project constraints.
* **Documentation:** Assisting in formatting and writing this structured, comprehensive `README.md`.

*No code was blindly copy-pasted; every function was written, analyzed, tested, and verified manually to ensure complete conceptual understanding.*

```

```
