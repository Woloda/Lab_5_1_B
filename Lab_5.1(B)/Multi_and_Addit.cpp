#include <iostream>
#include "FuzzyNumber.h"

FuzzyNumber operator +(FuzzyNumber obj_A, FuzzyNumber obj_B) {    //функція: дія --- додавання
	FuzzyNumber obj_addit;
	obj_addit.x = obj_A.x + obj_B.x - obj_A.l - obj_B.l;
	obj_addit.l = obj_A.x + obj_B.x;
	obj_addit.r = obj_A.x + obj_B.x + obj_A.r + obj_B.r;

	return obj_addit;
}

FuzzyNumber operator *(FuzzyNumber obj_A, FuzzyNumber obj_B) {	  //функція: дія --- множення
	FuzzyNumber obj_multi;
	obj_multi.x = obj_A.x * obj_B.x - obj_B.x * obj_A.l - obj_A.x * obj_B.l - obj_A.l * obj_B.l;
	obj_multi.l = obj_A.x * obj_B.x;
	obj_multi.r = obj_A.x * obj_B.x + obj_B.x * obj_A.r + obj_A.x * obj_B.r + obj_A.r * obj_B.r;

	return obj_multi;
}