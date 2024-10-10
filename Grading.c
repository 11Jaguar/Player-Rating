#include <stdio.h>
#include <string.h>

#define MAX_PLAYER 15
#define SKILLS 5
#define MAX_RATING 100.0 // Define maximum rating

void calculaterating(float average, char *level) {
    if (average >= 90) {
        strcpy(level, "Legendary");
    } else if (average >= 80) {
        strcpy(level, "Epic");
    } else if (average >= 70) {
        strcpy(level, "Rare");
    } else if (average >= 60) {
        strcpy(level, "Non Rare");
    } else {
        strcpy(level, "Common");
    }
}

int main() {
    int numPlayers, i, j;
    float rating[SKILLS];
    float OVR[MAX_PLAYER]; // Array to store overall ratings
    float teamRating = 0.0; // Variable to store overall team rating
    char level[20]; // String to hold the player's level
    char skills[SKILLS][30] = {"Shooting", "Passing", "Dribbling", "Speed", "Defending"};

    printf("Enter the number of players (max %d): ", MAX_PLAYER);
    scanf("%d", &numPlayers);

    // Input validation for the number of players
    if (numPlayers < 1 || numPlayers > MAX_PLAYER) {
        printf("Invalid number of players. Please enter a number between 1 and %d.\n", MAX_PLAYER);
        return 1;
    }

    for (i = 0; i < numPlayers; i++) {
        printf("\nEnter rating for Jersey no. %d:\n", i + 1);
        float total = 0.0;

        for (j = 0; j < SKILLS; j++) {
            printf("%s (0 - %.1f): ", skills[j], MAX_RATING);
            scanf("%f", &rating[j]);

            // Input validation for ratings
            if (rating[j] < 0 || rating[j] > MAX_RATING) {
                printf("Invalid rating. Please enter a rating between 0 and %.1f.\n", MAX_RATING);
                j--; // Repeat the input for the current skill
                continue; // Skip the addition to total
            }

            total += rating[j];
        }

        OVR[i] = total / SKILLS; // Store overall rating in the array
        calculaterating(OVR[i], level); // Calculate level based on overall rating

        printf("Overall rating of player %d: %.2f\n", i + 1, OVR[i]);
        printf("Rating for Player %d: %s\n", i + 1, level);
    }

    // Calculate team rating
    for (i = 0; i < numPlayers; i++) {
        teamRating += OVR[i];
    }
    teamRating /= numPlayers; // Average of overall ratings

    // Display overall ratings for all players
    printf("\nOverall ratings of all players:\n");
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d: Overall Rating = %.2f\n", i + 1, OVR[i]);
    }

    // Display overall team rating
    printf("Overall team rating: %.2f\n", teamRating);

    return 0;
}

