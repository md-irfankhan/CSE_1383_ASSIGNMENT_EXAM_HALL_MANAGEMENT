#include <stdio.h>
//-------Task 2: Automatic Seat Allocation
void allocateSeats(int hall[][10], int hallCount, int seatCount, int studentCount){
    int firstStudentId=25303001;
    int allocated = 0;
    for(int i=0;i<hallCount;i++){
        for(int j=0;j<seatCount;j++){
            if(allocated<studentCount){
               hall[i][j]=firstStudentId+1;
            }
            else{
                hall[i][j]=0;
            }
            
            allocated++;

        }

    }
}
//-------Task 3: Hall Occupancy Analysis
void hallOccupancy(int hall[][10], int hallCount, int seatCount){
    int hallNumber,seatNumber,occupied=0,vacant;
    float percentage;
    for(hallNumber=0;hallNumber<hallCount;hallNumber++){
        occupied=0;
        for(seatNumber=0;seatNumber<seatCount;seatNumber++){
            if(hall[hallNumber][seatNumber]!=0){
                occupied++;
            }
        }
        vacant=seatCount-occupied;
        percentage=((float)occupied/seatCount)*100;
        printf("Hall-%d:Occopied seat percentage: %.2f percent and vacant seat is %d \n",hallNumber+1,percentage,vacant);
    }

}

void overloadedHall(int hall[][10], int hallCount, int seatCount){
    int hallNumber,seatNumber,occupied=0;
    float percentage;
    for(hallNumber=0;hallNumber<hallCount;hallNumber++){
        occupied=0;
        for(seatNumber=0;seatNumber<seatCount;seatNumber++){
            if(hall[hallNumber][seatNumber]!=0){
                occupied++;
            }
        }
        percentage=((float)occupied/seatCount)*100;
        if(percentage>=90){
            printf("Warning:Hall-%d exceeds over 90 percent and Occopied seat percentage: %.2f\n",hallNumber+1,percentage);

        }
        
    }

}

void findEmptySeat(int hall[][10], int hallCount, int seatCount){
    int hallNumber,seatNumber,empty=0;
    for(hallNumber=0;hallNumber<hallCount;hallNumber++){
        empty=0;
        for(seatNumber=0;seatNumber<seatCount;seatNumber++){
            if(hall[hallNumber][seatNumber]==0){
                empty++;
                printf("Hall %d: Empty seat postion %d \n",hallNumber+1,seatNumber+1);
            }
        }
        
    }
}
int main(){
    int hallCount=0,seatCount, studentCount,maxSeat;
    /*This array represents row as exam hall and column as students seat
    Maximum 3 hall and maximum 10 seats per hall*/
    int hallArray[3][10];

    //-------Task 1: Input &amp; Validation Module

    //Take number of hall.
    printf("Enter number of hall(1-3):");
    while(hallCount>3 || hallCount<=0){
        scanf("%d",&hallCount);
        if(hallCount>3 || hallCount<=0){
            printf("Enter again:");
        }
    }
    //Take input number of seats.
    printf("Enter number of seats per hall:");
    while(seatCount>10 || seatCount<=0){
        scanf("%d",&seatCount);
        if(seatCount>10 || seatCount<=0){
            printf("Enter again:");
        }
    }
     //Calculates maximum seat.
    maxSeat=seatCount*hallCount;
    //Take input number of students.
    printf("Enter students(1- %d):",maxSeat);
    while(studentCount>maxSeat || studentCount<=0){
        scanf("%d",&studentCount);
        if(studentCount>maxSeat || studentCount<=0){
            printf("Enter again:");
        }
    }
   
    //This function used to allocate seats.
    allocateSeats(hallArray,hallCount,seatCount,studentCount);
    //This function used to callculate occupancy
    hallOccupancy(hallArray, hallCount, seatCount);

    overloadedHall(hallArray, hallCount, seatCount);

    findEmptySeat(hallArray, hallCount,seatCount);

}