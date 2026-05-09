#include <stdio.h>
#include <cs50.h>

/*
    Recreate Mario pyramids using hashes as blocks to print out a pyramid with heigth between 1 to 8 blocks.
*/

void build_block(int, int, int);
void print_block(int, char);


int main()
{
    int heigth = 1;
    do
    {
        heigth = get_int("Enter the pyramid heigth as an integer 1 to 8: ");
    }
    while (heigth < 1 || heigth > 8);

    for (int i = 1; i <= heigth; i++)
    {
        int leftblanks = heigth - i;
        int hashes = i;
        int middle = 2;

        build_block(leftblanks, hashes, middle);
        printf("\n");
    }
}

// Builds a block following the formula left_spaces + block_of_hashes + middle_separator + block_of_hashes
// In a future implementation we could add another argument with the type of block we want to use

void build_block(int leftblanks, int hashes, int middle)
{
    print_block(leftblanks, ' ');
    print_block(hashes, '#');
    print_block(middle, ' ');
    print_block(hashes, '#');
}

void print_block(int items, char block)
{
    char line;
    for (int i = 0; i < items; i++)
    {
        printf("%c", block);
    }

}
