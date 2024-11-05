#include <curses.h>
#include <cstring> // for strlen
#include <string>  // for string

void createInputWindow()
{
    // Create a new window for input
    WINDOW *inputWin = newwin(5, 40, 5, 5);   // 5 rows, 40 cols, starting at (5,5)
    box(inputWin, 0, 0);                      // Draw a border around the window
    mvwprintw(inputWin, 1, 1, "Type here: "); // Prompt user to type
    wrefresh(inputWin);                       // Refresh the window to show the changes

    char input[100] = ""; // Buffer for user input
    int index = 0;        // Current position in the input buffer

    // Main input loop
    while (true)
    {
        int ch = wgetch(inputWin); // Get character input

        if (ch == '\n')
        {          // Enter key
            break; // Exit loop on Enter
        }
        else if (ch == KEY_BACKSPACE || ch == 127)
        { // Handle Backspace
            if (index > 0)
            {
                index--;             // Move back in the buffer
                input[index] = '\0'; // Null-terminate the string
                wrefresh(inputWin);
            }
        }
        else if (index < sizeof(input) - 1)
        {                        // Prevent overflow
            input[index++] = ch; // Store character in buffer
            input[index] = '\0'; // Null-terminate the string
        }

        // Clear the input window and redraw the content
        werase(inputWin);                         // Clear the window
        box(inputWin, 0, 0);                      // Redraw the border
        mvwprintw(inputWin, 1, 1, "Type here: "); // Redraw prompt
        mvwprintw(inputWin, 2, 1, "%s", input);   // Display current input below the prompt
        wrefresh(inputWin);                       // Refresh the window to show changes
    }

    // After input is done
    werase(inputWin);                                  // Clear the window
    mvwprintw(inputWin, 1, 1, "You typed: %s", input); // Show what was typed
    wrefresh(inputWin);                                // Refresh to show the message

    getch();          // Wait for user input before closing
    delwin(inputWin); // Delete the input window
}

int main()
{
    initscr();            // Start NCurses
    cbreak();             // Disable line buffering
    noecho();             // Don't echo input characters
    keypad(stdscr, TRUE); // Enable special keys

    createInputWindow(); // Create the input window

    endwin(); // End NCurses
    return 0;
}
