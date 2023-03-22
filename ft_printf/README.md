# 42seoul-ft_printf
> This project is to recode printf.\
You will mainly learn how to use variadic arguments.

## Common Instructions
- Norm
- No error(segmentation falut, bus error, double free, etc)
- No leak
- Submit Makefile which will compile your source files
  - Flags -Wall, -Wextra and -Werror
  - Use cc(compiler)
  - No relink
  - Least contain $(NAME), all, clean, fclean, re
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers libraies or functions that are forbidden on the main part of the project.\
Bonuses must be in a different file _bonus.{c/h}.
- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile.\
Your project's Makefile must compile the library by using its Makefile, then compile the project.

## Mandatory part
![image](https://user-images.githubusercontent.com/74703501/144169956-8dbbf4c3-72f2-457a-974b-e7fd75057ceb.png)
- The prototype of ft_printf should be <b>int ft_printf(const char *, ...);</b>
- You have to recode the <b>libc's printf</b> function
- It must not do the buffer management like the real <b>printf</b>
- It will manage the following conversions: <b>cspdiuxX%</b>
- It will be compared with the real printf
- You must use the command ar to create your library, using the command libtool is forbidden
- A small description of the required conversion:
  - %c print a single character.
  - %s print a string of characters.
  - %p The void *pointer argument is printed in hexadecimal.
  - %d print a decimal (base 10) number.
  - %i print an integer in base 10.
  - %u print and unsigned decimal (base 10) number.
  - %x print a number in hexadecimal (base 16), with lowercase.
  - %X print a number in hexadecimal (base 16), with uppercase.
  - %% print a percent sign.
  
![image](https://user-images.githubusercontent.com/74703501/144170728-07118ff8-feb9-4816-913c-c1a5c7e7dc53.png)

## Bonus part
- Manage any combination of the following flags: '-0.' and minumum field width with all conversions
- Manage all the following flags: '# +' (yes, one of them is a space)

![image](https://user-images.githubusercontent.com/74703501/144170869-df95335f-8477-4d95-a0f3-a1e630e53962.png)

## Background
- variable argument
  - 인자의 개수가 변할 수 있는 것을 의미
  - 인자로 아무것도 넘겨주지 않을 수도 있고, 여러 개의 인자를 넘겨줄 수도 있음
  - 고정 인자는 무조건 1개 이상이어야 함 (기준이 되는 주소가 필요하기 때문)
  - 가변인자를 나타내는 ...은 파라미터 순서 상 가장 뒤에 있어야 함(ex. int ft_printf(char cont *format, ...);)
  
- <stdarg.h>
  - Types
    - va_list : Type to hold information about variable arguments (type)
  - Macro functions
    - va_start : Initialize a variable argument list (macro)
    - va_arg : Retrieve next argument (macro)
    - va_end : End using variable argument list (macro)
    - va_copy : Copy variable argument list (macro)
    ```c
    // last is fixed argument. This fixed argument allows 'va_start' to determine the location of the first variable argument
    // #define va_start(ap, v) ( (ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v))
    void  va_start(va_list ap, last);
    // #define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(T)))
    type  va_arg(va_list ap, type);
    // #define va_end(ap) (ap = (va_list)0);
    void  va_end(va_list ap);
    void  va_copy(va_list dest, va_list src);
    ```
  
- format placeholder specification
  - %[parameter][flags][width][.precision]type
    - parameter
      - n$ : n is the number of the parameter to disply using this format specifier, allowing the parameters provided to be output multiple times, using varying format specifiers or in different orders.
    - flags
      - minus(-) : lefg-align the output of this placeholder. (The default is to right-align the output.)
      - plus(+) : prepends a plus for positive signed-numeric types. positive= +, negative = -.(The default doesn't prepend anything in front of positive numbers.)
      - space( ) : Prepends a space for positive signed-numeric types. positive = (space), negative = -. This flag is ignored if the + flag exists. (The default doesn't prepend anything in front of positive numbers.)
      - zero(0) : When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces.)
      - hash(#) : For g and G types, trailing zeros are not removed. For f, F, e,E, g,G types, the output always contains a decimal point. For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.
    - width
      - The width field specifies a minimum number ofd characters to output, and is typically used to pad fixed-width fields in tabulated output, where the fields would otherwise be smaller, although is does not cause truncation of oversized fields.\
      The width field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk *.\
      Thought not part of the width field, a leading zero is interpreted as the zero-padding flag mentioned above, and a negative value is treated as the positive value in conjunction with the left-alignment - flag also mentioned above.
    - precision
      - The precision field usually specifies a maximum limit on the output, depending on the particular formatting type.\
      For floating point numeric types, it specifies the number of digits to the right of the decimal point that the output should be rounded.\
      For the string type, it limits the number of characters that should be ouput, after which the string is truncated.\
      The precision field may be omitted, or a numeric integer value, or a dynamic value when passed as another argument when indicated by an asterisk *.
    - type
      - % : Prints a literal % character (this type doesn't accept any flags, width, precision, length fields).
      - d, i : int as a signed integer. %d and %i are synonymous for output, but are different when used with scanf for input (where using %i will interpret a number as hexadecimal if it's preceded by 0x, and octal if it's preceded by 0.)
      - u : Print decimal unsigned int.
      - x, X : unsigned int as a hexadecimal number. x uses lower-case letters and X uses upper-case.
      - o : unsigned int in octal.
      - s : null-terminated string.
      - c : char (character).
      - p : void *(pointer to void) in an implementation-defined format.

## What I Learned
1. variable arguments
2. 문제 파악의 중요성

ft_printf 과제를 통해 가변인자를 다루는 방법에 대해 학습했다.\
Mandatory part는 가변 인자에 초점을 맞춰서 과제를 수행했지만, Bonus는 width와 precision의 관계를 확실하게 정립하지 못 해서 분기 처리에 초점을 맞추게 되었다.\
그래서 그런지 코드가 지져분 해지고, 처음에 작성한 코드에서 너무 많이 바뀌어 버렸다.\
따라서 다음 과제를 수행할 때는 과제를 진행하기 전에 필요한 사전 지식을 확실하게 학습하고 시작하도록 해야겠다.\
