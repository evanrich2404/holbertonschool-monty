#include "monty.h"

void pall_monty(const stack_t *h)
{
    size_t i = 0;
    while (h)
    {
        printf("So here is a val: %i\n", h->n);
        h = h->next;
        i++;
    }
}

int open_and_read(stack_t *head, char *filename)
{
    FILE *filePointer;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;
    char *token;
    char *arg;
    size_t counter = 0;
    stack_t *ptr = head;

    filePointer = fopen(filename, "r");
    if (filePointer == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    while ((read = getline(&line, &len, filePointer)) != -1)
    {
        line_number++;
        printf("Got this line: %s\n\n", line);
        // separate line into tokens
        token = strtok(line, " ");

        while (token != NULL)
        {
            if (strcmp(token, "push") == 0)
            {
                arg = strtok(NULL, " ");
                printf("I have %s and its argument %s\n", token, arg);

                int val = atoi(arg);
                ptr = push_monty(ptr, line_number, val);

                break;
            }
            token = strtok(NULL, " ");
        }

        // show values in stack 
        pall_monty(ptr);
    }

    fclose(filePointer);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

stack_t* push_monty(stack_t *stack, unsigned int line_number, int val)
{
    stack_t *new = malloc(sizeof(stack_t));
    
    new->n = val;
    stack->prev = new;
    new->next = stack;
    new->prev = NULL;

    return new;
}

int is_number(char *token)
{
    return isdigit(token);
}

/**
 * main - Main entry
 * Description: Monty bytecodes files interpreter
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
 */
int main(int argc, char **argv)
{
    stack_t initial = {-1, NULL, NULL};
    stack_t *head = &initial;

    if (argc != 2)
    {
        printf("USAGE: monty file \n");
        exit(EXIT_FAILURE);
    }

    open_and_read(head, argv[1]);
    return (0);
}
