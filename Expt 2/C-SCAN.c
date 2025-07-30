#include <stdio.h>

int head, a[20], i, distance, n, seektime = 0, size;

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("\nEnter Head position: ");
    scanf("%d", &head);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk size: ");
    scanf("%d", &size);

    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Add head position to request queue
    a[n] = head;
    n++;

    // Sort the requests including head
    bubbleSort(a, n);

    // Find position of head after sorting
    int pos;
    for (i = 0; i < n; i++) {
        if (a[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\n\tC-SCAN DISK SCHEDULING\n\n");

    // Move from head towards end
    for (i = pos; i < n - 1; i++) {
        distance = a[i + 1] - a[i];
        printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }

    // Jump to end if not already there
    if (a[n - 1] != size - 1) {
        distance = (size - 1) - a[n - 1];
        printf("Head movement from %d to %d : %d\n", a[n - 1], size - 1, distance);
        seektime += distance;
    }

    // Jump from end to start
    distance = size - 1;
    printf("Head movement from %d to 0 : %d\n", size - 1, distance);
    seektime += distance;

    // Continue from start to head's original position
    for (i = 0; i < pos; i++) {
        if (i == 0) {
            distance = a[i];
            printf("Head movement from %d to %d : %d\n", size - 1, a[i], distance);
        } else {
            distance = a[i] - a[i - 1];
            printf("Head movement from %d to %d : %d\n", a[i - 1], a[i], distance);
        }
        seektime += distance;
    }

    printf("\nTotal seek time is : %d\n", seektime);
    return 0;
}
