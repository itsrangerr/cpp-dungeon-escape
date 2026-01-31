/*
 * Project: Dungeon Escape (2D Console Game)
 * Description: A survival game where player (P) must avoid traps (X) to reach the exit (E).
 * Language: C++
 * Author: [Your Name]
 */

#include <iostream>
// Include cctype to use toupper() function - safer than -= 32
#include <cctype> 
using namespace std;

int main()
{
    // --- 1. MAP SETUP ---
    // 0: Floor(.), 1: Player(P), 2: Trap(X), 9: Exit(E)
    int map[5][5] = {0};
    
    // Setup objects
    map[0][0] = 1; // Player Start
    map[4][2] = 2; // Trap 1
    map[2][1] = 2; // Trap 2
    map[4][4] = 9; // Exit

    // Player coordinates
    int pR = 0; 
    int pC = 0;
    
    char move;
    bool isRunning = true;

    cout << "=== DUNGEON ESCAPE ===" << endl;

    // --- 2. GAME LOOP ---
    while (isRunning)
    {
        // --- RENDER MAP ---
        // Clear screen logic (optional, prints new lines to "fake" clearing)
        // system("cls"); // Use this if on Windows for cleaner look
        
        cout << "\n----------------" << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == 0)      cout << ". ";
                else if (map[i][j] == 1) cout << "P ";
                else if (map[i][j] == 2) cout << "X ";
                else if (map[i][j] == 9) cout << "E ";
            }
            cout << endl;
        }
        cout << "----------------" << endl;

        // --- INPUT ---
        cout << "Enter move (WASD) or Q to quit: ";
        cin >> move;

        // Convert to uppercase (Handles both 'a' and 'A')
        move = toupper(move);

        if (move == 'Q') {
            cout << "You gave up. Game Over!" << endl;
            break;
        }

        // --- LOGIC ---
        // Reset current position to 0 (Empty) temporarily
        // We will update the new position logic below
        map[pR][pC] = 0; 

        // Store old position in case move is invalid
        int oldR = pR;
        int oldC = pC;

        switch (move)
        {
        case 'A': // LEFT
            pC--; 
            break;
        case 'S': // DOWN
            pR++; 
            break;
        case 'D': // RIGHT
            pC++; 
            break;
        case 'W': // UP
            pR--; 
            break;
        default:
            cout << "Invalid move!" << endl;
            // Restore position
            map[oldR][oldC] = 1; 
            continue; // Skip the rest
        }

        // --- COLLISION & BOUNDARY CHECK ---
        
        // 1. Check Boundary (Did we hit a wall?)
        if (pR < 0 || pR > 4 || pC < 0 || pC > 4) {
            cout << ">>> WALL BLOCKED! Cannot move there." << endl;
            // Revert coordinates
            pR = oldR;
            pC = oldC;
        }
        // 2. Check Win/Loss
        else if (map[pR][pC] == 2) { // Hit Trap
            cout << "\n>>> BOOM! You hit a trap! GAME OVER." << endl;
            isRunning = false; // End game
        }
        else if (map[pR][pC] == 9) { // Hit Exit
            cout << "\n>>> CONGRATULATIONS! You escaped! YOU WIN." << endl;
            isRunning = false; // End game
        }

        // --- UPDATE MAP ---
        // If game is still running, place Player at new coordinates
        if (isRunning) {
            map[pR][pC] = 1;
        }
    }

    system("pause");
    return 0;
}