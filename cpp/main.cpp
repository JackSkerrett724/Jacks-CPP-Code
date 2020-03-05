#include <iostream>   
#include <string>   
#include <stdlib.h>   
#include <time.h>   
#include <ctime>
#include <conio.h>
using namespace std;

bool firstMovement = false; // yes this all looks ugly
bool isAlive = true;
bool isGoingUp = false;
char movementInput;
char Snake = '*';
int x = 6;
int y = 5;
static int i = 6;
const int xLen = 12;
const int yLen = 12;
int xGrid = 10;
int yGrid = 10;
int AppleX = 0;
int AppleY = 0;
int tailSpace = 1; // space  berween head and tail, ++ as apples are collected
int score = 0;
bool checkForChange = false;
bool hasCollectedApple = true;
bool increaseTail = false;

char grid[yLen][xLen];


void ClearScreen()
{
   system("CLS");
}

int End()
{
    return 0;
}

void wait ( double seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;  
  while (clock() < endwait) {}
}

void ResetGrid()
{
    for(int xPos = 0; xPos<xLen; xPos++)   
    {
        for(int yPos = 0; yPos<yLen; yPos++)   
        {
            grid[yPos][xPos] = '-';      
        }    
        cout<< '\n';   
    }
}

void AppleCheck()
{
    if(grid[y][x] == grid[AppleY][AppleX])
        {
            score++;
            hasCollectedApple = true;
            cout<<"Score: "; cout<<score<<endl;
            tailSpace++;
            increaseTail = true;
            
        }
}


void PlaceApple()   
{
    if(hasCollectedApple == true)   //WHY?!
        {
            AppleX = rand() % 8 + 1;   
            AppleY = rand() % 9 + 1;   
            grid[AppleY][AppleX] = 'A';
            hasCollectedApple = false;
            
        }
    else
        {
            AppleCheck();
        }
}   



void PrintGrid()//needs to like yaknow print the whole thing not one value
{
  for(int i = 0; i < xLen; ++i) 
    {
        for(int j = 0; j < yLen; ++j) 
        {
            cout<< grid[i][j]; cout<<" "; 
            
        }
        cout<<" "<<endl; 
    }
}

void SetBorder() 
{
    for(int i = 0; i < yLen; i++) 
    {  
        grid[i][0] = '/'; 
        grid[i][11] = '/';//(x/y)Len-1?19
    }
    for(int j = 0; j < xLen; j++) 
    {
        grid[0][j] = '/'; 
        grid[11][j] = '/'; 
    }
    
}

void TouchBorderCheck() 
{
    
    if(x > xGrid) 
    {
        isAlive = false; 
    }
    else if(x < xGrid-9) 
    {
        isAlive = false; 
    }
    else if(y > yGrid) 
    {
        
        isAlive = false;
    }
    else if(y < yGrid-9) 
    {
        // grid[y+1][x] = Snake;  
        // End();
        isAlive = false; 
    }
}

void GetMovement() 
{
    if(kbhit()) 
        {
            movementInput = getch(); 
        }
    
    
    // cin>>movementInput; <-- caused terminal to pause evry time input was wanted
    
    switch(movementInput) 
    {
    
    case 'w':  
            x--;
            grid[x][y] = Snake; 
            grid[x+tailSpace][y+tailSpace] = '-'; 
            // if(hasCollectedApple == true)
            // {
            //     grid[x+tailSpace+1][y] = Snake; 
            // }
            isGoingUp = true; 
            PrintGrid(); 
            TouchBorderCheck(); 
            if(increaseTail == true)
                {
                    grid[x+tailSpace][y] = 'o';
                    increaseTail == false;
                }
            break; 
            
            
        
    case 'a': 
        
            y--;
            grid[x][y] = Snake;
            grid[x+tailSpace][y+tailSpace] = '-';
            // if(hasCollectedApple == true)
            // {
            // grid[x-tailSpace][y+tailSpace + 1] = Snake;
            // }
            isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    grid[x][y+tailSpace] = 'o';
                    increaseTail == false;
                }
            break;
            

    case 's':
        if(isGoingUp == false)
        {
            x++;
            grid[x][y] = Snake;
            grid[x-tailSpace][y-tailSpace] = '-';
            // if(hasCollectedApple == true)
            // {
            // grid[x-tailSpace - 1][y] = Snake;
            // }
            isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    grid[x-tailSpace][y] = 'o';
                    increaseTail == false;
                }
            break;
        }
            
        case 'd':
        
            y++;
            grid[x][y] = Snake;
            grid[x-tailSpace][y-tailSpace] = '-';
            // if(hasCollectedApple == true)
            // {
            //     grid[x][y-tailSpace - 1] = Snake;
            // }
            isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    grid[x][y-tailSpace] = 'o';
                    increaseTail == false;
                }
            break;
        }
            wait(.5);
            ClearScreen();
        }
    
    
    
   
    


void InitStart()
{
    grid[6][5] = Snake;
}

int main()
{
    //   grid[0][0]= 'x';
    ResetGrid();
    PrintGrid();
    SetBorder();
    //   ResetGrid();
    //   PrintGrid();
    // grid[2][5] = 'f'; 
    // grid[5][4] = 'a';    These Were For Testing ^^
    // grid[0][0] = 'Z';
    cout<<"------------------------"<<endl;
    InitStart();
    PrintGrid();
    cin>>movementInput;
  while(isAlive)
    {  
        
        GetMovement(); 
        TouchBorderCheck();
        // PrintGrid();
        PlaceApple();
        
      
    }
  if(!isAlive)
    {
        cout<<"Game Over"<<endl;
    }
}
























































































































































































//gay12345678910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061626364656676869