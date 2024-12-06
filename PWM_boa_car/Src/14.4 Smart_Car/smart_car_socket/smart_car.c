#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "smart_car.h"

static int fd;

void init_LED()
{
    fd = open("/sys/class/gpio/export", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 export\n");
    write(fd, "61", 2);
    close(fd);	

    fd = open("/sys/class/gpio/export", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 export\n");
    write(fd, "62", 2);
    close(fd);

    fd = open("/sys/class/gpio/export", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 export\n");
    write(fd, "63", 2);
    close(fd);

    fd = open("/sys/class/gpio/export", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 export\n");
    write(fd, "64", 2);
    close(fd);
}
void set_clockwise()
{	
	char *cspeed="7000";
    fd = open("/sys/class/mydriver/my_device/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open value\n");
    write(fd, "0xcc", 5);
    close(fd);
    fd = open("/sys/class/mydriver/my_device/pwm2_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm2_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm1_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm1_speed\n");
    write(fd, cspeed, 6);
    close(fd);
    fd = open("/sys/class/mydriver/my_device/pwm4_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm4_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm3_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm3_speed\n");
    write(fd, cspeed, 6);
    close(fd);
}
void set_counterclockwise()
{
	char *cspeed="7000";
    fd = open("/sys/class/mydriver/my_device/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open value\n");
    write(fd, "0x33", 5);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm2_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm2_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm1_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm1_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm4_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm4_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm3_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm3_speed\n");
    write(fd, cspeed, 6);
    close(fd);
}
void set_go()
{
    fd = open("/sys/class/mydriver/my_device/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open value\n");
    write(fd, "0x00", 5);
    close(fd);
}

void set_back()
{
    fd = open("/sys/class/mydriver/my_device/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open value\n");
    write(fd, "0xFF", 5);
    close(fd);
}

void set_left(unsigned long speed)
{
    int i;
    char cspeed[6];

    cspeed[5] = '\0';
    for (i=4; i>=0; i--){
        cspeed[i] = '0'+ (speed % 10);
        speed /= 10;
    }

    fd = open("/sys/class/mydriver/my_device/pwm2_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm2_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm1_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm1_speed\n");
    write(fd, cspeed, 6);
    close(fd);
//Control LED 

    fd = open("/sys/class/gpio/gpio61/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio61/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 value\n");
    write(fd, "1", 1);
    close(fd);


    fd = open("/sys/class/gpio/gpio62/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio62 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio62/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio62 value\n");
    write(fd, "1", 1);
    close(fd);


    fd = open("/sys/class/gpio/gpio63/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio63 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio63/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio63 value\n");
    write(fd, "0", 1);
    close(fd);

    fd = open("/sys/class/gpio/gpio64/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio64 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio64/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio64 value\n");
    write(fd, "0", 1);
    close(fd);
}

void set_right(unsigned long speed)
{
    int i;
    char cspeed[6];

    cspeed[5] = '\0';
    for (i=4; i>=0; i--){
        cspeed[i] = '0'+ (speed % 10);
        speed /= 10;
    }

    fd = open("/sys/class/mydriver/my_device/pwm4_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm4_speed\n");
    write(fd, cspeed, 6);
    close(fd);

    fd = open("/sys/class/mydriver/my_device/pwm3_speed", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open pwm3_speed\n");
    write(fd, cspeed, 6);
    close(fd);


    fd = open("/sys/class/gpio/gpio61/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio61/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio61 value\n");
    write(fd, "0", 1);
    close(fd);


    fd = open("/sys/class/gpio/gpio62/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio62 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio62/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio62 value\n");
    write(fd, "0", 1);
    close(fd);

	
    fd = open("/sys/class/gpio/gpio63/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio63 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio63/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio63 value\n");
    write(fd, "1", 1);
    close(fd);

    fd = open("/sys/class/gpio/gpio64/direction", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio64 direction\n");
    write(fd, "out", 3);
    close(fd);
    fd = open("/sys/class/gpio/gpio64/value", O_WRONLY|O_TRUNC);
    if (fd < 0)
        printf("can't open gpio64 value\n");
    write(fd, "1", 1);
    close(fd);
}

void set_car(unsigned int FB, unsigned int LR, unsigned long fast, unsigned long slow)
{
    if (FB){
	set_back();
    }
    else {
	set_go();
    }

    if (LR){
        set_left(slow);
	set_right(fast);
    }
    else {
	set_left(fast);
        set_right(slow);
    }
} 

//speed from -50 to 50; angle from -90 to 90
void smart_car_set(int speed, int angle)
{
    static unsigned int dir_FB, dir_LR; //dir_FB = 0, forward. dir_LR = 0, right
    static unsigned long pwm_fast, pwm_slow;
    if (speed){
	if (speed < 0) {
	    dir_FB = 1;
	    speed = -1 * speed;
	}
        else {
	    dir_FB = 0;
	}

	if (angle < 0) {
	    dir_LR = 1;
	    angle = -1 * angle;
	}
	else {
	    dir_LR = 0;
	}
        pwm_fast = 5000 + speed * 80;
	pwm_slow = 5000 + speed * (80 - angle);
    }	
    else {
	pwm_fast = 0;
	pwm_slow = 0;
    }
    
    set_car(dir_FB, dir_LR, pwm_fast, pwm_slow);
}

