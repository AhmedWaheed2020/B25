a/*
 * BIT_MATH.h
 *
 * Created: 27/07/2020 09:17:36 ?
 *  Author: Ahmed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)  		 (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT) 		 (REG &=~ (1<<BIT))
#define Toggle_BIT(REG,BIT)		 (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)	     ((REG >> BIT) & (0X01))





#endif /* BIT_MATH_H_ */