#include <stdio.h>
#include <string.h>
#include "match_history_io.h"

#define BUFFER_LEN (4096)

void write_match_history(char *history, const size_t history_size,
                         const char *const names[], const int wins[], const int losses[],
                         const double kills[], const double deaths[], const double assists[],
                         const size_t count)
{
    char buffer[BUFFER_LEN];
    size_t i;
    size_t remaining_history_size = history_size - 1;

    history[0] = '\0'; /* C에서 빈 문자열을 정의하는 방법 */

    for (i = 0; i < count; i++)
    {
        size_t written_len;

        sprintf(buffer, "%8s %.2lf %.2lf %.2lf %d %d\n",
                names[i],
                kills[i], deaths[i], assists[i],
                wins[i], losses[i]);

        written_len = strlen(buffer);

        if (written_len > remaining_history_size)
        {
            break;
        }

        strcpy_s(history, history_size, buffer);
        history += written_len;
        remaining_history_size -= written_len;
    }
}

void read_match_history(char *history)
{
    const char *const DELIMS = "\n";
    const char *token = NULL;
    char *next_token = NULL;

    printf("%8s %7s %7s %7s %7s %6s %6s %9s\n",
           "Champ",
           "Kills", "Deaths", "Assists", "KDA",
           "Wins", "Losses",
           "Win Ratio");

    token = strtok_s(history, DELIMS, &next_token);

    while (token != NULL)
    {
        char name[BUFFER_LEN]; /* 충분히 크긴 한데 누군가 히스토리 속 이름을 길게 변조했을 수도 있다. 100% 안전하지 않음. */
        double kills;
        double deaths;
        double assists;
        int wins;
        int losses;

        double kda;
        double win_ratio;

        if (sscanf_s(token, "%s %lf %lf %lf %d %d",
                     name, BUFFER_LEN,
                     &kills, &deaths, &assists,
                     &wins, &losses) != 6)
        {
            continue;
        }

        kda = (kills + assists) / deaths;
        win_ratio = wins * 100.0 / (wins + losses);

        printf("%8s %7.2lf %7.2lf %7.2lf %7.2lf %6d %6d %8.2f%%\n",
               name,
               kills, deaths, assists, kda,
               wins, losses,
               win_ratio);

        token = strtok_s(NULL, DELIMS, &next_token);
    }
}
