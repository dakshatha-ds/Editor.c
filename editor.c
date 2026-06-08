#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    printf("\nCurrent Picture:\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawLine()
{
    int i;
    for(i = 5; i < 20; i++)
    {
        canvas[2][i] = '*';
    }
    printf("Line Drawn Successfully\n");
}

void drawRectangle()
{
    int i;

    for(i = 10; i < 20; i++)
    {
        canvas[5][i] = '*';
        canvas[10][i] = '*';
    }

    for(i = 5; i <= 10; i++)
    {
        canvas[i][10] = '*';
        canvas[i][19] = '*';
    }

    printf("Rectangle Drawn Successfully\n");
}

void drawTriangle()
{
    canvas[15][15] = '*';
    canvas[16][14] = '*';
    canvas[16][16] = '*';

    canvas[17][13] = '*';
    canvas[17][17] = '*';

    canvas[18][12] = '*';
    canvas[18][13] = '*';
    canvas[18][14] = '*';
    canvas[18][15] = '*';
    canvas[18][16] = '*';
    canvas[18][17] = '*';
    canvas[18][18] = '*';

    printf("Triangle Drawn Successfully\n");
}

void drawCircle()
{
    canvas[12][30] = '*';
    canvas[13][29] = '*';
    canvas[13][31] = '*';
    canvas[14][28] = '*';
    canvas[14][32] = '*';
    canvas[15][29] = '*';
    canvas[15][31] = '*';
    canvas[16][30] = '*';

    printf("Circle Drawn Successfully\n");
}

void addObject(int x, int y)
{
    if(x >= 0 && x < COLS && y >= 0 && y < ROWS)
    {
        canvas[y][x] = '*';
        printf("Object Added Successfully\n");
    }
}

void deleteObject(int x, int y)
{
    if(x >= 0 && x < COLS && y >= 0 && y < ROWS)
    {
        canvas[y][x] = '_';
        printf("Object Deleted Successfully\n");
    }
}

void modifyObject(int x, int y)
{
    if(x >= 0 && x < COLS && y >= 0 && y < ROWS)
    {
        canvas[y][x] = '#';
        printf("Object Modified Successfully\n");
    }
}

int main()
{
    int choice, x, y;

    clearCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Add Object\n");
        printf("6. Delete Object\n");
        printf("7. Modify Object\n");
        printf("8. Display Picture\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawLine();
                break;

            case 2:
                drawRectangle();
                break;

            case 3:
                drawTriangle();
                break;

            case 4:
                drawCircle();
                break;

            case 5:
                printf("Enter x and y position: ");
                scanf("%d %d", &x, &y);
                addObject(x, y);
                break;

            case 6:
                printf("Enter x and y position: ");
                scanf("%d %d", &x, &y);
                deleteObject(x, y);
                break;

            case 7:
                printf("Enter x and y position: ");
                scanf("%d %d", &x, &y);
                modifyObject(x, y);
                break;

            case 8:
                displayCanvas();
                break;

            case 9:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}