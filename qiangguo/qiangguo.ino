#include "Mouse.h"
#include "Keyboard.h"

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

#ifdef _DEBUG

#define MM(x, y, z)
#define MC(x)
#define MP(x)
#define MR(x)
#define KP(x)
#define KR(x)
#define KU(x)
#define KRA()
#define delay(x)
#else

#define MM(x, y, z) Mouse.move(x, y, z)
#define MC(x) Mouse.click(x)
#define MP(x) Mouse.press(x)
#define MR(x) Mouse.release(x)
#define KP(x) Keyboard.press(x)
#define KR(x) Keyboard.release(x)
#define KU(x) Keyboard.write(x)
#define KRA() Keyboard.releaseAll()
#define delay(x) delay(x)
#endif

int platform = WINDOWS;
int loop_count = 0;

int init_mouse()
{
  Mouse.begin();
  Serial.println("init_mouse start");
  for (int i = 0; i < 100; i++)
  {
    MM(-100, -100, 0);
    // delay(100);
  }

  Serial.println("init_mouse done!");
  // delay(3000);
  return 0;
}

int init_keyboard()
{
  Keyboard.begin();
  return 0;
}

int keyboard_return_home()
{
  Serial.println("keyboard_return_home");
  KP(KEY_LEFT_GUI);
  KP(KEY_RETURN);
  KRA();
  delay(1000);
  KP(KEY_LEFT_GUI);
  KP(KEY_RETURN);
  KRA();
  delay(1000);
  return 0;
}

int mouse_open_search()
{
  Serial.println("mouse_open_search");
  MM(50, 100, 0);
  MP(MOUSE_LEFT);
  for (int i = 0; i < 20; i++)
  {
    MM(0, 10, 0);
    delay(100 - random(10));
  }
  MR(MOUSE_LEFT);
  delay(1000);
  return 0;
}

int search_open_app()
{
  Serial.println("search_open_app");
  KP(KEY_BACKSPACE);
  Keyboard.write("xuexiqiangguo\r", 20);
  delay(1000);
  KP(KEY_RETURN);
  KRA();
  delay(1000);
  KP(KEY_RETURN);
  KRA();
  delay(5000);
  return 0;
}

int random_move(int x, int y)
{
  int dx = x + random(10);
  int dy = y + random(10);
  Serial.print("x: ");
  Serial.print(x);

  Serial.print(", y:");
  Serial.print(y);

  Serial.print(", dx: ");
  Serial.print(dx);

  Serial.print(", dy: ");
  Serial.println(dy);
  // MM(dx, dy, 0);
  return 0;
}

void back_button()
{

  KP(KEY_RIGHT_GUI);
  delay(100);
  KP(KEY_BACKSPACE);
  delay(500);
  KR(KEY_BACKSPACE);
  delay(500);
  KR(KEY_RIGHT_GUI);
  KRA();
  delay(1000 + random(1000));
}

void open_news()
{
  Serial.println("open_news");
  init_mouse();
  int rand_loop = 60 + random(10);
  for (int i = 0; i < rand_loop; i++)
  {
    int dx = 20 + random(2);
    int dy = 10 + random(1);
    MM(dx, dy, 0);
    delay(50 + random(100));
  }
  delay(50 + random(50));
  MC(MOUSE_LEFT);
  delay(50 + random(1000));
}

void mv_mouse(int x, int y, int *dx, int *dy)
{
  int acc = 10;

  while (abs(*dx - x) > acc || abs(*dy - y) > acc)
  {
    int nx = 0;
    int ny = 0;
    if (abs(*dx - x) > acc)
    {
      if (*dx > x)
      {
        nx = -random(acc);
      }
      else
      {
        nx = random(acc);
      }
    }
    if (abs(*dy - y) > acc)
    {
      if (*dy > y)
      {
        ny = -random(acc);
      }
      else
      {
        ny = random(acc);
      }
    }
    MM(nx, ny, 0);
    *dx += nx;
    *dy += ny;
    delay(10 + random(100));

    Serial.print("dx: ");
    Serial.print(*dx);
    Serial.print(", dy: ");
    Serial.println(*dy);
  }
  Serial.println("mv_mouse done!");
  Serial.print("dx: ");
  Serial.print(*dx);
  Serial.print(", dy: ");
  Serial.println(*dy);
  delay(500 + random(50));
}

void open_local_news()
{
  Serial.println("open_local_news");
  init_mouse();
  int rand_loop = 15 + random(2);
  int ddx = 0;
  int ddy = 0;
  int px = 1190;
  int py = 235;
  int nx = 0;
  int ny = 0;
  for (int i = 0; i < rand_loop; i++)
  {
    int dx = 35 + random(5);
    int dy = 7 + random(1);
    MM(dx, dy, 0);
    ddx += dx;
    ddy += dy;
    delay(10 + random(100));
  }

  mv_mouse(px, py, &ddx, &ddy);
  delay(50 + random(50));
  MC(MOUSE_LEFT);
  delay(50 + random(1000));

  MM(0, 30 + random(10), 0);

  // scroll down
  int scroll_loop = 10 + random(5);
  for (int i = 0; i < scroll_loop; i++)
  {
    MM(0, 0, -10 + random(20));
    delay(1000 - random(500));
  }
  delay(1000 + random(1000));
  MC(MOUSE_LEFT);
  delay(1000 + random(1000));
}

void open_video_news()
{
  Serial.println("open_video_news");
  init_mouse();
  int rand_loop = 15 + random(2);
  int ddx = 0;
  int ddy = 0;
  int px = 700;
  int py = 1350;
  int nx = 0;
  int ny = 0;
  for (int i = 0; i < rand_loop; i++)
  {
    int dx = 25 + random(5);
    int dy = 20 + random(1);
    MM(dx, dy, 0);
    ddx += dx;
    ddy += dy;
    delay(10 + random(100));
  }

  mv_mouse(px, py, &ddx, &ddy);
  delay(50 + random(50));
  MC(MOUSE_LEFT);
  delay(50 + random(1000));
}

void open_news_left()
{
  Serial.println("open_news_left");
  init_mouse();
  int rand_loop = 50 + random(10);
  for (int i = 0; i < rand_loop; i++)
  {
    int dx = 10 + random(1);
    int dy = 12 + random(1);
    MM(dx, dy, 0);
    delay(50 + random(100));
  }

  MP(MOUSE_LEFT);
  int dx = 0;
  int dy = 0;
  for (int i = 0; i < 10 + random(5); i++)
  {
    int tx = random(2);
    int ty = -20 + random(10);
    MM(tx, ty, 0);
    dx += tx;
    dy += ty;
    delay(10 + random(20));
  }
  MR(MOUSE_LEFT);
  delay(1000 + random(1000));
  MM(-dx, -dy, 0);
  for (int i = 0; i < 40 + random(5); i++)
  {
    MM(0, 0, -100 - random(10));
    delay(10 + random(20));
  }
  delay(2000 + random(1000));
  MC(MOUSE_LEFT);
  delay(50 + random(1000));
}

void read_news()
{
  Serial.println("read_news");
  init_mouse();
  int rand_loop = 60 + random(10);
  for (int i = 0; i < rand_loop; i++)
  {
    int dx = 30 + random(3);
    int dy = 15 + random(1);
    MM(dx, dy, 0);
    delay(50 + random(10));
  }

  MC(MOUSE_LEFT);
  delay(3000 + random(1000));
  MC(MOUSE_LEFT);
  delay(1000 + random(1000));

  for (int j = 0; j < 8 + random(5); j++)
  {
    MM(0, 0, 10 - random(25));
    delay(10000 - random(5000));
    int need_click = random(1);
    if (need_click)
    {
      MC(MOUSE_LEFT);
      delay(500 + random(500));
    }
  }
  delay(3000 + random(1000));
}

void close_news()
{
  Serial.println("close_news");
  back_button();
  delay(1000 + random(1000));
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // init_led_builtin();
  delay(3000);
  open_news_left();
  delay(20000);
  // Mouse.begin();
  // MM(0, 0, 100);

  init_mouse();
  init_keyboard();
  randomSeed(analogRead(0));

  // open app
  keyboard_return_home();
  init_mouse();
  mouse_open_search();
  search_open_app();

  // read local news
  // for (int i = 0; i < 2; i++)
  // {
  //   open_local_news();
  //   read_news();
  //   close_news();
  // }

  // read news
  open_news();
  read_news();
  for (int i = 0; i < 12 + random(16); i++)
  {
    open_news_left();
    read_news();
  }

  open_video_news();

  for (int i = 0; i < 12 + random(16); i++)
  {
    open_news_left();
    read_news();
  }
}

void loop()
{
  char inChar;

  // while (1)
  // {
  //   if (Serial.available() > 0)
  //   {
  //     inChar = Serial.read();
  //     Serial.println(inChar);
  //     break;
  //   }
  // }

  // if (inChar == 'r')
  // {
  //   random_move(3, 4);
  // }
  // else if (inChar == 't')
  // {
  //   /* code */
  // }

  // digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
  // delay(500);                      // wait for a second
  // digitalWrite(LED_BUILTIN, HIGH); // turn the LED off by making the voltage LOW
  // delay(500);                      // wait for a second
  // for (int i = 0; i < 10; i++)
  // {
  //   delay(1000);
  // }
  int delay_time = 300;
  Serial.print("delay_time: ");
  Serial.println(delay_time);
  delay(delay_time);

  loop_count++;
  Serial.print("loop_count ");
  Serial.print(loop_count);
  Serial.println(" Done!");
}
