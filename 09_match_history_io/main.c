#include <stdio.h>
#include "match_history_io.h"

#define NUM_CHAMPS (5)
#define HISTORY_SIZE (4096)

int main(void)
{
    const char *const names[NUM_CHAMPS] = {"Akali", "Sylas", "Yasuo", "Leblanc", "Aatrox"};
    const int wins[NUM_CHAMPS] = {52, 55, 28, 34, 32};
    const int losses[NUM_CHAMPS] = {62, 38, 31, 21, 21};
    const double average_kills[NUM_CHAMPS] = {6.11, 6.62, 4.81, 5.95, 5.19};
    const double average_deaths[NUM_CHAMPS] = {3.65, 3.87, 3.97, 3.05, 3.23};
    const double average_assists[NUM_CHAMPS] = {4.63, 6.68, 4.47, 5.25, 6.02};

    char history[HISTORY_SIZE];

    write_match_history(history, HISTORY_SIZE,
                        names, wins, losses,
                        average_kills, average_deaths, average_assists,
                        NUM_CHAMPS);

    read_match_history(history);

    return 0;
}
