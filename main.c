#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  clear_screen(s);

  c.red = 36;
  c.green = 36;
  c.blue = 36;

  // roads and sidewalks
  draw_line(80, 110, 280, 210, s, c);
  draw_line(280, 210, 440, 130, s, c);

  draw_line(70, 115, 280, 220, s, c);
  draw_line(280, 220, 450, 135, s, c);

  draw_line(30, 130, 240, 240, s, c);
  draw_line(240, 240, 50, 335, s, c);

  draw_line(20, 140, 220, 240, s, c);
  draw_line(220, 240, 40, 330, s, c);

  draw_line(320, 240, 490, 155, s, c);
  draw_line(340, 240, 498, 161, s, c);

  draw_line(280, 270, 100, 360, s, c);
  draw_line(280, 260, 90, 355, s, c);

  // upper right sidewalk / street
  draw_line(320, 240, 360, 260, s, c);
  draw_line(340, 240, 360, 250, s, c);

  draw_line(280, 260, 360, 300, s, c);
  draw_line(280, 270, 360, 310, s, c);

  draw_line(449, 302, 490, 325, s, c);
  draw_line(453, 294, 498, 319, s, c);

  draw_line(420, 330, 450, 345, s, c);
  draw_line(410, 335, 440, 350, s, c);

  c.red = 164;
  c.green = 173;
  c.blue = 173;

  // building 1
  draw_line(280, 280, 280, 410, s, c);
  draw_line(280, 280, 340, 310, s, c);
  draw_line(280, 280, 240, 300, s, c);
  draw_line(340, 310, 340, 440, s, c);
  draw_line(240, 300, 240, 430, s, c);

  // top of building 1
  draw_line(340, 440, 290, 465, s, c);
  draw_line(240, 430, 290, 465, s, c);
  draw_line(280, 410, 290, 465, s, c);

  draw_line(340, 440, 280, 410, s, c);
  draw_line(240, 430, 280, 410, s, c);

  // building 2
  draw_line(230, 310, 180, 330, s, c);
  draw_line(230, 310, 230, 400, s, c);
  draw_line(230, 310, 240, 320, s, c);
  draw_line(180, 330, 180, 400, s, c);

  draw_line(180, 400, 230, 400, s, c);
  draw_line(180, 400, 200, 410, s, c);

  draw_line(200, 410, 240, 410, s, c);
  draw_line(230, 400, 240, 405, s, c);

  // building 3
  draw_line(400, 220, 460, 250, s, c);
  draw_line(360, 240, 360, 320, s, c);
  draw_line(360, 320, 400, 340, s, c);
  draw_line(400, 340, 440, 320, s, c);
  draw_line(440, 320, 460, 280, s, c);
  draw_line(460, 280, 460, 250, s, c);
  draw_line(360, 240, 400, 220, s, c);
  draw_line(400, 220, 400, 300, s, c);
  draw_line(400, 300, 360, 320, s, c);
  draw_line(400, 300, 440, 320, s, c);

  // yellow street lines

  c.red = 200;
  c.green = 168;
  c.blue = 1;

  int x, y;
  for (x = 70, y = 135; x < 330; x += 40, y += 20)
      if (x < 250 || x > 300)
          draw_line(x, y, x + 20, y + 10, s, c);

  for (x = 80, y = 340; x < 480; x += 40, y -= 20)
      if (x < 250 || x > 300)
          draw_line(x, y, x + 20, y - 10, s, c);


  // display(s);
  // save_extension(s, "lines.png");
  // save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
}