#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include <cstring>

#include "pico_scroll.hpp"

using namespace pimoroni;

PicoScroll pico_scroll;
const uint8_t HEIGHT = 17;
const uint8_t WIDTH = 7;
uint8_t area[HEIGHT * WIDTH] = {};

enum rotation_t {
  d0,
  d90,
  d180,
  d270
};

typedef struct shape_s {
  uint8_t shape[4 * 4];
  rotation_t rotation;
  uint8_t x;
  uint8_t y;
} shape_t;

//   _
//  |_|
//
const uint8_t shape1[4][4] = {
  {0,0,0,0},
  {0,1,1,0},
  {0,1,1,0},
  {0,0,0,0}
};

//  _
//   |_
//
const uint8_t shape2[4][4] = {
  {0,0,0,0},
  {1,1,0,0},
  {0,1,1,0},
  {0,0,0,0}
};

//
//  |__  
//
const uint8_t shape3[4][4] = {
  {0,0,0,0},
  {1,0,0,0},
  {1,1,1,0},
  {0,0,0,0}
};

//
//  _|_  
//
const uint8_t shape4[4][4] = {
  {0,0,0,0},
  {0,1,0,0},
  {1,1,1,0},
  {0,0,0,0}
};

shape_t current_shape;
bool request_new_shape = true;
uint8_t x = 0;
uint8_t y = 0;


int main() {

  pico_scroll.init();


  bool a_pressed = false;
  bool b_pressed = false;
  bool x_pressed = false;
  bool y_pressed = false;

  while(true) {

    if(current_shape.y <= 0)
      request_new_shape = true;


    if(request_new_shape)
    {
      current_shape.x = 4;
      current_shape.y = 17;
      memcpy(current_shape.shape, shape4, 4*4);
      current_shape.rotation = d0;

      request_new_shape = false;
    }

    for(x = 0; x < 4; x++)
    {
      for(y = 0; y < 4; y++)
      {
        pico_scroll.set_pixel(
          x + current_shape.x,
          y + current_shape.y, 
          3
        );
      }
    }

    current_shape.y -= 1;

    if(pico_scroll.is_pressed(pico_scroll.A)) { a_pressed = true; }
    if(pico_scroll.is_pressed(pico_scroll.B)) { b_pressed = true; }
    if(pico_scroll.is_pressed(pico_scroll.X)) { x_pressed = true; }
    if(pico_scroll.is_pressed(pico_scroll.Y)) { y_pressed = true; }

    pico_scroll.clear();

    if(a_pressed & b_pressed & x_pressed & y_pressed) {
    } else {
      // button test phase
      if(a_pressed) {
      }else{
      }

      if(b_pressed) {
      }else{
      }

      if(x_pressed) {
      }else{
      }

      if(y_pressed) {
      }else{
      }
    }

    pico_scroll.update();

    sleep_ms(500);
  }

  return 0;
}
