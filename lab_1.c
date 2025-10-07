#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

int task_1(){
    long long size;
    printf("\n------------------------\n[TASK] 1\n\n");
    printf("Input array size: \n");
    scanf("%lld", &size);
    if (size < 0) return -1;
    int *random_array = (int*)malloc(size * sizeof(int));
    if (random_array == NULL) return -1;

    // init random digits generator
    int minn = 16256;
    int maxx = 0;
    long long summ = 0;
    srand(time(NULL));
    int random_digit;
    for (long long i = 0; i<size; i++){
        random_digit = rand() % 16256;
        random_array[i] = random_digit;
        if (random_digit < minn) minn = random_digit;
        if (random_digit > maxx) maxx = random_digit;
        summ += random_digit;
    }
    long double avg = summ / size;
    free(random_array);
    printf("Max value: %d; Min value: %d Average: %Lf\n", maxx, minn, avg );
    return 0;
} 

typedef struct {
        double x;
        double y;
} Point;

double calculateDistance(Point p1, Point p2){
    return sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) );
}

double calculateArea(Point bottomLeft, Point  topRight){
    double width = topRight.x - bottomLeft.x;
    double height = topRight.y - bottomLeft.y;
    return fabs(width * height);
}

int task_2(){
    double x1, y1, x2, y2;
    printf("\n------------------------\n[TASK] 2\n\n");
    printf("Type x1 y1 x2 y2 (in one line):\n");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    if (x1 == x2 && y1 == y2){
        printf("must enter 2 different points\n");
        return -1;
    }
    Point p1 = {x1, y1};
    Point p2 = {x2, y2};
    printf("Euclidean distance: %f; Rectangle area: %f\n", calculateDistance(p1, p2), calculateArea(p1, p2));
    return 0;
}

int task_3(int *arr, int start, int size){
    if (start>=size) {
        printf("start is greater than size");
        return -1;
    }
    int max_count = 0;
    int mode = *(arr + start);
    for (int *i = arr + start; i<arr+size; ++i){
        int count = 0;
        for (int *j = arr + start; j<arr+size; ++j ){
            if (*i == *j) ++count;
        }
        if (count > max_count) {
            max_count = count;
            mode = *i;
        }
    }
    printf("Mode: %d\n", mode);
    return 0;
}

int task_4(int *target, int *src, int size){
    for (int i = 0; i < size; ++i) {
        *(target + i) = *(src + i);
    }
    return 0;
}

int main(){
    task_1();
    task_2();

    // task 3
    printf("\n------------------------\n[TASK] 3\n\n");
    int arr[] = {1, 2, 2, 3, 2, 4};
    int start = 1;
    int size1 = 6;
    task_3(arr, start, size1);

    // task 4
    int src[] = {1, 2, 3, 4};
    int target[] = {0, 0, 0, 0};
    int *srcPtr = &src;
    int *targetPtr = &target;
    int size2 = 4;

    printf("\n------------------------\n[TASK] 4\n\n");
    printf("Before copy - src: %d %d %d %d, target: %d %d %d %d\n",
           *(src + 0), *(src + 1), *(src + 2), *(src + 3),
           *(target + 0), *(target + 1), *(target + 2), *(target + 3));

    task_4(target, srcPtr, targetPtr);
    
    printf("After copy - src: %d %d %d %d, target: %d %d %d %d\n",
           *(src + 0), *(src + 1), *(src + 2), *(src + 3),
           *(target + 0), *(target + 1), *(target + 2), *(target + 3));

    return 0;
}
