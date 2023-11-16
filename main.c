# include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

ssize_t custom_write(int fd, const void *buf, size_t count) {
    // Simulate write failure
    return -1;
}

// Undefine the macro after testing to restore the original write
#undef write

int main() {
    // Example usage
    char message[] = "Hello, World!";
    ssize_t result = custom_write(1, message, sizeof(message) - 1);

    // Check the result
    if (result == -1) {
        perror("Write failed");
        // Handle the failure
    } else {
        printf("Write succeeded\n");
    }

    return 0;
}