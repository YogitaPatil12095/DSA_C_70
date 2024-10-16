#include <stdio.h>
#include <string.h>

// Function to perform binary search
int binarySearch(char books[][50], int size, char *target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the middle book title with the target title
        int comparison = strcmp(books[mid], target);

        if (comparison == 0) {
            return mid; // Book found at index mid
        }
        else if (comparison < 0) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Book not found
}

int main() {
    // Array of book titles sorted alphabetically
    char books[][50] = {
        "A Tale of Two Cities", "Brave New World", "Catch-22",
        "Don Quixote", "Moby Dick", "Pride and Prejudice", "The Great Gatsby"
    };

    int size = sizeof(books) / sizeof(books[0]);

    // Book title to search for
    char target[50];
    printf("Enter the book title you are searching for: ");
    fgets(target, 50, stdin);

    // Remove the newline character from the input
    target[strcspn(target, "\n")] = 0;

    // Perform binary search
    int result = binarySearch(books, size, target);

    if (result != -1) {
        printf("\"%s\" found at index %d.\n", target, result);
    } else {
        printf("\"%s\" not found in the library.\n", target);
    }

    return 0;
}
