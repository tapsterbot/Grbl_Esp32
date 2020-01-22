// hk_cheetah.h
#define USE_MACHINE_INIT


// config
#define HOMING_FORCE_POSITIVE_SPACE
#define SHOW_EXTENDED_SETTINGS
// cpu map
#define LIMIT_MASK 0  // no limit pins
// defaults
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 250 // goes into idle 
#define DEFAULT_X_STEPS_PER_MM 334
#define DEFAULT_USER_INT_80 300  // kp
#define DEFAULT_USER_INT_81 300  // kd
#define DEFAULT_USER_INT_82 4000 // feed forward torque

#define CHEETAH_ID 1
#define CHEETAH_TIMER_INT_FREQ 10 // milliseconds between syncs
#define CHEETAH_STARTUP_DELAY (2 * 1000) / CHEETAH_TIMER_INT_FREQ // 2 seconds
#define CHEETAH_IDLE_TIMER CHEETAH_STARTUP_DELAY
#define MOTOR_ON 1
#define MOTOR_OFF 0

#ifndef hk_cheetah_h
    #define hk_cheetah_h

    #include "grbl.h"
	#include <CAN.h> // https://github.com/sandeepmistry/arduino-CAN	
	
	
	void machine_init();
	void cheetahSyncTask(void *pvParameters);
	void onCanReceive(int packetSize);
	void cheetah_sync_position();
	void hk_sendMoveCmd(uint8_t id, uint16_t new_pos, 
						uint16_t new_vel, uint16_t new_kp, 
						uint16_t new_kd, uint16_t new_ff);
						
	void cheetahMotorMode(int mode);
	void cheetahEncoderZero();

	
	
	
#endif