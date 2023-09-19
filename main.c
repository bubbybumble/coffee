#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

char* cup[25] = {
    "     _____________       ",
    "    <_____________>___   ",
    "    |            |/ _ \\  ",
    "    |              | | | ",
    "    |              |_| | ",
    " ___|            |\\___/  ",
    "/    \\___________/    \\\\ ",
    "\\\\_____________________/ "
};
char* steamFrames[][25] = {
    {
        "    (      (      )      ",
        "     ) (   )  (  (       ",
        "       )       )         ",
    },
    {
        "       )       )         ",
        "     ) (   )  (  (       ",
        "     (    (      )       ",
    },

};


int main(void)
{
    initscr();
    curs_set(false);
    
    int running = 1;
    while(running){
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        
        int startY = w.ws_row / 2 - 11/2;
        int startX = w.ws_col / 2 - 25/2;

        move(10,10);
        int i = 0;
        for(i = 0; i < 2; ++i){
            erase();
            for (int j = 0; j < 3; ++j){
                mvaddstr(j + startY, startX, steamFrames[i][j]);
                
            }
            for (int j = 0; j < 8; ++j){
                mvaddstr(j+3 + startY, startX, cup[j]);
                
            }
            refresh();
            sleep(1);
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
