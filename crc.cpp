#include <stdio.h>
#include <string.h>

// Length of the generator polynomial
#define N strlen(gen_poly)

// Data to be transmitted and received
char data[50];
// CRC value
char check_value[50];
// Generator polynomial
char gen_poly[30];

// Variables
int data_length, i, j;

// Function that performs XOR operation
void XOR() {
    // If both bits are the same, the output is 0
    // If the bits are different, the output is 1
    for (j = 1; j < N; j++)
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
}
void crc() {
    // Initializing check_value
    for (i = 0; i < N; i++)
        check_value[i] = data[i];

    do {
        // Check if the first bit is 1 and calls XOR function
        if (check_value[0] == '1')
            XOR();

        // Move the bits by 1 position for the next computation
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];

        // Appending a bit from data
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1); // Loop until the data ends
}
// Function to check for errors on the receiver side
void receiver() {
    // Get the received data
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\nData received: %s\n", data);

    // Cyclic Redundancy Check
    crc();

    // Check if the remainder is zero to find the error
    for (i = 0; (i < N - 1) && (check_value[i] != '1'); i++);
    if (i < N - 1)
        printf("Error detected\n\n");
    else
        printf("No error detected\n\n");
}

// CRC computation function


int main() {
    // Get the data to be transmitted
    printf("Enter data to be transmitted: ");
    scanf("%s", data);
   
    printf("Enter the Generating polynomial: ");
    // Get the generator polynomial
    scanf("%s", gen_poly);

    // Find the length of data
    data_length = strlen(data);

    // Appending N-1 zeros to the data
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
   
    data[i] = '\0'; // Null-terminate the string

    printf("\nData padded with N-1 zeros: %s\n", data);

    // Cyclic Redundancy Check
    crc();

    // Print the computed check value (CRC)
    printf("CRC or Check value is: %s\n", check_value);

    // Append data with check_value (CRC)
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = check_value[i - data_length];

    data[data_length + N - 1] = '\0'; // Null-terminate the final data

    // Print the final data to be sent
    printf("Final data to be sent: %s\n\n", data);

    // Calling the receiver function to check for errors
    receiver();
    return 0;
}
