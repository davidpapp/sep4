/*
 * game.h
 *
 * Created: 2016. 12. 12. 20:26:39
 *  Author: David
 */ 


#ifndef GAME_H_
#define GAME_H_

#include <FreeRTOS.h>
#include <semphr.h>


#define joy_UP !(PINC & 0x40)
#define joy_DOWN !(PINC & 0x01)
#define joy_LEFT !(PINC & 0x80)
#define joy_RIGHT !(PINC & 0x02)
#define joy_PUSH !(PIND & 0x08)
#define joy_ALLDIR !(PINC & 0xC3)

typedef void *(*game_stateFunc)();

void *game_idle();
void *game_run();
void *game_score();

void *init_game(uint16_t *scr_buff, SemaphoreHandle_t *scr_mtx, uint8_t *pl_pos_p, SemaphoreHandle_t *pl_mtx, uint8_t *ps_pos_p, SemaphoreHandle_t *ps_mtx);


#endif /* GAME_H_ */