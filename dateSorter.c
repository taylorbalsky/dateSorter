#include <stdio.h>
#include <stdlib.h>

//date structure
typedef struct	{
    int	day;
    int	month;
    int	year;
} date;

//function declarations
date *buildArray(int length);
void quicksortYear (date *array, int first, int last);
void quicksortMonth (date *array, int first, int last);
void quicksortDay (date *array, int first, int last);
void checkSameYear (date *array, int i, int length);
void checkSameMonth (date *array, int i, int length);

int main (){

    //get number of dates from user
    int length = 1;
    printf("Please enter the number of dates your array will hold: \n");
    scanf("%d", &length);
    if (length < 1) {
        printf("Oops! Not enough dates provided. Please try again.\n");
        return 0;
    }

    //create array and sort dates by year, month, and day
    date *array = buildArray(length);
    quicksortYear(array, 0, length);
    checkSameYear(array, 0, length);
    checkSameMonth(array, 0, length);

    //print sorted dates
    printf("Dates sorted from oldest to most recent:\n");
    for (int i=0; i<length; i++){
        printf("%d ", array[i].day);
        printf("%d ", array[i].month);
        printf("%d\n", array[i].year);
    }
}

//create and fill date array
date *buildArray (int length){
    date *array;
    array = malloc(sizeof(date) * length);
    for (int i=0; i<length; i++){
        printf("Enter date %d consisting of day, month, year (each seperated by a space): \n", i+1);
        scanf("%d %d %d", &array[i].day, &array[i].month, &array[i].year);
    }
    return array;
}

//apply quicksort algorithm to the years
void quicksortYear (date *array, int first, int last){
    int i;
    int j;
    int pivot;
    int tempDay;
    int tempMonth;
    int tempYear;
    if (first < last){
        pivot = first;
        i = first;
        j = last;
        while (i<j){
            while (array[i].year<=array[pivot].year && i<last){
                i++;
            }
            while (array[j].year>array[pivot].year && j>first){
                j--;
            }
            if (i<j){ //date swap
                tempDay = array[i].day;
                tempMonth = array[i].month;
                tempYear = array[i].year;
                array[i].day = array[j].day;
                array[i].month = array[j].month;
                array[i].year = array[j].year;
                array[j].day = tempDay;
                array[j].month = tempMonth;
                array[j].year = tempYear;
            }
        }
        //pivot swap
        tempDay = array[pivot].day;
        tempMonth = array[pivot].month;
        tempYear = array[pivot].year;
        array[pivot].day = array[j].day;
        array[pivot].month = array[j].month;
        array[pivot].year = array[j].year;
        array[j].day = tempDay;
        array[j].month = tempMonth;
        array[j].year = tempYear;
        quicksortYear(array, first, j-1);
        quicksortYear(array, j+1, last);
    }
}

//find dates with the same year and sort them by month
void checkSameYear (date *array, int i, int length){
    for (; i<length; i++){
        if (array[i].year == array[i+1].year){
            int count = 0;
            while (array[i].year == array[i+1].year){
                count++;
                i++;
            }
            quicksortMonth(array, i-count, i); //sort the subarray of dates with the same year
            checkSameYear(array, i+1, length); //call the function again with the next dates
        }
    }
    return;
}

//apply quicksort algorithm to the months
void quicksortMonth (date *array, int first, int last){
    int i;
    int j;
    int pivot;
    int tempDay;
    int tempMonth;
    int tempYear;
    if (first < last){
        pivot = first;
        i = first;
        j = last;
        while (i<j){
            while (array[i].month<=array[pivot].month && i<last){
                i++;
            }
            while (array[j].month>array[pivot].month && j>first){
                j--;
            }
            if (i<j){ //date swap
                tempDay = array[i].day;
                tempMonth = array[i].month;
                tempYear = array[i].year;
                array[i].day = array[j].day;
                array[i].month = array[j].month;
                array[i].year = array[j].year;
                array[j].day = tempDay;
                array[j].month = tempMonth;
                array[j].year = tempYear;
            }
        }
        //pivot swap
        tempDay = array[pivot].day;
        tempMonth = array[pivot].month;
        tempYear = array[pivot].year;
        array[pivot].day = array[j].day;
        array[pivot].month = array[j].month;
        array[pivot].year = array[j].year;
        array[j].day = tempDay;
        array[j].month = tempMonth;
        array[j].year = tempYear;
        quicksortMonth(array, first, j-1);
        quicksortMonth(array, j+1, last);
    }
}

//find dates with the same month and sort them by day
void checkSameMonth (date *array, int i, int length){
    for (; i<length; i++){
        if ((array[i].year == array[i+1].year) && (array[i].month == array[i+1].month)){
            int count = 0;
            while ((array[i].year == array[i+1].year) && (array[i].month == array[i+1].month)){
                count++;
                i++;
            }
            quicksortDay(array, i-count, i); //sort the subarray of dates with the same month
            checkSameMonth(array, i+1, length); //call the function again with the next dates
        }
    }
    return;
}

//apply quicksort algorithm to the days
void quicksortDay (date *array, int first, int last){
    int i;
    int j;
    int pivot;
    int tempDay;
    int tempMonth;
    int tempYear;
    if (first < last){
        pivot = first;
        i = first;
        j = last;
        while (i<j){
            while (array[i].day<=array[pivot].day && i<last){
                i++;
            }
            while (array[j].day>array[pivot].day && j>first){
                j--;
            }
            if (i<j){ //date swap
                tempDay = array[i].day;
                tempMonth = array[i].month;
                tempYear = array[i].year;
                array[i].day = array[j].day;
                array[i].month = array[j].month;
                array[i].year = array[j].year;
                array[j].day = tempDay;
                array[j].month = tempMonth;
                array[j].year = tempYear;
            }
        }
        //pivot swap
        tempDay = array[pivot].day;
        tempMonth = array[pivot].month;
        tempYear = array[pivot].year;
        array[pivot].day = array[j].day;
        array[pivot].month = array[j].month;
        array[pivot].year = array[j].year;
        array[j].day = tempDay;
        array[j].month = tempMonth;
        array[j].year = tempYear;
        quicksortDay(array, first, j-1);
        quicksortDay(array, j+1, last);
    }
}

