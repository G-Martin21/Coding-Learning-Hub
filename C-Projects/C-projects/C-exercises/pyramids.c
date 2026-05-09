#include <stdio.h>

void build_block (int, int, int);
void print_block (int, char);
        

int main()
{
    int x = 5;
    for (int i = 1; i <= x; i++)
    {
        int leftblanks = x-i;
        int hashes = i;
        int middle = 2;

        build_block(leftblanks, hashes, middle);
        printf("\n");
    }
}

// Builds a block following the formula left_spaces + block_of_hashes + middle_separator + block_of_hashes
// In a future implementation we could add another argument with the type of block we want to use
void build_block (int leftblanks, int hashes, int middle)
{
    print_block(leftblanks, ' ');
    print_block(hashes, '#');
    print_block(middle, ' ');
    print_block(hashes, '#');
}

void print_block (int items, char block)
{
    char line;
        for (int i = 0; i < items; i++)
        {
            printf("%c", block);
        }
        
}
    