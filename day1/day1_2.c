/**
 * Advent of Code 2025 - Day 1-2
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
    int timesCrossingZero = 0;
    
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Input file not found!");
        return 0;
    }
    
    while (fgets(line, sizeof(line), f)) {
        char dir = line[0];
        int dis = atoi(line + 1);
        
        printf("%d - %s\n", position, line);
        
        if (dir == 'L') {
            int offset = (position % SAFE_DIAL_NOTCHES);
            if (offset == 0) {
                offset = SAFE_DIAL_NOTCHES;
            }

            if (dis >= offset) {
                timesCrossingZero += 1 + (dis - offset) / SAFE_DIAL_NOTCHES;
            }

            position = (position - (dis % SAFE_DIAL_NOTCHES) % SAFE_DIAL_NOTCHES + SAFE_DIAL_NOTCHES) % SAFE_DIAL_NOTCHES;
        }
        
        if (dir == 'R') {
            int offset = (SAFE_DIAL_NOTCHES - (position % SAFE_DIAL_NOTCHES)) % SAFE_DIAL_NOTCHES;
            if (offset == 0) {
                offset = SAFE_DIAL_NOTCHES;
            }

            if (dis >= offset) {
                timesCrossingZero += 1 + (dis - offset) / SAFE_DIAL_NOTCHES;
            }

            position = (position + dis) % SAFE_DIAL_NOTCHES;
        }

    }
    
    fclose(f);
    
    printf("Password is: %d", timesCrossingZero);

    return 0;
}