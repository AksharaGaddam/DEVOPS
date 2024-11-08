#include <stdio.h>

int main() {
    int windowsize, sent = 0, ack, i;

    printf("Enter window size: ");
    scanf("%d", &windowsize);

    while (1) {
        for (i = 0; i < windowsize; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
            if (sent == windowsize) {
                break; // Exit if the window size is reached
            }
        }

        printf("\nPlease enter the last Acknowledgement received: ");
        scanf("%d", &ack);

        if (ack == windowsize) {
            break; // Exit if the last acknowledged frame equals the window size
        } else {
            sent = ack; // Set the next frame to be sent to the last acknowledged frame
        }
    }

    return 0;
}
