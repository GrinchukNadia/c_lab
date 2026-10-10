*This activity has been created as part of the 42 curriculum by* <ngrinchu> .
# Libft
A reusable library of fundamental C functions and utilities.
## Description
Libft is a project developed as part of the 42 Common Core curriculum. It's main goal is to create a personal C library by re-implementing standard library functions and developing additional utility functions.

The library provides functions for string manipulation, memory operations, character checks, conversions and linked list management.

This project helps develop a deeper understanding of C programming, pointers, dynamic memory allocation, and data structures.

## Instructions
### Compilation
To compile the library, run the following command:
```bash
make
```
This command compiles the source files and creates the static library `libft.a`.

Other available commands:
- `make clean` - removes object files (`.o`).
- `make fclean` - removes object files and `libft.a`.
- `make re` - rebuilds the library from scratch.
- `make bonus` - extends the library with additional linked list functions.
- `help` - displays all available commands.

### Usage
Copy the library's source files, header file and Makefile into a `libft` directory within your project.

Your project's Makefile should first build `libft.a` using the library's Makefile, then compile and link your project with the library.

### Resources
The following resources were used during the development of this project:
- 42 subject - to follow the project requirements and constraints.
- Manual pages (man) - to study function behavior, parameters, and return values.
- [cppreference](https://cppreference.com/c) - to study function specifications and edge cases.
- [SEI CERT C Coding Standard](https://cmu-sei.github.io/secure-coding-standards/sei-cert-c-coding-standard/) - to learn about memory management in C.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents) - to learn build rules, dependencies, and automatic variables.

AI Usage  
AI tools were used to clarify C programming concepts encountered in technical articles, explore edge cases, and discuss and improve testing strategies.

All functions were implemented and tested independently.

## Library Description
The library  is divided into tree main parts:
- **Libc functions** - reimplementations of standard C library functions.
- **Additional functions** - utility functions for string manipulation, memory allocation, and data conversion.
- **Linked list** - function for creating, modifying, travesing, and managing linked lists.

### Part 1 - Libc functions
| Function | Description |
|----------|-------------|
|`ft_isalpha` | Checks whether the character is an alphabetic letter (A-Z or a-z). |
| `ft_isdigit` | Checks whether the character is a decimal digit. |
| `ft_isalnum` | Checks whether the character is alphanumeric. |
| `ft_isascii` | Checks whether the character belongs to the ASCII character set. |
| `ft_isprint` | Checks whether the character is printable. |
| `ft_strlen` | Returns the length of the string, excluding the terminating '\0'. |
| `ft_memset` | Fills the first n bytes of memory with the given byte value. |
| `ft_bzero` | Sets the first n bytes of memory to zero. |
| `ft_memcpy` | Copies n bytes from src to dest. The memory areas must not overlap. |
| `ft_memmove` | Copies n bytes from src to dest. Handles overlapping memory areas safely. |
| `ft_strlcpy` | Copies src to dst within the size limit of dstsize. Copies only as much of src as fits in dst. Adds '\0' if dstsize is greater than 0. Returns the full length of src. |
| `ft_strlcat` | Appends src to the end of dst. Appends src within the size limit of dstsize. Returns the length of the string it tried to create. Appends only as much of src as fits in dst. |
| `ft_toupper` | Converts an lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
| `ft_strchr` | Finds the first occurrence of character c in the string. Returns a pointer to it, or NULL if it is not found. |
| `ft_strrchr` | Finds the last occurrence of character c in the string. Returns a pointer to it, or NULL if it is not found. |
| `ft_strncmp` | Compares at most n characters of two strings. Returns 0 if equal, a negative value if s1 < s2, or a positive value if s1 > s2. |
| `ft_memchr` | Searches for byte c in the first n bytes of memory. Returns a pointer to it, or NULL if it is not found. |
| `ft_memcmp` | Compares the first n bytes of two memory areas. Returns 0 if equal, a negative value if s1 < s2, or a positive value if s1 > s2. |
| `ft_strnstr` | Searches for the first occurrence of little in big, within the first len characters of big. Returns a pointer to the beginning of the match. Returns big if little is empty, or NULL if no match is found. |
| `ft_atoi` | Converts the initial part of the string to an integer. Skips leading whitespace and handles one optional '+' or '-' sign. Stops converting at the first non-digit character. Returns the converted integer. |
| `ft_calloc` | Allocates memory for count elements of size bytes each. Initializes all allocated bytes to zero. Returns a pointer to the allocated memory. Returns NULL if the allocation fails or the size calculation overflows. |
| `ft_strdup` | Creates a new allocated copy of the string. The returned string must be freed by the caller. |

### Part 2 - Additional functions
| Function | Description |
|----------|-------------|
| `ft_substr` | Returns a newly allocated substring from the given string. |
| `ft_strjoin` | Joins two strings into a newly allocated string. |
| `ft_strtrim` | Trims char from the given set from the beginning and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter character. |
| `ft_itoa` | Converts an integer to a newly allocated string representation. |
| `ft_strmapi` | Applies a function to each character and returns a newly allocated string. |
| `ft_striteri` | Applies a function to each character of a string, modifying it in place. |
| `ft_putchar_fd` | Writes a character to the given file descriptor. |
| `ft_putstr_fd` | Writes a string to the given file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to the given file descriptor. |
| `ft_putnbr_fd` | Writes an integer to the given file descriptor. |

### Part 3 - Linked list
| Function | Description |
|----------|-------------|
| `ft_lstnew` | Generates a new list node with the given content. |
| `ft_lstadd_front` | Adds a node  to the beginning of a linked list. |
| `ft_lstsize` | Counts the number of nodes in a linked list. |
| `ft_lstlast` | Returns the last node of a linked list. |
| `ft_lstadd_back` | Adds a node to the end of a linked list. |
| `ft_lstdelone` | Deletes a single node and frees its content using given function. Frees the node itself.|
| `ft_lstclear` | Deletes all nodes from the given position and sets the list pointer to NULL. |
| `ft_lstiter` | Applies a given in parameters function to the content of each node in a linked list. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. Frees the new list if a node allocation fails. |