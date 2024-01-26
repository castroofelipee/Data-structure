#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};


void insertContact(struct Contact** head, const char* name, const char* phone) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    
    if (*head == NULL || strcmp(name, (*head)->name) < 0) {
        newContact->next = *head;
        *head = newContact;
        return;
    }

   
    struct Contact* current = *head;
    while (current->next != NULL && strcmp(name, current->next->name) > 0) {
        current = current->next;
    }

    
    newContact->next = current->next;
    current->next = newContact;
}


void displayContacts(struct Contact* head) {
    printf("Lista de Contatos:\n");
    while (head != NULL) {
        printf("Nome: %s, Telefone: %s\n", head->name, head->phone);
        head = head->next;
    }
}


void freeContacts(struct Contact** head) {
    while (*head != NULL) {
        struct Contact* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Contact* contactList = NULL;

    
    insertContact(&contactList, "Alice", "123456789");
    insertContact(&contactList, "Bob", "987654321");
    insertContact(&contactList, "Charlie", "555111222");

    
    printf("Lista de Contatos antes da ordenacao:\n");
    displayContacts(contactList);

    
    struct Contact* sortedList = NULL;
    while (contactList != NULL) {
        struct Contact* temp = contactList;
        contactList = contactList->next;
        insertContact(&sortedList, temp->name, temp->phone);
        free(temp);
    }

    
    printf("\nLista de Contatos depois da ordenacao:\n");
    displayContacts(sortedList);

    
    freeContacts(&sortedList);

    return 0;
}
