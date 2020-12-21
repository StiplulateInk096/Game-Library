int setTitle(const char *title) {
	SDL_SetWindowTitle(window, (char*)title);
	return 0;
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
int close()
{
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
int messageBox(const char *message) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		"",
		message,
		NULL
	);
	return 0;
}
