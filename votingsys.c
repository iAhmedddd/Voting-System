#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5

// Structure to hold candidate data
typedef struct {
    char name[100];
    int votes;
} Candidate;

// Function to add a vote to a candidate
void addVote(Candidate candidates[], int index) {
    candidates[index].votes += 1;
}

// Function to find a candidate by name
int findCandidateIndex(Candidate candidates[], char *name) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Returns -1 if candidate is not found
}

// Function to sort candidates based on votes using simple selection sort
void sortCandidatesByVotes(Candidate candidates[]) {
    int i, j, maxIdx;
    Candidate temp;
    for (i = 0; i < MAX_CANDIDATES - 1; i++) {
        maxIdx = i;
        for (j = i + 1; j < MAX_CANDIDATES; j++) {
            if (candidates[j].votes > candidates[maxIdx].votes) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            temp = candidates[i];
            candidates[i] = candidates[maxIdx];
            candidates[maxIdx] = temp;
        }
    }
}

// Main function
int main() {
    Candidate candidates[MAX_CANDIDATES] = {{"Trump", 0}, {"Clinton", 0}, {"Biden", 0}, {"Obama", 0}, {"Sanders", 0}};
    int numVoters, i, correction = 0;
    char voteName[100];

    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    for (i = 0; i < numVoters; i++) {
        printf("\nEnter the name of the candidate you want to vote for: ");
        scanf("%s", voteName);
        int index = findCandidateIndex(candidates, voteName);
        if (index != -1) {
            addVote(candidates, index);
            printf("Vote recorded for %s\n", voteName);
        } else {
            printf("Invalid candidate name!\n");
        }

        // Allow vote correction
        printf("To correct your vote enter 1, else enter 0: ");
        scanf("%d", &correction);
        if (correction == 1) {
            printf("Re-enter the name of the candidate you want to vote for: ");
            scanf("%s", voteName);
            index = findCandidateIndex(candidates, voteName);
            if (index != -1) {
                addVote(candidates, index);
                printf("Vote corrected for %s\n", voteName);
            } else {
                printf("Invalid candidate name!\n");
            }
        }
    }

    // Sorting candidates by votes received
    sortCandidatesByVotes(candidates);

    // Displaying results
    printf("\nVoting Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}