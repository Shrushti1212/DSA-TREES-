#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char name[50];
    struct Song *prev;
    struct Song *next;
};

struct Song *head = NULL;

void addSong()
{
    struct Song *newNode,*temp;

    newNode = (struct Song*)malloc(sizeof(struct Song));

    printf("Enter song name: ");
    scanf("%s",newNode->name);

    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Song added successfully\n");
}

void deleteSong()
{
    struct Song *temp = head;
    char name[50];

    printf("Enter song name to delete: ");
    scanf("%s",name);

    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    while(temp != NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            if(temp == head)
                head = temp->next;

            if(temp->prev != NULL)
                temp->prev->next = temp->next;

            if(temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);

            printf("Song deleted\n");
            return;
        }

        temp = temp->next;
    }

    printf("Song not found\n");
}

void displayPlaylist()
{
    struct Song *temp = head;

    if(head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }

    printf("Playlist Songs:\n");

    while(temp != NULL)
    {
        printf("%s -> ",temp->name);
        temp = temp->next;
    }

    printf("NULL\n");
}

void saveToFile()
{
    FILE *fp;
    struct Song *temp = head;

    fp = fopen("playlist.txt","w");

    if(fp == NULL)
    {
        printf("File error\n");
        return;
    }

    while(temp != NULL)
    {
        fprintf(fp,"%s\n",temp->name);
        temp = temp->next;
    }

    fclose(fp);

    printf("Playlist saved to file\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\nMusic Playlist Manager\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Save Playlist to File\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: displayPlaylist(); break;
            case 4: saveToFile(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
