#include<ncurses.h>
#include<stdlib.h>
#include <unistd.h>
char* frames[][25] = {
    {
        "    (      (      )      ",
        "     ) (   )  (  (       ",
        "       )       )         ",
        "     _____________       ",
        "    <_____________>___   ",
        "    |            |/ _ \\  ",
        "    |              | | | ",
        "    |              |_| | ",
        " ___|            |\\___/  ",
        "/    \\___________/    \\\\ ",
        "\\\\_____________________/ "

    },
    {
        "       )       )         ",
        "     ) (   )  (  (       ",
        "     (    (      )       ",
        "     _____________       ",
        "    <_____________>___   ",
        "    |            |/ _ \\  ",
        "    |              | | | ",
        "    |              |_| | ",
        " ___|            |\\___/  ",
        "/    \\___________/    \\\\ ",
        "\\\\_____________________/ "
    },

};


int main(void)
{
    initscr();
    int running = 1;
    while(running){
        int i = 0;
        for(i = 0; i < 2; ++i){
            erase();
            for (int j = 0; j < 11; ++j){
                addstr(frames[i][j]);
                addstr("\n");
            }
            refresh();
            usleep(5000);
            // char ch = getch();
            // if (ch == "q") {
            //     /* This will cause the while loop to end the */
            //     /* next time the while loop checks the */
            //     /* value of "running" */
            //     running = 0;
            // }
        }
    }

    getch();

    endwin();

    return EXIT_SUCCESS;
}
