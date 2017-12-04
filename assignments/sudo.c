/*KEVIN LE*/

/* IMPORTANT! 

INPUT MUST BE IN SAVED IN FILE NAMED 'input.txt' 
IN CURRENT DIRECTORY FOR PROGRAM TO WORK       */

#include <stdio.h>

int canExecute(int sudoku[][9], int row, int col, int num)
{
    int rowBeginning = (row/3) * 3;
    int colBeginning = (col/3) * 3;
    int i, j;
    for(i=0; i<9; ++i)
    {
        if (sudoku[row][i] == num) return 0;
        if (sudoku[i][col] == num) return 0;
        if (sudoku[rowBeginning + (i%3)][colBeginning + (i/3)] == num) return 0;
    }
    return 1;
}
int createSudoku(int sudoku[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(sudoku[row][col] != 0)
        {
            if((col+1)<9) return createSudoku(sudoku, row, col+1);
            else if((row+1)<9) return createSudoku(sudoku, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(canExecute(sudoku, row, col, i+1))
                {
                    sudoku[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(createSudoku(sudoku, row, col +1)) return 1;
                        else sudoku[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(createSudoku(sudoku, row+1, 0)) return 1;
                        else sudoku[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}
int main( void )
{
    char filename[] = "input.txt";
    char nums[81];
    int intnums[81];
    int sudoku[9][9];
    int i, j, k;
   
    
  FILE *file = fopen ( filename, "r" );
  k=0;
  if (file != NULL) {
    char line [1000];
    printf("%c\n\n", ' ');
    printf("%s\n\n", "problem:");
    while(fgets(line,sizeof line,file)!= NULL) {
      if(line[0]!='+'){
          j=1;
          for(i=0;i<9;i++){
              nums[k]=line[j];
              k++;
              j+=2;
          }
      }
        printf("%s", line);
    }
      for(i=0;i<81;i++){
      if(nums[i]==' '){
          nums[i]='0';
      }
      intnums[i] = nums[i] - '0';
      }
      k=0;
      for(i=0;i<9;i++){
          for(j=0;j<9;j++){
              sudoku[i][j]=intnums[k];
              k++;
          }
      }
    fclose(file);
  }
  else {
    perror(filename); 
  }
    
    printf("%c\n\n", ' ');
    printf("%s\n", "solution:");
    if(createSudoku(sudoku, 0, 0))
    {
        printf("\n+-+-+-+-+-+-+-+-+-+\n");
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) printf("|%d", sudoku[i-1][j-1]);
            printf("|\n");
            printf("+-+-+-+-+-+-+-+-+-+\n");
        }
            printf("%c\n\n", ' ');
    }
    else printf("\n\nNO SOLUTION\n\n");
    return 0;
}
