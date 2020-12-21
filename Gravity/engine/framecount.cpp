int frameCounter() {
	frameCount++;
	return 0;
}
int setFrameRate() {
	SDL_GL_SetSwapInterval(1);
	return 0;
}
int calculateFrameRate() {
	int now = time(NULL);
	return now / frameCount;
}

