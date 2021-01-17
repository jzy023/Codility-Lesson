/*
A non-empty array A consisting of N integers is given. The array contains
an odd number of elements, and each element of the array can be paired with 
another element that has the same value, except for one element that is 
left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.

Write a function:

	int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions,
returns the value of the unpaired element.

For example, given array A such that:

	A[0] = 9  A[1] = 3  A[2] = 9
	A[3] = 3  A[4] = 9  A[5] = 7
	A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:
	> N is an odd integer within the range [1..1,000,000];
	> each element of array A is an integer within the range 
	  [1..1,000,000,000];
	> all but one of the values in A occur an even number of times.
*/

#include <iostream>
#include <vector>
#include <algorithm>

// int solution(std::vector<int> &A){
// 	// exception
//     int size = A.size();
//     if(size == 1){
//     	return A[0];
//     }

//     // initialization
//     bool isOdd = true;
//     std::sort(A.begin(),A.end());
    
//     // function
//     for(int i = 1; i < size; i++){
//         if(A[i] == A[i-1]){
//             isOdd = !isOdd;
//         }
//         else{
//             if(isOdd){
//                 return A[i-1];
//             }
//             else if(!isOdd && i != size -1){
//                 isOdd = !isOdd;;
//             }
//             else{
//             	return A[i];
//             }
//         }
//     }
//     return 0;
// }

// int solution(std::vector<int> &A){
// 	// initialization
// 	int maxA = 0;
// 	int size = A.size();

// 	// exception
// 	if (size == 1){
// 		return A[0];
// 	}

// 	// preprocessing
// 	for (int i : A){
// 		maxA = std::max(maxA,i);
// 	}
// 	std::vector<int> v(maxA+1,0);
// 	for (int i = 0; i < size; i++){
// 		if (v[A[i]] != 0)
// 		{
// 			v[A[i]] = 0;
// 		}
// 		else{
// 			v[A[i]] = A[i];	
// 		}
// 	}
	
// 	// function
// 	for (int i = 0; i < maxA+1; i++){
// 		if (v[i] != 0)
// 		{
// 			return v[i];
// 		}
// 	}
// 	return 0;
// }

int solution(std::vector<int> &A){
	int ans = 0;
		for(int i : A) {
			ans ^= i;
		}
		return ans;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,4,3,3,4};
	std::cout << solution(v);
	return 0;
}