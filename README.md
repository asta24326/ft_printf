*This project has been created as part of the 42 curriculum by asharafe.*

# 🖨️ ft_printf

### ✅ Result: 100/100

## 📄 Description
The goal of this project is pretty straightforward: you will recode the famous standard C library function `printf()`. This exercise is a great opportunity to discover variadic functions in C and understand how to build a well-structured and extensible parsing logic. Once finished, this function can be integrated into the Libft library to be used in future C projects.



---

## 🎯 Acquired Skills
* **Variadic Functions**: Learning how to use `va_start`, `va_arg`, `va_copy`, and `va_end` to handle a variable number of arguments.
* **String Formatting**: Mastering the art of processing conversion specifiers and flags.
* **Extensible Code**: Designing a function structure that allows for easy addition of new features.
* **Memory Management**: Ensuring all outputs are handled correctly without leaks or buffer overflows.
* **Standard Libc**: Gaining deeper insight into one of the most versatile functions in C.

---

## 🛠 Contents
The project implements a simplified version of `printf` that handles the following conversions:
* `%c` - Prints a single character.
* `%s` - Prints a string.
* `%p` - Prints a void * pointer in hexadecimal format.
* `%d` / `%i` - Prints a decimal (base 10) number.
* `%u` - Prints an unsigned decimal (base 10) number.
* `%x` - Prints a number in hexadecimal (base 16) lowercase format.
* `%X` - Prints a number in hexadecimal (base 16) uppercase format.
* `%%` - Prints a percent sign.

---

## ⚙️ Compilation
The project includes a `Makefile` that compiles the source files into a `libftprintf.a` library.

To compile the mandatory part:
```bash
make

```

To clean object files:

```bash
make clean

```

To clean the project (files and library):

```bash
make fclean

```

---

## 🧪 How to Use

To use `ft_printf` in your project, include the header and link the library during compilation.

1. **Include the header**:

```c
#include "ft_printf.h"

```

2. **Call the function**:

```c
ft_printf("Hello %s, the result is %d\n", "User", 42);

```

3. **Compile**:

```bash
cc main.c libftprintf.a -o my_project

```

---

## 💡 AI Usage

AI tools were used during the development of this project for:

* **Documentation**: Structuring the README to follow the gold standard established for 42 projects.
* **Edge Case Logic**: Brainstorming how to handle `NULL` pointers in `%s` or `%p` conversions.
* **Variadic Concepts**: Clarifying the internal workings of the `stdarg.h` macros.
* *Note: The core parsing logic and conversion implementations were developed manually.*

---

## 🔗 Resources

* `man`: `va_start`, `va_arg`, `va_end`, `printf`.
* 42 Project Subject: ft_printf.
* [Variadic Functions in C - GeeksforGeeks](https://www.geeksforgeeks.org/variadic-functions-in-c/).