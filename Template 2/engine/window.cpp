void setTitle(const char *title) {
	SDL_SetWindowTitle(window, (char*)title);
}
int shouldQuit() {
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			return 1;
		}
	}
	return 0;
}
void moveWindow(int x, int y) {
	SDL_SetWindowPosition(window, x, y);
}
void close()
{
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void messageBox(const char *message) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		"",
		message,
		NULL
	);
}
void setSize(int w,int h) {
	SDL_SetWindowSize(window, w, h);
}