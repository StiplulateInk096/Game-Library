void frameCounter() {
	frameCount++;
}
void setFrameRate() {
	SDL_GL_SetSwapInterval(1);
}
float calculateFrameRate() {
	int now = time(NULL);
	return now / frameCount;
}