#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[100];
int count = 0;

void addContact() {
    printf("Enter Name: ");
    scanf("%s", contacts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContact List:\n");
    for(int i = 0; i < count; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n\n", contacts[i].phone);
    }
}

void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
