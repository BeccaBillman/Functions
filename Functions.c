/* Becca Billman, Functions,COP 3223C, CR02, 07/09/2018*/

#include <stdio.h>

//variable declarations
int numCross(int x1, int y1, int r1, int x2, int y2, int r2);
int disSqr(int x1, int y1, int x2, int y2);
void cyclic_leftShift(int values[], int length);

//Main Function
int main() {
	
	//Print number
    printf("%d", numCross(7, 8, 2, 10, 10, 1));
    int array[] = {7,8,2,10,10,1};
    cyclic_leftShift(array, 6);
    printf("The shifted array is: ");
    for(int i=0; i < 6; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return 0;
}

int numCross(int x1, int y1, int r1, int x2, int y2, int r2){
    //Calculate the distance
    int distSq = disSqr(x1, y1, x2, y2);
    //Sum of radii
    int sumR = r1 + r2;
    //If the square distance is greater than the square of sum of radii,
    if(distSq > sumR*sumR ){
        //then the circles don't touch
        return 0;
    }
    //If the square distance is lesser than the square of sum of radii,
    else if(distSq < sumR*sumR){
        //then there are two points of contact
        return 2;
    }
    else{
        //It's a perfect touch. there is just one point of contact
        return 1;
    }

}

int disSqr(int x1, int y1, int x2, int y2){
    //Calculate the difference between x coordinates
    int dx = x1 - x2;
    //calculate the difference between y coordinates
    int dy = y1 - y2;
    //return the distance
    return dx*dx + dy*dy;

}

void cyclic_leftShift(int values[], int length){
    //Copy the element at index 0
    int temp = values[0];
    //Starting from the last index, move the elements to the left
    for(int i=0; i < length-1; i++){
        values[i] = values[i+1];
    }
    //replace the last value with the first
    values[length-1] = temp;
}



