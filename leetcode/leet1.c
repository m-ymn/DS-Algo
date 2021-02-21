#include <stdio.h>
#include <stdbool.h>

/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such
that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/
//int arr[] = {1,0,1,1} ;
//int arr[] = {1,2,3,1}; // k = 3, t = 0
int arr[] = {1,5,9,1,5,9} ;


bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    int i,j ;
    for(i = 0; i< numsSize; i++)
    {
        for(j=0;j<numsSize;j++)
            if((i != j) &&(abs(i - j) <= k) && (labs(nums[i]-nums[j]) <= t))
                return true ;

    }
    return false ;
}

int main(){
    bool y = containsNearbyAlmostDuplicate(&arr, 6, 2, 3) ;
    printf("%d" , (int*)y) ;
}
