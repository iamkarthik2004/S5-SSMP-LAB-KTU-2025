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
    
    printf("\nEnter number of disk requests: ");
    scanf("%d", &n);
    
    printf("\nEnter the disk size: ");
    scanf("%d", &size);
    
    printf("\nEnter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    a[n] = head;
    n++;
    
    bubbleSort(a, n);
    
    int pos;
    for (i = 0; i < n; i++) {
        if (a[i] == head) {
            pos = i;
            break;
        }
    }
    
    printf("\n\tSCAN DISK SCHEDULING\n\n");
    
    for (i = pos; i < n - 1; i++) {
        distance = a[i + 1] - a[i];
        printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }
    
    if (a[n - 1] != size - 1) {
        distance = size - 1 - a[n - 1];
        printf("Head movement from %d to %d : %d\n", a[n - 1], size - 1, distance);
        seektime += distance;
    }
    
    if (pos > 0) {
        printf("Head movement from %d to %d : %d\n", size - 1, a[pos - 1], size - 1 - a[pos - 1]);
        seektime += size - 1 - a[pos - 1];
        
        for (i = pos - 1; i > 0; i--) {
            distance = a[i] - a[i - 1];
            printf("Head movement from %d to %d : %d\n", a[i], a[i - 1], distance);
            seektime += distance;
        }
    }
    
    printf("\nTotal seek time is : %d\n", seektime);
    return 0;
}
