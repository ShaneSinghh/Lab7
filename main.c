//
//  main.c
//  lab7
//
//  Created by Suga Singh on 3/8/24.
//
#include <stdio.h>

#define ARRAY_SIZE 9

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int s;
    for (int i = 0; i < n - 1; i++) {
        s = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                s = 1;
            }}
        
        if (!s) {
            break;
        }}}

void selectionSort(int arr[], int n) {
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[m]) {
                m = j;
            }}
        
        if (m != i) {
            swap(&arr[i], &arr[m]);
        }}}

void numofSwaps(int arr[], int n, char *sort) {
    int x = 0;
    int v[ARRAY_SIZE] = {0};
    if (sort == "Bubble") {
        bubbleSort(arr, n);}
    else if (sort == "Selection") {
        selectionSort(arr, n);}
    else {
        printf("NOT RIGHT \n");
        return;}

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sort == "Bubble" && arr[j] > arr[j + 1]) ||
                (sort == "Selection" && arr[j] > arr[i])) {
                x++;
                v[arr[j]]++;
            }}}

    printf("%s\n", sort);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (v[i] > 0) {
            printf("%d: %d swaps\n", i, v[i]);}}
    printf("Total: %d\n", x);
}

int main() {
    printf("ARR1: ");
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    printf("/n");
    printf("ARR2: ");
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    numofSwaps(arr1, ARRAY_SIZE, "Bubble");
    
    numofSwaps(arr2, ARRAY_SIZE, "Selection");

    return 0;}
