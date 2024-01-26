/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int solveinc(int i,int j, int t, MountainArray &mountainArr){
        int mid = i + (j-i)/2;
        while(i <= j){
            int a = mountainArr.get(mid);
            if(a == t){
                return mid;
            }
            else if(a < t){
                i = mid+1;
            }else{
                j = mid-1;
            }
            mid = i + (j-i)/2;
        }
        
        return -1;
    } 
    
    int solvedec(int i,int j, int t, MountainArray &mountainArr){
        int mid = i + (j-i)/2;
        while(i <= j){
            int a = mountainArr.get(mid);
            if(a == t){
                return mid;
            }
            else if(a < t){
                j = mid-1;
            }else{
                i = mid+1;
            }
            mid = i + (j-i)/2;
        }
        
        return -1;
    } 
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int i = 0;
        int j = n-1;
        
        int mid = i + (j-i)/2;
        int peak;
        while(j-i > 1){
            
            int a = mountainArr.get(mid-1);
            int b= mountainArr.get(mid);
            int c = mountainArr.get(mid+1);
            if(b > a && b > c){
                peak = mid;
                break;
            }
            else if(a< b && b < c){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
            
            mid = i + (j-i)/2;
        }
        
        return solveinc(0,peak,target, mountainArr) != -1 ? solveinc(0,peak,target, mountainArr) : solvedec(peak+1,n-1,target, mountainArr);
        
    }
};