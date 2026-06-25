*This project has been created as part of the 42 curriculum by nicsanto*

# 📚 Libft (Library of Forty-Two)

**Libft** is the foundational project at School 42. C is a minimalist language, and in this project, the goal is to recode the C standard library (`libc`) from scratch, alongside developing additional utility functions. This library will be the core of almost all future projects in the curriculum.

The code was written strictly in accordance with the **42 Norm (Norminette)**, ensuring good structuring practices, readability, and the absence of memory leaks.

---

## 🛠️ What's in the library?

The functions are divided into three sections, exactly as required by the official 42 *Subject*:

### 🔹 Part 1: Classic Libc Functions
Exact recreations of standard system functions, focused on memory and string manipulation:
* **Character Verification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* **Memory Manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
* **String Manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
* **Numeric and Case Conversion:** `ft_atoi`, `ft_toupper`, `ft_tolower`

### 🔹 Part 2: Additional Functions
Tools created from scratch to facilitate the development of more complex projects at 42:
* **Advanced String Manipulation:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
* **Conversion (Int to String):** `ft_itoa`
* **Data Output (File Descriptors):** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 🔹 Part 3: Linked Lists
Functions for creating and manipulating dynamic data structures:
* **List Manipulation:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## 📖 Function Dictionary (What each one does)

Here is a quick summary of the purpose of each function implemented in this library:

**Character Verification and Transformation**
* `ft_isalpha`: Checks if a character is an alphabetic letter (a-z, A-Z).
* `ft_isdigit`: Checks if a character is a digit (0-9).
* `ft_isalnum`: Checks if a character is alphanumeric.
* `ft_isascii`: Checks if a character fits into the ASCII character set.
* `ft_isprint`: Checks if a character is printable.
* `ft_toupper`: Converts a lowercase letter to uppercase.
* `ft_tolower`: Converts an uppercase letter to lowercase.

**Memory Manipulation**
* `ft_memset`: Fills a block of memory with a specific value.
* `ft_bzero`: Erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (`\0`).
* `ft_memcpy`: Copies memory area.
* `ft_memmove`: Copies memory area safely, even if the memory areas overlap.
* `ft_memchr`: Scans memory for a character.
* `ft_memcmp`: Compares memory areas.
* `ft_calloc`: Allocates memory for an array and initializes it to zero.

**Classic String Manipulation**
* `ft_strlen`: Calculates the length of a string.
* `ft_strlcpy`: Size-bounded string copying.
* `ft_strlcat`: Size-bounded string concatenation.
* `ft_strchr`: Locates the first occurrence of a character in a string.
* `ft_strrchr`: Locates the last occurrence of a character in a string.
* `ft_strncmp`: Compares two strings up to n characters.
* `ft_strnstr`: Locates a substring in a string.
* `ft_strdup`: Creates a duplicate of a string using `malloc`.
* `ft_atoi`: Converts a string to an integer.

**Additional String Manipulation**
* `ft_substr`: Extracts a substring from a string.
* `ft_strjoin`: Concatenates two strings into a new string.
* `ft_strtrim`: Trims characters specified in a set from the beginning and end of a string.
* `ft_split`: Splits a string into an array of strings using a delimiter character.
* `ft_itoa`: Converts an integer to a string.
* `ft_strmapi`: Applies a function to each character of a string to create a new modified string.
* `ft_striteri`: Applies a function to each character of a string, modifying it directly.

**File Descriptor Output**
* `ft_putchar_fd`: Outputs a character to the given file descriptor.
* `ft_putstr_fd`: Outputs a string to the given file descriptor.
* `ft_putendl_fd`: Outputs a string to the given file descriptor, followed by a newline.
* `ft_putnbr_fd`: Outputs an integer to the given file descriptor.

**Linked Lists**
* `ft_lstnew`: Allocates and returns a new node.
* `ft_lstadd_front`: Adds a new node at the beginning of the list.
* `ft_lstsize`: Counts the number of nodes in a list.
* `ft_lstlast`: Returns the last node of the list.
* `ft_lstadd_back`: Adds a new node at the end of the list.
* `ft_lstdelone`: Frees the memory of the node's content and the node itself.
* `ft_lstclear`: Deletes and frees the given node and every successor of that node.
* `ft_lstiter`: Iterates the list and applies a function to the content of each node.
* `ft_lstmap`: Iterates the list and applies a function to the content of each node, creating a new list resulting from the successive applications of the function.

---

## 🚀 How to Compile and Use

The project includes a `Makefile` that automates the compilation process, generating the static library **`libft.a`**.

### Compilation
In the terminal, from the project's root directory, use the following commands:

| Command | Action |
| :--- | :--- |
| `make` | Compiles all `.c` files and generates the library executable `libft.a`. |
| `make clean` | Removes all object files (`.o`) generated during compilation, cleaning the folder. |
| `make fclean` | Executes `clean` and also deletes the `libft.a` file. Leaves the repository clean. |
| `make re` | Executes `fclean` and recompiles the entire project from scratch. |

### Usage in your code
To use Libft in your own programs, simply include the header at the top of your `.c` file:

```c
#include "libft.h"

And, when compiling your program in the terminal, remember to link the static library:

cc your_program.c libft.a
