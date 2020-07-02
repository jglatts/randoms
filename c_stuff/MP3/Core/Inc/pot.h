/*
 * pot.h
 *
 *  Created on: Jul 2, 2020
 *      Author: johng
 */

#ifndef INC_POT_H_
#define INC_POT_H_

typedef struct POT {
	uint8_t has_changed;
	uint8_t is_zero;
	uint32_t old_value;
	uint32_t new_value;
} POT;

#endif /* INC_POT_H_ */
