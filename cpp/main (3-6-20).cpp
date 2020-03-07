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
char Tail = '*';
int x = 6;
int y = 5;
// static int i = 6;
const int xLen = 12;
const int yLen = 12;
int xGrid = 10;
int yGrid = 10;
int AppleX = 0;
int AppleY = 0;

int tailSpace = 1; // space  berween head and tail, ++ as apples are collected
int score = 0;
int TailX = x - tailSpace;
int TailY = y - tailSpace;
bool checkForChange = false;
bool hasCollectedApple = true;
bool increaseTail = false;
bool wasGoingA = false;
bool wasGoingW = false;
bool wasGoingS = false;
bool wasGoingD = false;
int moveVar = 1;

char grid[yLen][xLen];

char moves[100];

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
            if(wasGoingA)
                {
                    grid[y+1][x-1] = '-';
                    wasGoingA = false;              // does this stuff work? i dont fricking know
                }
            else if(wasGoingD)
                {
                    grid[y-1][x+1] = '-';
                    wasGoingD = false;
                }

            


            if(movementInput == 'w')
                {
                    grid[x+tailSpace][y] = '-'; 
                }
        
            wasGoingW = true;
            
            // if(hasCollectedApple == true)
            // {
            //     grid[x+tailSpace+1][y] = Snake; 
            // }
            isGoingUp = true; 
            PrintGrid(); 
            TouchBorderCheck(); 
            if(increaseTail == true)
                {
                    // grid[x+tailSpace][y] = 'o';
                    increaseTail = false;
                }
            break; 
            
            
        
    case 'a': 
        
            y--;
            grid[x][y] = Snake;

            // if(wasGoingW)
            //     {
            //         grid[y+1][x+1] = '-';
            //         wasGoingW = false;
            //     }
            // else if(wasGoingS)
            //     {
            //         grid[y+1][x-1] = '-';
            //         wasGoingS = false;
            //     }



            if(movementInput == 'a')
            {
            grid[x][y+tailSpace] = '-';
            }
            // wasGoingA = true;
            // if(hasCollectedApple == true)
            // {
            // grid[x-tailSpace][y+tailSpace + 1] = Snake;
            // }
            // isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    // grid[x][y+tailSpace] = 'o';
                    increaseTail = false;
                }
            break;
            

    case 's':
        if(isGoingUp == false)
        {
            x++;
            grid[x][y] = Snake;


            // if(wasGoingA)
            //     {
            //         grid[y+tailSpace][x-1] = '-';
            //         wasGoingA = false;
            //     }

            // else if(wasGoingD)
            //     {
            //         grid[y-1][x-1] = '-';
            //         wasGoingD = false;
            //     }


            if(movementInput == 's')
            {
            grid[x-tailSpace][y] = '-';
            }
            wasGoingS = true;
            // if(hasCollectedApple == true)
            // {
            // grid[x-tailSpace - 1][y] = Snake;
            // }
            isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    // grid[x-tailSpace][y] = 'o';
                    increaseTail = false;
                }
            break;
        }
            
        case 'd':
        
            y++;
            grid[x][y] = Snake;

            // if(wasGoingS)
            //     {
            //         grid[y-1][x-1] = '-';
            //         wasGoingS = false;
            //     }
            // else if(wasGoingW)
            //     {
            //         grid[y-1][x+1] = '-';
            //         wasGoingW = false;
            //     }




            if(movementInput == 'd')
            {
            grid[x][y-tailSpace] = '-';
            }

            wasGoingD = true;
            // if(hasCollectedApple == true)
            // {
            //     grid[x][y-tailSpace - 1] = Snake;
            // }
            isGoingUp = false;
            PrintGrid();
            TouchBorderCheck();
            if(increaseTail == true)
                {
                    // grid[x][y-tailSpace] = 'o';
                    increaseTail = false;
                }
            break;
        }
            wait(.5);
            ClearScreen();
            moves[moveVar] = movementInput;      //
            moveVar++;                           //
            if(moveVar == 'w')                   //  << This does not work, but this attempts to have the tail follow the head while still "clearing" the space behind  it
                {                                //
                    grid[x-1][y] = 'x';          //
                }
           
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
        SetBorder();
        
      
    }
  if(!isAlive)
    {
        cout<<"Game Over"<<endl;
    }
}


