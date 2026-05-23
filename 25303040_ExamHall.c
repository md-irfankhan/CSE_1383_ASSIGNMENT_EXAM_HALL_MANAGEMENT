#include <stdio.h>
//-------Task 2: Automatic Seat Allocation
void allocateSeats(int hall[][10], int hallCount, int seatCount, int studentCount)
{
    int firstStudentId = 25303001;
    int allocated = 0;
    for (int hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        for (int seatNumber = 0; seatNumber < seatCount; seatNumber++)
        {
            if (allocated < studentCount)
            {

                hall[hallNumber][seatNumber] = firstStudentId;
                firstStudentId++;
            }
            else
            {
                hall[hallNumber][seatNumber] = 0;
            }

            allocated++;
        }
    }
}
//-------Task 3: Hall Occupancy Analysis
void hallOccupancy(int hall[][10], int hallCount, int seatCount)
{
    int hallNumber, seatNumber, occupied = 0, vacant;
    float percentage;
    printf("  \nOccupied seats...\n");
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        occupied = 0;
        for (seatNumber = 0; seatNumber < seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] != 0)
            {
                occupied++;
            }
        }
        vacant = seatCount - occupied;
        percentage = ((float)occupied / seatCount) * 100;
        printf("Hall-%d:Occopied seat percentage: %.2f percent and vacant seat is %d \n", hallNumber + 1, percentage, vacant);
    }
}
//--------Task 4: Detect Overloaded Halls
void detectOverloaded(int hall[][10], int hallCount, int seatCount)
{
    int hallNumber, seatNumber, occupied = 0;
    float percentage;
    printf("  \nOverloaded hall...\n");
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        occupied = 0;
        for (seatNumber = 0; seatNumber < seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] != 0)
            {
                occupied++;
            }
        }
        percentage = ((float)occupied / seatCount) * 100;
        if (percentage >= 90)
        {
            printf("Warning:Hall-%d exceeds over 90 percent and Occopied seat percentage: %.2f\n", hallNumber + 1, percentage);
        }
    }
}
//-----------Task 5: Empty Seat Finder
void findEmptySeat(int hall[][10], int hallCount, int seatCount)
{
    int hallNumber, seatNumber, empty = 0;
    printf("  \nEmpty seats...\n");
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        empty = 0;
        for (seatNumber = 0; seatNumber< seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] == 0)
            {
                empty++;
                printf("Hall %d: Empty seat postion %d \n", hallNumber + 1, seatNumber+ 1);
            }
        }
    }
}
//----------Task 6: Student Search Module
void searchStudent(int hall[][10], int hallCount, int seatCount, int studentID)
{
    int hallNumber, seatNumber, f = 0;
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {

        for (seatNumber = 0; seatNumber< seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] == studentID)
            {
                f = 1;
                printf("Hall %d: ID:%d seat postion is %d \n", hallNumber + 1, studentID, seatNumber + 1);
                break;
            }
        }
    }
    if (f == 0)
    {
        printf("Not Found..");
    }
}
//---------Task 7: Seating Pattern Display
void displaySeatArrangements(int hall[][10], int hallCount, int seatCount)
{
    int hallNumber, seatNumber;
    printf("  \nSeat Arrangements...\n");
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        printf("\nHall %d:\n", hallNumber+ 1);
        for (seatNumber = 0; seatNumber < seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] != 0)
            {
                printf("%d ", hall[hallNumber][seatNumber]);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}
//---------Task 8: Hall Optimization Suggestion
void suggestOptimization(int hall[][10], int hallCount, int seatCount)
{
    int hallNumber, seatNumber, occupied = 0, vacant;
    float percentage;
    printf("  \nOptimization suggestion...\n");
    for (hallNumber = 0; hallNumber < hallCount; hallNumber++)
    {
        occupied = 0;
        for (seatNumber= 0; seatNumber < seatCount; seatNumber++)
        {
            if (hall[hallNumber][seatNumber] != 0)
            {
                occupied++;
            }
        }
        vacant = seatCount - occupied;
        percentage = ((float)occupied / seatCount) * 100;
        if(percentage<25){
            printf("Hall %d occupide percentage is %.2f percent,Merge the hall with another hall.\n",hallNumber+1,percentage);
        }
    }
    if(percentage>25){
        printf("No optimization suggestion.\n");
    }
}
//..............Task 9: Report Generation Module
void reportGenerate(int hall[][10], int hallCount, int seatCount,int studentCount){
    int hallNumber, seatNumber, occupied = 0, vacant;
    float percentage;
    printf("  \n...Overall report...\n");
    printf("Total hall:%d\n",hallCount);
    printf("Total student:%d\n",studentCount);
    displaySeatArrangements(hall,hallCount,seatCount);
    findEmptySeat(hall,hallCount,seatCount);
    detectOverloaded(hall,hallCount,seatCount);
    suggestOptimization(hall,hallCount,seatCount);

}
int main()
{
    int hallCount = 0, seatCount, studentCount, maxSeat, studentId;
    /*This array represents row as exam hall and column as students seat
    Maximum 3 hall and maximum 10 seats per hall*/
    int hallArray[3][10];

    //-------Task 1: Input &amp; Validation Module

    // Take number of hall.
    printf("Enter number of hall(1-3):");
    while (hallCount > 3 || hallCount <= 0)
    {
        scanf("%d", &hallCount);
        if (hallCount > 3 || hallCount <= 0)
        {
            printf("Enter again:");
        }
    }
    // Take input number of seats.
    printf("Enter number of seats per hall(1-10):");
    while (seatCount > 10 || seatCount <= 0)
    {
        scanf("%d", &seatCount);
        if (seatCount > 10 || seatCount <= 0)
        {
            printf("Enter again:");
        }
    }
    // Calculates maximum seat.
    maxSeat = seatCount * hallCount;
    // Take input number of students.
    printf("Enter students(1- %d):", maxSeat);
    while (studentCount > maxSeat || studentCount <= 0)
    {
        scanf("%d", &studentCount);
        if (studentCount > maxSeat || studentCount <= 0)
        {
            printf("Enter again:");
        }
    }

    // This function used to allocate seats.
    allocateSeats(hallArray, hallCount, seatCount, studentCount);
    //This function is called to generate report
    reportGenerate(hallArray,hallCount,seatCount,studentCount);
    printf("Enter Student Id to search student:");
    //Student Search
    scanf("%d", &studentId);
    searchStudent(hallArray, hallCount, seatCount, studentId);
    
}