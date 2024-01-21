#include <stdio.h>

int arr[20], n, ch;

void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();

int main() {
    int i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n1.Insert at beginning \n2.Insert at end \n3.Insert at Pos \n4.Delete at begining \n5. Delete at end \n6.Delete at Pos \n7.Display\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertpos();
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                deletepos();
                break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 8);

    return 0;
}

void insertbeg() {
    int num, i;
    printf("Enter element: ");
    scanf("%d", &num);

    for (i = n - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = num;
    n++;
}

void insertend() {
    int num;
    printf("Enter element: ");
    scanf("%d", &num);
    arr[n] = num;
    n++;
}

void insertpos() {
    int pos, i, num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);

    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = num;
    n++;
}

void deletebeg() {
    int i;
    for (i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void deleteend() {
    n--;
}

void deletepos() {
    int pos, i, del;
    printf("Enter position: ");
    scanf("%d", &pos);

    del = arr[pos - 1];

    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("The deleted element is %d\n", del);
}

void display() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
