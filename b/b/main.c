// Algorithm.cpp : Defines the entry point for the console application.
//board 记录每个子是谁下的
//weight 记录每个位置的权值 指导机器人下一步下到哪里
//connected_table 保证5连接的子被统计次数不大于两次
#define _CRT_SECURE_NO_WARNNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define LARGEUR 11
#define HAUTEUR 11

enum JOUEUR
{
    EMPTY,
    USER,
    MACHINE,
};

//global variables definition
int is_initialized = 0;
int is_game_over = 0;

int board[LARGEUR][HAUTEUR];
int weight[LARGEUR][HAUTEUR]; //board weight
int connected_table[LARGEUR][HAUTEUR]; //connect count, one cell only contains in two connect list, so in this connected table value should smaller than 2

int user_connnected_number;
int machine_connnected_number;

//game over flag
int game_over_number;
int is_set_game_over_number; //if the number set, which means once there's "is_set_game_over_number" connected pieces would directly trigger game finished.
enum JOUEUR winner = EMPTY;

char user_display = 'X';
char machine_display = 'O';
char empty_display = '-';

int abs_max(int a, int b)
{
    return abs(a) > abs(b) ? abs(a) : abs(b);
}

void increase_cell_weight(int x, int y, int factor, enum JOUEUR joueur)
{
    if (joueur == MACHINE)
        weight[x][y] += factor;
    else
        weight[x][y] += 2 * factor;
}

int get_decrease_vertical_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x - k][y] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number == 0 && connected_table[x - k][y] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = -k;
    return count;
}

int get_increase_vertical_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x + k][y] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x + k][y] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = k;
    return count;
}

int get_decrease_horizontal_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x][y - k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x][y - k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = -k;
    return count;
}

int get_increase_horizontal_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x][y + k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x][y + k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = k;
    return count;
}

int get_decrease_left_lean_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x-k][y-k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x - k][y - k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = -k;
    return count;
}

int get_increase_left_lean_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x+k][y + k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x + k][y + k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = k;
    return count;
}

int get_decrease_right_lean_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x - k][y + k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x + k][y - k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = -k;
    return count;
}

int get_increase_right_lean_same_piece_count(int x, int y, enum JOUEUR joueur, int* range)
{
    int count = 0;
    int k = 0;
    while (board[x + k][y - k] == joueur && x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
    {
        if (is_set_game_over_number==0 && connected_table[x - k][y + k] <= 2)
            break;
        ++k;
        ++count;
    }
    *range = k;
    return count;
}

//when set is_game_over_number, call this function to check if achive game_over_number
int game_over(int x, int y, enum JOUEUR joueur)
{
    //because in each loop would count the x,y twice, so set initial count is -1
    int vertical_count = -1;
    int horizontal_count = -1;
    int left_lean_count = -1;
    int right_lean_count = -1;
    
    int tmp;
    vertical_count += get_decrease_vertical_same_piece_count(x, y, joueur, &tmp);
    vertical_count += get_increase_vertical_same_piece_count(x, y, joueur, &tmp);
    horizontal_count += get_decrease_horizontal_same_piece_count(x, y, joueur, &tmp);
    horizontal_count += get_increase_horizontal_same_piece_count(x, y, joueur, &tmp);
    left_lean_count += get_decrease_left_lean_same_piece_count(x, y, joueur, &tmp);
    left_lean_count += get_increase_left_lean_same_piece_count(x, y, joueur, &tmp);
    right_lean_count += get_decrease_right_lean_same_piece_count(x, y, joueur, &tmp);
    right_lean_count += get_increase_right_lean_same_piece_count(x, y, joueur, &tmp);
    
    if (vertical_count == game_over_number ||
        horizontal_count == game_over_number ||
        left_lean_count == game_over_number ||
        right_lean_count == game_over_number)
        return 1;
    
    return 0;
}

void update_connnected_table_vertical(int x, int y, int start, int stop)
{
    int i;
    for (i = start; i <= stop; ++i)
        ++connected_table[x + i][y];
}

void update_connnected_table_horizontal(int x, int y, int start, int stop)
{
    int i;
    for (i = start; i <= stop; ++i)
        ++connected_table[x][y + i];
}

void update_connected_table_lean_left(int x, int y, int start, int stop)
{
    int i;
    for (i = start; i <= stop; ++i)
        ++connected_table[x + i][y + i];
}

void update_connected_table_lean_right(int x, int y, int start, int stop)
{
    int i;
    for (i = start; i <= stop; ++i)
        ++connected_table[x + i][y - i];
}

int refresh_connnected_5_number(int x, int y, enum JOUEUR joueur)
{
    //because in each loop would count the x,y twice, so set initial count is -1
    int vertical_count = -1;
    int horizontal_count = -1;
    int left_lean_count = -1;
    int right_lean_count = -1;
    
    //x, y should only include two connected list
    int xy_connected_count = 0;
    
    int decrease_range, increase_range;
    vertical_count += get_decrease_vertical_same_piece_count(x, y, joueur, &decrease_range);
    vertical_count += get_increase_vertical_same_piece_count(x, y, joueur, &increase_range);
    if (vertical_count == 5)
    {
        ++xy_connected_count;
        update_connnected_table_vertical(x, y, decrease_range, increase_range);
    }
    
    horizontal_count += get_decrease_horizontal_same_piece_count(x, y, joueur, &decrease_range);
    horizontal_count += get_increase_horizontal_same_piece_count(x, y, joueur, &increase_range);
    if (horizontal_count == 5)
    {
        ++xy_connected_count;
        update_connnected_table_horizontal(x, y, decrease_range, increase_range);
    }
    
    left_lean_count += get_decrease_left_lean_same_piece_count(x, y, joueur, &decrease_range);
    left_lean_count += get_increase_left_lean_same_piece_count(x, y, joueur, &increase_range);
    if (left_lean_count == 5)
    {
        ++xy_connected_count;
        update_connected_table_lean_left(x, y, decrease_range, increase_range);
    }
    
    right_lean_count += get_decrease_right_lean_same_piece_count(x, y, joueur, &decrease_range);
    right_lean_count += get_increase_right_lean_same_piece_count(x, y, joueur, &increase_range);
    if (right_lean_count == 5)
    {
        ++xy_connected_count;
        update_connected_table_lean_right(x, y, decrease_range, increase_range);
    }
    //every cell should just used in 2 connected list
    if (xy_connected_count < 2)
        xy_connected_count = 2;
    return xy_connected_count;
}

void set_cell_weight(int x, int y, int value)
{
    weight[x][y] += value;
}

//init the WIDTH and HEIGHT of the board
void init()
{
    printf("please input game over number:(game over number=[5, 11)");
    scanf("%d", &game_over_number);
    
    is_set_game_over_number = (game_over_number < 11 && game_over_number >= 5);
    
    memset(board, EMPTY, LARGEUR*HAUTEUR*sizeof(int));
    memset(weight, 0, LARGEUR*HAUTEUR*sizeof(int));
    memset(connected_table, 0, LARGEUR*HAUTEUR*sizeof(int));
    winner = EMPTY;
    //init board weight, the cells which on the edge of the board would have lower value
    int k, i, j;
    for (k = 0; k < 5; ++k)
    {
        for (i = k; i < LARGEUR - k; ++i)
        {
            set_cell_weight(i, k, k - 5);
            set_cell_weight(i, HAUTEUR - 1 - k, k - 5);
        }
        
        for (j = k; j < HAUTEUR-k; ++j)
        {
            set_cell_weight(k, j, k - 5);
            set_cell_weight(LARGEUR-1-k, j, k - 5);
        }
    }
}

int can_put_a_piece(int x, int y)
{
    if (x >= LARGEUR || y >= HAUTEUR || x < 0 || y < 0 || board[x][y] != EMPTY)
    {
        printf("illegal position!\n");
        return 0;
    }
    return 1;
}

//3 connected and there's no different piece in two end => in this case should increase the two end point with higher weight
void refresh_weight_when_pattern_3_with_empty_ends(int x, int y, enum JOUEUR joueur)
{
    int start = 0;
    int stop = 0;
    
    get_decrease_vertical_same_piece_count(x, y, joueur, &start);
    get_increase_vertical_same_piece_count(x, y, joueur, &stop);
    if (stop - start >= 3 && x - start - 1 >= 0 && board[x - start - 1][y] == EMPTY && x + stop + 1 <= LARGEUR && board[x + stop + 1][y] == EMPTY)
    {
        increase_cell_weight(x - start - 1, y, 50, joueur);
        increase_cell_weight(x + stop + 1, y, 50, joueur);
    }
    
    get_decrease_horizontal_same_piece_count(x, y, joueur, &start);
    get_increase_horizontal_same_piece_count(x, y, joueur, &stop);
    if (stop - start >= 3 && y - start - 1 >= 0 && board[x][y - start - 1] == EMPTY && y + stop + 1 <= HAUTEUR && board[x][y + stop + 1] == EMPTY)
    {
        increase_cell_weight(x, y - start - 1, 50, joueur);
        increase_cell_weight(x, y + stop + 1, 50, joueur);
    }
    
    get_decrease_left_lean_same_piece_count(x, y, joueur, &start);
    get_increase_left_lean_same_piece_count(x, y, joueur, &stop);
    if (stop - start >= 3 && x - start - 1 >= 0 && y - start - 1 >= 0 && board[x - start - 1][y - start - 1] == EMPTY
        && x + stop + 1 <= LARGEUR && y + stop + 1 <= HAUTEUR && board[x + stop + 1][y + stop + 1] == EMPTY)
    {
        increase_cell_weight(x - start - 1, y - start - 1, 50, joueur);
        increase_cell_weight(x + stop + 1, y + stop + 1, 50, joueur);
    }
    
    get_decrease_right_lean_same_piece_count(x, y, joueur, &start);
    get_increase_right_lean_same_piece_count(x, y, joueur, &stop);
    if (stop - start >= 3 && x + start - 1 >= 0 && y - start + 1 <= HAUTEUR && board[x + start - 1][y - start + 1] == EMPTY
        && x + stop + 1 <= LARGEUR && y - stop - 1 >= 0 && board[x + stop + 1][y - stop - 1] == EMPTY)
    {
        increase_cell_weight(x + start - 1, y - start + 1, 50, joueur);
        increase_cell_weight(x + stop + 1, y - stop - 1, 50, joueur);
    }
}

void refresh_weight(int x, int y, enum JOUEUR joueur)
{
    int i, j;
    for (i = -5; i < 5; ++i)
    {
        for (j = -5; j < 5; ++j)
        {
            //make sure the effected range would still inside of board
            if ((x + i) >= 0 && (x + i) < LARGEUR && (y + j) >= 0 && (y + j) < HAUTEUR)
                increase_cell_weight(x + i, y + j, 5 - abs_max(i, j), joueur);
        }
    }
    
    weight[x][y] = -99999; //value so small, make sure machine can't choose the cell anymore.
    
    //intelligence part, 3 with two empty end should make weight very big in the two end and direction points
    refresh_weight_when_pattern_3_with_empty_ends(x, y, joueur);
}

void refresh_connnected_table(int x, int y, enum JOUEUR joueur)
{
    int connected_number = refresh_connnected_5_number(x, y, joueur);
    if (joueur == USER)
        user_connnected_number += connected_number;
    else
        machine_connnected_number += connected_number;
}

//return value: false means game over
int play(int x, int y, enum JOUEUR joueur)
{
    board[x][y] = joueur;
    refresh_weight(x, y, joueur);
    
    if (is_set_game_over_number == 1 && game_over(x, y, joueur) == 1)
    {
        winner = joueur;
        return 0;
    }
    
    refresh_connnected_table(x, y, joueur);
    
    return 1;
}

void display_weigth()
{
    int i, j;
    for (i = 0; i < LARGEUR; ++i)
    {
        for (j = 0; j < LARGEUR; ++j)
            printf("%d ", weight[i][j]);
        printf("\n");
    }
}

void display_connected_table()
{
    int i, j;
    for (i = 0; i < HAUTEUR; ++i)
    {
        for (j = 0; j < LARGEUR; ++j)
            printf("%d ", connected_table[i][j]);
        printf("\n");
    }
}

void display_board()
{
    int i, j;
    for (i = 0; i < HAUTEUR; ++i)
    {
        for (j = 0; j < LARGEUR; ++j)
        {
            if (board[i][j] == USER)
                printf("%c ", user_display);
            else if (board[i][j] == MACHINE)
                printf("%c ", machine_display);
            else
                printf("%c ", empty_display);
        }
        printf("\n");
    }
    //display_weigth();
}

//user play
//return value: false means game over
int user_play(int x, int y)
{
    return play(x, y, USER);
}

int is_back_to_command_mode(int x, int y)
{
    if (x == -1 && y == -1)
    {
        printf("back to command mode\n");
        return 1;
    }
    return 0;
}

int check_is_finished()
{
    int i, j;
    for (i = 0; i < LARGEUR; ++i)
    {
        for (j = 0; j < HAUTEUR; ++j)
        {
            if (board[i][j] == EMPTY)
                return 0;
        }
    }
    winner = user_connnected_number > machine_display ? USER : MACHINE;
    return 1;
}

int accept_user_input(int* x, int* y)
{
    printf("player enter position:");
    scanf("%d %d", x, y);
    
    while (can_put_a_piece(*x, *y) == 0)
    {
        if (is_back_to_command_mode(*x, *y))
            return 0;
        printf("player enter position:");
        scanf("%d %d", x, y);
    }
    return 1;
}

void find_next_step(int* x, int* y)
{
    int max = -99999;
    int i, j;
    for (i = 0; i < LARGEUR; ++i)
    {
        for (j = 0; j < HAUTEUR; ++j)
        {
            if (weight[i][j] > max)
            {
                *x = i;
                *y = j;
                max = weight[i][j];
            }
        }
    }
}

//machine play
//return value: false means game over
int machine_play()
{
    int x, y;
    find_next_step(&x, &y);
    return play(x, y, MACHINE);
}

void show_result()
{
    if (winner == USER)
        printf("user wins, congratulation!!!\n");
    else
        printf("sorry, you lose the game.\n");
    
    printf("result: \n");
    
    if (is_set_game_over_number)
    {
        printf("     player firstly connect %d pieces!\n", game_over_number);
    }
    else
    {
        printf("      user connected 5 number:%d\n", user_connnected_number);
        printf("      machine connected 5 number:%d\n", machine_connnected_number);
    }
}

//play mode
//every round, 1. user play, 2. machine play
void play_loop()
{
    while (1)
    {
        if (check_is_finished() == 1)
            return show_result();
        
        //user part, if input -1 -1, then break into command mode
        int x, y;
        if (accept_user_input(&x, &y) == 0)
            return;
        if (user_play(x, y) == 0)
            return show_result();
        
        //machine part
        if (check_is_finished() == 0 && machine_play() == 0)
            return show_result();
        
        display_board();
        
        //display_weigth();
        //display_connected_table();
    }
}

void display_command()
{
    printf("please input command:\n");
    printf("d: display board\n");
    printf("p: play game\n");
    printf("s. switch display\n");
    printf("r. restart game\n");
}

void switch_display()
{
    if (user_display == 'X')
    {
        user_display = 'O';
        machine_display = 'X';
    }
    else
    {
        user_display = 'X';
        machine_display = 'O';
    }
}

void restart_game()
{
    printf("start new game\n");
    init();
    is_initialized = 1;
    is_game_over = 0;
}

// commandes d'entrée d'utilisateur
// 1 : tableau d'affichage
// 2 : Retour au jeu
// 3 : affichage de commutation
// 3 : redémarrage jeu

void command_loop()
{
    display_command();
    char command;
    while (1)
    {
        scanf("%c", &command);
        switch (command)
        {
            case 'd':
                display_board();
                break;
            case 'p':
                if (is_initialized == 0 || is_game_over == 1)
                    restart_game();
                display_board();
                play_loop();
                display_board();
                break;
            case 's':
                switch_display();
                display_board();
                break;
            case 'r':
                restart_game();
                display_board();
                break;
            default:
                display_command();
                break;
        }
    }
}

int main()
{
    command_loop();
    return 0;
}