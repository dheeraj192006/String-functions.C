#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;
void addBook();
void searchBook();
void deleteBook();
void listBooks();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Book Records Management ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. List All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                listBooks();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Error: Maximum book limit reached.\n");
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 

    books[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully with ID %d.\n", newBook.id);
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found: ID=%d, Title=%s, Author=%s\n", books[i].id, books[i].title, books[i].author);
            return;
        }
    }

    printf("No book found with the title '%s'.\n", searchTitle);
}
void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d.\n", id);
    }

void listBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID=%d, Title=%s, Author=%s\n", books[i].id, books[i].title, books[i].author);
    }
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
