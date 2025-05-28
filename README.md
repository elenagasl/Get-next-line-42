# get_next_line

This project is part of the 42 school curriculum. The goal is to implement a function, `get_next_line`, that reads from a file descriptor line by line. Each call to the function returns the next line of the file, including the newline character if present.

## Description

`get_next_line` is designed to handle input from file descriptors, reading one line at a time in a memory-efficient way. It manages a static buffer to retain leftover data between calls, and dynamically allocates memory for each line returned.

You must ensure your function works with multiple file descriptors and handles edge cases such as very large files, empty lines, or `read()` returning less than `BUFFER_SIZE`.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Allowed Functions

- `read`
- `malloc`
- `free`

You are not allowed to use any other libc functions, including functions like `strchr`, `strlen`, or `memcpy`. You must implement your own versions if needed.

## Compilation

There is **no Makefile** provided for this project.

To compile your function manually:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

You can change the value of `BUFFER_SIZE` as needed for testing.

## File Structure

```
get_next_line/
├── get_next_line.c         // Main implementation
├── get_next_line_utils.c   // Helper functions
├── get_next_line.h         // Header file
├── main.c                  // (optional) test file
└── README.md               // Project documentation
```

## Usage Example

```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## Author

Developed by Elena as part of the 42 School curriculum.
