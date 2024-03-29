#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>

int send_game_statut(char **my_pos, int pid)
{
    if (is_game_finished(my_pos) == 0) {
        kill(pid, SIGUSR2);
        usleep(15000);
        my_putstr("Enemy won\n");
        return (1);
    }
    else {
        kill(pid, SIGUSR1);
        usleep(15000);
        return (0);
    }
}

int did_i_won(void)
{
    get_signal();
    pause();
    if (sig_reception == 2) {
        my_putstr("I won\n");
        return (1);
    }
    return (0);
}

void show_game_tabs(char **my_pos, char **enemy_pos)
{
    my_putstr("my positions:\n");
    my_show_word_array(my_pos);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    my_show_word_array(enemy_pos);
    my_putchar('\n');
}

void attack_turn(char **enemy_pos, int pid)
{
    int return_of_send_pos = 2;

    while (return_of_send_pos == 2)
        return_of_send_pos = send_pos(enemy_pos, pid);
}

void gameloop(char **my_pos, char **enemy_pos, int player_turn, int pid)
{
    int is_game_finished = 0;
    int player_type = player_turn;

    show_game_tabs(my_pos, enemy_pos);
    sig_reception = 1;
    for (int first_turn = 1; is_game_finished == 0; first_turn = 0) {
        if (player_turn == 0) {
            attack_turn(enemy_pos, pid);
            is_game_finished = did_i_won();
            player_turn = 1;
        }
        if (player_type == 1 && first_turn == 0)
            show_game_tabs(my_pos, enemy_pos);
        if (player_turn == 1) {
            get_pos(my_pos, pid);
            is_game_finished = send_game_statut(my_pos, pid);
            player_turn = 0;
        }
        if (player_type == 0)
            show_game_tabs(my_pos, enemy_pos);
    }
}