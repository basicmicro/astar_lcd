#include <AStar32U4LCD.h>
#include "RoboClaw.h"

void get_display_counts(void);

AStar32U4LCD astar;

RoboClaw roboclaw(&Serial1, 10000);

String count = String("Count:");

void setup() {
  roboclaw.begin(38400);
  astar.initPins();
  astar.init();
}

void loop() {
  
  roboclaw.ForwardM1(0x80, 64);
  get_display_counts();
  astar.clear();

  roboclaw.ForwardM1(0x80,0);
  get_display_counts();
  astar.clear();
 }

void get_display_counts(void) {

   delay(100);

   String enc_count = String(roboclaw.ReadEncM1(0x80));
   int enc_length = enc_count.length();
  
   astar.write(count.c_str(), 6);
   astar.setCursor(0,1);
   astar.write(enc_count.c_str(), enc_length);

   delay(2000);
}
