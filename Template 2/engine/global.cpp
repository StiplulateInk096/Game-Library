#define PI 3.14159265
#define TWO_PI PI*2
SDL_Window* window;
SDL_Renderer* renderer;
int frameCount = 0;
int frameRate = 0;
int width = 400;
int height = 400;
int mouseX = 0;
int mouseY = 0;
int gMouseX = 0;
int gMouseY = 0;
vector <thread> threads;