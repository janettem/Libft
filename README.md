# Libft
In this project for @hivehelsinki, my task was to recode several functions of the C standard library, as well as other useful functions.

## Libft
In this project, the task was to code a library of several functions of the libc, as well as other useful functions.

### Libc Functions
In the first part, the goal was to recode a set of the libc functions, as defined in their man pages. The functions are *atoi*, *bzero*, *isalnum*, *isalpha*, *isascii*, *isdigit*, *isprint*, *memccpy*, *memchr*, *memcmp*, *memcpy*, *memmove*, *memset*, *strcat*, *strchr*, *strcmp*, *strcpy*, *strdup*, *strlcat*, *strlen*, *strncat*, *strncmp*, *strncpy*, *strnstr*, *strrchr*, *strstr*, *tolower*, and *toupper*. The names of the functions are prefixed by "ft_" (for example, *atoi* gets renamed *ft_atoi*).

### Additional Functions
In the second part, the goal was to code functions that are not a part of the libc (at least not in the same form). The functions are *ft_itoa*, *ft_memalloc*, *ft_memdel*, *ft_putchar*, *ft_putchar_fd*, *ft_putendl*, *ft_putendl_fd*, *ft_putnbr*, *ft_putnbr_fd*, *ft_putstr*, *ft_putstr_fd*, *ft_strclr*, *ft_strdel*, *ft_strequ*, *ft_striter*, *ft_striteri*, *ft_strjoin*, *ft_strmap*, *ft_strmapi*, *ft_strnequ*, *ft_strnew*, *ft_strsplit*, *ft_strsub*, and *ft_strtrim*.

### Bonus Functions
In the bonus part, the goal was to code functions to manipulate lists using the structure below.

```
typedef struct  s_list
{
  void          *content; //The content
  size_t        content_size; //The size of the content
  struct s_list *next; //The pointer to the next link
}               t_list;
```

The functions are *ft_lstadd*, *ft_lstdel*, *ft_lstdelone*, *ft_lstiter*, *ft_lstmap*, and *ft_lstnew*.

We were also allowed to code more bonus functions, and I coded *abs*, *islower*, *isspace*, and *isupper* as defined in their man pages. Also, I prefixed the names of the functions with "ft_."

## *Get_next_line*
In this project, the task was to code *get_next_line*, a function to read a file descriptor line-by-line.

## *Ft_printf*
In this project, the task was to recode *printf* as defined in its man page with a few exceptions specified below. The name of the function is prefixed by "ft_."

### Flag Characters
The function manages the flag characters: #, 0, -, ' ' (a space), and +.

### Field Width
The function manages the minimum field width.

### Precision
The function manages the precision.

### Length Modifier
The function manages the length modifiers: hh (in hhd, hhi, hho, hhu, hhx, and hhX), h (in hd, hi, ho, hu, hx, and hX), l (ell) (in ld, li, lo, lu, lx, lX, and lf), ll (ell-ell) (in lld, lli, llo, llu, llx, and llX), and L (in Lf).

### Conversion Specifiers
The function manages the conversion specifiers: d, i, o, u, x, X, f, c, s, p, and %.

## Installation and Usage
Clone the repository by pasting "`git clone https://github.com/janettem/Libft.git Libft`" to your terminal. Then, move to the directory: `cd Libft`. Then, compile the library: `make`.

You can now use the functions in your program, like in the example below.

```
#include "incls/libft.h"
#include "incls/get_next_line.h"
#include "incls/ft_printf.h"

int main(void)
{
  ft_printf("Hello, World!\n");
  return (0);
}
```

Compile your program: `gcc my_program.c libft.a -o my_program`. Then, execute it: `./my_program`.
