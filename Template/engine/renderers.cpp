void pixel(int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}
void line(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
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
void circle(int cx, int cy, int radius) {
	for (double dy = 0; dy <= radius*2; dy += 1.0)
	{
		double dx = floor(sqrt((2 * radius * dy) - (dy * dy)));
		double dx2 = floor(sqrt((2 * radius * (dy-1)) - ((dy-1) * (dy-1))));
		if (!dy) dx2 = dx;
		line(cx - dx, radius + cy - dy, cx - dx2, radius + cy - dy + 1);
		line(cx + dx, radius + cy - dy, cx + dx2, radius + cy - dy + 1);
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
