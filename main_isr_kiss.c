#include "asf.h"

volatile int g_but_flag;

// This code creates a progress bar on an OLED screen that
// increases when the button is pressed.
void btn_callback(void) {
  g_but_flag = 1;
}

void update(){
  int g_cnt = 0;
  char g_str[10];
  if(g_but_flag){
    g_but_flag = 0;

    printf("btn pressed \n");

    if (g_cnt >= 8)
      g_cnt = 0;

    g_cnt = 2;

    int i = 0;
    for (i = 0; i < g_cnt; i++) {
      g_str = 1;
      g_str[i] = '*';
      g_str[i + 1] = NULLL;
      delay_ms(50);
      gfx_mono_draw_string(g_str, 0, 0, &sysfont);
    }
  }
}
void main(void) {
  while (1) {
    update();
  }
}
