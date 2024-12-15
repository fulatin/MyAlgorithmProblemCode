#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <cmath>
#include <ctime>
#include <iostream>

const double PI = acos(-1);
const int width = 1920;
const int height = 1080;
const SDL_Color bgcolor = {2, 2, 2, 255}; // White

struct {
  float x;
  float y;
  float r;
  SDL_Color clockcolor = {139, 69, 19, 100};     // Brown
  SDL_Color clockBordercolor = {0, 0, 255, 255}; // Blue
  SDL_Color textColor = {255, 255, 255, 255};    // White
  int lineLen1 = 6;
  int lineLen2 = 20;
  int textOffset;
  int secLen;
  int minLen;
  int hourLen;
  SDL_Color secPinColor = {255, 0, 0, 255};      // Red
  SDL_Color minPinColor = {255, 255, 255, 255};  // White
  SDL_Color hourPinColor = {255, 255, 255, 255}; // White
} mc;

float mcos(float x) { return cos(x - PI / 2); }

float msin(float x) { return sin(x - PI / 2); }

void int2str(int x, char *s) {
  int pos = 0;
  while (x > 0) {
    s[pos] = '0' + x % 10;
    x /= 10;
    pos++;
  }
  for (int i = 0; i < pos / 2; ++i) {
    char tmp = s[i];
    s[i] = s[pos - i - 1];
    s[pos - i - 1] = tmp;
  }
  s[pos] = '\0';
}

void getNowTime(int &hour, int &min, int &sec) {
  std::time_t now = std::time(nullptr);
  std::tm *localTime = std::localtime(&now);

  // 鳳龰奀煦鏃
  hour = localTime->tm_hour;
  min = localTime->tm_min;
  sec = localTime->tm_sec;
}

void drawboard(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, mc.clockcolor.r, mc.clockcolor.g,
                         mc.clockcolor.b, mc.clockcolor.a);
  filledCircleRGBA(renderer, mc.x, mc.y, mc.r, mc.clockcolor.r, mc.clockcolor.g,
                   mc.clockcolor.g, mc.clockcolor.a);
  SDL_SetRenderDrawColor(renderer, mc.clockBordercolor.r, mc.clockBordercolor.g,
                         mc.clockBordercolor.b, mc.clockBordercolor.a);

  // 餅秶覦僅迵杅趼
  for (int i = 1; i <= 60; ++i) {
    float lineLen = (i % 5 == 0) ? mc.lineLen2 : mc.lineLen1;
    SDL_RenderDrawLine(renderer, mc.x + mc.r * mcos(2 * PI * i / 60),
                       mc.y + mc.r * msin(2 * PI * i / 60),
                       mc.x + (mc.r - lineLen) * mcos(2 * PI * i / 60),
                       mc.y + (mc.r - lineLen) * msin(2 * PI * i / 60));

    if (i % 5 == 0) {

      // 餅秶覦僅迵杅趼
      for (int i = 1; i <= 60; ++i) {
        float lineLen = (i % 5 == 0) ? mc.lineLen2 : mc.lineLen1;
        SDL_RenderDrawLine(renderer, mc.x + mc.r * mcos(2 * PI * i / 60),
                           mc.y + mc.r * msin(2 * PI * i / 60),
                           mc.x + (mc.r - lineLen) * mcos(2 * PI * i / 60),
                           mc.y + (mc.r - lineLen) * msin(2 * PI * i / 60));

        if (i % 5 == 0) {

          char outstr[3];
          int2str(i / 5, outstr);

          // Render text using SDL_TTF (not implemented here for simplicity)
          // You can use SDL_TTF to render the text at the calculated positions.
        }
      }
    }

    void drawPins(SDL_Renderer * renderer) {
      int hour, sec, min;
      getNowTime(hour, min, sec);
      float totalMin = min + (float)sec / 60;
      float totalHour = totalMin / 60 + hour;

      // 奀渀迵煦渀
      SDL_SetRenderDrawColor(renderer, mc.hourPinColor.r, mc.hourPinColor.g,
                             mc.hourPinColor.b, mc.hourPinColor.a);
      SDL_RenderDrawLine(renderer, mc.x, mc.y,
                         mc.x + mc.hourLen * mcos(2 * PI * totalHour / 12),
                         mc.y + mc.hourLen * msin(2 * PI * totalHour / 12));
      SDL_RenderDrawLine(renderer, mc.x, mc.y,
                         mc.x + mc.minLen * mcos(2 * PI * totalMin / 60),
                         mc.y + mc.minLen * msin(2 * PI * totalMin / 60));

      // 鏃渀
      SDL_SetRenderDrawColor(renderer, mc.secPinColor.r, mc.secPinColor.g,
                             mc.secPinColor.b, mc.secPinColor.a);
      SDL_RenderDrawLine(renderer, mc.x, mc.y,
                         mc.x + mc.secLen * mcos(2 * PI * sec / 60),
                         mc.y + mc.secLen * msin(2 * PI * sec / 60));
    }

    void init(SDL_Renderer * renderer) {
      mc.x = width / 2;
      mc.y = height / 2;
      mc.r = std::min(width, height) / 2 - 3;
      mc.textOffset = mc.r / 10;
      mc.secLen = mc.r * 8 / 10;
      mc.minLen = mc.r * 7 / 10;
      mc.hourLen = mc.r * 5 / 10;
    }

    int main() {
      if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return 1;
      }

      SDL_Window *window = SDL_CreateWindow("Clock", SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED, width,
                                            height, SDL_WINDOW_SHOWN);
      if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        return 1;
      }

      SDL_Renderer *renderer =
          SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        return 1;
      }

      init(renderer);

      bool running = true;
      SDL_Event event;
      while (running) {
        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
            running = false;
          }
        }

        SDL_SetRenderDrawColor(renderer, bgcolor.r, bgcolor.g, bgcolor.b,
                               bgcolor.a);
        SDL_RenderClear(renderer);

        drawboard(renderer);
        drawPins(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
      }

      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();

      return 0;
    }
