#ifndef PICO_SCROLL_H_
#define PICO_SCROLL_H_

namespace pimoroni {
  class PicoScroll {
    public:
      bool A, B, X, Y;

      void init();
      void set_pixel(int x, int y, int v);
      bool is_pressed(bool key);
      void clear();
      void update();
  };


};

#endif
