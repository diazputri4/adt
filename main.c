#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    createQueue(&q);
    int choice, counter = 1;
    
    do {
        printf("\nMenu:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                enqueue(&q, counter);
                printf("Nomor antrian %d telah ditambahkan.\n", counter);
                counter++;
                break;
            case 2:
                if (!isEmpty(q)) {
                    printf("Nomor antrian %d diproses.\n", dequeue(&q));
                } else {
                    printf("Antrian kosong!\n");
                }
                break;
            case 3:
                printf("Daftar Antrian: ");
                printQueue(q);
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 4);
    
    return 0;
}
