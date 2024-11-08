#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 10

void send_frame(int frame_number) {
    printf("Frame %d has been transmitted.\n", frame_number);
}

void receive_ack(int *acks, int *ack_count) {
    printf("Enter the number of acknowledgments received (0 to exit): ");
    scanf("%d", ack_count);
    if (*ack_count == 0) {
        return; // Exit if 0 is entered
    }
    for (int i = 0; i < *ack_count; i++) {
        printf("Enter acknowledgment for frame: ");
        scanf("%d", &acks[i]);
    }
}

int main() {
    int window_size, sent_frames[MAX_FRAMES], acks[MAX_FRAMES];
    int frame_count = 0, ack_count = 0;

    printf("Enter window size: ");
    scanf("%d", &window_size);

    while (1) {
        // Send frames within the window
        for (int i = 0; i < window_size; i++) {
            if (frame_count < MAX_FRAMES) {
                send_frame(frame_count);
                sent_frames[frame_count] = frame_count; // Store the frame number sent
                frame_count++;
            } else {
                break; // Stop sending if max frames are reached
            }
        }

        // Receive acknowledgments
        receive_ack(acks, &ack_count);
        if (ack_count == 0) {
            break; // Exit on 0 acknowledgments

        } else {
            // Process received acknowledgments
            for (int i = 0; i < ack_count; i++) {
                printf("Acknowledgment received for frame: %d\n", acks[i]);
                if (acks[i] < frame_count) {
                    // If acknowledgment is less than the total sent frames, resend
                    printf("Resending frame: %d\n", acks[i]);
                    send_frame(acks[i]);
                }
            }
        }
    }

    return 0;
}

