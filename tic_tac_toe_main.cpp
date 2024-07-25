#include<iostream>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>

int partition=0;

// Function to change Cursor Position..
void setCursorPosition(int x,int y){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {static_cast<SHORT>(x),static_cast<SHORT>(y)};
    SetConsoleCursorPosition(hconsole,position);
}

// Change Console Color...
void setcolor(int color){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}

// Playing Area....
void horizontal_section_main_frame(){
    std::cout<<"+";
    for(int i=0; i<25; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"+";
    for(int i=0; i<25; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"+\n";
}

void draw_frame()
{
    horizontal_section_main_frame();
    for(int i=0;i<=10;i++)
    {
        std::cout<<"|";
        for(int j=0;j<51;j++)
        {
            std::cout<<" ";
        }
        std::cout<<"|";
        std::cout<<"\n";
    }
    horizontal_section_main_frame();
}

void create_partition()
{
    setcolor(6);
    int positionY=1;
    partition=1;
    for(int i=0;i<=10;i++)
    {
        setCursorPosition(26,positionY++);
        std::cout<<"|";
    }
    setcolor(15);
}

void extend_frame(){
    setCursorPosition(0,12);
    horizontal_section_main_frame();
    std::cout<<"|";
    for(int i=0;i<51;i++)
    {
        std::cout<<" ";
    }
    std::cout<<"|\n";
    horizontal_section_main_frame();
}

void shrink_frame(){
    int positionY=13;
    for(int j=0;j<2;j++)
    {
        setCursorPosition(0,positionY++);
        for(int i=0;i<55;i++)
        {
            std::cout<<" ";
        }
    }
}
//Function to calculate length of array...
template <typename T, size_t N>
constexpr size_t arrayLength(T (&)[N])
{
    return N;
}

void clear_frame(int positionX=1,int positionY=1,int n=11)
{
    int w=51;
    if(partition==1)
    {
        w=24;
        positionX=27;
    }
    setCursorPosition(positionX,positionY++);
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<w;j++)
        {
            std::cout<<" ";
        }
        setCursorPosition(positionX,positionY++);
    }
} 

//print function
void print(std::string* m,int arr_length)
{
    int w=51;
    int positionX=1,positionY=((11-arr_length)/2);
    clear_frame();
    if(partition==1)
    {
        w=25;
        positionX=27;
    }
    if((11-arr_length)%2!=0)
    {
        positionY++;
    }
    setCursorPosition(positionX,positionY);
    for(int i=0;i<arr_length;i++)
    {
        std::cout<<std::setw(((w-m[i].length())/2)+m[i].length())<<m[i];
        setCursorPosition(positionX,++positionY);
    }
}

//Game Board
void vertical_section(){
    std::cout<<"     |     |\n";
}

void horizontal_section()
{
    for(int i=0;i<5;i++){
        std::cout<<"-";
    }
    std::cout<<"+";
    for(int i=0;i<5;i++){
        std::cout<<"-";
    }
    std::cout<<"+";
    for(int i=0;i<5;i++){
        std::cout<<"-";
    }
}

void create_game_board(){
    int positionX=5;
    int positionY=4;
    if(partition==1)
    {
        positionX=31;
    }
    setCursorPosition(positionX,positionY);
    vertical_section();
    for(int i=0; i<2; i++)
    {
        setCursorPosition(positionX,++positionY);
        horizontal_section();
        setCursorPosition(positionX,++positionY);
        vertical_section();
    }
}

void board_preview()
{
    setcolor(15);
    create_game_board();
    setcolor(14);
    int positionY=4;
    int name=1; 
    for(int i=0;i<3; i++){
        setCursorPosition(7,positionY);
        std::cout<<name++;
        setCursorPosition(13,positionY);
        std::cout<<name++;
        setCursorPosition(19,positionY++);
        std::cout<<name++;
        positionY++;
    }
    create_partition();
}

//Game Section
void greet()
{
    setcolor(14);
    std::string greet_message[]={"","Tic ","Tac ","Toe!!"};
    print(greet_message,arrayLength(greet_message));
    Sleep(2000);
}

void winning_message(int p)
{
    setcolor(10);
    partition=0;
    clear_frame();
    setCursorPosition(15,6);
    std::cout<<"Hey Player "<<p+1<<" you won!!";
    shrink_frame();
    Sleep(2000);
}

void thanks(){
    setcolor(14);
    std::string thanks_message[]={"","Thanks for Playing..."};
    print(thanks_message,2);
    Sleep(2000);
    system("CLS");
}

void play()
{
    std::string about1[]={"","There will be","2 Players","First ( O )","Second ( X )","Press Enter to Continue"};
    print(about1,arrayLength(about1));
    int input;
    input=getch();
    if(input!=13)
    {
        return;
    }
    clear_frame();
    board_preview();
    std::string instructions[]={"","Insert Number","to initiate","your Move"};
    print(instructions,arrayLength(instructions));
    Sleep(2000);
    clear_frame();
    create_game_board();
    extend_frame();
    int boxes_filled=0;
    int input_value[9]={0};
    char input_ch;
    setcolor(14);
    while(boxes_filled!=9)
    {
        for(int i=0;i<2;i++)
        {
            setcolor(14);
            setCursorPosition(1,13);
            std::cout<<"                  ";
            setCursorPosition(4,13);
            std::cout<<"Player "<<i+1<<": ";
            std::cin>>input;
            if(input_value[input-1]==0)
            {
                if(i==0){
                    input_value[input-1]=1;
                    input_ch='O';
                }
                else if(i==1){
                    input_value[input-1]=2;
                    input_ch='X';
                }
                else{
                    std::cout<<"inside else..";
                }
            }
            else{
                setCursorPosition(1,13);
                std::cout<<"                  ";
                setCursorPosition(1,13);
                setcolor(5);
                std::cout<<"  Already Filled!!";
                i--;
                Sleep(1500);
                continue;
            }
            switch (input)
            {
                case 1 : setCursorPosition(33,4); break;
                case 2 : setCursorPosition(39,4); break;
                case 3 : setCursorPosition(45,4); break;
                case 4 : setCursorPosition(33,6); break;
                case 5 : setCursorPosition(39,6); break;
                case 6 : setCursorPosition(45,6); break;
                case 7 : setCursorPosition(33,8); break;
                case 8 : setCursorPosition(39,8); break;
                case 9 : setCursorPosition(45,8); break;
                default: std::cout<<"Wrong Choice"; break;
            }
            std::cout<<input_ch;
            boxes_filled++;
            setCursorPosition(1,17);
            if(boxes_filled>=5 && boxes_filled<9){
                for(int j=0;j<3;j++)
                {
                    if((input_value[j]==input_value[j+3])&&(input_value[j+3]==input_value[j+6])&&input_value[j]!=0)
                    {
                        winning_message(i);
                        return;
                    }
                    int t=0;
                    switch (j){
                        case 0: t=0;break;
                        case 1: t=3;break;
                        case 2: t=6;break;
                        default: t=0;break;
                    }
                    if((input_value[t]==input_value[t+1])&&(input_value[t+1]==input_value[t+2])&&input_value[t]!=0){
                        winning_message(i);
                        return;
                    }
                    else if((input_value[0]==input_value[4])&&(input_value[4]==input_value[8])&&input_value[j]!=0){
                        winning_message(i);
                        return;
                    }
                    else if((input_value[2]==input_value[4])&&(input_value[4]==input_value[6])&&input_value[j]!=0){
                        winning_message(i);
                        return;
                    }
                }
            }
            else if(boxes_filled==9){
                partition=0;
                setcolor(5);
                std::string draw_message[]={"Draw.."};
                print(draw_message,1);
                shrink_frame();
                Sleep(2000);
                break;
            }
            else{
                continue;
            }
        }
    }
}

void ask_to_play()
{
    while(1)
    {
        setcolor(14);
        std::string ask_message[]={"Press Enter ","To","Play","(Else press any Key)"};
        print(ask_message,arrayLength(ask_message));
        int input;
        input=getch();
        if(input==13)
        {
            play();
        }
        else{
            thanks();
            break;
        }
    }
}

int main()
{
    system("CLS");
    draw_frame();
    greet();
    ask_to_play();
    return 0;
}