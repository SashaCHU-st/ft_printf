# ft_printf

Creating your own program that behaves like the standard library function printf involves implementing formatted output functionality.

### This is achieved by parsing the format string, handling placeholders:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign

## Usage
1. Clone repository
2. Move to directory
```bash
cd ft_printf
```
3. Add the main function to the ft_printf 
```bash
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! The number is %d.\n", "world", 35);
    return 0;
}
```
4. Run make file
```bash
make
```
5. Expected output
```bash
Hello, world! The number is 35
```
