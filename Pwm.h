
/**
 * This is a siple Wire library to Raspberry. 
 * It doesn't use the specific i2c module (i2c_dev or i2c_bcm2708)
 * it maps the memory (the BSC0 chunk) into the virtual memory space 
 * and handles directly the register.
 * 
 * Thanks to this blog: http://www.susa.net/wordpress/2012/06/raspberry-pi-pcf8563-real-time-clock-rtc/
 */
 
#ifndef __RASPBERRY_WIRE_H__
#define __RASPBERRY_WIRE_H__ 1

#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

#include <Bcm2835.h>

#define PWM_ADDRESS     0x20c000

#define PWM_CTL         *((unsigned int *)(pwm.mem) + 0x00)
#define PWM_STA         *((unsigned int *)(pwm.mem) + 0x01)
#define PWM_DMAC        *((unsigned int *)(pwm.mem) + 0x02)
#define PWM_RNG1        *((unsigned int *)(pwm.mem) + 0x03)
#define PWM_DAT1        *((unsigned int *)(pwm.mem) + 0x04)
#define PWM_DAT1        *((unsigned int *)(pwm.mem) + 0x05)
#define PWM_FIF1        *((unsigned int *)(pwm.mem) + 0x06)
#define PWM_RNG2        *((unsigned int *)(pwm.mem) + 0x07)
#define PWM_DAT2        *((unsigned int *)(pwm.mem) + 0x08)

// p142
#define PWM_CTL_PWEN1   (0x01 << 0)
#define PWM_CTL_MODE1   (0x01 << 1)
#define PWM_CTL_RPTL1   (0x01 << 2)
#define PWM_CTL_SBIT1   (0x01 << 3)
#define PWM_CTL_POLA1   (0x01 << 4)
#define PWM_CTL_USEF1   (0x01 << 5)
#define PWM_CTL_CLRF1   (0x01 << 6)
#define PWM_CTL_MSEN1   (0x01 << 7)

#define PWM_CTL_PWEN2   (0x01 << 8)
#define PWM_CTL_MODE2   (0x01 << 9)
#define PWM_CTL_RPTL2   (0x01 << 10)
#define PWM_CTL_SBIT2   (0x01 << 11)
#define PWM_CTL_POLA2   (0x01 << 12)
#define PWM_CTL_USEF2   (0x01 << 13)
#define PWM_CTL_MSEN2   (0x01 << 15)

// p144
#define PWM_STA_FULL1   (0x01 << 0)
#define PWM_STA_EMPT1   (0x01 << 1)
#define PWM_STA_WERR1   (0x01 << 2)
#define PWM_STA_RERR1   (0x01 << 3)
#define PWM_STA_GAPO1   (0x01 << 4)
#define PWM_STA_GAPO2   (0x01 << 5)
#define PWM_STA_GAPO3   (0x01 << 6)
#define PWM_STA_GAPO4   (0x01 << 7)
#define PWM_STA_BERR    (0x01 << 8)
#define PWM_STA_STA1    (0x01 << 9)
#define PWM_STA_STA2    (0x01 << 10)
#define PWM_STA_STA3    (0x01 << 11)
#define PWM_STA_STA4    (0x01 << 12)

// p145
#define PWM_DMAC_DREQ   (0xff << 0)
#define PWM_DMAC_PANIC  (0xff << 8)
#define PWM_DMAC_ENAB   (0x01 << 31)

class PwmRPi {
    
    /**
     * Peripheral
     */
    Bcm2835::Peripheral pwm;
    
    /**
     * PWM pin
     */
    unsigned char channel;
    
public:

    PwmRPi(unsigned char channel);

    /**
     */
    void begin();

    /**
     */
    void stop();

    /**
     */
    void analogWrite(unsigned char value);
    
    
};

extern PwmRPi Pwm0;
extern PwmRPi Pwm1;

#endif /* __RASPBERRY_PWM_H__ */
