#define detail PI/1000

void pixel(int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}
void line(int x1, int y1, int x2, int y2) {
	float dx = x2 - x1;
	float dy = y2 - y1;	
	for (int y = y2; y <= y1; y++) {
		int x = x1 + dx * (y - y1) / dy;
		pixel(x, y);
	}
	for (int y = y1; y <= y2; y++) {
		int x = x1 + dx * (y - y1) / dy;
		pixel(x, y);
	}
	for (int x = x1; x <= x2; x++) {
		int y = y1 + dy * (x - x1) / dx;
		pixel(x, y);
	}
	for (int x = x2; x <= x1; x++) {
		int y = y1 + dy * (x - x1) / dx;
		pixel(x, y);
	}
}
void rect(int x, int y, int w, int h)
{
	line(x, y, x + w, y);
	line(x + w, y, x + w, y + h);
	line(x + w, y + h, x, y + h);
	line(x, y + h, x, y);
}
void filledRectangle(int x, int y, int w, int h) {
	for (int a = x; a < x + w; a++) {
		for (int b = y; b < y + h; b++) {
			pixel(a, b);
		}
	}
}
void badFilledCircle(int x, int y, int r) {
	for (int _x = x - r; _x < x + r; _x++) {
		for (int _y = y - r; _y < y + r; _y++) {
			if (dist(_x, _y, x, y) < r) pixel(_x, _y);
		}
	}
}
void filledCircle(int cx, int cy, int radius)
{
	for (double dy = 1; dy <= radius*2; dy += 1.0)
	{
		double dx = floor(sqrt((2 * radius * dy) - (dy * dy)));
		line(cx - dx, cy - dy + radius, cx + dx, cy - dy + radius);
	}
}
void circle(int xp, int yp, int r) {
	for (float a = 0; a < TWO_PI; a+=detail) {
		int x = sin(a)*r;
		int y = cos(a)*r;
		int px = sin(a-detail)*r;
		int py = cos(a-detail)*r;
		line(x+xp, y+yp, px+xp, py+yp);
	}
}
void ellipse(int xp, int yp, int rx, int ry) {
	for (float a = 0; a < TWO_PI; a+=detail) {
		int x = sin(a)*rx;
		int y = cos(a)*ry;
		int px = sin(a-detail)*rx;
		int py = cos(a-detail)*ry;
		line(x+xp, y+yp, px+xp, py+yp);
	}
}
void star(int x, int y, int r) {
	line(x, y - r, x + r / 4, y - r / 4);
	line(x + r / 4, y - r / 4, x + r, y);
	line(x + r, y, x + r / 4, y + r / 4);
	line(x, y + r, x + r / 4, y + r / 4);
	line(x, y + r, x - r / 4, y + r / 4);
	line(x - r / 4, y + r / 4, x - r, y);
	line(x - r, y, x - r / 4, y - r / 4);
	line(x - r / 4, y - r / 4, x, y - r);
}
void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}