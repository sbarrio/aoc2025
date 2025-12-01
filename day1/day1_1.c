/**
 * Advent of Code 2025 - Day 1-1
 * 
 * sbarrio
 * 
 **/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SAFE_DIAL_NOTCHES = 100;
const int START_DIAL_POSITION = 50;

int main()
{
    FILE *f;
    char line[20];
    int position = START_DIAL_POSITION;
    int timesAtZero = 0;
    
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Input file not found!");
        return 0;
    }
    
    while (fgets(line, sizeof(line), f)) {
        char dir = line[0];
        int dis = atoi(line + 1);
        
        if (dir == 'L') {
            position -= dis;
        }
        
        if (dir == 'R') {
            position = (position + dis) % SAFE_DIAL_NOTCHES;
        }
        
        while (position < 0) {
            position = SAFE_DIAL_NOTCHES - abs(position);
        }
        
        if (position == 0) {
            timesAtZero++;
        }
    }
    
    fclose(f);
    
    printf("Password is: %d", timesAtZero);

    return 0;
}